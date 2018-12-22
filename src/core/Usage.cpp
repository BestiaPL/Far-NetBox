//---------------------------------------------------------------------------
#include <vcl.h>
__removed #pragma hdrstop

#include <Configuration.h>
#include <CoreMain.h>
#include <Common.h>
#include <Usage.h>
//---------------------------------------------------------------------------
__removed #pragma package(smart_init)
//---------------------------------------------------------------------------
const UnicodeString LastInternalExceptionCounter(L"LastInternalException2");
const UnicodeString LastUpdateExceptionCounter(L"LastUpdateException");
//---------------------------------------------------------------------------
TUsage::TUsage(TConfiguration * Configuration)
{
  FCriticalSection = new TCriticalSection();
  FConfiguration = Configuration;
  FValues = new TStringList();
  FValues->Delimiter = L'&';
  FValues->StrictDelimiter = true;
  FCollect = true;
  Default();
}
//---------------------------------------------------------------------------
TUsage::~TUsage()
{
  delete FValues;
  delete FCriticalSection;
}
//---------------------------------------------------------------------------
void TUsage::Default()
{
  TGuard Guard(FCriticalSection);
  FPeriodCounters.clear();
  FLifetimeCounters.clear();
  FValues->Clear();

  if (Collect) // optimization
  {
    Set(L"FirstUse", StandardTimestamp());
    Set(L"FirstVersion", IntToStr(FConfiguration->CompoundVersion));
    UpdateLastReport();
  }
}
//---------------------------------------------------------------------------
void TUsage::Load(THierarchicalStorage * Storage)
{
  TGuard Guard(FCriticalSection);
  Default();

  if (Storage->OpenSubKey(L"Values", false))
  {
    TStrings * Names = new TStringList();
    try
    {
      Storage->GetValueNames(Names);
      for (int Index = 0; Index < Names->Count; Index++)
      {
        UnicodeString Name = Names->Strings[Index];
        Set(Name, Storage->ReadString(Name, L""));
      }
      Storage->CloseSubKey();
    }
    __finally
    {
      delete Names;
    }
  }

  Load(Storage, L"PeriodCounters", FPeriodCounters);
  Load(Storage, L"LifetimeCounters", FLifetimeCounters);
}
//---------------------------------------------------------------------------
void TUsage::Load(THierarchicalStorage * Storage,
  const UnicodeString& Name, TCounters & Counters)
{
  if (Storage->OpenSubKey(Name, false))
  {
    TStrings * Names = new TStringList();
    try
    {
      Storage->GetValueNames(Names);
      for (int Index = 0; Index < Names->Count; Index++)
      {
        UnicodeString Name = Names->Strings[Index];
        Counters.insert(
          std::make_pair(Name, Storage->ReadInteger(Name, 0)));
      }
      Storage->CloseSubKey();
    }
    __finally
    {
      delete Names;
    }
  }
}
//---------------------------------------------------------------------------
void TUsage::Save(THierarchicalStorage * Storage) const
{
  TGuard Guard(FCriticalSection);
  if (Storage->OpenSubKey(L"Values", true))
  {
    Storage->ClearValues();
    Storage->WriteValues(FValues, true);
    Storage->CloseSubKey();
  }

  Save(Storage, L"PeriodCounters", FPeriodCounters);
  Save(Storage, L"LifetimeCounters", FLifetimeCounters);
}
//---------------------------------------------------------------------------
void TUsage::Save(THierarchicalStorage * Storage,
  const UnicodeString & Name, const TCounters & Counters) const
{
  if (Storage->OpenSubKey(Name, true))
  {
    Storage->ClearValues();
    TCounters::const_iterator i = Counters.begin();
    while (i != Counters.end())
    {
      Storage->WriteInteger(i->first, i->second);
      i++;
    }
    Storage->CloseSubKey();
  }
}
//---------------------------------------------------------------------------
void TUsage::Set(const UnicodeString & Key, const UnicodeString & Value)
{
  if (Collect)
  {
    TGuard Guard(FCriticalSection);
    FValues->Values[Key] = Value;
  }
}
//---------------------------------------------------------------------------
void TUsage::Set(const UnicodeString & Key, int Value)
{
  Set(Key, IntToStr(Value));
}
//---------------------------------------------------------------------------
void TUsage::Set(const UnicodeString & Key, bool Value)
{
  Set(Key, Value ? 1 : 0);
}
//---------------------------------------------------------------------------
UnicodeString TUsage::Get(const UnicodeString & Key)
{
  TGuard Guard(FCriticalSection);
  UnicodeString Result = FValues->Values[Key];
  Result.Unique();
  return Result;
}
//---------------------------------------------------------------------------
void TUsage::UpdateLastReport()
{
  Set(L"LastReport", StandardTimestamp());
}
//---------------------------------------------------------------------------
void TUsage::Reset()
{
  TGuard Guard(FCriticalSection);
  UpdateLastReport();
  FPeriodCounters.clear();
  ResetLastExceptions();
}
//---------------------------------------------------------------------------
void TUsage::UpdateCurrentVersion()
{
  TGuard Guard(FCriticalSection);
  int CompoundVersion = FConfiguration->CompoundVersion;
  int PrevVersion = StrToIntDef(Get(L"CurrentVersion"), 0);
  if (PrevVersion != CompoundVersion)
  {
    Set(L"Installed", StandardTimestamp());
  }
  if (PrevVersion != 0)
  {
    if (PrevVersion < CompoundVersion)
    {
      Inc(L"Upgrades");
    }
    else if (PrevVersion > CompoundVersion)
    {
      Inc(L"Downgrades");
    }

    if (PrevVersion != CompoundVersion)
    {
      ResetLastExceptions();
    }
  }
  Set(L"CurrentVersion", CompoundVersion);
}
//---------------------------------------------------------------------------
void TUsage::ResetValue(const UnicodeString & Key)
{
  int Index = FValues->IndexOfName(Key);
  if (Index >= 0)
  {
    FValues->Delete(Index);
  }
}
//---------------------------------------------------------------------------
void TUsage::ResetLastExceptions()
{
  TGuard Guard(FCriticalSection);
  ResetValue(LastInternalExceptionCounter);
  ResetValue(LastUpdateExceptionCounter);
}
//---------------------------------------------------------------------------
void TUsage::Inc(const UnicodeString & Key, int Increment)
{
  if (Collect)
  {
    TGuard Guard(FCriticalSection);
    Inc(Key, FPeriodCounters, Increment);
    Inc(Key, FLifetimeCounters, Increment);
  }
}
//---------------------------------------------------------------------------
void TUsage::Inc(const UnicodeString & Key, TCounters & Counters, int Increment)
{
  TCounters::iterator i = Counters.find(Key);
  if (i != Counters.end())
  {
    i->second += Increment;
  }
  else
  {
    Counters.insert(std::make_pair(Key, Increment));
  }
}
//---------------------------------------------------------------------------
void TUsage::SetMax(const UnicodeString & Key, int Value)
{
  if (Collect)
  {
    TGuard Guard(FCriticalSection);
    SetMax(Key, Value, FPeriodCounters);
    SetMax(Key, Value, FLifetimeCounters);
  }
}
//---------------------------------------------------------------------------
void TUsage::SetMax(const UnicodeString & Key, int Value,
  TCounters & Counters)
{
  TCounters::iterator i = Counters.find(Key);
  if (i != Counters.end())
  {
    if (Value > i->second)
    {
      i->second = Value;
    }
  }
  else
  {
    Counters.insert(std::make_pair(Key, Value));
  }
}
//---------------------------------------------------------------------------
void TUsage::SetCollect(bool value)
{
  TGuard Guard(FCriticalSection);
  if (Collect != value)
  {
    FCollect = value;
    if (!FCollect)
    {
      FPeriodCounters.clear();
      FLifetimeCounters.clear();
      FValues->Clear();
    }
    else
    {
      Default();
    }
  }
}
//---------------------------------------------------------------------------
UnicodeString TUsage::Serialize(const UnicodeString & Delimiter, const UnicodeString & Filter) const
{
  TGuard Guard(FCriticalSection);
  UnicodeString Result;

  UnicodeString FilterUpper = Filter.UpperCase();
  for (int Index = 0; Index < FValues->Count; Index++)
  {
    Serialize(Result, FValues->Names[Index], FValues->ValueFromIndex[Index], Delimiter, FilterUpper);
  }

  Serialize(Result, L"Period", FPeriodCounters, Delimiter, FilterUpper);
  Serialize(Result, L"Lifetime", FLifetimeCounters, Delimiter, FilterUpper);

  return Result;
}
//---------------------------------------------------------------------------
void TUsage::Serialize(
  UnicodeString & List, const UnicodeString & Name, const TCounters & Counters,
  const UnicodeString & Delimiter, const UnicodeString & FilterUpper) const
{
  TCounters::const_iterator i = Counters.begin();
  while (i != Counters.end())
  {
    Serialize(List, Name + i->first, IntToStr(i->second), Delimiter, FilterUpper);
    i++;
  }
}
//---------------------------------------------------------------------------
void TUsage::Serialize(
  UnicodeString & List, const UnicodeString & Name, const UnicodeString & Value,
  const UnicodeString & Delimiter, const UnicodeString & FilterUpper) const
{
  if (FilterUpper.IsEmpty() ||
      (Name.UpperCase().Pos(FilterUpper) > 0) ||
      (Value.UpperCase().Pos(FilterUpper) > 0))
  {
    AddToList(List, FORMAT(L"%s=%s", (Name, Value)), Delimiter);
  }
}
//---------------------------------------------------------------------------
int TUsage::CalculateCounterSize(int64_t Size)
{
  const int SizeCounterFactor = 10240;
  return (Size <= 0) ? 0 : (Size < SizeCounterFactor ? 1 : Size / SizeCounterFactor);
}

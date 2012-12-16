//---------------------------------------------------------------------------
#ifndef SecureShellH
#define SecureShellH

#include <set>
#include "PuttyIntf.h"
#include "Configuration.h"
#include "SessionData.h"
#include "SessionInfo.h"
//---------------------------------------------------------------------------
#ifndef PuttyIntfH
struct Backend;
struct Config;
#endif
//---------------------------------------------------------------------------
struct _WSANETWORKEVENTS;
typedef struct _WSANETWORKEVENTS WSANETWORKEVENTS;
typedef UINT_PTR SOCKET;
typedef std::set<SOCKET> TSockets;
struct TPuttyTranslation;
//---------------------------------------------------------------------------
class TSecureShell
{
friend class TPoolForDataEvent;

private:
  SOCKET FSocket;
  HANDLE FSocketEvent;
  TSockets FPortFwdSockets;
  TSessionUI * FUI;
  TSessionData * FSessionData;
  bool FActive;
  TSessionInfo FSessionInfo;
  bool FSessionInfoValid;
  TDateTime FLastDataSent;
  Backend * FBackend;
  void * FBackendHandle;
  const unsigned int * FMinPacketSize;
  const unsigned int * FMaxPacketSize;
  Config * FConfig;
  TNotifyEvent FOnReceive;
  bool FFrozen;
  bool FDataWhileFrozen;
  bool FStoredPasswordTried;
  bool FStoredPasswordTriedForKI;
  int FSshVersion;
  bool FOpened;
  int FWaiting;
  bool FSimple;

  unsigned PendLen;
  unsigned PendSize;
  unsigned OutLen;
  unsigned char * OutPtr;
  unsigned char * Pending;
  TSessionLog * FLog;
  TConfiguration * FConfiguration;
  bool FAuthenticating;
  bool FAuthenticated;
  UnicodeString FStdErrorTemp;
  UnicodeString FStdError;
  UnicodeString FCWriteTemp;
  UnicodeString FAuthenticationLog;
  UnicodeString FLastTunnelError;
  UnicodeString FUserName;

  static TCipher __fastcall FuncToSsh1Cipher(const void * Cipher);
  static TCipher __fastcall FuncToSsh2Cipher(const void * Cipher);
  UnicodeString __fastcall FuncToCompression(int SshVersion, const void * Compress) const;
  void __fastcall Init();
  void __fastcall SetActive(bool value);
  void inline __fastcall CheckConnection(int Message = -1);
  void __fastcall WaitForData();
  void __fastcall Discard();
  void __fastcall FreeBackend();
  void __fastcall PoolForData(WSANETWORKEVENTS & Events, unsigned int & Result);
  inline void __fastcall CaptureOutput(TLogLineType Type,
    const UnicodeString & Line);
  void __fastcall ResetConnection();
  void __fastcall ResetSessionInfo();
  void __fastcall SocketEventSelect(SOCKET Socket, HANDLE Event, bool Startup);
  bool __fastcall EnumNetworkEvents(SOCKET Socket, WSANETWORKEVENTS & Events);
  void __fastcall HandleNetworkEvents(SOCKET Socket, WSANETWORKEVENTS & Events);
  bool __fastcall ProcessNetworkEvents(SOCKET Socket);
  bool __fastcall EventSelectLoop(unsigned int MSec, bool ReadEventRequired,
    WSANETWORKEVENTS * Events);
  void __fastcall UpdateSessionInfo();
  void __fastcall DispatchSendBuffer(int BufSize);
  void /* __fastcall */ SendBuffer(unsigned int & Result);
  unsigned int __fastcall TimeoutPrompt(TQueryParamsTimerEvent PoolEvent);

protected:
  TCaptureOutputEvent FOnCaptureOutput;

  void __fastcall GotHostKey();
  int __fastcall TranslatePuttyMessage(const TPuttyTranslation * Translation,
    size_t Count, UnicodeString & Message) const;
  int __fastcall TranslateAuthenticationMessage(UnicodeString & Message) const;
  int __fastcall TranslateErrorMessage(UnicodeString & Message) const;
  void __fastcall AddStdError(const UnicodeString & Str);
  void __fastcall AddStdErrorLine(const UnicodeString & Str);
  void __fastcall FatalError(Exception * E, const UnicodeString & Msg);
  void __fastcall /* inline */ LogEvent(const UnicodeString & Str);
  void __fastcall FatalError(const UnicodeString & Error);
  static void __fastcall ClearConfig(Config * cfg);
  static void __fastcall StoreToConfig(TSessionData * Data, Config * cfg, bool Simple);

public:
  explicit /* __fastcall */ TSecureShell(TSessionUI * UI, TSessionData * SessionData,
    TSessionLog * Log, TConfiguration * Configuration);
  virtual /* __fastcall */ ~TSecureShell();
  void __fastcall Open();
  void __fastcall Close();
  void __fastcall KeepAlive();
  int __fastcall Receive(unsigned char * Buf, int Len);
  bool __fastcall Peek(unsigned char *& Buf, int Len) const;
  UnicodeString __fastcall ReceiveLine();
  void __fastcall Send(const unsigned char * Buf, int Len);
  void __fastcall SendStr(const UnicodeString & Str);
  void __fastcall SendSpecial(int Code);
  void __fastcall Idle(unsigned int MSec = 0);
  void __fastcall SendEOF();
  void __fastcall SendLine(const UnicodeString & Line);
  void __fastcall SendNull();

  const TSessionInfo & __fastcall GetSessionInfo();
  bool __fastcall SshFallbackCmd() const;
  unsigned long __fastcall MinPacketSize();
  unsigned long __fastcall MaxPacketSize();
  void __fastcall ClearStdError();
  bool __fastcall GetStoredCredentialsTried() const;

  void __fastcall RegisterReceiveHandler(TNotifyEvent Handler);
  void __fastcall UnregisterReceiveHandler(TNotifyEvent Handler);

  // interface to PuTTY core
  void __fastcall UpdateSocket(SOCKET value, bool Startup);
  void __fastcall UpdatePortFwdSocket(SOCKET value, bool Startup);
  void __fastcall PuttyFatalError(const UnicodeString & Error);
  bool __fastcall PromptUser(bool ToServer,
    const UnicodeString & AName, bool NameRequired,
    const UnicodeString & Instructions, bool InstructionsRequired,
    TStrings * Prompts, TStrings * Results);
  void __fastcall FromBackend(bool IsStdErr, const unsigned char * Data, int Length);
  void __fastcall CWrite(const char * Data, int Length);
  const UnicodeString & __fastcall GetStdError() const;
  void __fastcall VerifyHostKey(const UnicodeString & Host, int Port,
    const UnicodeString & KeyType, const UnicodeString & KeyStr, const UnicodeString & Fingerprint);
  void __fastcall AskAlg(const UnicodeString & AlgType, const UnicodeString & AlgName);
  void __fastcall DisplayBanner(const UnicodeString & Banner);
  void __fastcall OldKeyfileWarning();
  void __fastcall PuttyLogEvent(const UnicodeString & Str);

  bool __fastcall GetReady() const;
  bool __fastcall GetActive() const { return FActive; }
  TCaptureOutputEvent & __fastcall GetOnCaptureOutput() { return FOnCaptureOutput; }
  void __fastcall SetOnCaptureOutput(TCaptureOutputEvent value) { FOnCaptureOutput = value; }
  TDateTime __fastcall GetLastDataSent() const { return FLastDataSent; }
  UnicodeString __fastcall GetLastTunnelError() const { return FLastTunnelError; }
  UnicodeString __fastcall GetUserName() const { return FUserName; }
  bool __fastcall GetSimple() const { return FSimple; }
  void __fastcall SetSimple(bool value) { FSimple = value; }
private:
  TSecureShell(const TSecureShell &);
  TSecureShell & operator=(const TSecureShell &);
};
//---------------------------------------------------------------------------
#endif

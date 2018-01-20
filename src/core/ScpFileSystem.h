
#pragma once

#include <FileSystems.h>
#include <CopyParam.h>

class TCommandSet;
class TSecureShell;

class TSCPFileSystem : public TCustomFileSystem
{
  NB_DISABLE_COPY(TSCPFileSystem)
public:
  static inline bool classof(const TObject *Obj) { return Obj->is(OBJECT_CLASS_TSCPFileSystem); }
  virtual bool is(TObjectClassId Kind) const override { return (Kind == OBJECT_CLASS_TSCPFileSystem) || TCustomFileSystem::is(Kind); }
public:
  explicit TSCPFileSystem(TTerminal *ATerminal);
  virtual ~TSCPFileSystem();

  virtual void Init(void * /*TSecureShell * */) override;
  virtual void FileTransferProgress(int64_t /*TransferSize*/, int64_t /*Bytes*/) override {}

  virtual void Open() override;
  virtual void Close() override;
  virtual bool GetActive() const override;
  virtual void CollectUsage() override;
  virtual void Idle() override;
  virtual UnicodeString GetAbsolutePath(UnicodeString APath, bool Local) override;
  virtual UnicodeString GetAbsolutePath(UnicodeString APath, bool Local) const override;
  virtual void AnyCommand(UnicodeString Command,
    TCaptureOutputEvent OutputEvent) override;
  virtual void ChangeDirectory(UnicodeString Directory) override;
  virtual void CachedChangeDirectory(UnicodeString Directory) override;
  virtual void AnnounceFileListOperation() override;
  virtual void ChangeFileProperties(UnicodeString AFileName,
    const TRemoteFile *AFile, const TRemoteProperties *Properties,
    TChmodSessionAction &Action) override;
  virtual bool LoadFilesProperties(TStrings *AFileList) override;
  virtual void CalculateFilesChecksum(const UnicodeString Alg,
    TStrings *AFileList, TStrings *Checksums,
    TCalculatedChecksumEvent OnCalculatedChecksum) override;
  virtual void CopyToLocal(const TStrings *AFilesToCopy,
    UnicodeString TargetDir, const TCopyParamType *CopyParam,
    intptr_t Params, TFileOperationProgressType *OperationProgress,
    TOnceDoneOperation &OnceDoneOperation) override;
  virtual void __fastcall Source(
    TLocalFileHandle &AHandle, const UnicodeString ATargetDir, UnicodeString &ADestFileName,
    const TCopyParamType *CopyParam, intptr_t AParams,
    TFileOperationProgressType *OperationProgress, uintptr_t AFlags,
    TUploadSessionAction &Action, bool &ChildError);
  virtual void __fastcall Sink(
    const UnicodeString &AFileName, const TRemoteFile *AFile,
    const UnicodeString &ATargetDir, UnicodeString &ADestFileName, intptr_t Attrs,
    const TCopyParamType * CopyParam, intptr_t AParams, TFileOperationProgressType *OperationProgress,
    uintptr_t AFlags, TDownloadSessionAction &Action);
  virtual void DoStartup() override;
  virtual void HomeDirectory() override;
  virtual bool IsCapable(intptr_t Capability) const override;
  virtual void LookupUsersGroups() override;
  virtual void ReadCurrentDirectory() override;
  virtual void ReadDirectory(TRemoteFileList *FileList) override;
  virtual void ReadFile(UnicodeString AFileName,
    TRemoteFile *&File) override;
  virtual void __fastcall ReadSymlink(TRemoteFile *ASymlinkFile,
    TRemoteFile *&AFile) override;
  virtual void __fastcall RemoteRenameFile(const UnicodeString AFileName, const TRemoteFile *AFile,
    const UnicodeString ANewName) override;
  virtual void __fastcall RemoteCopyFile(const UnicodeString AFileName, const TRemoteFile *AFile,
    const UnicodeString ANewName) override;
  virtual TStrings * __fastcall GetFixedPaths() const override;
  virtual void __fastcall SpaceAvailable(const UnicodeString APath,
    TSpaceAvailable &ASpaceAvailable) override;
  virtual const TSessionInfo & __fastcall GetSessionInfo() const override;
  virtual const TFileSystemInfo & __fastcall GetFileSystemInfo(bool Retrieve);
  virtual bool __fastcall TemporaryTransferFile(const UnicodeString AFileName) override;
  virtual bool __fastcall GetStoredCredentialsTried() const override;
  virtual UnicodeString __fastcall RemoteGetUserName() const override;
  virtual void __fastcall GetSupportedChecksumAlgs(TStrings *Algs) override;
  virtual void __fastcall LockFile(const UnicodeString AFileName, const TRemoteFile *AFile) override;
  virtual void __fastcall UnlockFile(const UnicodeString AFileName, const TRemoteFile *AFile) override;
  virtual void __fastcall UpdateFromMain(TCustomFileSystem *MainFileSystem) override;
  virtual void __fastcall ClearCaches();

protected:
  __property TStrings * Output = { read = FOutput };
  __property int ReturnCode = { read = FReturnCode };
  TStrings *GetOutput() const { return FOutput; }
  intptr_t GetReturnCode() const { return FReturnCode; }

  virtual UnicodeString __fastcall RemoteGetCurrentDirectory() const override;

private:
  TSecureShell *FSecureShell;
  TCommandSet *FCommandSet;
  TFileSystemInfo FFileSystemInfo;
  UnicodeString FCurrentDirectory;
  TStrings *FOutput;
  intptr_t FReturnCode;
  UnicodeString FCachedDirectoryChange;
  bool FProcessingCommand;
  int FLsFullTime;
  TCaptureOutputEvent FOnCaptureOutput;
  bool FScpFatalError;

  void DetectUtf();
  void ClearAliases();
  void ClearAlias(UnicodeString Alias);
  void CustomReadFile(const UnicodeString AFileName,
    TRemoteFile *&AFile, TRemoteFile *ALinkedByFile);
  static UnicodeString DelimitStr(UnicodeString AStr);
  void DetectReturnVar();
  bool IsLastLine(UnicodeString &Line);
  static bool IsTotalListingLine(const UnicodeString Line);
  void EnsureLocation();
  void ExecCommand(const UnicodeString Cmd, intptr_t Params,
    const UnicodeString CmdString);
  void ExecCommand(TFSCommand Cmd, intptr_t Params, fmt::ArgList args);
  FMT_VARIADIC_W(void, ExecCommand, TFSCommand, intptr_t)

//  void ExecCommand(TFSCommand Cmd, const TVarRec *args = nullptr,
//    int size = 0, int Params = -1);
  void ReadCommandOutput(intptr_t Params, const UnicodeString *Cmd = nullptr);
  void SCPResponse(bool *GotLastLine = nullptr);
  void SCPDirectorySource(UnicodeString DirectoryName,
    UnicodeString TargetDir, const TCopyParamType *CopyParam, intptr_t Params,
    TFileOperationProgressType *OperationProgress, intptr_t Level);
  void SCPError(const UnicodeString Message, bool Fatal);
  void SCPSendError(const UnicodeString Message, bool Fatal);
  void SCPSink(const UnicodeString ATargetDir,
    const UnicodeString AFileName, const UnicodeString ASourceDir,
    const TRemoteFile *AFile,
    const TCopyParamType *CopyParam, bool &Success,
    TFileOperationProgressType *OperationProgress, intptr_t Params, intptr_t Level);
  void SCPSource(const UnicodeString AFileName,
    const TRemoteFile *AFile,
    const UnicodeString TargetDir, const TCopyParamType *CopyParam, intptr_t Params,
    TFileOperationProgressType *OperationProgress, intptr_t Level);
  void SendCommand(const UnicodeString Cmd);
  void SkipFirstLine();
  void SkipStartupMessage();
  void UnsetNationalVars();
  TRemoteFile *CreateRemoteFile(const UnicodeString ListingStr,
    TRemoteFile *LinkedByFile = nullptr);
  void CaptureOutput(const UnicodeString AddedLine, TCaptureOutputType OutputType);
  void ChangeFileToken(const UnicodeString DelimitedName,
    const TRemoteToken &Token, TFSCommand Cmd, const UnicodeString RecursiveStr);
  uintptr_t ConfirmOverwrite(
    const UnicodeString ASourceFullFileName, const UnicodeString ATargetFileName,
    TOperationSide Side,
    const TOverwriteFileParams *FileParams, const TCopyParamType *CopyParam,
    intptr_t Params, TFileOperationProgressType *OperationProgress);

  static bool RemoveLastLine(UnicodeString &Line,
    intptr_t &ReturnCode, UnicodeString ALastLine = L"");
  UnicodeString InitOptionsStr(const TCopyParamType *CopyParam) const;
};
//---------------------------------------------------------------------------

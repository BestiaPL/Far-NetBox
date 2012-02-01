//---------------------------------------------------------------------------
#ifndef SecureShellH
#define SecureShellH

#include <set>
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
    TSessionUI *FUI;
    TSessionData *FSessionData;
    bool FActive;
    TSessionInfo FSessionInfo;
    bool FSessionInfoValid;
    nb::TDateTime FLastDataSent;
    Backend *FBackend;
    void *FBackendHandle;
    const unsigned int *FMinPacketSize;
    const unsigned int *FMaxPacketSize;
    Config *FConfig;
    nb::notify_signal_type FOnReceive;
    bool FFrozen;
    bool FDataWhileFrozen;
    bool FStoredPasswordTried;
    bool FStoredPasswordTriedForKI;
    int FSshVersion;
    bool FOpened;
    int FWaiting;
    bool FSimple;

    size_t PendLen;
    size_t PendSize;
    size_t OutLen;
    char *OutPtr;
    char *Pending;
    TSessionLog *FLog;
    TConfiguration *FConfiguration;
    bool FAuthenticating;
    bool FAuthenticated;
    std::wstring FStdErrorTemp;
    std::wstring FStdError;
    std::wstring FCWriteTemp;
    std::wstring FAuthenticationLog;
    std::wstring FLastTunnelError;
    std::wstring FUserName;
    TSecureShell *Self;

    static TCipher FuncToSsh1Cipher(const void *Cipher);
    static TCipher FuncToSsh2Cipher(const void *Cipher);
    std::wstring FuncToCompression(int SshVersion, const void *Compress) const;
    void Init();
    void inline CheckConnection(int Message = -1);
    void WaitForData();
    void Discard();
    void FreeBackend();
    void PoolForData(WSANETWORKEVENTS &Events, size_t &Result);
    inline void CaptureOutput(TLogLineType Type,
                              const std::wstring Line);
    void ResetConnection();
    void ResetSessionInfo();
    void SocketEventSelect(SOCKET Socket, HANDLE Event, bool Startup);
    bool EnumNetworkEvents(SOCKET Socket, WSANETWORKEVENTS &Events);
    void HandleNetworkEvents(SOCKET Socket, WSANETWORKEVENTS &Events);
    bool ProcessNetworkEvents(SOCKET Socket);
    bool EventSelectLoop(unsigned int MSec, bool ReadEventRequired,
                         WSANETWORKEVENTS *Events);
    void UpdateSessionInfo();
    void DispatchSendBuffer(size_t BufSize);
    void SendBuffer(size_t &Result);
    int TimeoutPrompt(queryparamstimer_slot_type *PoolEvent);

protected:
    captureoutput_signal_type FOnCaptureOutput;

    void GotHostKey();
    int TranslatePuttyMessage(const TPuttyTranslation *Translation,
                              size_t Count, std::wstring &Message);
    int TranslateAuthenticationMessage(std::wstring &Message);
    int TranslateErrorMessage(std::wstring &Message);
    void AddStdError(const std::wstring Str);
    void AddStdErrorLine(const std::wstring Str);
    void FatalError(const std::exception *E, const std::wstring Msg);
    void inline LogEvent(const std::wstring Str);
    void FatalError(const std::wstring Error);
    static void ClearConfig(Config *cfg);
    static void StoreToConfig(TSessionData *Data, Config *cfg, bool Simple);

public:
    explicit TSecureShell(TSessionUI *UI, TSessionData *SessionData,
                 TSessionLog *Log, TConfiguration *Configuration);
    virtual ~TSecureShell();
    void Open();
    void Close();
    void KeepAlive();
    size_t Receive(char *Buf, size_t Len);
    bool Peek(char *& Buf, size_t Len);
    std::wstring ReceiveLine();
    void Send(const char *Buf, size_t Len);
    void SendStr(const std::wstring Str, bool Utf = false);
    void SendSpecial(int Code);
    void Idle(unsigned int MSec = 0);
    void SendEOF();
    void SendLine(const std::wstring Line, bool Utf = false);
    void SendNull();

    const TSessionInfo &GetSessionInfo();
    bool SshFallbackCmd() const;
    unsigned long MinPacketSize();
    unsigned long MaxPacketSize();
    void ClearStdError();
    bool GetStoredCredentialsTried();

    void RegisterReceiveHandler(const nb::notify_slot_type &Handler);
    void UnregisterReceiveHandler(const nb::notify_slot_type &Handler);

    // interface to PuTTY core
    void UpdateSocket(SOCKET value, bool Startup);
    void UpdatePortFwdSocket(SOCKET value, bool Startup);
    void PuttyFatalError(const std::wstring Error);
    bool PromptUser(bool ToServer,
                    const std::wstring AName, bool NameRequired,
                    const std::wstring Instructions, bool InstructionsRequired,
                    nb::TStrings *Prompts, nb::TStrings *Results);
    void FromBackend(bool IsStdErr, const char *Data, size_t Length);
    void CWrite(const char *Data, size_t Length);
    const std::wstring GetStdError();
    void VerifyHostKey(const std::wstring Host, int Port,
                       const std::wstring KeyType, const std::wstring KeyStr, const std::wstring Fingerprint);
    void AskAlg(const std::wstring AlgType, const std::wstring AlgName);
    void DisplayBanner(const std::wstring Banner);
    void OldKeyfileWarning();
    void PuttyLogEvent(const std::wstring Str);

    // __property bool Active = { read = FActive, write = SetActive };
    bool GetActive() { return FActive; }
    void SetActive(bool value);
    // __property bool Ready = { read = GetReady };
    bool GetReady();
    // __property TCaptureOutputEvent OnCaptureOutput = { read = FOnCaptureOutput, write = FOnCaptureOutput };
    captureoutput_signal_type &GetOnCaptureOutput() { return FOnCaptureOutput; }
    void SetOnCaptureOutput(const captureoutput_slot_type &value) { FOnCaptureOutput.connect(value); }
    // __property nb::TDateTime LastDataSent = { read = FLastDataSent };
    nb::TDateTime GetLastDataSent() { return FLastDataSent; }
    // __property std::wstring LastTunnelError = { read = FLastTunnelError };
    std::wstring GetLastTunnelError() { return FLastTunnelError; }
    // __property std::wstring UserName = { read = FUserName };
    std::wstring GetUserName() { return FUserName; }
    // __property bool Simple = { read = FSimple, write = FSimple };
    bool GetSimple() { return FSimple; }
    void SetSimple(bool value) { FSimple = value; }
private:
    TSecureShell(const TSecureShell &);
    void operator=(const TSecureShell &);
};
//---------------------------------------------------------------------------
#endif

#include "jk.h"

#include "types.h"

#ifdef LINUX
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <wchar.h>
#endif

// Imports
#ifdef WIN32
LSTATUS (__stdcall *jk_RegSetValueExA)(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData);
LSTATUS (__stdcall *jk_RegDeleteKeyA)(HKEY hKey, LPCSTR lpSubKey);
LSTATUS (__stdcall *jk_RegQueryValueExA)(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS (__stdcall *jk_RegOpenKeyExA)(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS (__stdcall *jk_RegCloseKey)(HKEY hKey);
LSTATUS (__stdcall *jk_RegCreateKeyExA)(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);

void (__stdcall *jk_InitCommonControls)();

HRESULT (__stdcall *jk_DirectDrawEnumerateA)(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext);
HRESULT (__stdcall *jk_DirectDrawCreate)(GUID *lpGUID, LPDIRECTDRAW *lplpDD, IUnknown *pUnkOuter);

HRESULT (__stdcall *jk_DirectInputCreateA)(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA *ppDI, LPUNKNOWN punkOuter);

HRESULT (__stdcall *jk_DirectPlayLobbyCreateA)(LPGUID, LPDIRECTPLAYLOBBYA *, IUnknown *, LPVOID, DWORD);

HRESULT (__stdcall *jk_DirectSoundCreate)(LPGUID, LPDIRECTSOUND *, LPUNKNOWN);

BOOL (__stdcall *jk_DeleteDC)(HDC hdc);
UINT (__stdcall *jk_GetSystemPaletteEntries)(HDC hdc, UINT iStart, UINT cEntries, LPPALETTEENTRY pPalEntries);
int (__stdcall *jk_GetDeviceCaps)(HDC hdc, int index);
BOOL (__stdcall *jk_DeleteObject)(HGDIOBJ ho);
HFONT (__stdcall *jk_CreateFontA)(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
BOOL (__stdcall *jk_BitBlt)(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop);
BOOL (__stdcall *jk_GdiFlush)();
HGDIOBJ (__stdcall *jk_SelectObject)(HDC hdc, HGDIOBJ h);
HDC (__stdcall *jk_CreateCompatibleDC)(HDC hdc);
BOOL (__stdcall *jk_TextOutA)(HDC hdc, int x, int y, LPCSTR lpString, int c);
COLORREF (__stdcall *jk_SetTextColor)(HDC hdc, COLORREF color);
int (__stdcall *jk_SetBkMode)(HDC hdc, int mode);
HBITMAP (__stdcall *jk_CreateDIBSection)(HDC hdc, const BITMAPINFO *lpbmi, UINT usage, void **ppvBits, HANDLE hSection, DWORD offset);
UINT (__stdcall *jk_RealizePalette)(HDC hdc);
BOOL (__stdcall *jk_AnimatePalette)(HPALETTE hPal, UINT iStartIndex, UINT cEntries, const PALETTEENTRY *ppe);
HPALETTE (__stdcall *jk_SelectPalette)(HDC hdc, HPALETTE hPal, BOOL bForceBkgd);
HPALETTE (__stdcall *jk_CreatePalette)(const LOGPALETTE *plpal);
UINT (__stdcall *jk_SetDIBColorTable)(HDC hdc, UINT iStart, UINT cEntries, const RGBQUAD *prgbq);
BOOL (__stdcall *jk_GetTextExtentPoint32A)(HDC hdc, LPCSTR lpString, int c, LPSIZE psizl);
HGDIOBJ (__stdcall *jk_GetStockObject)(int i);

BOOL (__stdcall *jk_CloseHandle)(HANDLE hObject);
BOOL (__stdcall *jk_UnmapViewOfFile)(LPCVOID lpBaseAddress);
BOOL (__stdcall *jk_FindNextFileA)(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL (__stdcall *jk_DeleteFileA)(LPCSTR lpFileName);
BOOL (__stdcall *jk_FindClose)(HANDLE hFindFile);
HANDLE (__stdcall *jk_CreateFileMappingA)(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName);
HANDLE (__stdcall *jk_CreateFileA)(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
BOOL (__stdcall *jk_RemoveDirectoryA)(LPCSTR lpPathName);
HANDLE (__stdcall *jk_FindFirstFileA)(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
BOOL (__stdcall *jk_CreateDirectoryA)(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
void (__stdcall *jk_GetLocalTime)(LPSYSTEMTIME lpSystemTime);
void (__stdcall *jk_OutputDebugStringA)(LPCSTR lpOutputString);
void (__stdcall *jk_DebugBreak)();
BOOL (__stdcall *jk_WriteConsoleA)(HANDLE hConsoleOutput, const void *lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
BOOL (__stdcall *jk_FlushConsoleInputBuffer)(HANDLE hConsoleInput);
BOOL (__stdcall *jk_SetConsoleCursorInfo)(HANDLE hConsoleOutput, const CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
BOOL (__stdcall *jk_GetConsoleScreenBufferInfo)(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo);
BOOL (__stdcall *jk_SetConsoleCursorPosition)(HANDLE hConsoleOutput, COORD dwCursorPosition);
BOOL (__stdcall *jk_FreeConsole)();
BOOL (__stdcall *jk_AllocConsole)();
BOOL (__stdcall *jk_SetConsoleTitleA)(LPCSTR lpConsoleTitle);
HANDLE (__stdcall *jk_GetStdHandle)(DWORD nStdHandle);
BOOL (__stdcall *jk_SetConsoleTextAttribute)(HANDLE hConsoleOutput, WORD wAttributes);
HLOCAL (__stdcall *jk_LocalAlloc)(UINT uFlags, SIZE_T uBytes);
LPVOID (__stdcall *jk_MapViewOfFile)(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap);
UINT (__stdcall *jk_WinExec)(LPCSTR lpCmdLine, UINT uCmdShow);
BOOL (__stdcall *jk_SetStdHandle)(DWORD nStdHandle, HANDLE hHandle);
DWORD (__stdcall *jk_SetFilePointer)(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
void (__stdcall *jk_RaiseException)(DWORD dwExceptionCode, DWORD dwExceptionFlags, DWORD nNumberOfArguments, const ULONG_PTR *lpArguments);
HANDLE (__stdcall *jk_HeapCreate)(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
BOOL (__stdcall *jk_SetEndOfFile)(HANDLE hFile);
int (__stdcall *jk_LCMapStringW)(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest);
int (__stdcall *jk_LCMapStringA)(LCID Locale, DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest);
BOOL (__stdcall *jk_HeapDestroy)(HANDLE hHeap);
BOOL (__stdcall *jk_GetStringTypeW)(DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL (__stdcall *jk_GetStringTypeA)(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
int (__stdcall *jk_MultiByteToWideChar)(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
BOOL (__stdcall *jk_WriteFile)(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
BOOL (__stdcall *jk_FlushFileBuffers)(HANDLE hFile);
int (__stdcall *jk_WideCharToMultiByte)(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);
BOOL (__stdcall *jk_FileTimeToLocalFileTime)(const FILETIME *lpFileTime, LPFILETIME lpLocalFileTime);
BOOL (__stdcall *jk_FileTimeToSystemTime)(const FILETIME *lpFileTime, LPSYSTEMTIME lpSystemTime);
FARPROC (__stdcall *jk_GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
LPVOID (__stdcall *jk_HeapAlloc)(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
DWORD (__stdcall *jk_GetVersion)();
LPVOID (__stdcall *jk_HeapReAlloc)(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
void (__stdcall *jk_GetStartupInfoA)(LPSTARTUPINFOA lpStartupInfo);
HMODULE (__stdcall *jk_GetModuleHandleA)(LPCSTR lpModuleName);
LPSTR (__stdcall *jk_GetCommandLineA)();
BOOL (__stdcall *jk_HeapFree)(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
BOOL (__stdcall *jk_SetEnvironmentVariableA)(LPCSTR lpName, LPCSTR lpValue);
DWORD (__stdcall *jk_GetLastError)();
HANDLE (__stdcall *jk_GetCurrentProcess)();
BOOL (__stdcall *jk_TerminateProcess)(HANDLE hProcess, UINT uExitCode);
void (__stdcall *jk_ExitProcess)(UINT uExitCode);
BOOL (__stdcall *jk_VirtualFree)(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
LPVOID (__stdcall *jk_VirtualAlloc)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
LONG (__stdcall *jk_UnhandledExceptionFilter)(struct _EXCEPTION_POINTERS *ExceptionInfo);
DWORD (__stdcall *jk_GetModuleFileNameA)(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
BOOL (__stdcall *jk_FreeEnvironmentStringsA)(LPCH);
BOOL (__stdcall *jk_FillConsoleOutputCharacterA)(HANDLE hConsoleOutput, CHAR cCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten);
DWORD (__stdcall *jk_GetTimeZoneInformation)(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
LPWCH (__stdcall *jk_GetEnvironmentStringsW)();
BOOL (__stdcall *jk_GetCPInfo)(UINT CodePage, LPCPINFO lpCPInfo);
LPCH (__stdcall *jk_GetEnvironmentStrings)();
UINT (__stdcall *jk_GetACP)();
UINT (__stdcall *jk_SetHandleCount)(UINT uNumber);
DWORD (__stdcall *jk_GetFileType)(HANDLE hFile);
void (__stdcall *jk_RtlUnwind)(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue);
int (__stdcall *jk_CompareStringW)(LCID Locale, DWORD dwCmpFlags, PCNZWCH lpString1, int cchCount1, PCNZWCH lpString2, int cchCount2);
int (__stdcall *jk_CompareStringA)(LCID Locale, DWORD dwCmpFlags, PCNZCH lpString1, int cchCount1, PCNZCH lpString2, int cchCount2);
BOOL (__stdcall *jk_FreeEnvironmentStringsW)(LPWCH);
BOOL (__stdcall *jk_ReadFile)(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
HMODULE (__stdcall *jk_LoadLibraryA)(LPCSTR lpLibFileName);
UINT (__stdcall *jk_GetOEMCP)();


BOOL (__stdcall *jk_PostMessageA)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL (__stdcall *jk_MessageBeep)(UINT uType);
LRESULT (__stdcall *jk_DispatchMessageA)(const MSG *lpMsg);
int (__stdcall *jk_ReleaseDC)(HWND hWnd, HDC hDC);
HDC (__stdcall *jk_GetDC)(HWND hWnd);
HWND (__stdcall *jk_GetDesktopWindow)();
int (__stdcall *jk_ShowCursor)(BOOL bShow);
BOOL (__stdcall *jk_ValidateRect)(HWND hWnd, const RECT *lpRect);
int (__stdcall *jk_GetSystemMetrics)(int nIndex);
HCURSOR (__stdcall *jk_SetCursor)(HCURSOR hCursor);
HWND (__stdcall *jk_SetActiveWindow)(HWND hWnd);
HWND (__stdcall *jk_SetFocus)(HWND hWnd);
int (__stdcall *jk_MessageBoxW)(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
HWND (__stdcall *jk_CreateDialogParamA)(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
HWND (__stdcall *jk_GetDlgItem)(HWND hDlg, int nIDDlgItem);
BOOL (__stdcall *jk_SetDlgItemTextA)(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
UINT (__stdcall *jk_GetDlgItemTextA)(HWND hDlg, int nIDDlgItem, LPSTR lpString, int cchMax);
HWND (__stdcall *jk_GetFocus)();
BOOL (__stdcall *jk_ShowWindow)(HWND hWnd, int nCmdShow);
HWND (__stdcall *jk_FindWindowA)(LPCSTR lpClassName, LPCSTR lpWindowName);
BOOL (__stdcall *jk_InvalidateRect)(HWND hWnd, const RECT *lpRect, BOOL bErase);
int (__stdcall *jk_MessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
BOOL (__stdcall *jk_EndPaint)(HWND hWnd, const PAINTSTRUCT *lpPaint);
BOOL (__stdcall *jk_GetUpdateRect)(HWND hWnd, LPRECT lpRect, BOOL bErase);
HDC (__stdcall *jk_BeginPaint)(HWND hWnd, LPPAINTSTRUCT lpPaint);
DWORD (__stdcall *jk_GetWindowThreadProcessId)(HWND hWnd, LPDWORD lpdwProcessId);
BOOL (__stdcall *jk_GetCursorPos)(LPPOINT lpPoint);
void (__stdcall *jk_PostQuitMessage)(int nExitCode);
BOOL (__stdcall *jk_SetWindowPos)(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
LRESULT (__stdcall *jk_DefWindowProcA)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LONG (__stdcall *jk_SetWindowLongA)(HWND hWnd, int nIndex, LONG dwNewLong);
ATOM (__stdcall *jk_RegisterClassExA)(const WNDCLASSEXA *);
HICON (__stdcall *jk_LoadIconA)(HINSTANCE hInstance, LPCSTR lpIconName);
HCURSOR (__stdcall *jk_LoadCursorA)(HINSTANCE hInstance, LPCSTR lpCursorName);
BOOL (__stdcall *jk_IsDialogMessageA)(HWND hDlg, LPMSG lpMsg);
HWND (__stdcall *jk_CreateWindowExA)(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL (__stdcall *jk_UpdateWindow)(HWND hWnd);
BOOL (__stdcall *jk_TranslateMessage)(const MSG *lpMsg);
BOOL (__stdcall *jk_PeekMessageA)(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL (__stdcall *jk_GetMessageA)(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
LRESULT (__stdcall *jk_SendMessageA)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


MMRESULT (__stdcall *jk_auxGetVolume)(UINT uDeviceID, LPDWORD pdwVolume);
MMRESULT (__stdcall *jk_auxSetVolume)(UINT uDeviceID, DWORD dwVolume);
MCIERROR (__stdcall *jk_mciSendCommandA)(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
UINT (__stdcall *jk_auxGetNumDevs)();
MMRESULT (__stdcall *jk_auxGetDevCapsA)(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac);
MMRESULT (__stdcall *jk_joyGetPosEx)(UINT uJoyID, LPJOYINFOEX pji);
UINT (__stdcall *jk_joyGetNumDevs)();
MMRESULT (__stdcall *jk_joyGetPos)(UINT uJoyID, LPJOYINFO pji);
DWORD (__stdcall *jk_timeGetTime)();
MMRESULT (__stdcall *jk_joyGetDevCapsA)(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc);

HRESULT (__stdcall *jk_CoInitialize)(LPVOID pvReserved);
HRESULT (__stdcall *jk_CoCreateInstance)(const IID *const rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID *const riid, LPVOID *ppv);

LONG (__stdcall *jk_ChangeDisplaySettingsA)(DEVMODEA *lpDevMode, DWORD dwFlags);
BOOL (__stdcall *jk_EnumDisplaySettingsA)(LPCSTR lpszDeviceName, DWORD iModeNum, DEVMODEA *lpDevMode);

int (__stdcall *jk_snwprintf)(wchar_t *a1, size_t a2, const wchar_t *a3, ...);

// JK functions
void (*jk_exit)(int a) = (void*)0x512590;
int (*jk_printf)(const char* fmt, ...) = (void*)0x426E60;
int (*jk_assert)(void* log_func, char* file, int line_num, char *fmt, ...) = (void*)0x426D80;
#endif

int _memcmp (const void* str1, const void* str2, size_t count)
{
  register const unsigned char *s1 = (const unsigned char*)str1;
  register const unsigned char *s2 = (const unsigned char*)str2;

  while (count-- > 0)
    {
      if (*s1++ != *s2++)
	  return s1[-1] < s2[-1] ? -1 : 1;
    }
  return 0;
}

int _strlen(const char *str)
{
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

char* _strcpy(char *dst, const char *src)
{
    if (!dst) return NULL;
    if (!src) return NULL;

    char *tmp = dst;
    while(*dst++ = *src++);
    return tmp;
}

char* _strcat(char* str, const char* concat)
{
    _strcpy(str+_strlen(str), concat);
    return str;
}

void* _memset(void* ptr, int val, size_t num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        *(uint8_t*)(ptr+i) = val;
    }
    return ptr;
}

void* memset(void* ptr, int val, size_t num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        *(uint8_t*)(ptr+i) = val;
    }
    return ptr;
}

void* _memset32(void* ptr, uint32_t val, size_t num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        *(uint32_t*)(ptr+(i*sizeof(uint32_t))) = val;
    }
    return ptr;
}

int _strcmp(const char* s1, const char* s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int _strncmp(const char *s1, const char *s2, size_t n)
{
  unsigned char u1, u2;
  while (n-- > 0)
    {
      u1 = (unsigned char) *s1++;
      u2 = (unsigned char) *s2++;
      if (u1 != u2)
        return u1 - u2;
      if (u1 == '\0')
        return 0;
    }
  return 0;
}


float _frand()
{
    return (float)_rand() * 0.000030518509;
}

// JK globals
VM_VAR(g_hWnd, HWND, 0x855DE0);

VM_VAR(g_nShowCmd, uint32_t, 0x855DE8);

VM_VAR(g_app_suspended, uint32_t, 0x855E70);
VM_VAR(g_window_active, uint32_t, 0x855E74);
VM_VAR(g_app_active, uint32_t, 0x855E78);
VM_VAR(g_should_exit, uint32_t, 0x855E7C);
VM_VAR(g_thing_two_some_dialog_count, uint32_t, 0x855E80);
VM_VAR(g_handler_count, uint32_t, 0x855E84);

VM_VAR(g_855E8C, uint32_t, 0x855E8C);
VM_VAR(g_855E90, uint32_t, 0x855E90);
VM_VAR(g_window_not_destroyed, uint32_t, 0x855E94);

VM_VAR(g_cog_symboltable_hashmap, void*, 0x8B5428);

void jk_init()
{
#ifdef WIN32
    jk_RegSetValueExA = *(void**)0x008F03D8;
    jk_RegDeleteKeyA = *(void**)0x008F03DC;
    jk_RegQueryValueExA = *(void**)0x008F03E0;
    jk_RegOpenKeyExA = *(void**)0x008F03E4;
    jk_RegCloseKey = *(void**)0x008F03E8;
    jk_RegCreateKeyExA = *(void**)0x008F03EC;

    jk_InitCommonControls = *(void**)0x008F03F4;

    jk_DirectDrawEnumerateA = *(void**)0x008F03FC;
    jk_DirectDrawCreate = *(void**)0x008F0400;

    jk_DirectInputCreateA = *(void**)0x008F0408;

    jk_DirectPlayLobbyCreateA = *(void**)0x008F0410;

    jk_DirectSoundCreate = *(void**)0x008F0418;

    jk_DeleteDC = *(void**)0x008F0420;
    jk_GetSystemPaletteEntries = *(void**)0x008F0424;
    jk_GetDeviceCaps = *(void**)0x008F0428;
    jk_DeleteObject = *(void**)0x008F042C;
    jk_CreateFontA = *(void**)0x008F0430;
    jk_BitBlt = *(void**)0x008F0434;
    jk_GdiFlush = *(void**)0x008F0438;
    jk_SelectObject = *(void**)0x008F043C;
    jk_CreateCompatibleDC = *(void**)0x008F0440;
    jk_TextOutA = *(void**)0x008F0444;
    jk_SetTextColor = *(void**)0x008F0448;
    jk_SetBkMode = *(void**)0x008F044C;
    jk_CreateDIBSection = *(void**)0x008F0450;
    jk_RealizePalette = *(void**)0x008F0454;
    jk_AnimatePalette = *(void**)0x008F0458;
    jk_SelectPalette = *(void**)0x008F045C;
    jk_CreatePalette = *(void**)0x008F0460;
    jk_SetDIBColorTable = *(void**)0x008F0464;
    jk_GetTextExtentPoint32A = *(void**)0x008F0468;
    jk_GetStockObject = *(void**)0x008F046C;

    jk_CloseHandle = *(void**)0x008F0474;
    jk_UnmapViewOfFile = *(void**)0x008F0478;
    jk_FindNextFileA = *(void**)0x008F047C;
    jk_DeleteFileA = *(void**)0x008F0480;
    jk_FindClose = *(void**)0x008F0484;
    jk_CreateFileMappingA = *(void**)0x008F0488;
    jk_CreateFileA = *(void**)0x008F048C;
    jk_RemoveDirectoryA = *(void**)0x008F0490;
    jk_FindFirstFileA = *(void**)0x008F0494;
    jk_CreateDirectoryA = *(void**)0x008F0498;
    jk_GetLocalTime = *(void**)0x008F049C;
    jk_OutputDebugStringA = *(void**)0x008F04A0;
    jk_DebugBreak = *(void**)0x008F04A4;
    jk_WriteConsoleA = *(void**)0x008F04A8;
    jk_FlushConsoleInputBuffer = *(void**)0x008F04AC;
    jk_SetConsoleCursorInfo = *(void**)0x008F04B0;
    jk_GetConsoleScreenBufferInfo = *(void**)0x008F04B4;
    jk_SetConsoleCursorPosition = *(void**)0x008F04B8;
    jk_FreeConsole = *(void**)0x008F04BC;
    jk_AllocConsole = *(void**)0x008F04C0;
    jk_SetConsoleTitleA = *(void**)0x008F04C4;
    jk_GetStdHandle = *(void**)0x008F04C8;
    jk_SetConsoleTextAttribute = *(void**)0x008F04CC;
    jk_LocalAlloc = *(void**)0x008F04D0;
    jk_MapViewOfFile = *(void**)0x008F04D4;
    jk_WinExec = *(void**)0x008F04D8;
    jk_SetStdHandle = *(void**)0x008F04DC;
    jk_SetFilePointer = *(void**)0x008F04E0;
    jk_RaiseException = *(void**)0x008F04E4;
    jk_HeapCreate = *(void**)0x008F04E8;
    jk_SetEndOfFile = *(void**)0x008F04EC;
    jk_LCMapStringW = *(void**)0x008F04F0;
    jk_LCMapStringA = *(void**)0x008F04F4;
    jk_HeapDestroy = *(void**)0x008F04F8;
    jk_GetStringTypeW = *(void**)0x008F04FC;
    jk_GetStringTypeA = *(void**)0x008F0500;
    jk_MultiByteToWideChar = *(void**)0x008F0504;
    jk_WriteFile = *(void**)0x008F0508;
    jk_FlushFileBuffers = *(void**)0x008F050C;
    jk_WideCharToMultiByte = *(void**)0x008F0510;
    jk_FileTimeToLocalFileTime = *(void**)0x008F0514;
    jk_FileTimeToSystemTime = *(void**)0x008F0518;
    jk_GetProcAddress = *(void**)0x008F051C;
    jk_HeapAlloc = *(void**)0x008F0520;
    jk_GetVersion = *(void**)0x008F0524;
    jk_HeapReAlloc = *(void**)0x008F0528;
    jk_GetStartupInfoA = *(void**)0x008F052C;
    jk_GetModuleHandleA = *(void**)0x008F0530;
    jk_GetCommandLineA = *(void**)0x008F0534;
    jk_HeapFree = *(void**)0x008F0538;
    jk_SetEnvironmentVariableA = *(void**)0x008F053C;
    jk_GetLastError = *(void**)0x008F0540;
    jk_GetCurrentProcess = *(void**)0x008F0544;
    jk_TerminateProcess = *(void**)0x008F0548;
    jk_ExitProcess = *(void**)0x008F054C;
    jk_VirtualFree = *(void**)0x008F0550;
    jk_VirtualAlloc = *(void**)0x008F0554;
    jk_UnhandledExceptionFilter = *(void**)0x008F0558;
    jk_GetModuleFileNameA = *(void**)0x008F055C;
    jk_FreeEnvironmentStringsA = *(void**)0x008F0560;
    jk_FillConsoleOutputCharacterA = *(void**)0x008F0564;
    jk_GetTimeZoneInformation = *(void**)0x008F0568;
    jk_GetEnvironmentStringsW = *(void**)0x008F056C;
    jk_GetCPInfo = *(void**)0x008F0570;
    jk_GetEnvironmentStrings = *(void**)0x008F0574;
    jk_GetACP = *(void**)0x008F0578;
    jk_SetHandleCount = *(void**)0x008F057C;
    jk_GetFileType = *(void**)0x008F0580;
    jk_RtlUnwind = *(void**)0x008F0584;
    jk_CompareStringW = *(void**)0x008F0588;
    jk_CompareStringA = *(void**)0x008F058C;
    jk_FreeEnvironmentStringsW = *(void**)0x008F0590;
    jk_ReadFile = *(void**)0x008F0594;
    jk_LoadLibraryA = *(void**)0x008F0598;
    jk_GetOEMCP = *(void**)0x008F059C;


    jk_PostMessageA = *(void**)0x008F05A4;
    jk_MessageBeep = *(void**)0x008F05A8;
    jk_DispatchMessageA = *(void**)0x008F05AC;
    jk_ReleaseDC = *(void**)0x008F05B0;
    jk_GetDC = *(void**)0x008F05B4;
    jk_GetDesktopWindow = *(void**)0x008F05B8;
    jk_ShowCursor = *(void**)0x008F05BC;
    jk_ValidateRect = *(void**)0x008F05C0;
    jk_GetSystemMetrics = *(void**)0x008F05C4;
    jk_SetCursor = *(void**)0x008F05C8;
    jk_SetActiveWindow = *(void**)0x008F05CC;
    jk_SetFocus = *(void**)0x008F05D0;
    jk_MessageBoxW = *(void**)0x008F05D4;
    jk_CreateDialogParamA = *(void**)0x008F05D8;
    jk_GetDlgItem = *(void**)0x008F05DC;
    jk_SetDlgItemTextA = *(void**)0x008F05E0;
    jk_GetDlgItemTextA = *(void**)0x008F05E4;
    jk_GetFocus = *(void**)0x008F05E8;
    jk_ShowWindow = *(void**)0x008F05EC;
    jk_FindWindowA = *(void**)0x008F05F0;
    jk_InvalidateRect = *(void**)0x008F05F4;
    jk_MessageBoxA = *(void**)0x008F05F8;
    jk_EndPaint = *(void**)0x008F05FC;
    jk_GetUpdateRect = *(void**)0x008F0600;
    jk_BeginPaint = *(void**)0x008F0604;
    jk_GetWindowThreadProcessId = *(void**)0x008F0608;
    jk_GetCursorPos = *(void**)0x008F060C;
    jk_PostQuitMessage = *(void**)0x008F0610;
    jk_SetWindowPos = *(void**)0x008F0614;
    jk_DefWindowProcA = *(void**)0x008F0618;
    jk_SetWindowLongA = *(void**)0x008F061C;
    jk_RegisterClassExA = *(void**)0x008F0620;
    jk_LoadIconA = *(void**)0x008F0624;
    jk_LoadCursorA = *(void**)0x008F0628;
    jk_IsDialogMessageA = *(void**)0x008F062C;
    jk_CreateWindowExA = *(void**)0x008F0630;
    jk_UpdateWindow = *(void**)0x008F0634;
    jk_TranslateMessage = *(void**)0x008F0638;
    jk_PeekMessageA = *(void**)0x008F063C;
    jk_GetMessageA = *(void**)0x008F0640;
    jk_SendMessageA = *(void**)0x008F0644;


    jk_auxGetVolume = *(void**)0x008F064C;
    jk_auxSetVolume = *(void**)0x008F0650;
    jk_mciSendCommandA = *(void**)0x008F0654;
    jk_auxGetNumDevs = *(void**)0x008F0658;
    jk_auxGetDevCapsA = *(void**)0x008F065C;
    jk_joyGetPosEx = *(void**)0x008F0660;
    jk_joyGetNumDevs = *(void**)0x008F0664;
    jk_joyGetPos = *(void**)0x008F0668;
    jk_timeGetTime = *(void**)0x008F066C;
    jk_joyGetDevCapsA = *(void**)0x008F0670;

    jk_CoInitialize = *(void**)0x008F0678;
    jk_CoCreateInstance = *(void**)0x008F067C;
    
    jk_ChangeDisplaySettingsA = *(void**)0x8F4153;
    jk_EnumDisplaySettingsA = *(void**)0x8F4157;
    
    jk_snwprintf = (void*)0x00512BD0;
#endif
}

#ifdef LINUX
#include <ctype.h>

int _sscanf(const char * s, const char * format, ...)
{
    va_list args;
    va_start (args, format);
    int ret = vsscanf (s, format, args);
    va_end (args);
    return ret;
}

int _sprintf(const char * s, const char * format, ...)
{
    va_list args;
    va_start (args, format);
    int ret = vsprintf (s, format, args);
    va_end (args);
    return ret;
}

int _rand()
{
    return rand();
}

char* _strncpy(char* dst, const char* src, size_t num)
{
    return strncpy(dst, src, num);
}

void* _memcpy(void* dst, const void* src, size_t len)
{
    return memcpy(dst, src, len);
}

double _atof(const char* str)
{
    return atof(str);
}

int _atoi(const char* str)
{
    return atoi(str);
}

size_t _fwrite(const void * a, size_t b, size_t c, FILE * d)
{
    return fwrite(a,b,c,d);
}

int _fputs(const char * a, FILE * b)
{
    return fputs(a, b);
}

void jk_exit(int a)
{
    exit(a);
}

int jk_printf(const char* fmt, ...)
{
    va_list args;
    va_start (args, fmt);
    int ret = vprintf(fmt, args);
    va_end (args);
    return ret;
}

int _printf(const char* fmt, ...)
{
    va_list args;
    va_start (args, fmt);
    int ret = vprintf(fmt, args);
    va_end (args);
    return ret;
}

int jk_assert(void* log_func, char* file, int line_num, char *fmt, ...)
{
    
}

void* _malloc(size_t a)
{
    return malloc(a);
}

void _free(void* a)
{
    free(a);
}

wchar_t* _wcsncpy(wchar_t *s1, const wchar_t *s2, size_t n)
{
    wchar_t *ret = s1;
    for ( ; n; n--) if (!(*s1++ = *s2++)) break;
    for ( ; n; n--) *s1++ = 0;
    return ret;
}

void _strtolower(char* str)
{
    for(int i = 0; str[i]; i++){
      str[i] = tolower(str[i]);
    }
}

void _qsort(void *a, size_t b, size_t c, int (__cdecl *d)(const void *, const void *))
{
    qsort(a,b,c,d);
}

char* _strchr(char * a, char b)
{
    return strchr(a,b);
}

char* _strrchr(char * a, char b)
{
    return strrchr(a,b);
}

char* _strtok(char * a, const char * b)
{
    return strtok(a,b);
}

char* _strncat(char* a, const char* b, size_t c)
{
    return strncat(a,b,c);
}

size_t _strspn(const char* a, const char* b)
{
    return strspn(a,b);
}

char* _strpbrk(const char* a, const char* b)
{
    return strpbrk(a,b);
}

size_t _wcslen(const wchar_t * str)
{
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

int jk_snwprintf(wchar_t *a1, size_t a2, const wchar_t *fmt, ...)
{
    va_list args;
    va_start (args, fmt);
    int ret = vswprintf(a1, fmt, args); // TODO ehh
    va_end (args);
    return ret;
}

wchar_t* _wcscpy(wchar_t * a, const wchar_t *b)
{
    return wcscpy(a,b);
}

int jk_MessageBeep(int a)
{
}

int __strcmpi(const char *a, const char *b)
{
    return strcmp(a,b); // TODO verify
}

int __strnicmp(const char *a, const char *b, size_t c)
{
    int ca, cb, n;

    n = 0;
    do 
    {
        if (n >= c) break;
        ca = (unsigned char) *a++;
        cb = (unsigned char) *b++;
        ca = tolower(toupper(ca));
        cb = tolower(toupper(cb));
        n++;
    }
    while (ca == cb && ca != '\0');

    return ca - cb;
}

char __tolower(char a)
{
    return tolower(a);
}

int msvc_sub_512D30(int a, int b)
{
    assert(0);
}

int jk_MessageBoxW()
{
    assert(0);
}

int stdGdi_GetHwnd()
{
    //assert(0);
    return 0;
}

void jk_PostMessageA()
{
    assert(0);
}

void jk_GetCursorPos()
{
    assert(0);
}

int jk_GetUpdateRect()
{
    return 0;
}

void jk_BeginPaint()
{
    assert(0);
}

int jk_vsnwprintf(wchar_t * a, size_t b, const wchar_t *fmt, va_list list)
{
    return vswprintf(a, fmt, list);
}

void jk_EndPaint()
{
    assert(0);
}

int stdGdi_GetHInstance()
{
    assert(0);
    return 0;
}

int jk_LoadCursorA()
{
    assert(0);
    return 1;
}

void jk_SetCursor()
{
    assert(0);
}

void jk_InvalidateRect()
{
    assert(0);
}

void jk_ChangeDisplaySettingsA()
{
    assert(0);
}

void stdConsole_Startup()
{
    assert(0);
}

uint32_t jk_DirectDrawEnumerateA()
{
    assert(0);
    return 0;
}

uint32_t jk_DirectDrawCreate()
{
    assert(0);
    return 0;
}

uint32_t jk_DirectSoundCreate()
{
    assert(0);
    return 0;
}

uint32_t jk_DirectPlayLobbyCreateA()
{
    assert(0);
    return 0;
}

uint32_t jk_DirectInputCreateA()
{
    assert(0);
    return 0;
}

uint32_t jk_CreateFileA()
{
    assert(0);
    return 0;
}

uint32_t jk_CreateFileMappingA()
{
    assert(0);
    return 0;
}

uint32_t jk_LocalAlloc()
{
    assert(0);
    return 0;
}

uint32_t jk_MapViewOfFile()
{
    assert(0);
    return 0;
}

void jk_UnmapViewOfFile()
{
    assert(0);
}

void jk_CloseHandle()
{
    assert(0);
}

uint32_t jk_GetDesktopWindow()
{
    assert(0);
    return 0;
}

uint32_t jk_GetDC()
{
    assert(0);
    return 0;
}

uint32_t jk_GetDeviceCaps()
{
    assert(0);
    return 0;
}

uint32_t jk_WinExec()
{
    assert(0);
    return 0;
}

int _string_modify_idk(int c)
{
    return toupper(c);
}

void jk_ReleaseDC()
{
    assert(0);
}

void jk_SetFocus()
{
    assert(0);
}

void jk_SetActiveWindow()
{
    assert(0);
}

void jk_ShowCursor()
{
    assert(0);
}

void jk_ValidateRect()
{
    assert(0);
}

int __isspace(int a)
{
    return isspace(a);
}

int _iswspace(int a)
{
    return isspace(a);
}

size_t __wcslen(wchar_t * strarg)
{
    if(!strarg)
     return -1; //strarg is NULL pointer
   wchar_t* str = strarg;
   for(;*str;++str)
     ; // empty body
   return str-strarg;
}

wchar_t* __wcscat(wchar_t * a, const wchar_t * b)
{
    wchar_t* ret = a;
    a += __wcslen(a);
    memcpy(a, b, __wcslen(b) * sizeof(wchar_t));
    return ret;
}

wchar_t* __wcschr(const wchar_t * s, wchar_t c)
{
    do {
        if (*s == c)
        {
        return (wchar_t*)s;
        }
    } while (*s++);
    return NULL;
}

wchar_t* __wcsncpy(wchar_t * a, const wchar_t * b, size_t c)
{
    wchar_t* ret = a;
    size_t len = __wcslen(b) * sizeof(wchar_t);
    if (len > c*2) {
        len = c*2;
    }
    memcpy(a, b, len);
    a[len] = 0;
    return &a[len];
}

wchar_t* __wcsrchr(const wchar_t * s, wchar_t c)
{
    wchar_t *rtnval = 0;
    do {
        if (*s == c)
            rtnval = (wchar_t*) s;
        } while (*s++);
    return (rtnval);
}
#else
int _iswspace(int a)
{
    return msvc_sub_512D30(a, 8);
}
#endif

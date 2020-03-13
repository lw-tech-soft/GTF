#ifndef GTF_H
#define GTF_H
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <direct.h>
#include <TLHelp32.h>
#include <io.h>

using namespace std;

//statu codes
#define SUCCESS 0
#define ERR_LOAD 1
#define BAD_INPUT 2

wstring MythwareRootPath = L"C:\\Program Files(x86)\\极域课堂管理系统软件V6.0 2016 豪华版\\";
wstring MythwareMainProgramName = L"StudentMain.exe";
wstring NtsdPath;
wstring AppPath;

bool WindowingRunning = false;
bool MinimizeRunning = false;

DWORD GetMythwarePID()
{
	PROCESSENTRY32 process;
	process.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE)
		return 0;
	bool stillprocess = Process32First(snapshot, &process);
	while (stillprocess)
	{
		if (process.szExeFile == MythwareMainProgramName)
			return process.th32ProcessID;
		stillprocess = Process32Next(snapshot, &process);
	}
	CloseHandle(snapshot);
}

bool GetAppPath()
{
	wchar_t* pathtmp = _wgetcwd(NULL, 0);
	if (pathtmp == NULL)
		return false;
	else
		AppPath = pathtmp;
	free(pathtmp);
	if (AppPath[AppPath.length() - 1] != L'\\' && AppPath[AppPath.length() - 1] != L'/')
		AppPath += L'\\';
	return true;
}

bool KillMythware()
{
	DWORD mpid = GetMythwarePID();
	if (!mpid)
		return false;
	_wsystem((NtsdPath + L" -c q -p " + to_wstring(mpid)).c_str());
	return true;
}

bool SetMythwareRootPath(const wstring& newRootPath)
{
	if (_waccess(newRootPath.c_str(), 0) == -1)
		return false;
	MythwareRootPath = newRootPath;
	if (MythwareRootPath[MythwareRootPath.length() - 1] != L'\\' && MythwareRootPath[MythwareRootPath.length() - 1] != L'/')
		MythwareRootPath += L'\\';
	return true;
}

bool SetMythwareMainProgramName(const wstring& newMainProgramName)
{
	if (_waccess((MythwareRootPath + newMainProgramName).c_str(), 0) == -1)
		return false;
	MythwareMainProgramName = newMainProgramName;
	return 0;
}

BOOL CALLBACK WindowingEnumProc(HWND hwnd, LPARAM lparam)
{
	DWORD winpid;
	GetWindowThreadProcessId(hwnd, &winpid);
	if (winpid == lparam)
	{
		wchar_t caption[200]{};
		GetWindowText(hwnd, caption, 200);
		if (wcscmp(caption, L"屏幕广播") == 0)
		{
			HWND ButDepend = GetDlgItem(hwnd, 0x0000E800);
			HWND Button = GetDlgItem(ButDepend, 0x000003EC);
			if (!IsWindowEnabled(Button))
				EnableWindow(Button, TRUE);
		}
	}
	return TRUE;
}

void Windowing()
{
	DWORD mpid = 0;
	while (WindowingRunning)
	{
		mpid = GetMythwarePID();
		if (!mpid) { this_thread::sleep_for(chrono::milliseconds(1)); continue; }
		EnumWindows(WindowingEnumProc, mpid);
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}


bool StartWindowing()
{
	if (WindowingRunning)
		return false;
	WindowingRunning = true;
	thread WindowingThread(Windowing);
	WindowingThread.detach();
	return true;
}

bool StopWindowing()
{
	if (!WindowingRunning)
		return false;
	WindowingRunning = false;
	return true;
}

BOOL CALLBACK MinimizeEnumProc(HWND hwnd, LPARAM lparam)
{
	DWORD winpid;
	GetWindowThreadProcessId(hwnd, &winpid);
	if (winpid == lparam)
	{
		wchar_t caption[200]{};
		GetWindowText(hwnd, caption, 200);
		if (wcscmp(caption, L"共享屏幕") == 0 || wcscmp(caption, L"BlackScreen Window") == 0)
			ShowWindow(hwnd, SW_FORCEMINIMIZE);
	}
	return TRUE;
}
void Minimize()
{
	DWORD mpid = 0;
	while (MinimizeRunning)
	{
		mpid = GetMythwarePID();
		if (!mpid) { this_thread::sleep_for(chrono::milliseconds(1)); continue; }
		EnumWindows(MinimizeEnumProc, mpid);
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

bool StartMinimize()
{
	if (MinimizeRunning)
		return false;
	MinimizeRunning = true;
	thread MinimizeThread(Minimize);
	MinimizeThread.detach();
	return true;
}

bool StopMinimize()
{
	if (!MinimizeRunning)
		return false;
	MinimizeRunning = false;
	return true;
}
#endif
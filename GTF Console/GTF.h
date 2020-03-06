#ifndef GTF_H
#define GTF_H
#include <string>
#include <cstdlib>
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
wstring AppPath;

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

bool KillMythware(const wstring& ntsdpath)
{
	PROCESSENTRY32 process;
	process.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE)
		return false;
	bool stillprocess = Process32First(snapshot, &process);
	while (stillprocess)
	{
		if (process.szExeFile == MythwareMainProgramName)
			_wsystem((AppPath + L"ntsd.exe -c q -p " + to_wstring(process.th32ProcessID)).c_str());
		stillprocess = Process32Next(snapshot, &process);
	}
	CloseHandle(snapshot);
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
#endif
#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>
#include "GTF.h"
#include "GTF Console.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs"); //use gbk to support chinese
	if (!GetAppPath()) { wcerr << ErrWord; return ERR_LOAD; }
	wcout << WelcomeWord;
	while (1)
	{
		read_end_line = false;
		wcin.clear();
		wstring command;
		wcout << L">>>";
		GetCommand(command);
		if (command == L"help")
			wcout << HelpWord;
		else if (command == L"kill")
			KillMythware(AppPath + L"\\ntsd.exe");
		else if (command == L"mythpath")
			Mythpath();
		else if (command == L"exit")
			return 0;
		else
			wcout << BadCommandWord;
	}
}

bool GetCommand(wstring& str)
{
	if (read_end_line)
		return false;
	wchar_t ch;
	bool quo = 0;
	wstring com;
	while (true)
	{
		wcin.get(ch);
		if (ch == L'\n')
		{
			read_end_line = true;
			return false;
		}
		else if (isspace(ch))
			continue;
		else
		{
			if (ch == L'\"')
				quo = true;
			else
				com += ch;
			break;
		}
	}
	while (wcin.get(ch))
	{
		if (ch == L'\"')
		{
			if (quo)
			{
				str = quo;
				return true;
			}
			else
				quo = true;
		}
		else if (ch == L'\n')
			break;
		else if (isspace(ch) && quo == false)
		{
			str = quo;
			return true;
		}
		else
			com += ch;
	}
	read_end_line = true;
	if (quo)
		return false;
	else
		return true;
}

void Mythpath()
{
	wstring argument[3];
	if (!GetCommand(argument[1]))
	{
		wcout << L"Mythware根目录: " << MythwareRootPath << endl;
		wcout << L"Mythware主程序: " << MythwareMainProgramName << endl << endl;
	}
	else if (!GetCommand(argument[2]))
		wcout << BadCommandWord;
	else
	{
		if (GetCommand(argument[0]))
		{
			while (!read_end_line)
				GetCommand(argument[0]);
			wcout << BadCommandWord;
		}
		else
		{
			if (argument[1] != L"%")
			{
				if (SetMythwareRootPath(argument[1]))
					wcout << L"Mythware根目录设置成功\n";
				else
					wcout << L"Mythware根目录设置错误,原因可能是目录不正确或没有充足权限\n";
			}
			if (argument[2] != L"%")
			{
				if (SetMythwareRootPath(argument[2]))
					wcout << L"Mythware主程序名设置成功\n";
				else
					wcout << L"Mythware主程序名设置错误,原因可能是目录或程序名不正确或没有充足权限\n";
			}
		}
	}
}
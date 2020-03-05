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
		wcin.clear();
		wstring command;
		wcout << L">>>";
		GetCommand(command);
		if (command == L"help")
			wcout << HelpWord;
		else if (command == L"kill")
			KillMythware(AppPath + L"\\ntsd.exe");
		else if (command == L"exit")
			return 0;
		else
			wcout << BadCommandWord;
	}
}

void GetCommand(wstring& com)
{
	wchar_t ch;
	bool quo = 0;
	while (wcin.get(ch))
	{
		if (ch == L'\"')
			quo = quo - 1;
		else if (ch == L'\n')
			break;
		else if (isspace(ch) && quo == false)
		{
			read_success = true;
			return;
		}
		else
			com += ch;
	}
	if (quo)
		read_err_quo = true;
	read_end_line = true;
}
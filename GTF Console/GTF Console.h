#ifndef GTF_Console_H
#define GTF_Console_H
#include <string>

const wstring WelcomeWord =
LR"(GTF - Console
 - Version:2.0.0000
 - Product By LTSlw
=====================================

)";

const wstring HelpWord =
LR"(GTF [Commands] [Arguments]

exit          退出GTF
help          获取帮助
kill          结束mythware
mythpath      查看/设置mythware的路径
mythexename   查看/设置mythware主程序文件名

)";

const wstring BadCommandWord =
LR"(不正确的命令!
请到help命令获取帮助

)";

const wstring ErrWord = L"程序遇到错误,退出!";

//3 bools for GetCommand()
bool read_success = 0;
bool read_end_line = 0;
bool read_err_quo = 0;

void GetCommand(wstring&);
#endif
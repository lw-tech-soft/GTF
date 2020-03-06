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

exit
  -default                             退出GTF
help
  -default                             获取帮助
kill
  -default                             结束mythware
mythpath      
  -无参数                              查看当前mythware的路径
  -[RootPath] [MainProgramPath]        设置mythware的路径,不需改变的参数用%代替
)";

const wstring BadCommandWord =
LR"(不正确的命令!
请到help命令获取帮助

)";

const wstring ErrWord = L"程序遇到错误,退出!";

bool read_end_line = 0;
bool GetCommand(wstring&);
void Mythpath();
#endif
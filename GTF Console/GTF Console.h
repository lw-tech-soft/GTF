#ifndef GTF_Console_H
#define GTF_Console_H
#include <string>

const wstring WelcomeWord =
LR"(GTF - Console
 - Version:2.0.0000
 - Product By LTSlw & LTSyc.
=====================================

)";

const wstring HelpWord =
LR"(GTF [Commands] [Arguments]

about
  -无参数                              查看制作者的信息
exit
  -无参数                              退出GTF
getpid
  -无参数                              查看极域进程ID
help
  -无参数                              获取帮助
kill
  -无参数                              结束极域
mythpath      
  -无参数                              查看当前极域的路径
  -[RootPath] [MainProgramPath]        设置极域的路径,不需改变的参数用%代替
window
  -[statu](start/stop)                 开启/关闭屏幕广播窗口化
mini
  -[statu](start/stop)                 最小化
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
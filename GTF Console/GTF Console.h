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
  -default                             �˳�GTF
help
  -default                             ��ȡ����
kill
  -default                             ����mythware
mythpath      
  -�޲���                              �鿴��ǰmythware��·��
  -[RootPath] [MainProgramPath]        ����mythware��·��,����ı�Ĳ�����%����
)";

const wstring BadCommandWord =
LR"(����ȷ������!
�뵽help�����ȡ����

)";

const wstring ErrWord = L"������������,�˳�!";

bool read_end_line = 0;
bool GetCommand(wstring&);
void Mythpath();
#endif
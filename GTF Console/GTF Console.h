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
  -�޲���                              �鿴�����ߵ���Ϣ
exit
  -�޲���                              �˳�GTF
getpid
  -�޲���                              �鿴�������ID
help
  -�޲���                              ��ȡ����
kill
  -�޲���                              ��������
mythpath      
  -�޲���                              �鿴��ǰ�����·��
  -[RootPath] [MainProgramPath]        ���ü����·��,����ı�Ĳ�����%����
window
  -[statu](start/stop)                 ����/�ر���Ļ�㲥���ڻ�
mini
  -[statu](start/stop)                 ��С��
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
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

exit          �˳�GTF
help          ��ȡ����
kill          ����mythware
mythpath      �鿴/����mythware��·��
mythexename   �鿴/����mythware�������ļ���

)";

const wstring BadCommandWord =
LR"(����ȷ������!
�뵽help�����ȡ����

)";

const wstring ErrWord = L"������������,�˳�!";

//3 bools for GetCommand()
bool read_success = 0;
bool read_end_line = 0;
bool read_err_quo = 0;

void GetCommand(wstring&);
#endif
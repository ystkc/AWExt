/*
*
*		����Ʒ����֪ʶ��������-��ͬ��ʽ���� 4.0 �������Э�������ɡ�
*		http://creativecommons.org/licenses/by-sa/4.0/
*		
*	AcrtStudio 11.19.2015
*
*	screenshoot version - 2.0.1
*	<--it is not guaranteed that screenshoot versions are bugfree-->
*
*/

#define WIN32_LEAN_AND_MEAN
#include<cstdio>
#include<cstdlib>
#include<pthread.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define DEBUG 0
using namespace std;
void* force(string taskname)
{
	if (FAILED(system(const_cast<char*>(("taskkill -f -im "+ taskname).c_str())))//taskkill
	 && GetLastError() == 18)
	 {
	 	chktool("ntsd.exe");
	 	system("start %Temp%\\AcrtStudio\\ntsd.exe");
	 	
	 }
	
}
void* killzjc(void* args)
{
	while (1)
	{
		Sleep(60000);
		system("taskkill -f -im Student.exe&taskkill -f -im StudentTools.exe");
	}
	return NULL;
}
void* help(void* args)
{
	MessageBox(NULL,"q:��ʾ����\tx:�����ö�\tt:ȡ���ö�\na:����͸��\tr:�ָ�����\t#:�˳�����","������ʾ",MB_OK);
	return NULL;
}
void* tishi(void* args)
{
	if (MessageBox(NULL,"---������ӽ��Ҹ���ѧϰ���---\n1.�����������ѧϰ��;�����ѯ��������ѧϰ��\n2.�κν����������ڲ�������;�����ге�һ���򲻺���ʹ�ò��������κͺ��\n3.���Ծ�ά�����ü��ɣ���ӽ�ʦ���ţ������𺦹����Ʋ�\n4.�����������磬�Ծ���������������������Լ\nҪ��������ѧϰ,�����������Ϣ��\nҪ��ʵ�Ѻý���,��������թ���ˡ�\nҪ��ǿ�Ի���ʶ,������Լ�����ѡ�\nҪά�����簲ȫ,���ƻ���������\nҪ�������Ľ���,����������ʱ�ա�\n\n\t\tѡ���Ǽ���Ϊͬ������4��\n\n\t\t\t\t\tAcrtStudio 2018.5.28\n��ע�����AntimonTelery\nȫ����ҵ���������֤","��ʾ",MB_YESNO)==7)
	exit(3);
	help((void*)NULL);
	return NULL;
}
int ope=0;
void rec(int k,HWND hwnd)
{
	if (k==1)ShowWindow(hwnd,SW_SHOW);
	else if (k==2)SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	else if (k==3)SetLayeredWindowAttributes(hwnd, 0, 255, 0x2),
	SetWindowLong(hwnd,GWL_EXSTYLE,
    GetWindowLong(hwnd,GWL_EXSTYLE) & ~0x80000 & ~WS_EX_TRANSPARENT & ~WS_EX_LAYERED);
    ope=0;
	return ;
}
int main()
{
	pthread_t tids;
	if (DEBUG)
	{
		pthread_create(&tids, NULL, killzjc, (void*)NULL);
	}
//	ShowWindow(GetConsoleWindow(),SW_HIDE);//������-mwindows 
	pthread_create(&tids, NULL, tishi, (void*)NULL);
	HWND operatinghwnd;
	while (!KEY_DOWN(51/*'3'*/)||!KEY_DOWN(16))
	{
		if (KEY_DOWN((int)'X'))
		{
			rec(ope,operatinghwnd);
			operatinghwnd=GetForegroundWindow();
			ShowWindow(operatinghwnd,SW_HIDE);
			ope=1;
			while (KEY_DOWN((int)'X'))Sleep(50);
		}
		if (KEY_DOWN((int)'Q'))
		{
			pthread_create(&tids, NULL, help, (void*)NULL);
			while (KEY_DOWN((int)'Q'))Sleep(50);
		}
		if (KEY_DOWN((int)'T'))
		{
			rec(ope,operatinghwnd);
			operatinghwnd=GetForegroundWindow();
			SetWindowPos(operatinghwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			ope=2;
			while (KEY_DOWN((int)'T'))Sleep(50);
		}
		if (KEY_DOWN((int)'A'))
		{
			rec(ope,operatinghwnd);
			operatinghwnd=GetForegroundWindow();
			SetWindowLong(operatinghwnd,GWL_EXSTYLE,
     		GetWindowLong(operatinghwnd,GWL_EXSTYLE) | 0x80000 | WS_EX_TRANSPARENT | WS_EX_LAYERED);
			SetLayeredWindowAttributes(operatinghwnd, 0, 100/*0-255*/, 0x2);
			ope=3;
			while (KEY_DOWN((int)'A'))Sleep(50);
		}
		if (KEY_DOWN((int)'R'))
		{
			rec(ope,operatinghwnd);
			while (KEY_DOWN((int)'R'))Sleep(50);
		}
		Sleep(50);
	}
	rec(ope,operatinghwnd);
	return 0;
}


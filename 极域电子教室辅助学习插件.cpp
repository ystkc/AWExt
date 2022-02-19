/*
*
*		本作品采用知识共享署名-相同方式共享 4.0 国际许可协议进行许可。
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
	MessageBox(NULL,"q:显示帮助\tx:隐藏置顶\tt:取消置顶\na:顶层透视\tr:恢复顶层\t#:退出运行","操作提示",MB_OK);
	return NULL;
}
void* tishi(void* args)
{
	if (MessageBox(NULL,"---极域电子教室辅助学习插件---\n1.本程序仅用于学习用途例如查询资料自主学习等\n2.任何将本程序用于不合理用途者自行承担一切因不合理使用产生的责任和后果\n3.请自觉维护课堂纪律，遵从教师安排，不得损害公共财产\n4.合理利用网络，自觉遵守青少年网络文明公约\n要善于网上学习,不浏览不良信息。\n要诚实友好交流,不侮辱欺诈他人。\n要增强自护意识,不随意约会网友。\n要维护网络安全,不破坏网络秩序。\n要有益身心健康,不沉溺虚拟时空。\n\n\t\t选择是即视为同意以上4点\n\n\t\t\t\t\tAcrtStudio 2018.5.28\n已注册给：AntimonTelery\n全球企业无限制许可证","提示",MB_YESNO)==7)
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
//	ShowWindow(GetConsoleWindow(),SW_HIDE);//加入了-mwindows 
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


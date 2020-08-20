// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"


HHOOK g_hhk;
HMODULE g_hModule;
HWND g_hWnd;

LRESULT CALLBACK KeyBoardProc
(
	int nCode,
	WPARAM wParam,
	LPARAM lParam
)
{
	unsigned int nVKCode = wParam;
	char szBuf[256];
	if (nVKCode >= 'A' && nVKCode <= 'Z')
	{
		sprintf_s(szBuf, "%c pressed", nVKCode);
		/*OutputDebugStringA(szBuf);*/

		COPYDATASTRUCT cds;
		cds.dwData = 0;
		cds.cbData = strlen(szBuf) + 1;//要传送的数据长度
		cds.lpData = szBuf;				//要传送的数据

		SendMessage(g_hWnd,   //想改窗口句柄发送消息
			WM_COPYDATA,
			(WPARAM)g_hWnd,   //表示当前自己的窗口句柄,可以不写
			(LPARAM)&cds      //构建一个结构体,用于将数据传输
			);

	}

	return CallNextHookEx(g_hhk, nCode, wParam, lParam);
}

//dll 导出函数,提供给其他程序使用
BOOL MySetHook(HWND hWnd)
{
	g_hWnd = hWnd;
	g_hhk = SetWindowsHookEx(WH_KEYBOARD,
		(HOOKPROC)KeyBoardProc,
		g_hModule, //表示第三方的注入dll ,全局钩子使用,DLL的模块句柄
		0 //线程ID,填0 表示勾所有线程
	);
	if (g_hhk == NULL)
	{
		return FALSE;
	}

	return TRUE;

}




BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		g_hModule = hModule;
		//当DLL被加载时调用
		//编写初始化操作
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	{
		//当DLL被释放时调用
		//编写反初始化操作
	}
	break;
	}
	return TRUE;
}


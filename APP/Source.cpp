//#include<Windows.h>
//#include <CommCtrl.h>
//#include"resource.h"
//#include <WindowsX.h>
//
//#define MENU_EXIT_ID 1
//#define MENU_ABOUT_ID 2
//#define MENU_FONT_ID 3
//#define MENU_REPLACE_ID 4
//#define TREE_ID 6
//#define MENU_KEYS 7
//#define SET_BUTTON 8
//#define TIMER_ID 9
//#define ADD_RECORD 10
//#define REMOVE_RECORDS 11
//#define CTRL_A 51
//#define EXIT_KEY 52
//#define CTRL_F 53
//#define CTRL_R 54
//#define CTRL_K 55
//#define IDC_EDIT2 12
//
//INT BUTTON_Y = 130;
//HWND hWnd = NULL;
//HINSTANCE handle;
//FINDREPLACE findDlg;
//HWND m_TreeView;
//HWND hwndHot;
//TCHAR szBuffer[100] = TEXT("");
//TCHAR szReplaceBuffer[100] = TEXT("");
//CHAR Buf[20] = "";
//HWND hFindDlg = NULL;
//HWND hDlg = NULL;
//UINT uFindMsgString = 0;
//HWND Button;
//HWND hEdit;
//INT time = 0;
//PSTR stri;
//
//HTREEITEM TreeView_FindItem(HWND hwnd, HTREEITEM hParent, LPCTSTR lpText, BOOL fIgnoreCase)
//{
//	TCHAR szItemText[100];
//	TVITEM item;
//	item.mask = TVIF_TEXT;
//	item.cchTextMax = _countof(szItemText);
//	item.pszText = szItemText;
//	item.hItem = TreeView_GetChild(hwnd, hParent);
//	while (NULL != item.hItem)
//	{
//		BOOL bRet = TreeView_GetItem(hwnd, &item);
//		if (FALSE != bRet)
//		{
//			DWORD dwCmpFlags = (FALSE != fIgnoreCase) ? NORM_IGNORECASE : 0;
//			HRESULT hr = CompareString(LOCALE_USER_DEFAULT, dwCmpFlags, lpText, -1, item.pszText, -1);
//			if (CSTR_EQUAL == hr)
//			{
//				return item.hItem;
//			}
//		}
//		HTREEITEM hitem = TreeView_FindItem(hwnd, item.hItem, lpText, fIgnoreCase);
//		if (NULL != hitem)
//		{
//			return hitem;
//		}
//		item.hItem = TreeView_GetNextSibling(hwnd, item.hItem);
//	}
//	return NULL;
//}
//
//VOID Exit(HWND hWnd) {
//	int mbResult = MessageBox(hWnd, TEXT("Действительно выйти?"), TEXT("Выход"), MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
//	if (IDYES == mbResult)
//	{
//		DestroyWindow(hWnd);
//	}
//}
//
//VOID FontWindow(HWND hWnd) {
//	CHOOSEFONT cf;
//	static LOGFONT lf;
//	HFONT hfont;
//	ZeroMemory(&cf, sizeof(CHOOSEFONT));
//	cf.lStructSize = sizeof(CHOOSEFONT);
//	cf.hwndOwner = hWnd;
//	cf.lpLogFont = &lf;
//	cf.nSizeMax = 18;
//	cf.nSizeMin = 8;
//	cf.Flags = CF_SCREENFONTS | CF_LIMITSIZE;
//	if (ChooseFont(&cf) == TRUE)
//	{
//		hfont = CreateFontIndirect(cf.lpLogFont);
//		SendMessage(m_TreeView, WM_SETFONT, (WPARAM)hfont, TRUE);
//	}
//}
//
//VOID ReplaceWindow(HWND hWnd)
//{
//	if (0 == uFindMsgString)
//	{
//		uFindMsgString = RegisterWindowMessage(FINDMSGSTRING);
//	}
//	if (IsWindow(hFindDlg) == FALSE)
//	{
//		if (0 == uFindMsgString)
//		{
//			uFindMsgString = RegisterWindowMessage(FINDMSGSTRING);
//		}
//		if (IsWindow(hFindDlg) == FALSE)
//		{
//			findDlg.lStructSize = sizeof(FINDREPLACE);
//			findDlg.Flags = FR_REPLACE | FR_HIDEWHOLEWORD | FR_MATCHCASE;
//			findDlg.hInstance = handle;
//			findDlg.hwndOwner = hWnd;
//			findDlg.lpstrFindWhat = szBuffer;
//			findDlg.lpstrReplaceWith = szReplaceBuffer;
//			findDlg.wFindWhatLen = _countof(szBuffer);
//			findDlg.wReplaceWithLen = _countof(szReplaceBuffer);
//			hFindDlg = ReplaceText(&findDlg);
//		}
//	}
//}
//
//HTREEITEM InsTreeItem(HTREEITEM hParent, LPSTR szText, HTREEITEM hAfter)
//{
//	TV_INSERTSTRUCT tvins;
//	HTREEITEM hItem;
//	memset(&tvins, 0, sizeof(tvins));
//	tvins.item.mask = TVIF_TEXT | TVIF_IMAGE |
//		TVIF_SELECTEDIMAGE | TVIF_PARAM;
//	tvins.item.pszText = szText;
//	tvins.item.cchTextMax = lstrlen(szText);
//	tvins.item.iImage = NULL;
//	tvins.item.iSelectedImage = NULL;
//	tvins.hInsertAfter = hAfter;
//	tvins.hParent = hParent;
//	hItem = TreeView_InsertItem(m_TreeView, &tvins);
//	return hItem;
//}
//
//VOID OnFindMsgString(HWND hwnd, LPFINDREPLACE lpFindReplace)
//{
//	if (lpFindReplace->Flags & FR_FINDNEXT)
//	{
//		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
//		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
//		if (NULL != hitem)
//		{
//			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
//			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
//			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
//			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
//			SetFocus(m_TreeView);
//		}
//		else
//		{
//			MessageBox(hwnd, TEXT("Элемент не найден"), TEXT("SampleWin32"), MB_OK | MB_ICONINFORMATION);
//		}
//	}
//	if (lpFindReplace->Flags & FR_REPLACE)
//	{
//		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
//		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
//		if (NULL != hitem)
//		{
//			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
//			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
//			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
//			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
//			TVITEM t;
//			t.hItem = hitem;
//			t.pszText = szReplaceBuffer;
//			t.mask = TVM_SETITEM;
//			TreeView_SetItem(m_TreeView, &t);
//			SetFocus(m_TreeView);
//		}
//		else
//		{
//			MessageBox(hwnd, TEXT("Элемент не найден"), TEXT("Не найдено"), MB_OK | MB_ICONINFORMATION);
//		}
//	}
//	if (lpFindReplace->Flags & FR_REPLACEALL)
//	{
//		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
//		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
//		while (NULL != hitem)
//		{
//			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
//			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
//			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
//			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
//			TVITEM t;
//			t.hItem = hitem;
//			t.pszText = szReplaceBuffer;
//			t.mask = TVM_SETITEM;
//			TreeView_SetItem(m_TreeView, &t);
//			SetFocus(m_TreeView);
//			hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
//		}
//	}
//}
//
//VOID TreeViewInitializer(HWND hWnd) {
//	HTREEITEM hRoot = InsTreeItem((HTREEITEM)TVI_ROOT, LPSTR("Тип двигателя"), (HTREEITEM)TVI_FIRST);
//	HTREEITEM hTreeElectric = InsTreeItem(hRoot, LPSTR("Электрический"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeFossilFuel = InsTreeItem(hRoot, LPSTR("ДВС"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeHybrid = InsTreeItem(hRoot, LPSTR("Гибридный"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeNissan = InsTreeItem(hTreeElectric, LPSTR("Nissan"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeNissanLeaf = InsTreeItem(hTreeNissan, LPSTR("Leaf"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeTesla = InsTreeItem(hTreeElectric, LPSTR("Tesla"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeTeslaModelS = InsTreeItem(hTreeTesla, LPSTR("Model S"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeTeslaModelX = InsTreeItem(hTreeTesla, LPSTR("Model X"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeTeslaModel3 = InsTreeItem(hTreeTesla, LPSTR("Model 3"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeTeslaModelY = InsTreeItem(hTreeTesla, LPSTR("Model Y"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeFord = InsTreeItem(hTreeFossilFuel, LPSTR("Ford"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeFordFocus = InsTreeItem(hTreeFord, LPSTR("Focus"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeBMW = InsTreeItem(hTreeFossilFuel, LPSTR("BMW"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeBMWX5 = InsTreeItem(hTreeBMW, LPSTR("X5"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeToyota = InsTreeItem(hTreeHybrid, LPSTR("Toyota"), (HTREEITEM)TVI_SORT);
//	HTREEITEM hTreeToyotaPrius = InsTreeItem(hTreeToyota, LPSTR("Prius"), (HTREEITEM)TVI_SORT);
//}
//
//VOID MenuInitializer(HWND hwnd) {
//	HMENU hMenuBar = CreateMenu();
//	HMENU hExit = CreateMenu();
//	HMENU hFile = CreateMenu();
//	HMENU hView = CreateMenu();
//	HMENU hFont = CreateMenu();
//	HMENU hKeys = CreateMenu();
//	AppendMenu(hFile, MF_POPUP, MENU_KEYS, "Горячие клавиши");
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, "Файл");
//	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hView, "Вид");
//	AppendMenu(hView, MF_POPUP, MENU_FONT_ID, "Шрифт");
//	AppendMenu(hView, MF_POPUP, MENU_REPLACE_ID, "Заменить");
//	AppendMenu(hMenuBar, MF_POPUP, MENU_ABOUT_ID, "О программе");
//	AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
//	AppendMenu(hFile, MF_STRING, MENU_EXIT_ID, "Выход");
//	SetMenu(hwnd, hMenuBar);
//}
//
//VOID HotKeysInitializer(HWND hWnd)
//{
//	RegisterHotKey(hWnd, CTRL_A, MOD_CONTROL, 0x41);
//	RegisterHotKey(hWnd, CTRL_K, MOD_CONTROL, 0x4B);
//	RegisterHotKey(hWnd, CTRL_F, MOD_CONTROL, 0x46);
//	RegisterHotKey(hWnd, CTRL_R, MOD_CONTROL, 0x52);
//}
//
//BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//	{
//		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)"О приложении");
//		SetDlgItemText(hwnd, IDOK, "Понятно");
//		SetDlgItemText(hwnd, IDNO, "Лабораторная работа №2: создание оконного приложения");
//		break;
//	}
//	case WM_CLOSE:
//		EndDialog(hwnd, 0);
//	case WM_COMMAND:
//	{
//		if (LOWORD(wParam) == IDOK)
//			EndDialog(hwnd, 0);
//	}
//	}
//	return FALSE;
//}
//
//BOOL CALLBACK HotKeysDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//	{
//		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)"Горячие клавиши");
//		SetDlgItemText(hwnd, IDOK, "ОК");
//		SetDlgItemText(hwnd, IDYES, "Выход: настраивается вручную\nО приложении: CTRL+E\nШрифт: CTRL+F\nЗаменить: CTRL+R\nГорячие клавиши: CTRL+K");
//		break;
//	}
//	case WM_CLOSE:
//		EndDialog(hwnd, 0);
//	case WM_COMMAND:
//	{
//		if (LOWORD(wParam) == IDOK)
//			EndDialog(hwnd, 0);
//	}
//	}
//	return FALSE;
//}
//
//VOID AboutWindow(HWND hWnd) {
//	DialogBoxParam(handle, MAKEINTRESOURCE(IDD_DIALOG), hWnd, AboutDlgProc, 0);
//}
//
//VOID HotKeysWindow(HWND hWnd)
//{
//	DialogBoxParam(handle, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, HotKeysDlgProc, 0);
//}
//
//VOID OnMouseWheel(HWND hwnd, int xPos, int yPos, int zDelta, UINT fwKeys)
//{
//	DestroyWindow(Button);
//	if (BUTTON_Y < 130)
//		BUTTON_Y = 130;
//	if (BUTTON_Y > 180)
//		BUTTON_Y = 180;
//	BUTTON_Y = BUTTON_Y + 5 * zDelta / WHEEL_DELTA;
//	Button = CreateWindow("BUTTON", "Назначить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 340, BUTTON_Y, 80, 30, hWnd, (HMENU)SET_BUTTON, handle, NULL);
//}
//
//VOID RemoveRecords(){
//	if (NULL != TreeView_GetSelection(m_TreeView))
//	{
//		int mbResult = MessageBox(hWnd, TEXT("Действительно удалить?"), TEXT("SampleWin32"), MB_YESNO | MB_ICONQUESTION);
//		if (mbResult == IDYES)
//		{
//			TreeView_DeleteItem(m_TreeView, TreeView_GetSelection(m_TreeView));
//		}
//	}
//	else
//	{
//		MessageBox(hWnd, TEXT("Вы не выбрали элемент для удаления"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
//	}
//}
//
//BOOL CALLBACK AddRecordsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//	{
//		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)"Добавление записи");
//		SetDlgItemText(hwnd, IDD_DIALOG2, "Введите название записи");
//		break;
//	}
//	case WM_CLOSE:
//		EndDialog(hwnd, 0);
//	case WM_COMMAND:
//	{
//		if (LOWORD(wParam) == IDCANCEL)
//			EndDialog(hwnd, 0);
//		if (LOWORD(wParam) == IDOK_ADDRECORDS)
//		{
//			GetDlgItemText(hwnd, IDC_EDIT1, Buf, 20);
//			if (Buf[0] == 0)
//				MessageBox(hWnd, TEXT("Имя не должно быть пустым"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
//			else
//			{
//					EndDialog(hwnd, 0);
//			}
//		}
//	}
//	}
//	return FALSE;
//}
//
//VOID AddRecords() {
//	HTREEITEM selected = TreeView_GetSelection(m_TreeView);
//	if (NULL != selected)
//	{
//		DialogBox(handle, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, AddRecordsProc);
//		if (Buf[0] != 0)
//		{
//			HTREEITEM hItem = InsTreeItem(selected, Buf, (HTREEITEM)TVI_SORT);
//		}
//	}
//	else
//	{
//		MessageBox(hWnd, TEXT("Вы не выбрали родительский элемет"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
//	}
//}
//
//LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	RECT r;
//	HDC hdc;
//	switch (uMsg)
//	{
//		HANDLE_MSG(hWnd, WM_MOUSEWHEEL, OnMouseWheel);
//	case WM_COMMAND:
//		if (LOWORD(wParam) == MENU_REPLACE_ID)
//			ReplaceWindow(hWnd);
//		if (LOWORD(wParam) == MENU_EXIT_ID)
//			Exit(hWnd);
//		if (LOWORD(wParam) == MENU_ABOUT_ID)
//			AboutWindow(hWnd);
//		if (LOWORD(wParam) == MENU_FONT_ID)
//			FontWindow(hWnd);
//		if (LOWORD(wParam) == MENU_KEYS)
//			HotKeysWindow(hWnd);
//		if (LOWORD(wParam) == ADD_RECORD)
//			AddRecords();
//		if (LOWORD(wParam) == REMOVE_RECORDS)
//				RemoveRecords();
//		if (LOWORD(wParam) == SET_BUTTON)
//		{
//			/*INT wHotkey = LOBYTE(SendMessage(hwndHot, HKM_GETHOTKEY, 0, 0));
//			UnregisterHotKey(hWnd, EXIT_KEY);
//			RegisterHotKey(hWnd, EXIT_KEY, MOD_ALT | MOD_CONTROL, wHotkey);*/
//			UnregisterHotKey(hWnd, EXIT_KEY);
//			WORD val = LOWORD(SendMessage(hwndHot, HKM_GETHOTKEY, 0, 0));
//			BYTE wHotkey = LOBYTE(val);
//			BYTE flags = HIBYTE(val);
//			RegisterHotKey(hWnd, EXIT_KEY, (flags & 0x0007), wHotkey); 
//			SetFocus(hWnd);
//		}
//		return 0;
//	case WM_CLOSE:
//	{
//		Exit(hWnd);
//		return 0;
//	}
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	case WM_CREATE:
//		MenuInitializer(hWnd);
//		TreeViewInitializer(hWnd);
//		HotKeysInitializer(hWnd);
//		SetTimer(hWnd, TIMER_ID, 1000, NULL);
//		return 0;
//	case WM_HOTKEY:
//		if (wParam == CTRL_A)
//			AboutWindow(hWnd);
//		if (wParam == EXIT_KEY)
//			Exit(hWnd);
//		if (wParam == CTRL_K)
//			HotKeysWindow(hWnd);
//		if (wParam == CTRL_F)
//			FontWindow(hWnd);
//		if (wParam == CTRL_R)
//			ReplaceWindow(hWnd);
//		return 0;
//	case WM_KEYUP:
//		r.left = 350;
//		r.top = 400;
//		r.right = 400;
//		r.bottom = 450;
//		hdc = GetDC(hWnd);
//		FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(128, 128, 128)));
//		return 0;
//	case WM_KEYDOWN:
//		r.left = 350;
//		r.top = 400;
//		r.right = 400;
//		r.bottom = 450;
//		hdc = GetDC(hWnd);
//		FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
//		MessageBeep(MB_ICONHAND);
//		return 0;
//	case WM_MOVING:
//	{
//		RECT rect;
//		hdc = GetDC(hWnd);
//		GetWindowRect(hWnd, &rect);
//		CHAR st[10] = "";
//		TextOut(hdc, 320, 20, "X: ", 3);
//		TextOut(hdc, 320, 40, "Y: ", 3);
//		TextOut(hdc, 350, 20, "          ",10);
//		TextOut(hdc, 350, 40, "          ", 10);
//		wsprintf(st, "%d", rect.left);
//		TextOut(hdc, 350, 20, st, strlen(st));
//		wsprintf(st, "%d", rect.top);
//		TextOut(hdc, 350, 40, st, strlen(st));
//		return 0;
//	}
//	case WM_PAINT:
//	{
//		HBRUSH bru = CreateSolidBrush(RGB(128, 128, 128));
//		r.left = 350;
//		r.top = 400;
//		r.right = 400;
//		r.bottom = 450;
//		hdc = GetDC(hWnd);
//		FillRect(hdc, &r,bru);
//		r.left = 380;
//		r.top = 300;
//		r.right = 430;
//		r.bottom = 350;
//		hdc = GetDC(hWnd);
//		FillRect(hdc, &r, bru);
//		DeleteObject(bru);
//		break;
//	}
//	case WM_MBUTTONDBLCLK:
//		MessageBox(hWnd, TEXT("Осторожно, колёсико может сломаться!!!"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
//		return 0;
//	case WM_MBUTTONDOWN:
//	{
//		HBRUSH bru = CreateSolidBrush(RGB(0, 0, 255));
//		r.left = 380;
//		r.top = 300;
//		r.right = 430;
//		r.bottom = 350;
//		hdc = GetDC(hWnd);
//		FillRect(hdc, &r, bru);
//		MessageBeep(MB_ICONEXCLAMATION);
//		DeleteObject(bru);
//		return 0;
//	}
//	case WM_MBUTTONUP:
//	{
//		r.left = 380;
//		r.top = 300;
//		r.right = 430;
//		r.bottom = 350;
//		hdc = GetDC(hWnd);
//		HBRUSH bru = CreateSolidBrush(RGB(128, 128, 128));
//		FillRect(hdc, &r, bru);
//		DeleteObject(bru);
//		return 0;
//	}
//	case WM_CHAR:
//	{
//		wchar_t vowels[12] = { 'a', 'u', 'e', 'o', 'y', 'i','A', 'U', 'E', 'O', 'Y', 'I' };
//		wchar_t consonants[40] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z','B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z' };
//		BOOL checking = FALSE;
//		for (int i = 0; i < 32; i++)
//		{
//			if (vowels[i] == (wchar_t)wParam)
//			{
//				checking = TRUE;
//				break;
//			}
//		}
//		if (checking)
//			MessageBox(hWnd, TEXT("Гласная буква"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
//		else
//		{
//			for (int i = 0; i < 40; i++)
//			{
//				if (consonants[i] == (wchar_t)wParam)
//				{
//					checking = TRUE;
//					break;
//				}
//			}
//			if (checking)
//				MessageBox(hWnd, TEXT("Согласная буква"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
//		}
//		/*hdc = GetDC(hWnd);
//		char str[80] = "";
//		TextOut(hdc, 430, 410, " ", 2);
//		wsprintf(str, "%c", (char)wParam);*/
//		/*TextOut(hdc, 430, 410, str, strlen(str));
//		stri = stri + (char)wParam;
//		TextOut(hdc, 430, 410, stri, strlen(stri));*/
//
//
//		//GetDlgItemText(hDlg, IDC_EDIT1, str, 80);
//		//str = (char)wParam;
//		//SetDlgItemText(hDlg, IDC_EDIT2, wParam);
//
//
//
//		return 0;
//	}
//	case WM_TIMER:
//	{
//		hdc = GetDC(hWnd);
//		char s[5] = "";
//		TextOut(hdc, 430, 430, " ", 2);
//		wsprintf(s, "%d", time);
//		TextOut(hdc, 430, 430, s, strlen(s));
//		time++;
//		return 0;
//	}
//	}
//	if (uFindMsgString == uMsg)
//	{
//		OnFindMsgString(hWnd, (LPFINDREPLACE)lParam);
//		return 0;
//	}
//	return DefWindowProc(hWnd, uMsg, wParam, lParam);
//}
//
//VOID CreatingElements(HINSTANCE hInstance, HWND hWnd)
//{
//	Button = CreateWindow("BUTTON", "Назначить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 340, BUTTON_Y, 80, 30, hWnd, (HMENU)SET_BUTTON, hInstance, NULL);
//	CreateWindow("static", "Выход из программы: ", WS_CHILD | WS_VISIBLE, 320, 70, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
//	hwndHot = CreateWindowEx(0, HOTKEY_CLASS, TEXT(""), WS_CHILD | WS_VISIBLE, 320, 100, 100, 20, hWnd, NULL, hInstance, NULL);
//	CreateWindow("BUTTON", "Автомобили", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 10, 10, 300, 450, hWnd, (HMENU)-1, hInstance, NULL);
//	m_TreeView = CreateWindowEx(0, TEXT("SysTreeView32"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, 20, 30, 280, 420, hWnd, NULL, hInstance, NULL);
//	TreeViewInitializer(hWnd);
//	CreateWindow("static", "Клавиатура", WS_CHILD | WS_VISIBLE, 340, 370, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
//	CreateWindowEx(0, TEXT("Button"), TEXT("Добавить запись"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 460, 120, 30, hWnd, (HMENU)ADD_RECORD, hInstance, NULL);
//	CreateWindow(TEXT("Button"), TEXT("Удалить запись"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 460, 120, 30, hWnd, (HMENU)REMOVE_RECORDS, hInstance, NULL);
//	CreateWindow("static", "Мышь", WS_CHILD | WS_VISIBLE, 340, 260, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
//
//	//hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", NULL ,WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,500, 50, 50, 30, hWnd, (HMENU)IDC_EDIT2, hInstance, NULL);
//	//CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT, 500, 150, 50, 30, hWnd, (HMENU)5, hInstance, NULL);
//
//
//}
//
//WNDCLASSEX RegisterWindowClass(HINSTANCE hInstance) {
//	WNDCLASSEX window = { sizeof(WNDCLASSEX) };
//	window.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
//	window.lpfnWndProc = WindowProcedure;
//	window.hInstance = hInstance;
//	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	window.hCursor = LoadCursor(NULL, IDC_ARROW);
//	window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	window.lpszMenuName = NULL;
//	window.lpszClassName = TEXT("WindowClass");
//	window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	return window;
//}
//
//BOOL PreTranslateMessage(LPMSG lpMsg)
//{
//	BOOL bRet = TRUE;
//	if (!TranslateAccelerator(hWnd, NULL, lpMsg))
//	{
//		bRet = IsDialogMessage(hDlg, lpMsg);
//
//		if (FALSE == bRet)
//			bRet = IsDialogMessage(hFindDlg, lpMsg);
//	}
//	return bRet;
//}
//
//VOID MessagesProcessing() {
//	MSG  msg;
//	BOOL bRet;
//	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != FALSE)
//	{
//		if (bRet == -1)
//		{
//		}
//		else if (!PreTranslateMessage(&msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR lpszCmdLine, int nCmdShow)
//{
//	handle = hInstance;
//	if (!RegisterClassEx(&RegisterWindowClass(hInstance)))
//		return EXIT_FAILURE;
//	LoadLibrary(TEXT("ComCtl32.dll"));
//	hWnd = CreateWindowEx(0, TEXT("WindowClass"), TEXT("Моя прога"), WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU, 300, 100, 600, 600, NULL, NULL, hInstance, NULL);
//	if (hWnd == NULL)
//		return EXIT_FAILURE;
//	CreatingElements(hInstance, hWnd);
//	ShowWindow(hWnd, nCmdShow);
//	MessagesProcessing();
//	return EXIT_SUCCESS;
//}



#include<Windows.h>
#include <CommCtrl.h>
#include"resource.h"
#include <WindowsX.h>

#define MENU_EXIT_ID 1
#define MENU_ABOUT_ID 2
#define MENU_FONT_ID 3
#define MENU_REPLACE_ID 4
#define TREE_ID 6
#define MENU_KEYS 7
#define SET_BUTTON 8
#define TIMER_ID 9
#define ADD_RECORD 10
#define REMOVE_RECORDS 11
#define CTRL_A 51
#define EXIT_KEY 52
#define CTRL_F 53
#define CTRL_R 54
#define CTRL_K 55
#define IDC_EDIT2 12

INT BUTTON_Y = 130;
HWND hWnd = NULL;
HINSTANCE handle;
FINDREPLACE findDlg;
HWND m_TreeView;
HWND hwndHot;
TCHAR szBuffer[100] = TEXT("");
TCHAR szReplaceBuffer[100] = TEXT("");
TCHAR Buf[20] = TEXT("");
HWND hFindDlg = NULL;
HWND hDlg = NULL;
UINT uFindMsgString = 0;
HWND Button;
HWND hEdit;
INT time = 0;
PSTR stri;

HTREEITEM TreeView_FindItem(HWND hwnd, HTREEITEM hParent, LPCTSTR lpText, BOOL fIgnoreCase)
{
	TCHAR szItemText[100];
	TVITEM item;
	item.mask = TVIF_TEXT;
	item.cchTextMax = _countof(szItemText);
	item.pszText = szItemText;
	item.hItem = TreeView_GetChild(hwnd, hParent);
	while (NULL != item.hItem)
	{
		BOOL bRet = TreeView_GetItem(hwnd, &item);
		if (FALSE != bRet)
		{
			DWORD dwCmpFlags = (FALSE != fIgnoreCase) ? NORM_IGNORECASE : 0;
			HRESULT hr = CompareString(LOCALE_USER_DEFAULT, dwCmpFlags, lpText, -1, item.pszText, -1);
			if (CSTR_EQUAL == hr)
			{
				return item.hItem;
			}
		}
		HTREEITEM hitem = TreeView_FindItem(hwnd, item.hItem, lpText, fIgnoreCase);
		if (NULL != hitem)
		{
			return hitem;
		}
		item.hItem = TreeView_GetNextSibling(hwnd, item.hItem);
	}
	return NULL;
}

VOID Exit(HWND hWnd) {
	int mbResult = MessageBox(hWnd, (LPCWSTR)TEXT("Действительно выйти?"), (LPCWSTR)TEXT("Выход"), MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
	if (IDYES == mbResult)
	{
		DestroyWindow(hWnd);
	}
}

VOID FontWindow(HWND hWnd) {
	CHOOSEFONT cf;
	static LOGFONT lf;
	HFONT hfont;
	ZeroMemory(&cf, sizeof(CHOOSEFONT));
	cf.lStructSize = sizeof(CHOOSEFONT);
	cf.hwndOwner = hWnd;
	cf.lpLogFont = &lf;
	cf.nSizeMax = 18;
	cf.nSizeMin = 8;
	cf.Flags = CF_SCREENFONTS | CF_LIMITSIZE;
	if (ChooseFont(&cf) == TRUE)
	{
		hfont = CreateFontIndirect(cf.lpLogFont);
		SendMessage(m_TreeView, WM_SETFONT, (WPARAM)hfont, TRUE);
	}
}

VOID ReplaceWindow(HWND hWnd)
{
	if (0 == uFindMsgString)
	{
		uFindMsgString = RegisterWindowMessage(FINDMSGSTRING);
	}
	if (IsWindow(hFindDlg) == FALSE)
	{
		if (0 == uFindMsgString)
		{
			uFindMsgString = RegisterWindowMessage(FINDMSGSTRING);
		}
		if (IsWindow(hFindDlg) == FALSE)
		{
			findDlg.lStructSize = sizeof(FINDREPLACE);
			findDlg.Flags = FR_REPLACE | FR_HIDEWHOLEWORD | FR_MATCHCASE;
			findDlg.hInstance = handle;
			findDlg.hwndOwner = hWnd;
			findDlg.lpstrFindWhat = szBuffer;
			findDlg.lpstrReplaceWith = szReplaceBuffer;
			findDlg.wFindWhatLen = _countof(szBuffer);
			findDlg.wReplaceWithLen = _countof(szReplaceBuffer);
			hFindDlg = ReplaceText(&findDlg);
		}
	}
}

HTREEITEM InsTreeItem(HTREEITEM hParent, LPWSTR szText, HTREEITEM hAfter)
{
	TV_INSERTSTRUCT tvins;
	HTREEITEM hItem;
	memset(&tvins, 0, sizeof(tvins));
	tvins.item.mask = TVIF_TEXT | TVIF_IMAGE |
		TVIF_SELECTEDIMAGE | TVIF_PARAM;
	tvins.item.pszText = szText;
	tvins.item.cchTextMax = lstrlen(szText);
	tvins.item.iImage = NULL;
	tvins.item.iSelectedImage = NULL;
	tvins.hInsertAfter = hAfter;
	tvins.hParent = hParent;
	hItem = TreeView_InsertItem(m_TreeView, &tvins);
	return hItem;
}

VOID OnFindMsgString(HWND hwnd, LPFINDREPLACE lpFindReplace)
{
	if (lpFindReplace->Flags & FR_FINDNEXT)
	{
		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
		if (NULL != hitem)
		{
			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
			SetFocus(m_TreeView);
		}
		else
		{
			MessageBox(hwnd, (LPCWSTR)TEXT("Элемент не найден"), (LPCWSTR)TEXT("SampleWin32"), MB_OK | MB_ICONINFORMATION);
		}
	}
	if (lpFindReplace->Flags & FR_REPLACE)
	{
		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
		if (NULL != hitem)
		{
			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
			TVITEM t;
			t.hItem = hitem;
			t.pszText = szReplaceBuffer;
			t.mask = TVM_SETITEM;
			TreeView_SetItem(m_TreeView, &t);
			SetFocus(m_TreeView);
		}
		else
		{
			MessageBox(hwnd, (LPCWSTR)TEXT("Элемент не найден"), (LPCWSTR)TEXT("Не найдено"), MB_OK | MB_ICONINFORMATION);
		}
	}
	if (lpFindReplace->Flags & FR_REPLACEALL)
	{
		BOOL fIgnorCase = (lpFindReplace->Flags & FR_MATCHCASE) ? FALSE : TRUE;
		HTREEITEM hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
		while (NULL != hitem)
		{
			TreeView_Expand(hWnd, hitem, TVE_EXPAND);
			TreeView_SetItemState(m_TreeView, TreeView_GetNextSelected(m_TreeView, NULL), 0, TVIS_SELECTED);
			TreeView_SetItemState(m_TreeView, hitem, TVIS_SELECTED, TVIS_SELECTED);
			TreeView_SelectSetFirstVisible(m_TreeView, hitem);
			TVITEM t;
			t.hItem = hitem;
			t.pszText = szReplaceBuffer;
			t.mask = TVM_SETITEM;
			TreeView_SetItem(m_TreeView, &t);
			SetFocus(m_TreeView);
			hitem = TreeView_FindItem(m_TreeView, NULL, szBuffer, fIgnorCase);
		}
	}
}

VOID TreeViewInitializer(HWND hWnd) {
	HTREEITEM hRoot = InsTreeItem((HTREEITEM)TVI_ROOT, (LPWSTR)TEXT("Тип двигателя"), (HTREEITEM)TVI_FIRST);
	HTREEITEM hTreeElectric = InsTreeItem(hRoot, (LPWSTR)TEXT("Электрический"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeFossilFuel = InsTreeItem(hRoot, (LPWSTR)TEXT("ДВС"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeHybrid = InsTreeItem(hRoot, (LPWSTR)TEXT("Гибридный"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeNissan = InsTreeItem(hTreeElectric, (LPWSTR)TEXT("Nissan"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeNissanLeaf = InsTreeItem(hTreeNissan, (LPWSTR)TEXT("Leaf"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeTesla = InsTreeItem(hTreeElectric, (LPWSTR)TEXT("Tesla"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeTeslaModelS = InsTreeItem(hTreeTesla, (LPWSTR)TEXT("Model S"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeTeslaModelX = InsTreeItem(hTreeTesla, (LPWSTR)TEXT("Model X"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeTeslaModel3 = InsTreeItem(hTreeTesla, (LPWSTR)TEXT("Model 3"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeTeslaModelY = InsTreeItem(hTreeTesla, (LPWSTR)TEXT("Model Y"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeFord = InsTreeItem(hTreeFossilFuel, (LPWSTR)TEXT("Ford"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeFordFocus = InsTreeItem(hTreeFord, (LPWSTR)TEXT("Focus"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeBMW = InsTreeItem(hTreeFossilFuel, (LPWSTR)TEXT("BMW"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeBMWX5 = InsTreeItem(hTreeBMW, (LPWSTR)TEXT("X5"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeToyota = InsTreeItem(hTreeHybrid, (LPWSTR)TEXT("Toyota"), (HTREEITEM)TVI_SORT);
	HTREEITEM hTreeToyotaPrius = InsTreeItem(hTreeToyota, (LPWSTR)TEXT("Prius"), (HTREEITEM)TVI_SORT);
}

VOID MenuInitializer(HWND hwnd) {
	HMENU hMenuBar = CreateMenu();
	HMENU hExit = CreateMenu();
	HMENU hFile = CreateMenu();
	HMENU hView = CreateMenu();
	HMENU hFont = CreateMenu();
	HMENU hKeys = CreateMenu();
	AppendMenu(hFile, MF_POPUP, MENU_KEYS, (LPCWSTR)TEXT("Горячие клавиши"));
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, (LPCWSTR)TEXT("Файл"));
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hView, (LPCWSTR)TEXT("Вид"));
	AppendMenu(hView, MF_POPUP, MENU_FONT_ID, (LPCWSTR)TEXT("Шрифт"));
	AppendMenu(hView, MF_POPUP, MENU_REPLACE_ID, (LPCWSTR)TEXT("Заменить"));
	AppendMenu(hMenuBar, MF_POPUP, MENU_ABOUT_ID, (LPCWSTR)TEXT("О программе"));
	AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFile, MF_STRING, MENU_EXIT_ID, (LPCWSTR)TEXT("Выход"));
	SetMenu(hwnd, hMenuBar);
}

VOID HotKeysInitializer(HWND hWnd)
{
	RegisterHotKey(hWnd, CTRL_A, MOD_CONTROL, 0x41);
	RegisterHotKey(hWnd, CTRL_K, MOD_CONTROL, 0x4B);
	RegisterHotKey(hWnd, CTRL_F, MOD_CONTROL, 0x46);
	RegisterHotKey(hWnd, CTRL_R, MOD_CONTROL, 0x52);
}

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)TEXT("О приложении"));
		SetDlgItemText(hwnd, IDOK, (LPCWSTR)TEXT("Понятно"));
		SetDlgItemText(hwnd, IDNO, (LPCWSTR)TEXT("Лабораторная работа №2: создание оконного приложения"));
		break;
	}
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDOK)
			EndDialog(hwnd, 0);
	}
	}
	return FALSE;
}

BOOL CALLBACK HotKeysDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)TEXT("Горячие клавиши"));
		SetDlgItemText(hwnd, IDOK, (LPCWSTR)TEXT("ОК"));
		SetDlgItemText(hwnd, IDYES, (LPCWSTR)TEXT("Выход: настраивается вручную\nО приложении: CTRL+E\nШрифт: CTRL+F\nЗаменить: CTRL+R\nГорячие клавиши: CTRL+K"));
		break;
	}
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDOK)
			EndDialog(hwnd, 0);
	}
	}
	return FALSE;
}

VOID AboutWindow(HWND hWnd) {
	DialogBoxParam(handle, MAKEINTRESOURCE(IDD_DIALOG), hWnd, AboutDlgProc, 0);
}

VOID HotKeysWindow(HWND hWnd)
{
	DialogBoxParam(handle, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, HotKeysDlgProc, 0);
}

VOID OnMouseWheel(HWND hwnd, int xPos, int yPos, int zDelta, UINT fwKeys)
{
	DestroyWindow(Button);
	if (BUTTON_Y < 130)
		BUTTON_Y = 130;
	if (BUTTON_Y > 180)
		BUTTON_Y = 180;
	BUTTON_Y = BUTTON_Y + 5 * zDelta / WHEEL_DELTA;
	Button = CreateWindow((LPCWSTR)"BUTTON", (LPCWSTR)"Назначить", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 340, BUTTON_Y, 80, 30, hWnd, (HMENU)SET_BUTTON, handle, NULL);
}

VOID RemoveRecords() {
	if (NULL != TreeView_GetSelection(m_TreeView))
	{
		int mbResult = MessageBox(hWnd, (LPCWSTR)TEXT("Действительно удалить?"), (LPCWSTR)TEXT("SampleWin32"), MB_YESNO | MB_ICONQUESTION);
		if (mbResult == IDYES)
		{
			TreeView_DeleteItem(m_TreeView, TreeView_GetSelection(m_TreeView));
		}
	}
	else
	{
		MessageBox(hWnd, (LPCWSTR)TEXT("Вы не выбрали элемент для удаления"), (LPCWSTR)TEXT("Ошибка"), MB_OK | MB_ICONERROR);
	}
}

BOOL CALLBACK AddRecordsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)"Добавление записи");
		SetDlgItemText(hwnd, IDD_DIALOG2, (LPCWSTR)TEXT("Введите название записи"));
		break;
	}
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDCANCEL)
			EndDialog(hwnd, 0);
		if (LOWORD(wParam) == IDOK_ADDRECORDS)
		{
			GetDlgItemText(hwnd, IDC_EDIT1, Buf, 20);
			if (Buf[0] == 0)
				MessageBox(hWnd,(LPCWSTR)TEXT("Имя не должно быть пустым"), (LPCWSTR)TEXT("Ошибка"), MB_OK | MB_ICONERROR);
			else
			{
				EndDialog(hwnd, 0);
			}
		}
	}
	}
	return FALSE;
}

VOID AddRecords() {
	HTREEITEM selected = TreeView_GetSelection(m_TreeView);
	if (NULL != selected)
	{
		DialogBox(handle, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, AddRecordsProc);
		if (Buf[0] != 0)
		{
			HTREEITEM hItem = InsTreeItem(selected, Buf, (HTREEITEM)TVI_SORT);
		}
	}
	else
	{
		MessageBox(hWnd, (LPCWSTR)TEXT("Вы не выбрали родительский элемет"), (LPCWSTR)TEXT("Ошибка"), MB_OK | MB_ICONERROR);
	}
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT r;
	HDC hdc;
	switch (uMsg)
	{
		HANDLE_MSG(hWnd, WM_MOUSEWHEEL, OnMouseWheel);
	case WM_COMMAND:
		if (LOWORD(wParam) == MENU_REPLACE_ID)
			ReplaceWindow(hWnd);
		if (LOWORD(wParam) == MENU_EXIT_ID)
			Exit(hWnd);
		if (LOWORD(wParam) == MENU_ABOUT_ID)
			AboutWindow(hWnd);
		if (LOWORD(wParam) == MENU_FONT_ID)
			FontWindow(hWnd);
		if (LOWORD(wParam) == MENU_KEYS)
			HotKeysWindow(hWnd);
		if (LOWORD(wParam) == ADD_RECORD)
			AddRecords();
		if (LOWORD(wParam) == REMOVE_RECORDS)
			RemoveRecords();
		if (LOWORD(wParam) == SET_BUTTON)
		{
			/*INT wHotkey = LOBYTE(SendMessage(hwndHot, HKM_GETHOTKEY, 0, 0));
			UnregisterHotKey(hWnd, EXIT_KEY);
			RegisterHotKey(hWnd, EXIT_KEY, MOD_ALT | MOD_CONTROL, wHotkey);*/
			UnregisterHotKey(hWnd, EXIT_KEY);
			WORD val = LOWORD(SendMessage(hwndHot, HKM_GETHOTKEY, 0, 0));
			BYTE wHotkey = LOBYTE(val);
			BYTE flags = HIBYTE(val);
			RegisterHotKey(hWnd, EXIT_KEY, (flags & 0x0007), wHotkey);
			SetFocus(hWnd);
		}
		return 0;
	case WM_CLOSE:
	{
		Exit(hWnd);
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		MenuInitializer(hWnd);
		TreeViewInitializer(hWnd);
		HotKeysInitializer(hWnd);
		SetTimer(hWnd, TIMER_ID, 1000, NULL);
		return 0;
	case WM_HOTKEY:
		if (wParam == CTRL_A)
			AboutWindow(hWnd);
		if (wParam == EXIT_KEY)
			Exit(hWnd);
		if (wParam == CTRL_K)
			HotKeysWindow(hWnd);
		if (wParam == CTRL_F)
			FontWindow(hWnd);
		if (wParam == CTRL_R)
			ReplaceWindow(hWnd);
		return 0;
	case WM_KEYUP:
		r.left = 350;
		r.top = 400;
		r.right = 400;
		r.bottom = 450;
		hdc = GetDC(hWnd);
		FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(128, 128, 128)));
		return 0;
	case WM_KEYDOWN:
		r.left = 350;
		r.top = 400;
		r.right = 400;
		r.bottom = 450;
		hdc = GetDC(hWnd);
		FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
		MessageBeep(MB_ICONHAND);
		return 0;
	case WM_MOVING:
	{
		RECT rect;
		hdc = GetDC(hWnd);
		GetWindowRect(hWnd, &rect);
		TCHAR st[10] = TEXT("");
		TextOut(hdc, 320, 20, TEXT("X: "), 3);
		TextOut(hdc, 320, 40, TEXT("Y: "), 3);
		TextOut(hdc, 350, 20, TEXT("          "), 10);
		TextOut(hdc, 350, 40, TEXT("          "), 10);
		wsprintf(st, L"%d", rect.left);
		TextOut(hdc, 350, 20, st, wcslen(st));
		wsprintf(st, L"%d", rect.top);
		TextOut(hdc, 350, 40, st, wcslen(st));
		return 0;
	}
	case WM_PAINT:
	{
		HBRUSH bru = CreateSolidBrush(RGB(128, 128, 128));
		r.left = 350;
		r.top = 400;
		r.right = 400;
		r.bottom = 450;
		hdc = GetDC(hWnd);
		FillRect(hdc, &r, bru);
		r.left = 380;
		r.top = 300;
		r.right = 430;
		r.bottom = 350;
		hdc = GetDC(hWnd);
		FillRect(hdc, &r, bru);
		DeleteObject(bru);
		break;
	}
	case WM_MBUTTONDBLCLK:
		MessageBox(hWnd, TEXT("Осторожно, колёсико может сломаться!!!"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		return 0;
	case WM_MBUTTONDOWN:
	{
		HBRUSH bru = CreateSolidBrush(RGB(0, 0, 255));
		r.left = 380;
		r.top = 300;
		r.right = 430;
		r.bottom = 350;
		hdc = GetDC(hWnd);
		FillRect(hdc, &r, bru);
		MessageBeep(MB_ICONEXCLAMATION);
		DeleteObject(bru);
		return 0;
	}
	case WM_MBUTTONUP:
	{
		r.left = 380;
		r.top = 300;
		r.right = 430;
		r.bottom = 350;
		hdc = GetDC(hWnd);
		HBRUSH bru = CreateSolidBrush(RGB(128, 128, 128));
		FillRect(hdc, &r, bru);
		DeleteObject(bru);
		return 0;
	}
	case WM_CHAR:
	{
		WCHAR vowels[32] = { 'a', 'u', 'e', 'o', 'y', 'i','A', 'U', 'E', 'O', 'Y', 'I',TEXT('а'),TEXT('e'),TEXT('ё'),TEXT('и'),TEXT('о'),TEXT('у'),TEXT('ы'),TEXT('э'),TEXT('ю'),TEXT('я'),TEXT('А'),TEXT('Е'),TEXT('Ё'),TEXT('И'),TEXT('О'),TEXT('У'),TEXT('Ы'),TEXT('Э'),TEXT('Ю'),TEXT('Я') };
		WCHAR consonants[86] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z','B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z',TEXT('б'),TEXT('в'),TEXT('г'),TEXT('д'),TEXT('ж'),TEXT('з'),TEXT('й'),TEXT('к'),TEXT('л'),TEXT('м'),TEXT('н'),TEXT('п'),TEXT('р'),TEXT('c'),TEXT('т'),TEXT('ф'),TEXT('х'),TEXT('ц'),TEXT('ч'),TEXT('щ'),TEXT('ш'),TEXT('ъ'),TEXT('ь'),TEXT('Б'),TEXT('В'),TEXT('Г'),TEXT('Д'),TEXT('Ж'),TEXT('З'),TEXT('Й'),TEXT('К'),TEXT('Л'),TEXT('М'),TEXT('Н'),TEXT('П'),TEXT('Р'),TEXT('С'),TEXT('Т'),TEXT('Ф'),TEXT('Х'),TEXT('Ц'),TEXT('Ч'),TEXT('Щ'),TEXT('Ш'),TEXT('Ъ'),TEXT('Ь') };
		BOOL checking = FALSE;
		for (int i = 0; i < 32; i++)
		{
			if (vowels[i] == (WCHAR)wParam)
			{
				checking = TRUE;
				break;
			}
		}
		if (checking)
			MessageBox(hWnd, TEXT("Гласная буква"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		else
		{
			for (int i = 0; i < 86; i++)
			{
				if (consonants[i] == (WCHAR)wParam)
				{
					checking = TRUE;
					break;
				}
			}
			if (checking)
				MessageBox(hWnd, TEXT("Согласная буква"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		}
		/*hdc = GetDC(hWnd);
		char str[80] = "";
		TextOut(hdc, 430, 410, " ", 2);
		wsprintf(str, "%c", (char)wParam);*/
		/*TextOut(hdc, 430, 410, str, strlen(str));
		stri = stri + (char)wParam;
		TextOut(hdc, 430, 410, stri, strlen(stri));*/


		//GetDlgItemText(hDlg, IDC_EDIT1, str, 80);
		//str = (char)wParam;
		//SetDlgItemText(hDlg, IDC_EDIT2, wParam);



		return 0;
	}
	case WM_TIMER:
	{
		hdc = GetDC(hWnd);
		TCHAR s[5] = TEXT("");
		TextOut(hdc, 430, 430, L" ", 2);
		wsprintf(s, L"%d", time);
		TextOutW(hdc, 430, 430, s, wcslen(s));
		time++;
		return 0;
	}
	}
	if (uFindMsgString == uMsg)
	{
		OnFindMsgString(hWnd, (LPFINDREPLACE)lParam);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

VOID CreatingElements(HINSTANCE hInstance, HWND hWnd)
{
	Button = CreateWindow((LPCWSTR)TEXT("BUTTON"), (LPCWSTR)TEXT("Назначить"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 340, BUTTON_Y, 80, 30, hWnd, (HMENU)SET_BUTTON, hInstance, NULL);
	CreateWindow((LPCWSTR)TEXT("static"), (LPCWSTR)TEXT("Выход из программы: "), WS_CHILD | WS_VISIBLE, 320, 70, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
	hwndHot = CreateWindowEx(0, HOTKEY_CLASS, (LPCWSTR)TEXT(""), WS_CHILD | WS_VISIBLE, 320, 100, 100, 20, hWnd, NULL, hInstance, NULL);
	CreateWindow((LPCWSTR)TEXT("BUTTON"), (LPCWSTR)TEXT("Автомобили"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 10, 10, 300, 450, hWnd, (HMENU)-1, hInstance, NULL);
	m_TreeView = CreateWindowEx(0, (LPCWSTR)TEXT("SysTreeView32"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, 20, 30, 280, 420, hWnd, NULL, hInstance, NULL);
	TreeViewInitializer(hWnd);
	CreateWindow((LPCWSTR)TEXT("static"), (LPCWSTR)TEXT("Клавиатура"), WS_CHILD | WS_VISIBLE, 340, 370, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
	CreateWindowEx(0, (LPCWSTR)TEXT("Button"), (LPCWSTR)TEXT("Добавить запись"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 460, 120, 30, hWnd, (HMENU)ADD_RECORD, hInstance, NULL);
	CreateWindow((LPCWSTR)TEXT("Button"), (LPCWSTR)TEXT("Удалить запись"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 460, 120, 30, hWnd, (HMENU)REMOVE_RECORDS, hInstance, NULL);
	CreateWindow((LPCWSTR)TEXT("static"), (LPCWSTR)TEXT("Мышь"), WS_CHILD | WS_VISIBLE, 340, 260, 150, 30, hWnd, (HMENU)1, hInstance, NULL);
}

WNDCLASSEX RegisterWindowClass(HINSTANCE hInstance) {
	WNDCLASSEX window = { sizeof(WNDCLASSEX) };
	window.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	window.lpfnWndProc = WindowProcedure;
	window.hInstance = hInstance;
	window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	window.hCursor = LoadCursor(NULL, IDC_ARROW);
	window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	window.lpszMenuName = NULL;
	window.lpszClassName = TEXT("WindowClass");
	window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	return window;
}

BOOL PreTranslateMessage(LPMSG lpMsg)
{
	BOOL bRet = TRUE;
	if (!TranslateAccelerator(hWnd, NULL, lpMsg))
	{
		bRet = IsDialogMessage(hDlg, lpMsg);

		if (FALSE == bRet)
			bRet = IsDialogMessage(hFindDlg, lpMsg);
	}
	return bRet;
}

VOID MessagesProcessing() {
	MSG  msg;
	BOOL bRet;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != FALSE)
	{
		if (bRet == -1)
		{
		}
		else if (!PreTranslateMessage(&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	handle = hInstance;
	if (!RegisterClassEx(&RegisterWindowClass(hInstance)))
		return EXIT_FAILURE;
	LoadLibrary(TEXT("ComCtl32.dll"));
	hWnd = CreateWindowEx(0, TEXT("WindowClass"), (LPCWSTR)(TEXT("Моя прога")), WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU, 300, 100, 600, 600, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL)
		return EXIT_FAILURE;
	CreatingElements(hInstance, hWnd);
	ShowWindow(hWnd, nCmdShow);
	MessagesProcessing();
	return EXIT_SUCCESS;
}

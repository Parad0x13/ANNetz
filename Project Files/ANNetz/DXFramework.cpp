#include <iostream>

#include "DXFramework.h"
#include "global.h"

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

DXFramework::DXFramework() {
	//
}

DXFramework::~DXFramework() {
	UnregisterClass(applicationName, hInstance);
	hInstance = NULL;
}

bool DXFramework::initialize() {
	if (!createDXWindow("ANNetz DirectX Engine", WINDOW_POSX, WINDOW_POSY, SCREEN_WIDTH, SCREEN_HEIGHT))return false;
	return true;
}

void DXFramework::begin() {
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// Update and render functions
		}
	}
}

bool DXFramework::createDXWindow(char* windowTitle, int x, int y, int width, int height) {
	HWND hwnd;
	WNDCLASSEX wc;

	applicationName = windowTitle;
	hInstance = GetModuleHandle(NULL);

	// Setup the windows class with default settings
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "RegisterClassEx() failed", "Error", MB_OK);
		return false;
	}

	int nStyle = WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE
		| WS_CAPTION | WS_MINIMIZEBOX;

	// [TODO] Add fullscreen here
	//int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	//int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	hwnd = CreateWindowEx(WS_EX_APPWINDOW, windowTitle, windowTitle, nStyle, x, y, width, height, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL) {
		MessageBox(NULL, "CreateWindowEX() failed", "Error", MB_OK);
		PostQuitMessage(0);
		return false;
	}

	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	case WM_PAINT: {
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	}break;
	case WM_CLOSE: {
		PostQuitMessage(0);
		DestroyWindow(hwnd);
	}break;
	default: {
		return DefWindowProc(hwnd, message, wParam, lParam);
	}}

	return 0;
}
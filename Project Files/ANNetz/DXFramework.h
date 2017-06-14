#pragma once

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>


#define WIN32_LEAN_AND_MEAN

//copy from SDK c++ tutorials01 DX11 
#define IDS_APP_TITLE           103

#define IDR_MAINFRAME           128
#define IDD_TUTORIAL1_DIALOG    102
#define IDD_ABOUTBOX            103
#define IDM_ABOUT               104
#define IDM_EXIT                105
#define IDI_TUTORIAL1           107
#define IDI_SMALL               108
#define IDC_TUTORIAL1           109
#define IDC_MYICON              2
#define IDC_STATIC              -1
// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC                 130
#define _APS_NEXT_RESOURCE_VALUE    129
#define _APS_NEXT_COMMAND_VALUE     32771
#define _APS_NEXT_CONTROL_VALUE     1000
#define _APS_NEXT_SYMED_VALUE       110
#endif
#endif

class DXFramework {
public:
	DXFramework();
	~DXFramework();

	HINSTANCE               g_hInst = NULL;
	HWND                    g_hWnd = NULL;
	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*           g_pd3dDevice = NULL;
	ID3D11DeviceContext*    g_pImmediateContext = NULL;
	IDXGISwapChain*         g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_pRenderTargetView = NULL;

	HRESULT initDevice();
	void cleanupDevice();

	void render();
	bool initialize();
	void begin();

private:
	bool createDXWindow(char* windowTitle, int x, int y, int width, int height);
	
	char* applicationName;
	HINSTANCE hInstance;
};

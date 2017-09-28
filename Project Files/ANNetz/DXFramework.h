#pragma once

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include <vector>

#include "Utility.h"
#include "global.h"
#include "ComponentManager.h"

#define WIN32_LEAN_AND_MEAN

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

	int WINAPI wWinMain();

	void RefreshData(ComponentManager*);
	void RefreshPositions(ComponentManager*);
private:

	HINSTANCE                           g_hInst = NULL;
	HWND                                g_hWnd = NULL;
	D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*                       g_pd3dDevice = NULL;
	ID3D11DeviceContext*                g_pImmediateContext = NULL;
	IDXGISwapChain*                     g_pSwapChain = NULL;
	ID3D11RenderTargetView*             g_pRenderTargetView = NULL;
	ID3D11Texture2D*                    g_pDepthStencil = NULL;
	ID3D11DepthStencilView*             g_pDepthStencilView = NULL;
	ID3D11VertexShader*                 g_pVertexShader = NULL;
	ID3D11PixelShader*                  g_pPixelShader = NULL;
	ID3D11InputLayout*                  g_pVertexLayout = NULL;
	ID3D11Buffer*                       g_pVertexBuffer = NULL;
	ID3D11Buffer*                       g_pIndexBuffer = NULL;
	ID3D11Buffer*                       g_pCBNeverChanges = NULL;
	ID3D11Buffer*                       g_pCBChangeOnResize = NULL;
	ID3D11Buffer*                       g_pCBChangesEveryFrame = NULL;
	ID3D11ShaderResourceView*           g_pTextureRV = NULL;
	ID3D11SamplerState*                 g_pSamplerLinear = NULL;
	XMMATRIX                            g_World;
	XMMATRIX                            g_View;
	XMMATRIX                            g_Projection;
	XMFLOAT4                            g_vMeshColor = XMFLOAT4(0.7f, 0.7f, 0.7f, 1.0f);

	D3D11_BUFFER_DESC desc;

	HRESULT CompileShaderFromFile(LPCSTR, LPCSTR, LPCSTR, ID3DBlob**);
	HRESULT InitWindow();
	HRESULT InitDevice();
	void CleanupDevice();
	void Render();

	void createVB(int);
	void createIB(int);

	void refreshVBuffer(std::vector<SimpleVertex>);
};

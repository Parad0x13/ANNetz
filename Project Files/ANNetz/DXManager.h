#ifndef DX_MANAGER_H
#define DX_MANAGER_H

#include<dxgi.h>
#include<d3dcommon.h>
#include<d3d11.h>

class DXManager {
public:
	DXManager();
	~DXManager();

	bool initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen);
	void beginScene(float r, float g, float b, float a);
	void endSzene();

	void enableALphaBlending(bool enable);
	void enableZBuffer(bool enable);

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* getDeviceContext();

private:
	bool initalizeSwapChain(HWND hwnd, bool fullscreen, int screenWidth, int screenHeight, unsigned int numerator, unsigned int denominator);
	bool initializeDepthBuffer(int screenWidth, int screenHeight);
	bool initializeDepthStencilBuffer();
	bool initializeStencilView();
	bool initializeRasterizerState();
	void initalizeViewport(int screenWidth, int screenHeight);
	bool initializeAlphaBlending();
	bool initializeZBuffer();

	bool m_vsync_enabled;
	int m_videoCardMemory;
	char m_videoCardDescription[128];
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;

	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_detphStencilBuffer;

	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;

	ID3D11RasterizerState* m_rasterState;

	ID3D11BlendState* m_alphaEnabledBlendingState;
	ID3D11BlendState* m_alphaDisabledBlendingState;
	ID3D11DepthStencilState* m_depthDisabledStencilState;


};
#endif


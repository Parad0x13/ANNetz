#include "DXManager.h"


DXManager::DXManager() {
	m_swapChain = 0;
	m_device = 0;
	m_deviceContext = 0;

	m_renderTargetView = 0;
	m_detphStencilBuffer = 0;

	m_depthStencilState = 0;
	m_depthStencilView = 0;

	m_rasterState = 0;

	m_alphaEnabledBlendingState = 0;
	m_alphaDisabledBlendingState = 0;
	m_depthDisabledStencilState = 0;
}


DXManager::~DXManager() {
	//do release stuff here video tutorial 1 14:40
}

bool DXManager::initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen) {
	HRESULT result;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* adapterOutput;
	unsigned int numModes, numerator = 0, denominator = 0, stringLength;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;
	int error;
	ID3D10Texture2D* backBufferPtr;

	//store vsync settings;
	m_vsync_enabled = vsync;

	//create DirectX graphic interface factory
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(result)) return false;
	


	//use the factory to create an adapter for the primary graphic interface 
	result = factory->EnumAdapters(0, &adapter);
	if (FAILED(result)) return false;

	//enumarate the primary adapter output
	result = adapter->EnumOutputs(0, &adapterOutput);
	if (FAILED(result)) return false;

	//get the number of modes that fit the DXGI_FORMAT_R8G8B8A8_UNORM format for the adapter output
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(result)) return false;

	//create list to hold all possible modes for this monitor
	displayModeList = new DXGI_MODE_DESC[numModes];

	//fill the display mode list

	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result)) return false;

	for (int i = 0; i < numModes; i++) {
		if (displayModeList[i].Width == (unsigned int)screenWidth) {
			if (displayModeList[i].Height == (unsigned int)screenHeight) {
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	if (numerator == 0 && denominator == 0) return false;
	
	//get the adapter description
	result = adapter->GetDesc(&adapterDesc);

	//store the video card memory in mbs
	m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);

	//convert the name of the video card to a char array
	//weird error...
	//error = wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128);


	//release memory
	delete[] displayModeList;
	displayModeList = 0;

	adapterOutput->Release();
	adapterOutput = 0;

	adapter->Release();
	adapter = 0;

	factory->Release();
	factory = 0;
	return true;
}

void DXManager::beginScene(float r, float g, float b, float a) {
}

void DXManager::endSzene() {
}

void DXManager::enableALphaBlending(bool enable) {
}

void DXManager::enableZBuffer(bool enable) {
}

ID3D11Device * DXManager::GetDevice() {
	return nullptr;
}

ID3D11DeviceContext * DXManager::getDeviceContext() {
	return nullptr;
}

bool DXManager::initalizeSwapChain(HWND hwnd, bool fullscreen, int screenWidth, int screenHeight, unsigned int numerator, unsigned int denominator) {
	return false;
}

bool DXManager::initializeDepthBuffer(int screenWidth, int screenHeight) {
	return false;
}

bool DXManager::initializeDepthStencilBuffer() {
	return false;
}

bool DXManager::initializeStencilView() {
	return false;
}

bool DXManager::initializeRasterizerState() {
	return false;
}

void DXManager::initalizeViewport(int screenWidth, int screenHeight) {
}

bool DXManager::initializeAlphaBlending() {
	return false;
}

bool DXManager::initializeZBuffer() {
	return false;
}

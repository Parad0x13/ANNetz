#pragma once

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT 800

#define WINDOW_POSX 200
#define WINDOW_POSY 200

const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;

struct SimpleVertex {
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
};

struct ConstantBuffer {
	XMMATRIX mWorld;
	XMMATRIX mView;
	XMMATRIX mProjection;
};
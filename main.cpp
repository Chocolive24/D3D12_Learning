#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h> // For CommandLineToArgvW
 
// The min/max macros conflict with like-named member functions.
// Only use std::min and std::max defined in <algorithm>.
#if defined(min)
#undef min
#endif
 
#if defined(max)
#undef max
#endif
 
// In order to define a function called CreateWindow, the Windows macro needs to
// be undefined.
#if defined(CreateWindow)
#undef CreateWindow
#endif
 
// Windows Runtime Library. Needed for Microsoft::WRL::ComPtr<> template class.
#include <wrl.h>
using namespace Microsoft::WRL;

// DirectX 12 specific headers.
#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
 
// D3D12 extension library.
#include <directx/d3d12.h>

// STL Headers
#include <algorithm>
#include <cassert>
#include <chrono>

#include <iostream>

#include "helpers.h"

int main() {
  // The number of swap chain back buffers.
  const uint8_t g_NumFrames = 3;
  // Use WARP adapter
  bool g_UseWarp = false;

  constexpr uint32_t g_ClientWidth = 1280;
  constexpr uint32_t g_ClientHeight = 720;

  // Set to true once the DX12 objects have been initialized.
  bool g_IsInitialized = false;

  // Window handle.
  HWND g_hWnd;
  // Window rectangle (used to toggle fullscreen state).
  RECT g_WindowRect;

  // DirectX 12 Objects
  ComPtr<ID3D12Device2> g_Device;
  ComPtr<ID3D12CommandQueue> g_CommandQueue;
  ComPtr<IDXGISwapChain4> g_SwapChain;
  ComPtr<ID3D12Resource> g_BackBuffers[g_NumFrames];
  ComPtr<ID3D12GraphicsCommandList> g_CommandList;
  ComPtr<ID3D12CommandAllocator> g_CommandAllocators[g_NumFrames];
  ComPtr<ID3D12DescriptorHeap> g_RTVDescriptorHeap;
  UINT g_RTVDescriptorSize;
  UINT g_CurrentBackBufferIndex;

  // Synchronization objects
  ComPtr<ID3D12Fence> g_Fence;
  uint64_t g_FenceValue = 0;
  uint64_t g_FrameFenceValues[g_NumFrames] = {};
  HANDLE g_FenceEvent;

  std::cout << "Hello World" << std::endl;
	return 0;
}
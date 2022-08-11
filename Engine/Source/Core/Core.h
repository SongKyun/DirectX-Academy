#pragma once

// �����ڵ� ����.
#ifndef UNICODE
#define UNICODE
#endif

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

// �̺�å.
// C4251 ������ ���� ��Ȱ��ȭ.
#pragma warning(disable: 4251)
#pragma warning(disable: 4244)
#pragma warning(disable: 4172)

#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

// includes.
#include <Windows.h>
#include <d3d11.h>				// dx11.
#include <d3dcompiler.h>		// ���̴� ������/�ε�.
#include <comdef.h>

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>				// smart pointer.
#include <algorithm>
#include <sstream>				// ���ڿ� ���տ� ����. String.Format().
#include <filesystem>

#include <cassert>				// assert �Լ� ����� ����. Ư�� ������ �������� ������ �ߴ�.

// Ÿ�� ������.
using uint32 = unsigned int;
using uint64 = unsigned __int64;
using int64 = __int64;
using uint8 = unsigned char;

// ���� �Լ�.
// COM ��ü �޸� ������ �� ����� �Լ�.
// ���� Type���� COM Ÿ�Կ� ��ü�� ����.
template<typename Type>
void SafeRelease(Type t)
{
	if (t != nullptr)
	{
		t->Release();
		t = nullptr;
	}
}
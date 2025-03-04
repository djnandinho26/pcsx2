// SPDX-FileCopyrightText: 2002-2025 PCSX2 Dev Team
// SPDX-License-Identifier: GPL-3.0+

#pragma once

#include "GS/Renderers/Common/GSDevice.h"
#include "GS/GSExtra.h"

#if defined(_DEBUG) || defined(PCSX2_DEVBUILD)
#define ENABLE_OGL_DEBUG // enable GS debug logging
//#define ENABLE_TRACE_REG // print GS reg write
//#define ENABLE_EXTRA_LOG // print extra log
#endif

// Note: GL messages are present in common code, so in all renderers.

#ifdef ENABLE_OGL_DEBUG
	#define GL_CACHE(...) g_gs_device->InsertDebugMessage(GSDevice::DebugMessageCategory::Cache, __VA_ARGS__)
#else
	#define GL_CACHE(...) (void)(0)
#endif

#if defined(ENABLE_OGL_DEBUG) && defined(ENABLE_TRACE_REG)
	#define GL_REG(...) g_gs_device->InsertDebugMessage(GSDevice::DebugMessageCategory::Reg, __VA_ARGS__)
#else
	#define GL_REG(...) (void)(0)
#endif

#if defined(ENABLE_OGL_DEBUG) && defined(_DEBUG)
	#define GL_DBG(...) g_gs_device->InsertDebugMessage(GSDevice::DebugMessageCategory::Debug, __VA_ARGS__)
#else
	#define GL_DBG(...) (void)(0)
#endif

#if defined(ENABLE_OGL_DEBUG)
	struct GLAutoPop
	{
		~GLAutoPop()
		{
			g_gs_device->PopDebugGroup();
		}
	};

	#define GL_PUSH_(...) g_gs_device->PushDebugGroup(__VA_ARGS__)
	#define GL_PUSH(...)  g_gs_device->PushDebugGroup(__VA_ARGS__); GLAutoPop gl_auto_pop;
	#define GL_POP()      g_gs_device->PopDebugGroup()
	#define GL_INS(...)   g_gs_device->InsertDebugMessage(GSDevice::DebugMessageCategory::Message, __VA_ARGS__)
	#define GL_PERF(...)  g_gs_device->InsertDebugMessage(GSDevice::DebugMessageCategory::Performance, __VA_ARGS__)
#else
	#define GL_PUSH_(...) (void)(0)
	#define GL_PUSH(...) (void)(0)
	#define GL_POP()     (void)(0)
	#define GL_INS(...)  (void)(0)
	#define GL_PERF(...) (void)(0)
#endif

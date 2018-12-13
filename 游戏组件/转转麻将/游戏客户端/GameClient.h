#pragma once

#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h”
#endif

#include "Resource.h"
#include "GameClientDlg.h"

//////////////////////////////////////////////////////////////////////////

//应用程序类
class CGameClientApp : public CGameFrameApp
{
	//函数定义
public:
	//构造函数
	CGameClientApp();
	//析构函数
	virtual ~CGameClientApp();

	//继承函数
public:
	//创建主窗口
	virtual CGameFrameEngine * GetGameFrameEngine(DWORD dwSDKVersion) { return new CGameClientDlg; }
};

//应用程序对象
extern CGameClientApp theApp;

#ifdef VIDEO_GAME
//视频对象
extern CVideoServiceManager g_VedioServiceManager;
#endif

//////////////////////////////////////////////////////////////////////////

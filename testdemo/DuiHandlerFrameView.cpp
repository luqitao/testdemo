#include "StdAfx.h"
#include "DuiHandlerFrameView.h"

//////////////////////////////////////////////////////////////
// CDuiHandlerFrameView

CDuiHandlerFrameView::CDuiHandlerFrameView(void) : CDuiHandler()
{
	m_uTimerAni = 0;
	m_nAniIndex = 0;
}

CDuiHandlerFrameView::~CDuiHandlerFrameView(void)
{
}

// 初始化
void CDuiHandlerFrameView::OnInit()
{
}

// DUI定时器事件处理
void CDuiHandlerFrameView::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

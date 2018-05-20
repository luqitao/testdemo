#include "StdAfx.h"
#include "DuiHandlerOscilloscope.h"

//////////////////////////////////////////////////////////////
// CDuiHandlerOscilloscope

CDuiHandlerOscilloscope::CDuiHandlerOscilloscope(void) : CDuiHandler()
{
	m_uTimerAni = 0;
	m_nAniIndex = 0;
}

CDuiHandlerOscilloscope::~CDuiHandlerOscilloscope(void)
{
}

// 初始化
void CDuiHandlerOscilloscope::OnInit()
{
}

// DUI定时器事件处理
void CDuiHandlerOscilloscope::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

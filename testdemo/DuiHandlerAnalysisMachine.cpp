#include "StdAfx.h"
#include "DuiHandlerAnalysisMachine.h"

//////////////////////////////////////////////////////////////
// CDuiHandlerAnalysisMachine

CDuiHandlerAnalysisMachine::CDuiHandlerAnalysisMachine(void) : CDuiHandler()
{
	m_uTimerAni = 0;
	m_nAniIndex = 0;
}

CDuiHandlerAnalysisMachine::~CDuiHandlerAnalysisMachine(void)
{
}

// 初始化
void CDuiHandlerAnalysisMachine::OnInit()
{
}

// DUI定时器事件处理
void CDuiHandlerAnalysisMachine::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

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

// ��ʼ��
void CDuiHandlerAnalysisMachine::OnInit()
{
}

// DUI��ʱ���¼�����
void CDuiHandlerAnalysisMachine::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

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

// ��ʼ��
void CDuiHandlerOscilloscope::OnInit()
{
}

// DUI��ʱ���¼�����
void CDuiHandlerOscilloscope::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

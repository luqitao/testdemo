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

// ��ʼ��
void CDuiHandlerFrameView::OnInit()
{
}

// DUI��ʱ���¼�����
void CDuiHandlerFrameView::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

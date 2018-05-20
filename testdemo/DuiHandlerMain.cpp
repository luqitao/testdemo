#include "StdAfx.h"
#include "DuiHandlerMain.h"
#include "registry.h"
#include "DuiHandlerFrameView.h"
#include "DuiHandlerAnalysisMachine.h"
#include "DuiHandlerOscilloscope.h"

//////////////////////////////////////////////////////////////
// CDuiHandlerMain

CDuiHandlerMain::CDuiHandlerMain(void) : CDuiHandler()
{
	m_pDlg = NULL;
	m_uTimerAni = 0;
	m_nAniIndex = 0;
	//m_pPanel = NULL;
}

CDuiHandlerMain::~CDuiHandlerMain(void)
{
}

// ��ʼ��
void CDuiHandlerMain::OnInit()
{
	
	// ��tabҳ'֡����'ע���¼��������
	CDuiHandlerFrameView* pDuiHandlerFrameView = new CDuiHandlerFrameView();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerFrameView, _T("tab.FrameView"));
	pDuiHandlerFrameView->OnInit();
	// ��tabҳ'������'ע���¼��������
	CDuiHandlerAnalysisMachine* pDuiHandlerAnalysisMachine = new CDuiHandlerAnalysisMachine();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerAnalysisMachine, _T("tab.AnalysisMachine"));
	pDuiHandlerAnalysisMachine->OnInit();
	// ��tabҳ'ʾ����'ע���¼��������
	CDuiHandlerOscilloscope* pDuiHandlerOscilloscope = new CDuiHandlerOscilloscope();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerOscilloscope, _T("tab.Oscilloscope"));
	pDuiHandlerOscilloscope->OnInit();

	// ����������ʱ��
	m_uTimerAni = DuiSystem::AddDuiTimer(500);

	// ��ʼ��ԭ���ؼ�
	CDuiNativeWnd* pNativeWnd = (CDuiNativeWnd*)GetControl(_T("nativewnd_1"));
	if(pNativeWnd)
	{
		CIPAddressCtrl* pIPAddress = new CIPAddressCtrl;
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL;
		pIPAddress->Create(dwStyle, CRect(0, 0, 0, 0), pNativeWnd->GetPaintWnd(), 1111);
		pIPAddress->ShowWindow(SW_NORMAL);
		pNativeWnd->SetNativeWnd(pIPAddress);
		
	}
}

// Ƥ����Ϣ����(ʵ��Ƥ���ı���ͻ�ȡ)
LRESULT CDuiHandlerMain::OnDuiMsgSkin(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if(Msg == MSG_GET_SKIN_TYPE)	// ��ȡSkin����
	{
		CRegistryUtil reg(HKEY_CURRENT_USER);
		int nBkType = reg.GetDWordValue(NULL, REG_CONFIG_SUBKEY, REG_CONFIG_BKTYPE);
		*(int*)wParam = nBkType;
		return TRUE;
	}else
	if(Msg == MSG_GET_SKIN_VALUE)	// ��ȡSkinֵ
	{
		CRegistryUtil reg(HKEY_CURRENT_USER);
		if(wParam == BKTYPE_IMAGE_RESOURCE)
		{
			*(int*)lParam = reg.GetDWordValue(NULL, REG_CONFIG_SUBKEY, REG_CONFIG_BKPIC_RES);
			return TRUE;
		}else
		if(wParam == BKTYPE_COLOR)
		{
			*(COLORREF*)lParam = reg.GetDWordValue(NULL, REG_CONFIG_SUBKEY, REG_CONFIG_BKCOLOR);
			return TRUE;
		}else
		if(wParam == BKTYPE_IMAGE_FILE)
		{
			*(CString*)lParam = reg.GetStringValue(NULL, REG_CONFIG_SUBKEY, REG_CONFIG_BKPIC_FILE);
			return TRUE;
		}
	}else
	if(Msg == MSG_SET_SKIN_VALUE)	// ����Skinֵ
	{
		CRegistryUtil reg(HKEY_CURRENT_USER);
		reg.SetDWordValue(HKEY_CURRENT_USER, REG_CONFIG_SUBKEY, REG_CONFIG_BKTYPE, wParam);
		if(wParam == BKTYPE_IMAGE_RESOURCE)
		{
			reg.SetDWordValue(HKEY_CURRENT_USER, REG_CONFIG_SUBKEY, REG_CONFIG_BKPIC_RES, lParam);
		}else
		if(wParam == BKTYPE_COLOR)
		{
			reg.SetDWordValue(HKEY_CURRENT_USER, REG_CONFIG_SUBKEY, REG_CONFIG_BKCOLOR, lParam);
		}else
		if(wParam == BKTYPE_IMAGE_FILE)
		{
			CString* pstrImgFile = (CString*)lParam;
			reg.SetStringValue(HKEY_CURRENT_USER, REG_CONFIG_SUBKEY, REG_CONFIG_BKPIC_FILE, *pstrImgFile);
		}
		return TRUE;
	}
	return FALSE;
}


// DUI��ʱ���¼�����
void CDuiHandlerMain::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

// ���̼���Ϣ����
LRESULT CDuiHandlerMain::OnDuiMsgInterprocess(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	// �����в���,���Զ������в������д���,Ҳ����ֱ����ʾ������
	DUI_INTERPROCESS_MSG* pInterMsg = (DUI_INTERPROCESS_MSG*)lParam;
	CString strCmd = pInterMsg->wInfo;
	if(!strCmd.IsEmpty())
	{
		DuiSystem::DuiMessageBox(NULL, L"ִ���������в���:" + strCmd);
	}else
	{
		CDlgBase* pDlg = DuiSystem::Instance()->GetDuiDialog(L"dlg_main");
		if(pDlg)
		{
			pDlg->SetForegroundWindow();
			pDlg->ShowWindow(SW_NORMAL);
			pDlg->ShowWindow(SW_SHOW);
			pDlg->BringWindowToTop();
		}
	}
	return TRUE;
}

LRESULT CDuiHandlerMain::OnDuiMsgBtnConnectX(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	DuiSystem::DuiMessageBox(NULL, L"�����豸�ɹ�");
	BOOL bIsDisable = TRUE;
	SetDisable(strName, bIsDisable);
	SetDisable(_T("btndisconnect"), !bIsDisable);
	return TRUE;
}

LRESULT CDuiHandlerMain::OnDuiMsgBtnDisConnectX(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	DuiSystem::DuiMessageBox(NULL, L"�Ͽ��豸�ɹ�");
	BOOL bIsDisable = TRUE;
	SetDisable(strName, bIsDisable);
	SetDisable(_T("btnconnect"), !bIsDisable);
	return TRUE;
}
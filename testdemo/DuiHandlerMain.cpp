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

// 初始化
void CDuiHandlerMain::OnInit()
{
	
	// 将tab页'帧总览'注册事件处理对象
	CDuiHandlerFrameView* pDuiHandlerFrameView = new CDuiHandlerFrameView();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerFrameView, _T("tab.FrameView"));
	pDuiHandlerFrameView->OnInit();
	// 将tab页'分析仪'注册事件处理对象
	CDuiHandlerAnalysisMachine* pDuiHandlerAnalysisMachine = new CDuiHandlerAnalysisMachine();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerAnalysisMachine, _T("tab.AnalysisMachine"));
	pDuiHandlerAnalysisMachine->OnInit();
	// 将tab页'示波器'注册事件处理对象
	CDuiHandlerOscilloscope* pDuiHandlerOscilloscope = new CDuiHandlerOscilloscope();
	DuiSystem::RegisterHandler(m_pDlg, pDuiHandlerOscilloscope, _T("tab.Oscilloscope"));
	pDuiHandlerOscilloscope->OnInit();

	// 启动动画定时器
	m_uTimerAni = DuiSystem::AddDuiTimer(500);

	// 初始化原生控件
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

// 皮肤消息处理(实现皮肤的保存和获取)
LRESULT CDuiHandlerMain::OnDuiMsgSkin(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if(Msg == MSG_GET_SKIN_TYPE)	// 获取Skin类型
	{
		CRegistryUtil reg(HKEY_CURRENT_USER);
		int nBkType = reg.GetDWordValue(NULL, REG_CONFIG_SUBKEY, REG_CONFIG_BKTYPE);
		*(int*)wParam = nBkType;
		return TRUE;
	}else
	if(Msg == MSG_GET_SKIN_VALUE)	// 获取Skin值
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
	if(Msg == MSG_SET_SKIN_VALUE)	// 设置Skin值
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


// DUI定时器事件处理
void CDuiHandlerMain::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

// 进程间消息处理
LRESULT CDuiHandlerMain::OnDuiMsgInterprocess(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	// 命令行参数,可以对命令行参数进行处理,也可以直接显示主窗口
	DUI_INTERPROCESS_MSG* pInterMsg = (DUI_INTERPROCESS_MSG*)lParam;
	CString strCmd = pInterMsg->wInfo;
	if(!strCmd.IsEmpty())
	{
		DuiSystem::DuiMessageBox(NULL, L"执行了命令行参数:" + strCmd);
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
	DuiSystem::DuiMessageBox(NULL, L"连接设备成功");
	BOOL bIsDisable = TRUE;
	SetDisable(strName, bIsDisable);
	SetDisable(_T("btndisconnect"), !bIsDisable);
	return TRUE;
}

LRESULT CDuiHandlerMain::OnDuiMsgBtnDisConnectX(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	DuiSystem::DuiMessageBox(NULL, L"断开设备成功");
	BOOL bIsDisable = TRUE;
	SetDisable(strName, bIsDisable);
	SetDisable(_T("btnconnect"), !bIsDisable);
	return TRUE;
}
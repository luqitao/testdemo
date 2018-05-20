// DuiVision message handler base class
#pragma once
class CDuiObject;

// DUI�¼�������
class CDuiHandlerMain : public CDuiHandler
{
public:
	CDuiHandlerMain(void);
	virtual ~CDuiHandlerMain(void);

	void SetDialog(CDlgBase* pDlg) { m_pDlg = pDlg; };
	//void SetDuiPanel(CDuiPanel* pPanel) { m_pPanel = pPanel; }

	virtual void OnInit();

	// Ƥ��ѡ����Ϣ����
	LRESULT OnDuiMsgSkin(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);

	// ���̼���Ϣ����
	LRESULT	OnDuiMsgInterprocess(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);

	LRESULT OnDuiMsgBtnConnectX(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnDuiMsgBtnDisConnectX(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);

	//virtual LRESULT OnDuiMessage(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
	virtual void OnTimer(UINT uTimerID, CString strTimerName);

	CDlgBase* m_pDlg;
	//CDuiPanel*	m_pPanel;
	UINT m_uTimerAni;	// ������ʱ��
	int m_nAniIndex;	// ��������

	// ��Ϣ������
	DUI_DECLARE_MESSAGE_BEGIN(CDuiHandlerMain)
		DUI_CONTROL_ID_MESSAGE(APP_IPC, OnDuiMsgInterprocess)
		DUI_CONTROL_NAME_MESSAGE(NAME_SKIN_WND, OnDuiMsgSkin)

		DUI_CONTROL_NAMEMSG_MESSAGE(_T("btnconnect"), MSG_BUTTON_DOWN, OnDuiMsgBtnConnectX)
		DUI_CONTROL_NAMEMSG_MESSAGE(_T("btndisconnect"), MSG_BUTTON_DOWN, OnDuiMsgBtnDisConnectX)
	DUI_DECLARE_MESSAGE_END()
};

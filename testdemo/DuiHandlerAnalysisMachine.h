// DuiVision message handler base class
#pragma once
class CDuiObject;

// DUI事件处理类
class CDuiHandlerAnalysisMachine : public CDuiHandler
{
public:
	CDuiHandlerAnalysisMachine(void);
	virtual ~CDuiHandlerAnalysisMachine(void);

	virtual void OnInit();
	
	//virtual LRESULT OnDuiMessage(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
	virtual void OnTimer(UINT uTimerID, CString strTimerName);

	UINT m_uTimerAni;	// 动画定时器
	int m_nAniIndex;	// 动画索引

	// 消息处理定义
	DUI_DECLARE_MESSAGE_BEGIN(CDuiHandlerAnalysisMachine)
	DUI_DECLARE_MESSAGE_END()
};

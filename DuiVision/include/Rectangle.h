// ���ľ��οؼ�
#pragma once
#include "ControlBase.h"

class CRectangle : public CControlBase
{
	DUIOBJ_DECLARE_CLASS_NAME(CRectangle, _T("rect"))
public:
	CRectangle(HWND hWnd, CDuiObject* pDuiObject);
	CRectangle(HWND hWnd, CDuiObject* pDuiObject, UINT uControlID, CRect rc, 
		Color clr = Color(254, 255, 255, 255), BOOL bIsVisible = TRUE);
	virtual ~CRectangle(void);

protected:
	virtual void DrawControl(CDC &dc, CRect rcUpdate);

public:
	int			m_nTransparentType;			// ͸����������
	int			m_nBeginTransparent;	// ��䲿����ʼ͸����
	int			m_nEndTransparent;		// ��䲿����ֹ͸����
	int			m_nFrameWidth;			// �߿����
	int			m_nDashStyle;			// �߿�����
	Color		m_clr;					// �����ɫ
	Color		m_clrFrame;				// �߿���ɫ

	DUI_DECLARE_ATTRIBUTES_BEGIN()
		DUI_COLOR_ATTRIBUTE("color", m_clr, FALSE)
		DUI_COLOR_ATTRIBUTE(_T("crframe"), m_clrFrame, FALSE)
		DUI_ENUM_ATTRIBUTE(_T("dashstyle"), UINT, TRUE)
            DUI_ENUM_VALUE(_T("solid"), DashStyleSolid)
            DUI_ENUM_VALUE(_T("dash"), DashStyleDash)
            DUI_ENUM_VALUE(_T("dot"), DashStyleDot)
			DUI_ENUM_VALUE(_T("dashdot"), DashStyleDashDot)
            DUI_ENUM_VALUE(_T("dotdot"), DashStyleDashDotDot)
            DUI_ENUM_VALUE(_T("custom"), DashStyleCustom)
        DUI_ENUM_END(m_nDashStyle)
		DUI_INT_ATTRIBUTE("frame-width", m_nFrameWidth, FALSE)
		DUI_ENUM_ATTRIBUTE(_T("transparent-type"), UINT, TRUE)
            DUI_ENUM_VALUE(_T("horizontal"), TRANSPARENT_HORIZONTAL)
            DUI_ENUM_VALUE(_T("vertical"), TRANSPARENT_VERTICAL)
        DUI_ENUM_END(m_nTransparentType)
		DUI_INT_ATTRIBUTE("begin-transparent", m_nBeginTransparent, FALSE)
		DUI_INT_ATTRIBUTE("end-transparent", m_nEndTransparent, FALSE)
	DUI_DECLARE_ATTRIBUTES_END()
};
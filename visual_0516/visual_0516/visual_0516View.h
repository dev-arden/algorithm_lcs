
// visual_0516View.h : Cvisual_0516View Ŭ������ �������̽�
//

#pragma once


class Cvisual_0516View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cvisual_0516View();
	DECLARE_DYNCREATE(Cvisual_0516View)

// Ư���Դϴ�.
public:
	Cvisual_0516Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~Cvisual_0516View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // visual_0516View.cpp�� ����� ����
inline Cvisual_0516Doc* Cvisual_0516View::GetDocument() const
   { return reinterpret_cast<Cvisual_0516Doc*>(m_pDocument); }
#endif



// visual0516View.h : Cvisual0516View Ŭ������ �������̽�
//

#pragma once


class Cvisual0516View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cvisual0516View();
	DECLARE_DYNCREATE(Cvisual0516View)

// Ư���Դϴ�.
public:
	Cvisual0516Doc* GetDocument() const;

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
	virtual ~Cvisual0516View();
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
public:
	afx_msg void OnRotation();
	afx_msg void OnRotation2();
};

#ifndef _DEBUG  // visual0516View.cpp�� ����� ����
inline Cvisual0516Doc* Cvisual0516View::GetDocument() const
   { return reinterpret_cast<Cvisual0516Doc*>(m_pDocument); }
#endif


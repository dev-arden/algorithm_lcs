
// ����ó��_�ǽ�View.h : C����ó��_�ǽ�View Ŭ������ �������̽�
//

#pragma once


class C����ó��_�ǽ�View : public CView
{
protected: // serialization������ ��������ϴ�.
	C����ó��_�ǽ�View();
	DECLARE_DYNCREATE(C����ó��_�ǽ�View)

// Ư���Դϴ�.
public:
	C����ó��_�ǽ�Doc* GetDocument() const;

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
	virtual ~C����ó��_�ǽ�View();
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

#ifndef _DEBUG  // ����ó��_�ǽ�View.cpp�� ����� ����
inline C����ó��_�ǽ�Doc* C����ó��_�ǽ�View::GetDocument() const
   { return reinterpret_cast<C����ó��_�ǽ�Doc*>(m_pDocument); }
#endif


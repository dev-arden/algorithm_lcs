
// ����ó��_Ȯ�����View.h : C����ó��_Ȯ�����View Ŭ������ �������̽�
//

#pragma once


class C����ó��_Ȯ�����View : public CView
{
protected: // serialization������ ��������ϴ�.
	C����ó��_Ȯ�����View();
	DECLARE_DYNCREATE(C����ó��_Ȯ�����View)

// Ư���Դϴ�.
public:
	C����ó��_Ȯ�����Doc* GetDocument() const;

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
	virtual ~C����ó��_Ȯ�����View();
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
	afx_msg void OnOnnearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedian();
};

#ifndef _DEBUG  // ����ó��_Ȯ�����View.cpp�� ����� ����
inline C����ó��_Ȯ�����Doc* C����ó��_Ȯ�����View::GetDocument() const
   { return reinterpret_cast<C����ó��_Ȯ�����Doc*>(m_pDocument); }
#endif


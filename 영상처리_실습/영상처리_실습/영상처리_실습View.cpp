
// ����ó��_�ǽ�View.cpp : C����ó��_�ǽ�View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "����ó��_�ǽ�.h"
#endif

#include "����ó��_�ǽ�Doc.h"
#include "����ó��_�ǽ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ó��_�ǽ�View

IMPLEMENT_DYNCREATE(C����ó��_�ǽ�View, CView)

BEGIN_MESSAGE_MAP(C����ó��_�ǽ�View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C����ó��_�ǽ�View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C����ó��_�ǽ�View ����/�Ҹ�

C����ó��_�ǽ�View::C����ó��_�ǽ�View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C����ó��_�ǽ�View::~C����ó��_�ǽ�View()
{
}

BOOL C����ó��_�ǽ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C����ó��_�ǽ�View �׸���

void C����ó��_�ǽ�View::OnDraw(CDC* /*pDC*/)
{
	C����ó��_�ǽ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// C����ó��_�ǽ�View �μ�


void C����ó��_�ǽ�View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C����ó��_�ǽ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C����ó��_�ǽ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C����ó��_�ǽ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void C����ó��_�ǽ�View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C����ó��_�ǽ�View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C����ó��_�ǽ�View ����

#ifdef _DEBUG
void C����ó��_�ǽ�View::AssertValid() const
{
	CView::AssertValid();
}

void C����ó��_�ǽ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ó��_�ǽ�Doc* C����ó��_�ǽ�View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ó��_�ǽ�Doc)));
	return (C����ó��_�ǽ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ó��_�ǽ�View �޽��� ó����

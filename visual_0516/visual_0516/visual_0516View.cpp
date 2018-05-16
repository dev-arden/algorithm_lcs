
// visual_0516View.cpp : Cvisual_0516View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "visual_0516.h"
#endif

#include "visual_0516Doc.h"
#include "visual_0516View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cvisual_0516View

IMPLEMENT_DYNCREATE(Cvisual_0516View, CView)

BEGIN_MESSAGE_MAP(Cvisual_0516View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cvisual_0516View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cvisual_0516View ����/�Ҹ�

Cvisual_0516View::Cvisual_0516View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cvisual_0516View::~Cvisual_0516View()
{
}

BOOL Cvisual_0516View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cvisual_0516View �׸���

void Cvisual_0516View::OnDraw(CDC* /*pDC*/)
{
	Cvisual_0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cvisual_0516View �μ�


void Cvisual_0516View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cvisual_0516View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cvisual_0516View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cvisual_0516View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cvisual_0516View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cvisual_0516View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cvisual_0516View ����

#ifdef _DEBUG
void Cvisual_0516View::AssertValid() const
{
	CView::AssertValid();
}

void Cvisual_0516View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cvisual_0516Doc* Cvisual_0516View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cvisual_0516Doc)));
	return (Cvisual_0516Doc*)m_pDocument;
}
#endif //_DEBUG


// Cvisual_0516View �޽��� ó����

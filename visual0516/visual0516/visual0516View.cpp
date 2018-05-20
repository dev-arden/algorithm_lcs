
// visual0516View.cpp : Cvisual0516View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "visual0516.h"
#endif

#include "visual0516Doc.h"
#include "visual0516View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cvisual0516View

IMPLEMENT_DYNCREATE(Cvisual0516View, CView)

BEGIN_MESSAGE_MAP(Cvisual0516View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cvisual0516View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ROTATION, &Cvisual0516View::OnRotation)
	ON_COMMAND(ID_ROTATION2, &Cvisual0516View::OnRotation2)
END_MESSAGE_MAP()

// Cvisual0516View ����/�Ҹ�

Cvisual0516View::Cvisual0516View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cvisual0516View::~Cvisual0516View()
{
}

BOOL Cvisual0516View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cvisual0516View �׸���

void Cvisual0516View::OnDraw(CDC* pDC)
{
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++)
	{
		for (j = 0; j < pDoc->m_width; j++)
		{
			R = pDoc->m_InputImage[i*pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	for (i = 0; i < pDoc->m_Re_height; i++)
	{
		for (j = 0; j < pDoc->m_Re_width; j++)
		{
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// Cvisual0516View �μ�


void Cvisual0516View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cvisual0516View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cvisual0516View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cvisual0516View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cvisual0516View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cvisual0516View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cvisual0516View ����

#ifdef _DEBUG
void Cvisual0516View::AssertValid() const
{
	CView::AssertValid();
}

void Cvisual0516View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cvisual0516Doc* Cvisual0516View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cvisual0516Doc)));
	return (Cvisual0516Doc*)m_pDocument;
}
#endif //_DEBUG


// Cvisual0516View �޽��� ó����


void Cvisual0516View::OnRotation()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate();
	Invalidate(TRUE);
}


void Cvisual0516View::OnRotation2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate2();
	Invalidate(TRUE);
}

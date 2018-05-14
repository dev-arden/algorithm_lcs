
// ����ó��_Ȯ�����View.cpp : C����ó��_Ȯ�����View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "����ó��_Ȯ�����.h"
#endif

#include "����ó��_Ȯ�����Doc.h"
#include "����ó��_Ȯ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ó��_Ȯ�����View

IMPLEMENT_DYNCREATE(C����ó��_Ȯ�����View, CView)

BEGIN_MESSAGE_MAP(C����ó��_Ȯ�����View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C����ó��_Ȯ�����View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ONNEAREST, &C����ó��_Ȯ�����View::OnOnnearest)
	ON_COMMAND(ID_BILINEAR, &C����ó��_Ȯ�����View::OnBilinear)
	ON_COMMAND(ID_MEDIAN, &C����ó��_Ȯ�����View::OnMedian)
END_MESSAGE_MAP()

// C����ó��_Ȯ�����View ����/�Ҹ�

C����ó��_Ȯ�����View::C����ó��_Ȯ�����View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C����ó��_Ȯ�����View::~C����ó��_Ȯ�����View()
{
}

BOOL C����ó��_Ȯ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// C����ó��_Ȯ�����View �׸���

void C����ó��_Ȯ�����View::OnDraw(CDC* pDC)
{
	C����ó��_Ȯ�����Doc* pDoc = GetDocument();
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


// C����ó��_Ȯ�����View �μ�


void C����ó��_Ȯ�����View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C����ó��_Ȯ�����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void C����ó��_Ȯ�����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void C����ó��_Ȯ�����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void C����ó��_Ȯ�����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C����ó��_Ȯ�����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C����ó��_Ȯ�����View ����

#ifdef _DEBUG
void C����ó��_Ȯ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C����ó��_Ȯ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ó��_Ȯ�����Doc* C����ó��_Ȯ�����View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ó��_Ȯ�����Doc)));
	return (C����ó��_Ȯ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ó��_Ȯ�����View �޽��� ó����


void C����ó��_Ȯ�����View::OnOnnearest()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	C����ó��_Ȯ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->Onnearest();
	Invalidate(TRUE);
}


void C����ó��_Ȯ�����View::OnBilinear()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	C����ó��_Ȯ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();
	Invalidate(TRUE);

}


void C����ó��_Ȯ�����View::OnMedian()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	C����ó��_Ȯ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();
	Invalidate(TRUE);
}

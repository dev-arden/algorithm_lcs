
// visual0516View.cpp : Cvisual0516View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cvisual0516View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ROTATION, &Cvisual0516View::OnRotation)
	ON_COMMAND(ID_ROTATION2, &Cvisual0516View::OnRotation2)
END_MESSAGE_MAP()

// Cvisual0516View 생성/소멸

Cvisual0516View::Cvisual0516View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cvisual0516View::~Cvisual0516View()
{
}

BOOL Cvisual0516View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cvisual0516View 그리기

void Cvisual0516View::OnDraw(CDC* pDC)
{
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// Cvisual0516View 인쇄


void Cvisual0516View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cvisual0516View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cvisual0516View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cvisual0516View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// Cvisual0516View 진단

#ifdef _DEBUG
void Cvisual0516View::AssertValid() const
{
	CView::AssertValid();
}

void Cvisual0516View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cvisual0516Doc* Cvisual0516View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cvisual0516Doc)));
	return (Cvisual0516Doc*)m_pDocument;
}
#endif //_DEBUG


// Cvisual0516View 메시지 처리기


void Cvisual0516View::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate();
	Invalidate(TRUE);
}


void Cvisual0516View::OnRotation2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cvisual0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotate2();
	Invalidate(TRUE);
}

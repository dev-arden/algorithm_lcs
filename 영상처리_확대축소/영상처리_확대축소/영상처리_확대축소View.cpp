
// 영상처리_확대축소View.cpp : C영상처리_확대축소View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "영상처리_확대축소.h"
#endif

#include "영상처리_확대축소Doc.h"
#include "영상처리_확대축소View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C영상처리_확대축소View

IMPLEMENT_DYNCREATE(C영상처리_확대축소View, CView)

BEGIN_MESSAGE_MAP(C영상처리_확대축소View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C영상처리_확대축소View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ONNEAREST, &C영상처리_확대축소View::OnOnnearest)
	ON_COMMAND(ID_BILINEAR, &C영상처리_확대축소View::OnBilinear)
	ON_COMMAND(ID_MEDIAN, &C영상처리_확대축소View::OnMedian)
END_MESSAGE_MAP()

// C영상처리_확대축소View 생성/소멸

C영상처리_확대축소View::C영상처리_확대축소View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C영상처리_확대축소View::~C영상처리_확대축소View()
{
}

BOOL C영상처리_확대축소View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C영상처리_확대축소View 그리기

void C영상처리_확대축소View::OnDraw(CDC* pDC)
{
	C영상처리_확대축소Doc* pDoc = GetDocument();
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


// C영상처리_확대축소View 인쇄


void C영상처리_확대축소View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C영상처리_확대축소View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C영상처리_확대축소View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C영상처리_확대축소View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void C영상처리_확대축소View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C영상처리_확대축소View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C영상처리_확대축소View 진단

#ifdef _DEBUG
void C영상처리_확대축소View::AssertValid() const
{
	CView::AssertValid();
}

void C영상처리_확대축소View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C영상처리_확대축소Doc* C영상처리_확대축소View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C영상처리_확대축소Doc)));
	return (C영상처리_확대축소Doc*)m_pDocument;
}
#endif //_DEBUG


// C영상처리_확대축소View 메시지 처리기


void C영상처리_확대축소View::OnOnnearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	C영상처리_확대축소Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->Onnearest();
	Invalidate(TRUE);
}


void C영상처리_확대축소View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	C영상처리_확대축소Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();
	Invalidate(TRUE);

}


void C영상처리_확대축소View::OnMedian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	C영상처리_확대축소Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();
	Invalidate(TRUE);
}

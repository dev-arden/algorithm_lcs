
// visual_0516View.cpp : Cvisual_0516View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cvisual_0516View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cvisual_0516View 생성/소멸

Cvisual_0516View::Cvisual_0516View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cvisual_0516View::~Cvisual_0516View()
{
}

BOOL Cvisual_0516View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cvisual_0516View 그리기

void Cvisual_0516View::OnDraw(CDC* /*pDC*/)
{
	Cvisual_0516Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cvisual_0516View 인쇄


void Cvisual_0516View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cvisual_0516View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cvisual_0516View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cvisual_0516View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// Cvisual_0516View 진단

#ifdef _DEBUG
void Cvisual_0516View::AssertValid() const
{
	CView::AssertValid();
}

void Cvisual_0516View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cvisual_0516Doc* Cvisual_0516View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cvisual_0516Doc)));
	return (Cvisual_0516Doc*)m_pDocument;
}
#endif //_DEBUG


// Cvisual_0516View 메시지 처리기

// Dialogdegree.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "visual0516.h"
#include "Dialogdegree.h"
#include "afxdialogex.h"


// CDialogdegree 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDialogdegree, CDialogEx)

CDialogdegree::CDialogdegree(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, degree(0)
{

}

CDialogdegree::~CDialogdegree()
{
}

void CDialogdegree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITdegree, degree);
}


BEGIN_MESSAGE_MAP(CDialogdegree, CDialogEx)
END_MESSAGE_MAP()


// CDialogdegree 메시지 처리기입니다.

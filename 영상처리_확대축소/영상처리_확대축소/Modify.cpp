// Modify.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "영상처리_확대축소.h"
#include "Modify.h"
#include "afxdialogex.h"


// CModify 대화 상자입니다.

IMPLEMENT_DYNAMIC(CModify, CDialogEx)

CModify::CModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, modify(0)
{

}

CModify::~CModify()
{
}

void CModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_modify, modify);
}


BEGIN_MESSAGE_MAP(CModify, CDialogEx)
END_MESSAGE_MAP()


// CModify 메시지 처리기입니다.

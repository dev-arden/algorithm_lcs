// Modify.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����ó��_Ȯ�����.h"
#include "Modify.h"
#include "afxdialogex.h"


// CModify ��ȭ �����Դϴ�.

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


// CModify �޽��� ó�����Դϴ�.

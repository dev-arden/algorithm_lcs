// Dialogdegree.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "visual0516.h"
#include "Dialogdegree.h"
#include "afxdialogex.h"


// CDialogdegree ��ȭ �����Դϴ�.

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


// CDialogdegree �޽��� ó�����Դϴ�.

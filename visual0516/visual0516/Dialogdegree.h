#pragma once


// CDialogdegree ��ȭ �����Դϴ�.

class CDialogdegree : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogdegree)

public:
	CDialogdegree(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDialogdegree();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int degree;
};

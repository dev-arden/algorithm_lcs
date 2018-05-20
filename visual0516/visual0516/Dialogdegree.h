#pragma once


// CDialogdegree 대화 상자입니다.

class CDialogdegree : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogdegree)

public:
	CDialogdegree(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDialogdegree();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int degree;
};

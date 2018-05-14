
// ����ó��_Ȯ�����Doc.h : C����ó��_Ȯ�����Doc Ŭ������ �������̽�
//


#pragma once


class C����ó��_Ȯ�����Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	C����ó��_Ȯ�����Doc();
	DECLARE_DYNCREATE(C����ó��_Ȯ�����Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	int m_Re_size;
	int m_Re_height;
	int m_Re_width;
	unsigned char* m_OutputImage;

	int m_width;
	int m_height;
	int m_size;
	unsigned char*m_InputImage;


// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~C����ó��_Ȯ�����Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	void Onnearest();
	double** OnMaskProcess(unsigned char *Target, double Mask[3][3]);
	double** OnScale(double **Target, int height, int width);
	double** Image2DMem(int height, int width);
	double** m_tempImage;
	void OnBilinear();
	void OnMedianSub();
	void OnBubbleSort(double * A, int MAX);
	void OnSwap(double *a, double *b);
};

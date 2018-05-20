
// visual0516Doc.h : Cvisual0516Doc Ŭ������ �������̽�
//


#pragma once


class Cvisual0516Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	Cvisual0516Doc();
	DECLARE_DYNCREATE(Cvisual0516Doc)

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
	virtual ~Cvisual0516Doc();
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
	void OnRotate();
	double** OnMaskProcess(unsigned char *Target, double Mask[3][3]);
	double** OnScale(double **Target, int height, int width);
	double** Image2DMem(int height, int width);
	double** m_tempImage;
	void OnRotate2();
	void Interpolate(unsigned char* m_OutputImage);
};


// 영상처리_확대축소Doc.h : C영상처리_확대축소Doc 클래스의 인터페이스
//


#pragma once


class C영상처리_확대축소Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	C영상처리_확대축소Doc();
	DECLARE_DYNCREATE(C영상처리_확대축소Doc)

// 특성입니다.
public:

// 작업입니다.
public:
	int m_Re_size;
	int m_Re_height;
	int m_Re_width;
	unsigned char* m_OutputImage;

	int m_width;
	int m_height;
	int m_size;
	unsigned char*m_InputImage;


// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~C영상처리_확대축소Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
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

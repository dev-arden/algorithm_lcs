
// 영상처리_확대축소Doc.cpp : C영상처리_확대축소Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "영상처리_확대축소.h"
#endif

#include "영상처리_확대축소Doc.h"

#include <propkey.h>
#include "Modify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C영상처리_확대축소Doc

IMPLEMENT_DYNCREATE(C영상처리_확대축소Doc, CDocument)

BEGIN_MESSAGE_MAP(C영상처리_확대축소Doc, CDocument)
END_MESSAGE_MAP()


// C영상처리_확대축소Doc 생성/소멸

C영상처리_확대축소Doc::C영상처리_확대축소Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

C영상처리_확대축소Doc::~C영상처리_확대축소Doc()
{
}

BOOL C영상처리_확대축소Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// C영상처리_확대축소Doc serialization

void C영상처리_확대축소Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void C영상처리_확대축소Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void C영상처리_확대축소Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void C영상처리_확대축소Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C영상처리_확대축소Doc 진단

#ifdef _DEBUG
void C영상처리_확대축소Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C영상처리_확대축소Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C영상처리_확대축소Doc 명령


BOOL C영상처리_확대축소Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
	if (File.GetLength() == 32 * 32)
	{
		m_height = 32;
		m_width = 32;
	}
	else if (File.GetLength() == 64 * 64)
	{
		m_height = 64;
		m_width = 64;
	}
	else if (File.GetLength() == 128 * 128)
	{
		m_height = 128;
		m_width = 128;
	}
	else if (File.GetLength() == 256 * 256)
	{
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512)
	{
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480)
	{
		m_height = 640;
		m_width = 480;
	}
	else if (File.GetLength() == 176 * 144)
	{
		m_height = 144;
		m_width = 176;
	}
	else if (File.GetLength() == 176 * 216)
	{
		m_height = 216;
		m_width = 176;
	}
	else
	{
		AfxMessageBox(L"Not Support Lmage Size", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	m_size = m_width * m_height;
	m_InputImage = new unsigned char[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_InputImage[i] = 255;
	}
	File.Read(m_InputImage, m_size);
	File.Close();


	return TRUE;
}





void C영상처리_확대축소Doc::Onnearest()
{
	CModify dlg;
	dlg.DoModal();
	int i, j;
	int ZoomRate = dlg.modify; // 영상확대배율
	double **tempArray;
	m_Re_height = int(ZoomRate*m_height); // 확대된영상의높이
	m_Re_width = int(ZoomRate*m_width); // 확대된영상의너비
	m_Re_size = m_Re_height * m_Re_width;
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
		}
	}
	for (i = 0; i< m_Re_height; i++) {
		for (j = 0; j< m_Re_width; j++) {
			tempArray[i][j] = m_tempImage[i / ZoomRate][j / ZoomRate];
			// 이웃한화소를이용한보간
		}
	}
	for (i = 0; i< m_Re_height; i++) {
		for (j = 0; j< m_Re_width; j++) {
			m_OutputImage[i* m_Re_width + j] = (unsigned char)tempArray[i][j];
		}
	}
}


double** C영상처리_확대축소Doc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{
	int i, j, n, m;
	double **tempInputImage, **tempOutputImage, S = 0.0;
	tempInputImage = Image2DMem(m_height + 2, m_width + 2);
	// 입력값을위한메모리할당
	tempOutputImage = Image2DMem(m_height, m_width);
	// 출력값을위한메모리할당
	// 1차원입력영상M_InputImage[]의값을2차원배열tempInputImage[][]에할당
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)Target[i * m_width + j];
		}
	}
	// 회선연산
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			for (n = 0; n<3; n++) {
				for (m = 0; m<3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			} // 회선마스크의크기만큼이동하면서값을누적
			tempOutputImage[i][j] = S; // 누적된값을출력메모리에저장
			S = 0.0; // 다음블록으로이동하면누적값을초기화
		}
	}
	return tempOutputImage;
}


double** C영상처리_확대축소Doc::OnScale(double **Target, int height, int width)
{
	// 정규화를위한함수
	int i, j;
	double min, max;
	min = max = Target[0][0];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] <= min)
				min = Target[i][j];
		}
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] >= max)
				max = Target[i][j];
		}
	}
	max = max - min;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			Target[i][j] = (Target[i][j] - min) * (255. / max);
		}
	}
	return Target;
}

double** C영상처리_확대축소Doc::Image2DMem(int height, int width)
{ // 2차원메모리할당을위한함수
	double** temp;
	int i, j;
	temp = new double *[height];
	for (i = 0; i<height; i++) {
		temp[i] = new double[width];
	}
	for (i = 0; i<height; i++) {
		for (j = 0; j<width; j++) {
			temp[i][j] = 0.0;
		}
	} // 할당된2차원메모리를초기화
	return temp;
}


void C영상처리_확대축소Doc::OnBilinear()
{
	int i, j, point, i_H, i_W;
	unsigned char newValue;
	double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
	double C1, C2, C3, C4;
	m_Re_height = (int)(m_height * ZoomRate); // 확대된영상의높이
	m_Re_width = (int)(m_width * ZoomRate); // 확대된영상의너비
	m_Re_size = m_Re_height * m_Re_width;
	m_tempImage = Image2DMem(m_height, m_width);
	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
		}
	}

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			r_H = i / ZoomRate;
			r_W = j / ZoomRate;
			i_H = (int)floor(r_H);
			i_W = (int)floor(r_W);
			s_H = r_H - i_H; // 수평방향거리계산
			s_W = r_W - i_W; // 수직방향거리계산
			if (i_H < 0 || i_H >= (m_height - 1) || i_W < 0
				|| i_W >= (m_width - 1))
			{
				point = i* m_Re_width + j;
				m_OutputImage[point] = 255;
			}

			else
			{
				C1 = (double)m_tempImage[i_H][i_W];
				C2 = (double)m_tempImage[i_H][i_W + 1];
				C3 = (double)m_tempImage[i_H + 1][i_W + 1];
				C4 = (double)m_tempImage[i_H + 1][i_W];
				newValue = (unsigned char)(C1*(1 - s_H)*(1 - s_W)
					+ C2*s_W*(1 - s_H) + C3*s_W*s_H + C4*(1 - s_W)*s_H);
				point = i* m_Re_width + j;
				m_OutputImage[point] = newValue;
			}

		}
	}
}



void C영상처리_확대축소Doc::OnMedianSub()
{
	CModify dlg;
	dlg.DoModal();
	int i, j, n, m, M = dlg.modify, index = 0; // M = 서브샘플링비율
	double *Mask, Value;
	Mask = new double[M*M]; // 마스크의크기결정
	m_Re_height = (m_height + 1) / M;
	m_Re_width = (m_width + 1) / M;
	m_Re_size = m_Re_height* m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = Image2DMem(m_height + 1, m_width + 1);
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
		}
	}
	for (i = 0; i<m_height - 1; i = i + M) {
		for (j = 0; j<m_width - 1; j = j + M) {
			for (n = 0; n<M; n++) {
				for (m = 0; m<M; m++) {
					Mask[n*M + m] = m_tempImage[i + n][j + m];
					// 입력영상을블록으로잘라마스크배열에저장
				}
			}
			OnBubbleSort(Mask, M*M); // 마스크에저장된값을정렬
			Value = Mask[(int)(M*M / 2)]; // 정렬된값중가운데값을선택
			m_OutputImage[index] = (unsigned char)Value;
			// 가운데값을출력
			index++;
		}
	}
}



void C영상처리_확대축소Doc::OnBubbleSort(double * A, int MAX)
{
	int i, j;
	for (i = 0; i<MAX; i++) {
		for (j = 0; j<MAX - 1; j++) {
			if (A[j] > A[j + 1]) {
				OnSwap(&A[j], &A[j + 1]);
			}
		}
	}
}


void C영상처리_확대축소Doc::OnSwap(double *a, double *b)
{ // 데이터교환함수
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

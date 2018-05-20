
// visual0516Doc.cpp : Cvisual0516Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "visual0516.h"
#endif

#include "visual0516Doc.h"

#include <propkey.h>
#include "Dialogdegree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cvisual0516Doc

IMPLEMENT_DYNCREATE(Cvisual0516Doc, CDocument)

BEGIN_MESSAGE_MAP(Cvisual0516Doc, CDocument)
END_MESSAGE_MAP()


// Cvisual0516Doc 생성/소멸

Cvisual0516Doc::Cvisual0516Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

Cvisual0516Doc::~Cvisual0516Doc()
{
}

BOOL Cvisual0516Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// Cvisual0516Doc serialization

void Cvisual0516Doc::Serialize(CArchive& ar)
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
void Cvisual0516Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void Cvisual0516Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cvisual0516Doc::SetSearchContent(const CString& value)
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

// Cvisual0516Doc 진단

#ifdef _DEBUG
void Cvisual0516Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cvisual0516Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cvisual0516Doc 명령


BOOL Cvisual0516Doc::OnOpenDocument(LPCTSTR lpszPathName)
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



void Cvisual0516Doc::OnRotate()
{
	int i, j, CenterH, CenterW, newH, newW, degree = 45;
	// degree = 회전할각도
	double Radian, PI, **tempArray, Value;
	m_Re_height = m_height; // 회전된영상의높이
	m_Re_width = m_width; // 회전된영상의너비
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	PI = 3.14159265358979; // 회전각을위한PI 값
	Radian = (double)degree*PI / 180.0; // degree 값을radian으로변경
	CenterH = m_height / 2; // 영상의중심좌표
	CenterW = m_width / 2; // 영상의중심좌표
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
		}
	}
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			// 회전 변환 행렬을 이용하여 회전하게 될 좌표 값 계산
			newH = (int)((i - CenterH)*cos(Radian)
				- (j - CenterW)*sin(Radian) + CenterH);
			newW = (int)((i - CenterH)*sin(Radian)
				+ (j - CenterW)*sin(Radian) + CenterW);
			if (newH < 0 || newH >= m_height) {
				// 회전된 좌표가 출력 영상을 위한 배열 값을 넘어갈 때
				Value = 0;
			}
			else if (newW < 0 || newW >= m_width) {
				// 회전된 좌표가 출력 영상을 위한 배열 값을 넘어갈 때
				Value = 0;
			}
			else {
				Value = m_tempImage[newH][newW];
			}
			tempArray[i][j] = Value;
		}
	}

	for (i = 0; i< m_Re_height; i++) 
	{
		for (j = 0; j< m_Re_width; j++) 
		{
			m_OutputImage[i* m_Re_width + j]= (unsigned char)tempArray[i][j];
		}
	}
	delete[] m_tempImage;
	delete[] tempArray;
}


double** Cvisual0516Doc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
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


double** Cvisual0516Doc::OnScale(double **Target, int height, int width)
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


double** Cvisual0516Doc::Image2DMem(int height, int width)
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


void Cvisual0516Doc::OnRotate2()
{
	CDialogdegree dlg;
	dlg.DoModal();
	int center_x = m_width / 2;
	int center_y = m_height / 2;
	int new_x;
	int new_y;
	double pi = 3.141592;
	double seta; // seta값계산
	seta = pi / (180.0 / dlg.degree); // 헤더값복사


	m_Re_height = m_height; // 회전된영상의높이
	m_Re_width = m_width; // 회전된영상의너비
	m_Re_size = m_width * m_height;
	m_OutputImage = new unsigned char[m_Re_size];


	// -->
	// <--배경색으로초기화
	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i*m_Re_width + j] = 0; // 0: 검정색
		}
	}

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			new_x = (i - center_y) *sin(seta) + (j - center_x) *cos(seta) + center_x;
			new_y = (i - center_y) *cos(seta) - (j - center_x) *sin(seta) + center_y;
			if (new_x < 0)continue;
			if (new_x >= m_width)continue;
			if (new_y < 0)continue;
			if (new_y >= m_height)continue;
			m_OutputImage[new_y * m_width + new_x] = m_InputImage[i*m_width + j];


		}
	}
	Interpolate(m_OutputImage);
}

void Cvisual0516Doc::Interpolate(unsigned char* m_OutputImage)
{
	int left_pixval = 0;
	int right_pixval = 0;

	for (int i = 0; i<m_Re_height; i++)
	{
		for (int j = 0; j<m_Re_width; j++) 
		{
			if (j == 0) 
			{
				right_pixval = m_OutputImage[i*m_Re_width + j + 1];
				left_pixval = right_pixval;
			}
			else if (j == m_Re_width - 1) 
			{
				left_pixval = m_OutputImage[i*m_Re_width + j - 1];
				right_pixval = left_pixval;
			}
			else 
			{
				left_pixval = m_OutputImage[i*m_Re_width + j - 1];
				right_pixval = m_OutputImage[i*m_Re_width + j + 1];
			}
			if (m_OutputImage[i*m_Re_width + j] == 0 && left_pixval != 0 && right_pixval != 0) 
			{
				m_OutputImage[i*m_Re_width + j] = (left_pixval + right_pixval) / 2;
			}
		}
	}
}


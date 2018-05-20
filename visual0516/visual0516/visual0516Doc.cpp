
// visual0516Doc.cpp : Cvisual0516Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// Cvisual0516Doc ����/�Ҹ�

Cvisual0516Doc::Cvisual0516Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

Cvisual0516Doc::~Cvisual0516Doc()
{
}

BOOL Cvisual0516Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// Cvisual0516Doc serialization

void Cvisual0516Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void Cvisual0516Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void Cvisual0516Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// Cvisual0516Doc ����

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


// Cvisual0516Doc ���


BOOL Cvisual0516Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
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
	// degree = ȸ���Ұ���
	double Radian, PI, **tempArray, Value;
	m_Re_height = m_height; // ȸ���ȿ����ǳ���
	m_Re_width = m_width; // ȸ���ȿ����ǳʺ�
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	PI = 3.14159265358979; // ȸ����������PI ��
	Radian = (double)degree*PI / 180.0; // degree ����radian���κ���
	CenterH = m_height / 2; // �������߽���ǥ
	CenterW = m_width / 2; // �������߽���ǥ
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
		}
	}
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			// ȸ�� ��ȯ ����� �̿��Ͽ� ȸ���ϰ� �� ��ǥ �� ���
			newH = (int)((i - CenterH)*cos(Radian)
				- (j - CenterW)*sin(Radian) + CenterH);
			newW = (int)((i - CenterH)*sin(Radian)
				+ (j - CenterW)*sin(Radian) + CenterW);
			if (newH < 0 || newH >= m_height) {
				// ȸ���� ��ǥ�� ��� ������ ���� �迭 ���� �Ѿ ��
				Value = 0;
			}
			else if (newW < 0 || newW >= m_width) {
				// ȸ���� ��ǥ�� ��� ������ ���� �迭 ���� �Ѿ ��
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
	// �Է°������Ѹ޸��Ҵ�
	tempOutputImage = Image2DMem(m_height, m_width);
	// ��°������Ѹ޸��Ҵ�
	// 1�����Է¿���M_InputImage[]�ǰ���2�����迭tempInputImage[][]���Ҵ�
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)Target[i * m_width + j];
		}
	}
	// ȸ������
	for (i = 0; i<m_height; i++) {
		for (j = 0; j<m_width; j++) {
			for (n = 0; n<3; n++) {
				for (m = 0; m<3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			} // ȸ������ũ��ũ�⸸ŭ�̵��ϸ鼭��������
			tempOutputImage[i][j] = S; // �����Ȱ�����¸޸𸮿�����
			S = 0.0; // ������������̵��ϸ鴩�������ʱ�ȭ
		}
	}
	return tempOutputImage;
}


double** Cvisual0516Doc::OnScale(double **Target, int height, int width)
{
	// ����ȭ�������Լ�
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
{ // 2�����޸��Ҵ��������Լ�
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
	} // �Ҵ��2�����޸𸮸��ʱ�ȭ
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
	double seta; // seta�����
	seta = pi / (180.0 / dlg.degree); // ���������


	m_Re_height = m_height; // ȸ���ȿ����ǳ���
	m_Re_width = m_width; // ȸ���ȿ����ǳʺ�
	m_Re_size = m_width * m_height;
	m_OutputImage = new unsigned char[m_Re_size];


	// -->
	// <--���������ʱ�ȭ
	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i*m_Re_width + j] = 0; // 0: ������
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


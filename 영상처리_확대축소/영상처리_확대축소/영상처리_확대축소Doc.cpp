
// ����ó��_Ȯ�����Doc.cpp : C����ó��_Ȯ�����Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "����ó��_Ȯ�����.h"
#endif

#include "����ó��_Ȯ�����Doc.h"

#include <propkey.h>
#include "Modify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C����ó��_Ȯ�����Doc

IMPLEMENT_DYNCREATE(C����ó��_Ȯ�����Doc, CDocument)

BEGIN_MESSAGE_MAP(C����ó��_Ȯ�����Doc, CDocument)
END_MESSAGE_MAP()


// C����ó��_Ȯ�����Doc ����/�Ҹ�

C����ó��_Ȯ�����Doc::C����ó��_Ȯ�����Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

C����ó��_Ȯ�����Doc::~C����ó��_Ȯ�����Doc()
{
}

BOOL C����ó��_Ȯ�����Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// C����ó��_Ȯ�����Doc serialization

void C����ó��_Ȯ�����Doc::Serialize(CArchive& ar)
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
void C����ó��_Ȯ�����Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C����ó��_Ȯ�����Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void C����ó��_Ȯ�����Doc::SetSearchContent(const CString& value)
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

// C����ó��_Ȯ�����Doc ����

#ifdef _DEBUG
void C����ó��_Ȯ�����Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C����ó��_Ȯ�����Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C����ó��_Ȯ�����Doc ���


BOOL C����ó��_Ȯ�����Doc::OnOpenDocument(LPCTSTR lpszPathName)
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





void C����ó��_Ȯ�����Doc::Onnearest()
{
	CModify dlg;
	dlg.DoModal();
	int i, j;
	int ZoomRate = dlg.modify; // ����Ȯ�����
	double **tempArray;
	m_Re_height = int(ZoomRate*m_height); // Ȯ��ȿ����ǳ���
	m_Re_width = int(ZoomRate*m_width); // Ȯ��ȿ����ǳʺ�
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
			// �̿���ȭ�Ҹ��̿��Ѻ���
		}
	}
	for (i = 0; i< m_Re_height; i++) {
		for (j = 0; j< m_Re_width; j++) {
			m_OutputImage[i* m_Re_width + j] = (unsigned char)tempArray[i][j];
		}
	}
}


double** C����ó��_Ȯ�����Doc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
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


double** C����ó��_Ȯ�����Doc::OnScale(double **Target, int height, int width)
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

double** C����ó��_Ȯ�����Doc::Image2DMem(int height, int width)
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


void C����ó��_Ȯ�����Doc::OnBilinear()
{
	int i, j, point, i_H, i_W;
	unsigned char newValue;
	double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
	double C1, C2, C3, C4;
	m_Re_height = (int)(m_height * ZoomRate); // Ȯ��ȿ����ǳ���
	m_Re_width = (int)(m_width * ZoomRate); // Ȯ��ȿ����ǳʺ�
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
			s_H = r_H - i_H; // �������Ÿ����
			s_W = r_W - i_W; // ��������Ÿ����
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



void C����ó��_Ȯ�����Doc::OnMedianSub()
{
	CModify dlg;
	dlg.DoModal();
	int i, j, n, m, M = dlg.modify, index = 0; // M = ������ø�����
	double *Mask, Value;
	Mask = new double[M*M]; // ����ũ��ũ�����
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
					// �Է¿�������������߶󸶽�ũ�迭������
				}
			}
			OnBubbleSort(Mask, M*M); // ����ũ������Ȱ�������
			Value = Mask[(int)(M*M / 2)]; // ���ĵȰ��߰����������
			m_OutputImage[index] = (unsigned char)Value;
			// ����������
			index++;
		}
	}
}



void C����ó��_Ȯ�����Doc::OnBubbleSort(double * A, int MAX)
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


void C����ó��_Ȯ�����Doc::OnSwap(double *a, double *b)
{ // �����ͱ�ȯ�Լ�
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

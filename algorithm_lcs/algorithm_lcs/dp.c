#define _CRT_SECURE_NO_WARNINGS//visual studio 2015���ʹ� ���ȹ����� ���� scanf ���� �ۼ��� ���־�� ��.
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

unsigned int i, j, m, n, procession[100][100]; //i, j, m, n ������ ������ �迭 procession ����
char x[100], y[100], show_lcs[100][100]; //����ڰ� �Է��� ���ڿ��� �����ϴ� �迭 x,y�� ���� ���� �κ� ����(lcs)�� ���ڿ��� ������ ������ �迭 show_lcs����

int lcs()//lcs�� ���̸� �����ϴ� �Լ�
{
	m = strlen(x); //����ڰ� �Է��� ���ڿ��� ������ �迭 x�� ���̸� m�� ����  
	n = strlen(y); //����ڰ� �Է��� ���ڿ��� ������ �迭 y�� ���̸� n�� ����


	for (i = 0; i <= m; i++) //���� 0�� �ڸ��� 0���� �ʱ�ȭ -> ����� �� ���� ���� 0���� �ʱ�ȭ
		procession[i][0] = 0;
	for (i = 0; i <= n; i++) //���� 0�� �ڸ��� 0���� �ʱ�ȭ -> ����� �� ���� ���� 0���� �ʱ�ȭ
		procession[0][i] = 0;
	//������� procession�迭�� �� ���� ��� �� ���� ���� �ʱ�ȭ.  

	//������� �κ��� ������ �̿��Ͽ� ���� ���α׷���!
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				//x[i-1]�� y[j-1]�� ���ٸ�
				procession[i][j] = procession[i - 1][j - 1] + 1; //procession[i][j]�� procession[i-1][j-1]+1�� ����
				show_lcs[i][j] = 'c';//show_lcs[i][j]�� ���ڿ� 'c' ����
			}
			else if (procession[i - 1][j] >= procession[i][j - 1])
			{
				//procession[i-1][j]>=procession[i][j-1]��� 
				procession[i][j] = procession[i - 1][j]; //procession[i][j]�� procession[i-1][j]�� ����
				show_lcs[i][j] = 'u';//show_lcs[i][j]�� ���ڿ� 'u' ����
			}
			else
			{
				//�� ���� ��쿡��
				procession[i][j] = procession[i][j - 1]; //procession[i][j]�� procession[i][j-1]�� ����
				show_lcs[i][j] = 'l';//show_lcs[i][j]�� ���ڿ� 'l' ����
			}
		}
	printf("%d", procession[m][n]); //procession[m][n]�� ���
}

void print(int i, int j)//lcs�� ���ڿ��� �����ϴ� �Լ�
{
	if (i == 0 || j == 0)//�Ű����� i�� ���� 0�̰ų� j�� ���� 0�̸� -> �Է¹��� �ΰ��� ���ڿ� �� �ϳ��� ���̰� 0�̶��
		return;// �Լ� ���� ����
	if (show_lcs[i][j] == 'c')
		//show_lcs[i][j]=='c'��� -> ���� lcs()�Լ��� ������ x[i - 1] = y[j - 1] -> �Է¹��� �ΰ��� ���ڿ����� i-1,j-1��°�� ���ڰ� ���ٸ�
	{
		print(i - 1, j - 1);//print�Լ� ȣ��
		printf("%c", x[i - 1]);//x[i-1] ���ڸ� ���
	}
	else if (show_lcs[i][j] == 'u')
		//show_lcs[i][j]=='u'��� -> ���� lcs()�Լ��� ������ procession[i-1][j]>=procession[i][j-1] ->���̰� ���ϴ� ������ ����κ�, ���� ����� �밢���� ������ üũ
		print(i - 1, j);//print�Լ� ȣ��
	else //�� ���� �����
		print(i, j - 1);//print�Լ� ȣ��
}


int main()
{
	while (1) {
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;// �ð� ������ ���� ����

		printf("LCS ���� �� ���ڿ� ���ϴ� ���α׷� - Dynamic Programming\n");
		printf("ù��° ���ڿ��� �Է����ּ���.:");
		scanf("%s", x); //�Է� ���� ���ڿ��� x�� ����
		printf("�ι�° ���ڿ��� �Է����ּ���.:");
		scanf("%s", y); //�Է� ���� ���ڿ��� y�� ����

		QueryPerformanceFrequency(&liFrequency); // ���ļ�(1�ʴ� �����Ǵ� ī��Ʈ��)�� ����. �ð����� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����
		printf("\nLCS�� ���� : ");
		lcs(); //���� ���� �κ� ������ ���̸� ��� 
		printf("\nLCS�� ���ڿ� : ");
		print(m, n);//���� ���� �κ� ������ ���ڿ��� ���
		printf("\n\n");

		/* ���� �ð� ��� */
		QueryPerformanceCounter(&EndCounter); // �ڵ� ���� �� ī��Ʈ ����		
		printf("����ð� = %f ��\n", (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart);
		printf("-------------------------------------------------------------\n");
	}
	return 0;
}
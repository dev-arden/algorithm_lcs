#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

int getmax(int a, int b); //x[0..m-1], y[0..n-1] �϶� lcs�� ���̸� �������ִ� �Լ�
double count[100][100] = { 0 }; //�ߺ� ȣ�� Ƚ���� �˱� ���� �������迭
double show_lcs[100][100] = { 0 };

int lcs(char *x, char *y, int m, int n) //lcs�� ���̸� �������ִ� �Լ�
{
	count[m][n]++; //�ߺ��� �߻��Ǹ�(�Ʒ��� ���ǿ� �����ϸ�) +1 �����ؼ� ����

	if (m == 0 || n == 0) //���̰� 0�� ���
		return 0; //0�� ������

	if (x[m - 1] == y[n - 1]) //m,n�� �ε��� �ȿ� ����ִ� ���ڰ� ���� ���
		return 1 + lcs(x, y, m - 1, n - 1); //1 + lcs(x, y, m-1, n-1);�� ������

	else //�ߺ��Ǵ� ���ڰ� ���� ���
		return getmax(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n)); //getmax(lcs(x, y, m, n-1), lcs(x, y, m-1, n))�� ������
}

int getmax(int a, int b)//a�� b �߿� �ִ� ���� �˰��ϴ� �Լ�
{
	if (a >= b) return a; //a�� b���� ũ�ų� ���ٸ� a��, a�� b���� �۴ٸ� b�� ���� 
	else return b;
}

int main()
{
	while (1) {
		int m, n; //strlen(x), strlen(y)�� �����ϱ� ���� ���� ���� 
		int i, j; //lcs()�ߺ� ȣ�� Ƚ���� ���� ���� ���� ���� 
		char x[100]; //ù ��° �Է� ���� ���ڿ� �迭 x
		char y[100]; //�� ��° �Է� ���� ���ڿ� �迭 y
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;// �ð� ������ ����ϱ� ���� ����	
		printf("���� ���� �κм����� ���� ���ϱ� (��� ȣ��ver.)\n");
		printf("ù��° ���ڿ��� �Է����ּ��� : ");
		scanf("%s", x); //scanf�� ���ؼ� �Է� ���� ���ڸ� x�� ����
		printf("�ι�° ���ڿ��� �Է����ּ��� : ");
		scanf("%s", y); //scanf�� ���ؼ� �Է� ���� ���ڸ� y�� ����

		QueryPerformanceFrequency(&liFrequency); // ���ļ�(1�ʴ� �����Ǵ� ī��Ʈ��)�� ���Ѵ�. �ð������� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����

		m = strlen(x); //x�� ���̸� m�� ���� 
		n = strlen(y); //y�� ���̸� n�� ����
		printf("\nLCS�� ���� ���� ���� ���� �κм����� ���� : %d\n", lcs(x, y, m, n)); //LCS�� ���� ���� ���� ���� �κ� ������ ���̸� ��� 


		QueryPerformanceCounter(&EndCounter); // ���� �ð� ���
		printf("����ð� = %f ��\n", (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart);

		printf("\nlcs �ߺ� ȣ�� Ƚ��(���)\n"); //lcs() �ߺ� Ƚ�� ���

		for (i = 0; i <= m; i++) { //i�� 0�� �����ϰ� i�� �ϳ��� �÷����鼭 i~~m �� ������ for���� ������. 
			for (j = 0; j <= n; j++) { //j�� 0�� �����ϰ� j�� �ϳ��� �÷����鼭 j~~m �� ������ for���� ������.
				printf("%15.0lf", count[i][j]); //15�ڸ����� ��� �����ϵ��� ���� 
			}
			printf("\n"); //for���� �� ������ �� �پ� ��� ���⸦ �ϸ鼭 ������¸� ���� �Ѵ�.  
		}
	}
	return 0;
}
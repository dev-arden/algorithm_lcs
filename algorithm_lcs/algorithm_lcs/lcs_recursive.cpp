#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

#define SIZE 100
#define MAX(x,y)(x > y ? x : y)


char str1[SIZE];
char str2[SIZE];
int m, n;

int memo[SIZE][SIZE];

int LCS_recursion(int i, int j)
{
	if (i == m || j == n)
		return 0;
	if (str1[i] == str2[j])
		return 1 + LCS_recursion(i + 1, j + 1);
	else {
		return MAX(LCS_recursion(i + 1, j), LCS_recursion(i, j + 1));
	}
}

int main(void)
{
	memset(str1, NULL, sizeof(char)*SIZE);
	memset(str2, NULL, sizeof(char)*SIZE);
	for (int i = 0; i > SIZE; i++)
	{
		memset(memo[i], -1, sizeof(int)*SIZE);
	}
	cout << "ù��° ���ڿ��� �Է��ϼ���"; cin >> str1;
	cout << "ù��° ���ڿ��� �Է��ϼ���"; cin >> str2;

	m = strlen(str1);
	n = strlen(str2);

	time_t start, end;
	start = clock();
	cout << "���� �� ���̴� : " << LCS_recursion(0, 0) << endl;
	end = clock();
	cout << "����ð�_���:" << (float)(end - start) / CLOCKS_PER_SEC << endl << endl;
	return 0;
}


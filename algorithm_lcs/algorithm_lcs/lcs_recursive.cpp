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
	cout << "첫번째 문자열을 입력하세요"; cin >> str1;
	cout << "첫번째 문자열을 입력하세요"; cin >> str2;

	m = strlen(str1);
	n = strlen(str2);

	time_t start, end;
	start = clock();
	cout << "가장 긴 길이는 : " << LCS_recursion(0, 0) << endl;
	end = clock();
	cout << "수행시간_재귀:" << (float)(end - start) / CLOCKS_PER_SEC << endl << endl;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

int getmax(int a, int b); //x[0..m-1], y[0..n-1] 일때 lcs의 길이를 리턴해주는 함수
double count[100][100] = { 0 }; //중복 호출 횟수를 알기 위한 이차원배열
double show_lcs[100][100] = { 0 };

int lcs(char *x, char *y, int m, int n) //lcs의 길이를 리턴해주는 함수
{
	count[m][n]++; //중복이 발생되면(아래의 조건에 만족하면) +1 증가해서 저장

	if (m == 0 || n == 0) //길이가 0일 경우
		return 0; //0을 리턴함

	if (x[m - 1] == y[n - 1]) //m,n의 인덱스 안에 들어있는 문자가 같은 경우
		return 1 + lcs(x, y, m - 1, n - 1); //1 + lcs(x, y, m-1, n-1);를 리턴함

	else //중복되는 글자가 없는 경우
		return getmax(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n)); //getmax(lcs(x, y, m, n-1), lcs(x, y, m-1, n))을 리턴함
}

int getmax(int a, int b)//a와 b 중에 최대 값을 알게하는 함수
{
	if (a >= b) return a; //a가 b보다 크거나 같다면 a를, a가 b보다 작다면 b를 리턴 
	else return b;
}

int main()
{
	while (1) {
		int m, n; //strlen(x), strlen(y)를 대입하기 위한 변수 선언 
		int i, j; //lcs()중복 호출 횟수를 세기 위한 전역 변수 
		char x[100]; //첫 번째 입력 받을 문자열 배열 x
		char y[100]; //두 번째 입력 받을 문자열 배열 y
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;// 시간 측정에 사용하기 위한 변수	
		printf("최장 공통 부분순서의 길이 구하기 (재귀 호출ver.)\n");
		printf("첫번째 문자열을 입력해주세요 : ");
		scanf("%s", x); //scanf를 통해서 입력 받은 문자를 x에 저장
		printf("두번째 문자열을 입력해주세요 : ");
		scanf("%s", y); //scanf를 통해서 입력 받은 문자를 y에 저장

		QueryPerformanceFrequency(&liFrequency); // 주파수(1초당 증가되는 카운트수)를 구한다. 시간측정의 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장

		m = strlen(x); //x의 길이를 m에 저장 
		n = strlen(y); //y의 길이를 n에 저장
		printf("\nLCS를 통해 구한 최장 공통 부분순서의 길이 : %d\n", lcs(x, y, m, n)); //LCS를 통해 구한 최장 공통 부분 순서의 길이를 출력 


		QueryPerformanceCounter(&EndCounter); // 수행 시간 출력
		printf("수행시간 = %f 초\n", (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart);

		printf("\nlcs 중복 호출 횟수(행렬)\n"); //lcs() 중복 횟수 출력

		for (i = 0; i <= m; i++) { //i에 0을 대입하고 i를 하나씩 늘려가면서 i~~m 돌 때까지 for문을 돌린다. 
			for (j = 0; j <= n; j++) { //j에 0을 대입하고 j를 하나씩 늘려가면서 j~~m 돌 때까지 for문을 돌린다.
				printf("%15.0lf", count[i][j]); //15자리까지 출력 가능하도록 설정 
			}
			printf("\n"); //for문을 돌 때마다 한 줄씩 띄어 쓰기를 하면서 출력형태를 고르게 한다.  
		}
	}
	return 0;
}
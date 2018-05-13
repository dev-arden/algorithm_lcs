#define _CRT_SECURE_NO_WARNINGS//visual studio 2015부터는 보안문제로 인해 scanf 사용시 작성을 해주어야 함.
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

unsigned int i, j, m, n, procession[100][100]; //i, j, m, n 변수와 이차원 배열 procession 선언
char x[100], y[100], show_lcs[100][100]; //사용자가 입력한 문자열을 저장하는 배열 x,y와 최장 공통 부분 순서(lcs)의 문자열을 보여줄 이차원 배열 show_lcs선언

int lcs()//lcs의 길이를 리턴하는 함수
{
	m = strlen(x); //사용자가 입력한 문자열을 저장한 배열 x의 길이를 m에 저장  
	n = strlen(y); //사용자가 입력한 문자열을 저장한 배열 y의 길이를 n에 저장


	for (i = 0; i <= m; i++) //열이 0인 자리를 0으로 초기화 -> 행렬의 맨 왼쪽 행을 0으로 초기화
		procession[i][0] = 0;
	for (i = 0; i <= n; i++) //행이 0인 자리를 0으로 초기화 -> 행렬의 맨 위쪽 열을 0으로 초기화
		procession[0][i] = 0;
	//이차행렬 procession배열의 맨 왼쪽 행과 맨 위쪽 열을 초기화.  

	//재귀적인 부분을 루프를 이용하여 동적 프로그래밍!
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				//x[i-1]이 y[j-1]과 같다면
				procession[i][j] = procession[i - 1][j - 1] + 1; //procession[i][j]에 procession[i-1][j-1]+1을 저장
				show_lcs[i][j] = 'c';//show_lcs[i][j]에 문자열 'c' 대입
			}
			else if (procession[i - 1][j] >= procession[i][j - 1])
			{
				//procession[i-1][j]>=procession[i][j-1]라면 
				procession[i][j] = procession[i - 1][j]; //procession[i][j]에 procession[i-1][j]를 저장
				show_lcs[i][j] = 'u';//show_lcs[i][j]에 문자열 'u' 대입
			}
			else
			{
				//그 외의 경우에는
				procession[i][j] = procession[i][j - 1]; //procession[i][j]에 procession[i][j-1]를 저장
				show_lcs[i][j] = 'l';//show_lcs[i][j]에 문자열 'l' 대입
			}
		}
	printf("%d", procession[m][n]); //procession[m][n]을 출력
}

void print(int i, int j)//lcs의 문자열을 리턴하는 함수
{
	if (i == 0 || j == 0)//매개변수 i의 값이 0이거나 j의 값이 0이면 -> 입력받은 두개의 문자열 중 하나라도 길이가 0이라면
		return;// 함수 수행 종료
	if (show_lcs[i][j] == 'c')
		//show_lcs[i][j]=='c'라면 -> 위의 lcs()함수에 따르면 x[i - 1] = y[j - 1] -> 입력받은 두개의 문자열에서 i-1,j-1번째의 문자가 같다면
	{
		print(i - 1, j - 1);//print함수 호출
		printf("%c", x[i - 1]);//x[i-1] 문자를 출력
	}
	else if (show_lcs[i][j] == 'u')
		//show_lcs[i][j]=='u'라면 -> 위의 lcs()함수에 따르면 procession[i-1][j]>=procession[i][j-1] ->길이가 변하는 시점이 공통부분, 따라서 행렬의 대각선인 시점을 체크
		print(i - 1, j);//print함수 호출
	else //그 외의 경우라면
		print(i, j - 1);//print함수 호출
}


int main()
{
	while (1) {
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;// 시간 측정을 위한 변수

		printf("LCS 길이 및 문자열 구하는 프로그램 - Dynamic Programming\n");
		printf("첫번째 문자열을 입력해주세요.:");
		scanf("%s", x); //입력 받은 문자열을 x에 저장
		printf("두번째 문자열을 입력해주세요.:");
		scanf("%s", y); //입력 받은 문자열을 y에 저장

		QueryPerformanceFrequency(&liFrequency); // 주파수(1초당 증가되는 카운트수)를 구함. 시간측정 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장
		printf("\nLCS의 길이 : ");
		lcs(); //최장 공통 부분 순서의 길이를 출력 
		printf("\nLCS의 문자열 : ");
		print(m, n);//최장 공통 부분 순서의 문자열을 출력
		printf("\n\n");

		/* 수행 시간 출력 */
		QueryPerformanceCounter(&EndCounter); // 코드 수행 후 카운트 저장		
		printf("수행시간 = %f 초\n", (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart);
		printf("-------------------------------------------------------------\n");
	}
	return 0;
}
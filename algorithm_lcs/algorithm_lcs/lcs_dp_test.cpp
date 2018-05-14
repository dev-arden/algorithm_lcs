#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <ctime>
#include <Windows.h>

using namespace std;

string str1, str2;

int lcs[1001][1001];

int main()
{
	//while (1)
	//{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;
		string tmp1, tmp2;
		ifstream inf("input.txt");

		getline(inf, tmp1); //파일 입출력 
		getline(inf, tmp2); //표준 입출

		cout << endl << "-------------LCS_동적프로그래밍버전---------------\n" << endl ;
		
		cout << "파일로부터 입력받은 첫번째 문자열 : " <<tmp1;

		cout << endl;
		cout << "파일로부터 입력받은 두번째 문자열 : " << tmp2 << "\n";

		QueryPerformanceFrequency(&liFrequency); // 주파수(1초당 증가되는 카운트수)를 구함. 시간측정 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장
		// LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
		str1 = '0' + tmp1;
		str2 = '0' + tmp2;

		int len1 = str1.size();
		int len2 = str2.size();

		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (i == 0 || j == 0)
				{
					lcs[i][j] = 0;
					continue;
				}

				// 현재 비교하는 값이 서로 같다면, lcs는 + 1
				if (str1[i] == str2[j])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;

				// 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
				else
				{
					if (lcs[i - 1][j] > lcs[i][j - 1])
						lcs[i][j] = lcs[i - 1][j];
					else
						lcs[i][j] = lcs[i][j - 1];
				}
			}
		}

		/*
		// 검증 코드
		for (int i = 0; i < len1; i++)
		{
		for (int j = 0; j < len2; j++)
		cout << lcs[i][j] << " ";
		cout << endl;
		}
		*/


		int i = len1 - 1;
		int j = len2 - 1;
		stack<int> st; // 거꾸로 담기니 stack을 이용

		while (lcs[i][j] != 0)
		{
			// 경로 추적
			// cout << " i :: " << i << " j :: " << j << endl;

			// 테이블이 같은 넘버링이라면
			// 왼쪽으로 이동
			if (lcs[i][j] == lcs[i][j - 1])
				j--;

			// 위쪽으로 이동
			else if (lcs[i][j] == lcs[i - 1][j])
				i--;

			// 왼쪽 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
			else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
			{
				st.push(i);
				i--;
				j--;
			}
		}

		// 길이 출력
		cout << "\nLCS의 길이: " << lcs[len1 - 1][len2 - 1] ;

		cout << endl;
		cout << "LCS의 문자열: ";
		// 단어 출력
		while (!st.empty())
		{
			cout << str1[st.top()];
			st.pop();
		}
		QueryPerformanceCounter(&EndCounter); // 코드 수행 후 카운트 저장	

		cout << endl << endl;
		cout << "동적플밍버전_수행시간:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;
	//}
	return 0;
}



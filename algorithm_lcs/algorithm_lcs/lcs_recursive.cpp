#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>    
#include <ctime>
#include <vector>
#include <Windows.h>

using namespace std;

string s1, s2;
double count_[100][100] = { 0 };



int lcs(int idx1, int idx2, vector <char> &v) 
{

	count_[idx1+1][idx2+1]++;

	if (idx1 == -1 || idx2 == -1) {
		return 0;
	}

	if (s1[idx1] == s2[idx2]) {
		v.push_back(s1[idx1]); // record that we used this char
		return 1 + lcs(idx1 - 1, idx2 - 1, v);
	}
	else {
		vector<char> v1, v2;

		int p1 = lcs(idx1 - 1, idx2, v1);
		int p2 = lcs(idx1, idx2 - 1, v2);

		if (p1 > p2) { // we used the chars we already had in v + the ones in v1
			v.insert(v.end(), v1.begin(), v1.end());
			return p1;
		}
		else { // we used the chars we already had in v + the ones in v2
			v.insert(v.end(), v2.begin(), v2.end());
			return p2;
		}
	}
}

int main(int argc, const char * argv[])
{
	while (1)
	{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;
		int choice = 0;
		int i = 0, j = 0;

		//여기에 파일 고를 수 있는 메뉴를 만들자

		cout << "입력하세요" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ifstream inf("input.txt");
			getline(inf, s1); //파일 입출력 
			getline(inf, s2); //표준 입출
		}
		break;
		case 2:
			ifstream inf2("inputin.txt");
			getline(inf2, s1); //파일 입출력 
			getline(inf2, s2); //표준 입출
			break;
		}


		cout << endl << "-------------LCS_재귀버전---------------\n" << endl  ;
		
		cout << "파일로부터 입력받은 첫번째 문자열 : " << s1;

		cout << endl;
		cout << "파일로부터 입력받은 두번째 문자열 : " << s2 << "\n";
		cout << endl;

		int m = s1.length();
		int n = s2.length();

		QueryPerformanceFrequency(&liFrequency); // 주파수(1초당 증가되는 카운트수)를 구함. 시간측정 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장
		vector<char> v; // chars we used
		int sol = lcs(m - 1, n - 1, v); //i want to output "sdc"
		cout << "LCS의 길이: " << sol;
		reverse(v.begin(), v.end());

		cout << endl;
		cout << "LCS의 문자열: ";
		for (auto num : v) {
			cout << num;
		}

		QueryPerformanceCounter(&EndCounter); // 코드 수행 후 카운트 저장		
		cout << "\n재귀버전_수행시간:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;

		cout << "lcs 중복 호출 횟수(행렬)" <<endl ; //lcs() 중복 횟수 출력

		for (i = 0; i <= m; i++)
		{
			cout << endl;
			for (j = 0; j <= n; j++)
			{
				cout.width(10);
				cout << count_[i][j];
			}
			cout << endl;
		}
	}
	return 0;
	
}









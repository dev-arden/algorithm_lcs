#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>    
#include <ctime>
#include <vector>
#include <Windows.h>

using namespace std;

string s1, s2;//파일로부터 읽어들인 두개의 문자열이 담기는 변수
double count_[100][100] = { 0 };//중복 호출 횟수를 확인하기 위한 이차원 배열



int lcs(int idx, int idy, vector <char> &v)
//lcs의 길이를 리턴하는 함수, 매개변수 idx : 읽어들인 문자열 s1-1, idy : s2-1, v : lcs 문자열을 확인하기 위한 벡터
{

	count_[idx + 1][idy + 1]++;//중복 호출이 발생하면 +1

							   /*길이가 0 일때 : idx = m-1 (s1의 길이 - 1),idy = n-1 (s2의 길이 - 1)
							   -> idx, idy가 -1이라는 것은 sl, s2의 길이가 0이라는 것
							   */
	if (idx == -1 || idy == -1) {
		return 0;//0 리턴
	}

	if (s1[idx] == s2[idy]) { //idx+1(m), idy+1(n)의 인덱스에 들어있는 문자가 같을 때 
		v.push_back(s1[idx]); // 벡터의 현재 마지막 원소 뒤에 새로운 원소를 추가 -> 나중에 lcs 문자열 확인해야하니까
		return 1 + lcs(idx - 1, idy - 1, v);//재귀, 1 + lcs(idx - 1, idy - 1, v);을 리턴
	}
	else {// 중복 문자가 없을 때
		vector<char> v1, v2;// v1,v2 벡터 선언

		int p1 = lcs(idx - 1, idy, v1);//변수 p1 선언 ,재귀->lcs(idx - 1, idy, v1);을 리턴
		int p2 = lcs(idx, idy - 1, v2);//변수 p2 선언, 재귀->lcs(idx, idy - 1, v2);

		if (p1 > p2) {//p1의 값이 p2의 값보다 클 때
			v.insert(v.end(), v1.begin(), v1.end());// 벡터 v의 끝에 v1의 원소를 삽입
			return p1;//p1값 리턴
		}
		else { //p1의 값이 p2의 값보다 작거나 같을 때
			v.insert(v.end(), v2.begin(), v2.end());// 벡터 v의 끝에 v2의 원소를 삽입
			return p2;//p2값 리턴
		}
	}
}

int main()
{
	/*
	사용자에게 프로그램을 설명하기 위한 출력문
	*/
	cout << "아래에는 총 16개의 번호가 있습니다\n" << endl;
	cout << "각 번호에 따라 프로그램이 읽는 파일이 달라집니다.\n" << endl;
	cout << "파일 안에는 두 개의 문자열이 존재합니다.\n" << endl;
	cout << "파일 안 두 개의 문자열의 최장 공통 부분 순서의 길이 및 문자열을 알려주는 프로그램입니다.\n" << endl;
	cout << "1 ~ 6번까지는 ALGORITHMREPORTEUNBEE를 기본 문자열로 하는 파일이며, 번호가 증가할수록 LCS의 길이가 감소합니다\n" << endl;
	cout << "7 ~ 10번까지는 ITENGINERRING을 기본 문자열로 하는 파일이며, 번호가 증가할수록 LCS의 길이가 감소합니다\n" << endl;
	cout << "11 ~ 13번까지는 SOOGOHAETTAOHYEAH를 기본 문자열로 하는 파일이며, 번호가 증가할수록 LCS의 길이가 감소합니다\n" << endl;
	cout << "14 ~ 16번까지는 NOELGALLAGHERS를 기본 문자열로 하는 파일이며, 번호가 증가할수록 LCS의 길이가 감소합니다\n" << endl;
	while (1)//무한루프
	{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;//시간 측정을 하기 위한 변수 선언
		int choice = 0;//사용자가 입력할 파일 번호 변수 

					   /*
					   파일 번호 메뉴판, 1번부터 16번까지 4줄로 출력
					   */
		cout << "************파일번호*******************\n" << endl;
		for (int x = 1; x < 17; x++)
		{
			cout.width(10);
			cout << x;
			if (x % 4 == 0)
				cout << endl;
		}
		cout << "\n**************************************\n";

		cout << "\nLCS를 확인하고 싶은 파일의 번호를 입력하세요  ";

		cin >> choice;//파일 번호 입력받기

					  /*
					  switch문을 이용하여 파일 번호에 따라 읽어들이는 파일이 달라짐
					  */
		switch (choice)
		{
		case 1:
		{
			ifstream inf("input.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input.txt파일 읽기
			getline(inf, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf, s2); //파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;//수행 후 탈출
		case 2:
		{
			ifstream inf2("input2.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input2.txt파일 읽기
			getline(inf2, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf2, s2); //파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;
		case 3:
		{
			ifstream inf3("input3.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input3.txt파일 읽기
			getline(inf3, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf3, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 4:
		{
			ifstream inf4("input4.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input4.txt파일 읽기
			getline(inf4, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf4, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;
		case 5:
		{
			ifstream inf5("input5.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input5.txt파일 읽기
			getline(inf5, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf5, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input6.txt파일 읽기
			getline(inf6, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf6, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input7.txt파일 읽기
			getline(inf7, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf7, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input8.txt파일 읽기
			getline(inf8, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf8, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input9.txt파일 읽기
			getline(inf9, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf9, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input10.txt파일 읽기
			getline(inf10, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf10, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input11.txt파일 읽기
			getline(inf11, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf11, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input12.txt파일 읽기
			getline(inf12, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf12, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input13.txt파일 읽기
			getline(inf13, s1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf13, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input14.txt파일 읽기
			getline(inf14, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf14, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input15.txt파일 읽기
			getline(inf15, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf15, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 16:
		{
			ifstream inf16("input16.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input16.txt파일 읽기
			getline(inf16, s1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf16, s2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		}

		//사용자가 보기 편하도록 출력문 생성
		cout << endl << "----------------------------LCS_재귀버전---------------------------------\n" << endl;

		cout << "파일로부터 입력받은 첫번째 문자열 : " << s1 << "\n";//파일로부터 입력받은 첫번째 문자열 출력
		cout << "파일로부터 입력받은 두번째 문자열 : " << s2 << "\n";//파일로부터 입력받은 두번째 문자열 출력
		cout << endl;//한줄띄기

		int m = s1.length();//첫번째 문자열의 길이를 담는 변수 m
		int n = s2.length();//두번째 문자열의 길이를 담는 변수 n

		QueryPerformanceFrequency(&liFrequency); // 1초당 증가되는 카운트수인 주파수 를 구함. 시간측정 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장
		vector<char> v; // lcs의 문자열을 보여주기 위한 벡터 v 선언
		int sol = lcs(m - 1, n - 1, v); //lcs의 길이를 알기위한 sol변수 -> lcs(m - 1, n - 1, v); 함수 호출 
		cout << "LCS의 길이: " << sol; //lcs의 길이 출력
		reverse(v.begin(), v.end());//lcs의 문자열을 담은 벡터 v의 원소들을 저장할 공간 예약
		cout << endl;//한줄띄기
		cout << "LCS의 문자열: ";//출력문
							 /*
							 변수 형식을 유추하기 위한 auto 키워드
							 벡터 v를 복사해서 출력
							 */
		for (auto showlcs : v) {
			cout << showlcs;
		}

		QueryPerformanceCounter(&EndCounter); // 코드 수행 후 카운트 저장		
		cout << "\n재귀버전_수행시간:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;//수행시간 출력
		cout << "LCS 중복 횟수" << endl; //출력문

									 /*
									 중복 호출 횟수를 출력하기 위한 for문
									 */
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout.width(15);//출력형식 지정, 15로 폭을 지정
				cout << count_[i][j];
			}
			cout << endl;//사용자가 보기 편하도록 하기위함.
		}
	}
	return 0;

}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <ctime>
#include <Windows.h>

using namespace std;

string s1, s2;//lcs 알고리즘을 위한 변수 s1, s2 선언
int lcs[1001][1001];//lcs의 길이를 확인하기 위한 이차원 배열 lcs 선언

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
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;//시간 측정을 하기 위한 변수
		string tmp1, tmp2;//파일로부터 읽어들인 두개의 문자열이 담기는 변수
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
			getline(inf, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf, tmp2); //파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;//수행 후 탈출
		case 2:
		{
			ifstream inf2("input2.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input2.txt파일 읽기
			getline(inf2, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf2, tmp2); //파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;
		case 3:
		{
			ifstream inf3("input3.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input3.txt파일 읽기
			getline(inf3, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf3, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 4:
		{
			ifstream inf4("input4.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input4.txt파일 읽기
			getline(inf4, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf4, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음
		}
		break;
		case 5:
		{
			ifstream inf5("input5.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input5.txt파일 읽기
			getline(inf5, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf5, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input6.txt파일 읽기
			getline(inf6, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf6, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input7.txt파일 읽기
			getline(inf7, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf7, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input8.txt파일 읽기
			getline(inf8, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf8, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input9.txt파일 읽기
			getline(inf9, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf9, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input10.txt파일 읽기
			getline(inf10, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf10, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input11.txt파일 읽기
			getline(inf11, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf11, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input12.txt파일 읽기
			getline(inf12, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf12, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input13.txt파일 읽기
			getline(inf13, tmp1); //파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음
			getline(inf13, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input14.txt파일 읽기
			getline(inf14, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음 
			getline(inf14, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input15.txt파일 읽기
			getline(inf15, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf15, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		case 16:
		{
			ifstream inf16("input16.txt");//파일 읽기를 위한 ifstream 클래스의 객체 선언, input16.txt파일 읽기
			getline(inf16, tmp1);//파일 입출력, 첫줄의 문자열을 읽어들인 후 s1에 담음  
			getline(inf16, tmp2);//파일 입출력, 그 다음줄의 문자열을 읽어들인 후 s2에 담음 
		}
		break;
		}


		//사용자가 보기 편하도록 출력문 생성
		cout << endl << "-------------LCS_동적프로그래밍버전-----------------------------\n" << endl;

		cout << "파일로부터 입력받은 첫번째 문자열 : " << tmp1 << "\n";//파일로부터 입력받은 첫번째 문자열 출력
		cout << "파일로부터 입력받은 두번째 문자열 : " << tmp2 << "\n";//파일로부터 입력받은 두번째 문자열 출력

		QueryPerformanceFrequency(&liFrequency); // // 1초당 증가되는 카운트수인 주파수 를 구함. 시간측정 초기화
		QueryPerformanceCounter(&StartCounter); // 코드 수행 전 카운트 저장

		s1 = '0' + tmp1;// LCS 알고리즘을 위해 앞에 tmp1에 '0'을 붙인 후 s1에 담음
		s2 = '0' + tmp2;// LCS 알고리즘을 위해 앞에 tmp2에 '0'을 붙인 후 s2에 담음

		int len1 = s1.size();// s1의 원소의 수 -> s1의 길이
		int len2 = s2.size();// s2의 원소의 수 -> s2의 길이

							 //동적 프로그래밍을 위한 루프!
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (i == 0 || j == 0) //s1의 길이가 0이거나 s2의 길이가 0일때
				{
					lcs[i][j] = 0;//lcs[i][j]에 0을 담기
					continue;// 이 경우에는 처리 생략
				}

				if (s1[i] == s2[j])// i,j의 인덱스에 들어있는 문자가 같을 때
					lcs[i][j] = lcs[i - 1][j - 1] + 1;//lcs[i - 1][j - 1] + 1을 lcs[i][j]에 담기

				else//중복 문자가 없을 때
				{
					if (lcs[i - 1][j] > lcs[i][j - 1])//lcs[i - 1][j]의 값이 lcs[i][j - 1]의 값보다 크다면
						lcs[i][j] = lcs[i - 1][j];//lcs의 값을 왼쪽에서 가져오기
					else //lcs[i - 1][j]의 값이 lcs[i][j - 1]의 값보다 작거나 같다면
						lcs[i][j] = lcs[i][j - 1];//lcs의 값을 위쪽에서 가져오기
				}
			}
		}

		int i = len1 - 1;// len1 - 1값을 담는 i변수
		int j = len2 - 1;// len2 - 1값을 담는 j변수
		stack<int> st; // lcs의 공통 문자열을 찾기 위한 자료구조 스택, 거꾸로 담겨야 하므로 stack을 이용

					   //경로 추적을 위한 while문
		while (lcs[i][j] != 0) //lcs[i][j]가 0이 아닌 동안 -> 공통 문자가 있는 경우
		{
			if (lcs[i][j] == lcs[i][j - 1])//lcs[i][j]이 lcs[i][j - 1]과 같다면 -> 현재 값이 왼쪽에 있는 값이랑 같다면
				j--;// 왼쪽으로 이동

			else if (lcs[i][j] == lcs[i - 1][j])//lcs[i][j]가 lcs[i - 1][j]랑 같다면 -> 현재 값이 위쪽에 있는 값이랑 같다면
				i--;//위쪽으로 이동

			else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])// lcs[i][j] - 1이 lcs[i - 1][j - 1]랑 같다면  -> 현재 값이 왼쪽,위쪽에 있는 값이랑 모두 다르다면
			{
				st.push(i);//스택 st에 데이터 i넣기
				i--; j--; //대각선 방향으로 이동
			}
		}

		cout << "\nLCS의 길이: " << lcs[len1 - 1][len2 - 1]; //lcs의 길이 출력
		cout << endl;//한줄띄기
		cout << "LCS의 문자열: ";//출력문

		while (!st.empty()) // 스택 st가 비어있지 않은 동안
		{
			cout << s1[st.top()];//스택의 맨위에 있는 데이터값을 인덱스로 해서 그에 해당하는 문자 출력
			st.pop();//출력 후에는 pop함수를 통해 데이터 삭제
		}
		QueryPerformanceCounter(&EndCounter); // 코드 수행 후 카운트 저장	

		cout << endl << endl;//사용자가 보기 편하도록 두줄 띄기
		cout << "동적플밍버전_수행시간:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;//수행시간 출력
		cout << "----------------------------------------------------------------" << endl;//출력문
	}
	return 0;//0리턴
}
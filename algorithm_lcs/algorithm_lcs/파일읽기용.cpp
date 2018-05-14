#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
	string str1; string str2; 
	ifstream inf("input.txt");
	getline(inf, str1); //파일 입출력 
	getline(inf,str2); //표준 입출

	cout << str1 << "\n" << str2;

	return 0;
}

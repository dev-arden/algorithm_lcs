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
	cout << "�Ʒ����� �� 15���� ��ȣ�� �ֽ��ϴ�\n" << endl;
	cout << "�� ��ȣ�� ���� ���α׷��� �д� ������ �޶����ϴ�.\n" << endl;
	cout << "���� �ȿ��� �� ���� ���ڿ��� �����մϴ�.\n" << endl;
	cout << "���� �� �� ���� ���ڿ��� ���� ���� �κ� ������ ���� �� ���ڿ��� �˷��ִ� ���α׷��Դϴ�.\n" << endl;
	cout << "��ȣ�� �����Ҽ��� ���� ���� �κ� ������ ���̰� �����մϴ�\n" << endl;
	while (1)
	{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;
		int choice = 0;
		int i = 0, j = 0;

		//���⿡ ���� �� �� �ִ� �޴��� ������

		cout << "************���Ϲ�ȣ*******************\n" << endl;
		for (int x = 1; x < 16; x++)
		{
			cout.width(10);
			cout << x;
			if (x % 3 == 0)
				cout << endl;
		}
		cout << "\n**************************************\n";

		cout << "\nLCS�� Ȯ���ϰ� ���� ������ ��ȣ�� �Է��ϼ���  ";

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ifstream inf("input.txt");
			getline(inf, s1); //���� ����� 
			getline(inf, s2); //ǥ�� ����
		}
		break;
		case 2:
		{
			ifstream inf2("input2.txt");
			getline(inf2, s1); //���� ����� 
			getline(inf2, s2); //ǥ�� ����
		}
		break;
		case 3:
		{
			ifstream inf3("input3.txt");
			getline(inf3, s1); //���� ����� 
			getline(inf3, s2); //ǥ�� ����
		}
		break;
		case 4:
		{
			ifstream inf4("input4.txt");
			getline(inf4, s1); //���� ����� 
			getline(inf4, s2); //ǥ�� ����
		}
		break;
		case 5:
		{
			ifstream inf5("input5.txt");
			getline(inf5, s1); //���� ����� 
			getline(inf5, s2); //ǥ�� ����
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");
			getline(inf6, s1); //���� ����� 
			getline(inf6, s2); //ǥ�� ����
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");
			getline(inf7, s1); //���� ����� 
			getline(inf7, s2); //ǥ�� ����
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");
			getline(inf8, s1); //���� ����� 
			getline(inf8, s2); //ǥ�� ����
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");
			getline(inf9, s1); //���� ����� 
			getline(inf9, s2); //ǥ�� ����
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");
			getline(inf10, s1); //���� ����� 
			getline(inf10, s2); //ǥ�� ����
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");
			getline(inf11, s1); //���� ����� 
			getline(inf11, s2); //ǥ�� ����
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");
			getline(inf12, s1); //���� ����� 
			getline(inf12, s2); //ǥ�� ����
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");
			getline(inf13, s1); //���� ����� 
			getline(inf13, s2); //ǥ�� ����
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");
			getline(inf14, s1); //���� ����� 
			getline(inf14, s2); //ǥ�� ����
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");
			getline(inf15, s1); //���� ����� 
			getline(inf15, s2); //ǥ�� ����
		}
		break;
		}


		cout << endl << "----------------------------LCS_��͹���---------------------------------\n" << endl  ;
		
		cout << "���Ϸκ��� �Է¹��� ù��° ���ڿ� : " << s1;

		cout << endl;
		cout << "���Ϸκ��� �Է¹��� �ι�° ���ڿ� : " << s2 << "\n";
		cout << endl;

		int m = s1.length();
		int n = s2.length();

		QueryPerformanceFrequency(&liFrequency); // ���ļ�(1�ʴ� �����Ǵ� ī��Ʈ��)�� ����. �ð����� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����
		vector<char> v; // chars we used
		int sol = lcs(m - 1, n - 1, v); //i want to output "sdc"
		cout << "LCS�� ����: " << sol;
		reverse(v.begin(), v.end());

		cout << endl;
		cout << "LCS�� ���ڿ�: ";
		for (auto num : v) {
			cout << num;
		}

		QueryPerformanceCounter(&EndCounter); // �ڵ� ���� �� ī��Ʈ ����		
		cout << "\n��͹���_����ð�:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;

		cout << "lcs �ߺ� ȣ�� Ƚ��(���)" <<endl ; //lcs() �ߺ� Ƚ�� ���

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









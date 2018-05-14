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
	while (1)
	{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;
		string tmp1, tmp2;
		
		int choice = 0;

		//���⿡ ���� �� �� �ִ� �޴��� ������
		cout << "��ȣ�� ���� �о���̴� ������ �޶����ϴ�" << endl;
		cout << "��ȣ�� �����Ҽ��� ���� ���� ���ڿ��� LCS�� ���̰� �����մϴ�" << endl;
		
		for (int x = 1; x < 16; x++)
		{
			cout.width(10);
			cout << x ;
			if (x % 3 == 0)
				cout << endl;
		}

		cout << "\nLCS�� Ȯ���ϰ� ���� ������ ��ȣ�� �Է��ϼ���  " ;
		
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ifstream inf("input.txt");
			getline(inf, tmp1); //���� ����� 
			getline(inf, tmp2); //ǥ�� ����
		}
		break;
		case 2:
		{
			ifstream inf2("input2.txt");
			getline(inf2, tmp1); //���� ����� 
			getline(inf2, tmp2); //ǥ�� ����
		}
			break;
		case 3:
		{
			ifstream inf3("input3.txt");
			getline(inf3, tmp1); //���� ����� 
			getline(inf3, tmp2); //ǥ�� ����
		}
			break;
		case 4:
		{
			ifstream inf4("input4.txt");
			getline(inf4, tmp1); //���� ����� 
			getline(inf4, tmp2); //ǥ�� ����
		}
			break;
		case 5:
		{
			ifstream inf5("input5.txt");
			getline(inf5, tmp1); //���� ����� 
			getline(inf5, tmp2); //ǥ�� ����
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");
			getline(inf6, tmp1); //���� ����� 
			getline(inf6, tmp2); //ǥ�� ����
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");
			getline(inf7, tmp1); //���� ����� 
			getline(inf7, tmp2); //ǥ�� ����
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");
			getline(inf8, tmp1); //���� ����� 
			getline(inf8, tmp2); //ǥ�� ����
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");
			getline(inf9, tmp1); //���� ����� 
			getline(inf9, tmp2); //ǥ�� ����
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");
			getline(inf10, tmp1); //���� ����� 
			getline(inf10, tmp2); //ǥ�� ����
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");
			getline(inf11, tmp1); //���� ����� 
			getline(inf11, tmp2); //ǥ�� ����
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");
			getline(inf12, tmp1); //���� ����� 
			getline(inf12, tmp2); //ǥ�� ����
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");
			getline(inf13, tmp1); //���� ����� 
			getline(inf13, tmp2); //ǥ�� ����
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");
			getline(inf14, tmp1); //���� ����� 
			getline(inf14, tmp2); //ǥ�� ����
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");
			getline(inf15, tmp1); //���� ����� 
			getline(inf15, tmp2); //ǥ�� ����
		}
		break;
		}



		cout << endl << "-------------LCS_�������α׷��ֹ���-----------------------------\n" << endl ;
		
		cout << "���Ϸκ��� �Է¹��� ù��° ���ڿ� : " <<tmp1;

		cout << endl;
		cout << "���Ϸκ��� �Է¹��� �ι�° ���ڿ� : " << tmp2 << "\n";

		QueryPerformanceFrequency(&liFrequency); // ���ļ�(1�ʴ� �����Ǵ� ī��Ʈ��)�� ����. �ð����� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����
		// LCS �˰����� ���� �տ� '0'�� �ٿ��ش�.
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

				// ���� ���ϴ� ���� ���� ���ٸ�, lcs�� + 1
				if (str1[i] == str2[j])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;

				// ���� �ٸ��ٸ� LCS�� ���� ���� Ȥ�� ������ �����´�.
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
		// ���� �ڵ�
		for (int i = 0; i < len1; i++)
		{
		for (int j = 0; j < len2; j++)
		cout << lcs[i][j] << " ";
		cout << endl;
		}
		*/


		int i = len1 - 1;
		int j = len2 - 1;
		stack<int> st; // �Ųٷ� ���� stack�� �̿�

		while (lcs[i][j] != 0)
		{
			// ��� ����
			// cout << " i :: " << i << " j :: " << j << endl;

			// ���̺��� ���� �ѹ����̶��
			// �������� �̵�
			if (lcs[i][j] == lcs[i][j - 1])
				j--;

			// �������� �̵�
			else if (lcs[i][j] == lcs[i - 1][j])
				i--;

			// ���� ���� ��� �ٸ� �ѹ����̶�� �밢�� �������� �̵�
			else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
			{
				st.push(i);
				i--;
				j--;
			}
		}

		// ���� ���
		cout << "\nLCS�� ����: " << lcs[len1 - 1][len2 - 1] ;

		cout << endl;
		cout << "LCS�� ���ڿ�: ";
		// �ܾ� ���
		while (!st.empty())
		{
			cout << str1[st.top()];
			st.pop();
		}
		QueryPerformanceCounter(&EndCounter); // �ڵ� ���� �� ī��Ʈ ����	

		cout << endl << endl;
		cout << "�����ùֹ���_����ð�:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;
		cout << "----------------------------------------------------------------" << endl;
	}
	return 0;
}



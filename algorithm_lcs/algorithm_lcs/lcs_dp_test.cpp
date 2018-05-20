#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <ctime>
#include <Windows.h>

using namespace std;

string s1, s2;//lcs �˰����� ���� ���� s1, s2 ����
int lcs[1001][1001];//lcs�� ���̸� Ȯ���ϱ� ���� ������ �迭 lcs ����

int main()
{
	/*
	����ڿ��� ���α׷��� �����ϱ� ���� ��¹�
	*/
	cout << "�Ʒ����� �� 16���� ��ȣ�� �ֽ��ϴ�\n" << endl;
	cout << "�� ��ȣ�� ���� ���α׷��� �д� ������ �޶����ϴ�.\n" << endl;
	cout << "���� �ȿ��� �� ���� ���ڿ��� �����մϴ�.\n" << endl;
	cout << "���� �� �� ���� ���ڿ��� ���� ���� �κ� ������ ���� �� ���ڿ��� �˷��ִ� ���α׷��Դϴ�.\n" << endl;
	cout << "1 ~ 6�������� ALGORITHMREPORTEUNBEE�� �⺻ ���ڿ��� �ϴ� �����̸�, ��ȣ�� �����Ҽ��� LCS�� ���̰� �����մϴ�\n" << endl;
	cout << "7 ~ 10�������� ITENGINERRING�� �⺻ ���ڿ��� �ϴ� �����̸�, ��ȣ�� �����Ҽ��� LCS�� ���̰� �����մϴ�\n" << endl;
	cout << "11 ~ 13�������� SOOGOHAETTAOHYEAH�� �⺻ ���ڿ��� �ϴ� �����̸�, ��ȣ�� �����Ҽ��� LCS�� ���̰� �����մϴ�\n" << endl;
	cout << "14 ~ 16�������� NOELGALLAGHERS�� �⺻ ���ڿ��� �ϴ� �����̸�, ��ȣ�� �����Ҽ��� LCS�� ���̰� �����մϴ�\n" << endl;
	while (1)//���ѷ���
	{
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;//�ð� ������ �ϱ� ���� ����
		string tmp1, tmp2;//���Ϸκ��� �о���� �ΰ��� ���ڿ��� ���� ����
		int choice = 0;//����ڰ� �Է��� ���� ��ȣ ����

					   /*
					   ���� ��ȣ �޴���, 1������ 16������ 4�ٷ� ���
					   */
		cout << "************���Ϲ�ȣ*******************\n" << endl;
		for (int x = 1; x < 17; x++)
		{
			cout.width(10);
			cout << x;
			if (x % 4 == 0)
				cout << endl;
		}
		cout << "\n**************************************\n";

		cout << "\nLCS�� Ȯ���ϰ� ���� ������ ��ȣ�� �Է��ϼ���  ";

		cin >> choice;//���� ��ȣ �Է¹ޱ�

					  /*
					  switch���� �̿��Ͽ� ���� ��ȣ�� ���� �о���̴� ������ �޶���
					  */
		switch (choice)
		{
		case 1:
		{
			ifstream inf("input.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input.txt���� �б�
			getline(inf, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf, tmp2); //���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;//���� �� Ż��
		case 2:
		{
			ifstream inf2("input2.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input2.txt���� �б�
			getline(inf2, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf2, tmp2); //���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;
		case 3:
		{
			ifstream inf3("input3.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input3.txt���� �б�
			getline(inf3, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf3, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 4:
		{
			ifstream inf4("input4.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input4.txt���� �б�
			getline(inf4, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf4, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;
		case 5:
		{
			ifstream inf5("input5.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input5.txt���� �б�
			getline(inf5, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf5, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input6.txt���� �б�
			getline(inf6, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf6, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input7.txt���� �б�
			getline(inf7, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf7, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input8.txt���� �б�
			getline(inf8, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf8, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input9.txt���� �б�
			getline(inf9, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf9, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input10.txt���� �б�
			getline(inf10, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf10, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input11.txt���� �б�
			getline(inf11, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf11, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input12.txt���� �б�
			getline(inf12, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf12, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input13.txt���� �б�
			getline(inf13, tmp1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf13, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input14.txt���� �б�
			getline(inf14, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf14, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input15.txt���� �б�
			getline(inf15, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf15, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 16:
		{
			ifstream inf16("input16.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input16.txt���� �б�
			getline(inf16, tmp1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf16, tmp2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		}


		//����ڰ� ���� ���ϵ��� ��¹� ����
		cout << endl << "-------------LCS_�������α׷��ֹ���-----------------------------\n" << endl;

		cout << "���Ϸκ��� �Է¹��� ù��° ���ڿ� : " << tmp1 << "\n";//���Ϸκ��� �Է¹��� ù��° ���ڿ� ���
		cout << "���Ϸκ��� �Է¹��� �ι�° ���ڿ� : " << tmp2 << "\n";//���Ϸκ��� �Է¹��� �ι�° ���ڿ� ���

		QueryPerformanceFrequency(&liFrequency); // // 1�ʴ� �����Ǵ� ī��Ʈ���� ���ļ� �� ����. �ð����� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����

		s1 = '0' + tmp1;// LCS �˰����� ���� �տ� tmp1�� '0'�� ���� �� s1�� ����
		s2 = '0' + tmp2;// LCS �˰����� ���� �տ� tmp2�� '0'�� ���� �� s2�� ����

		int len1 = s1.size();// s1�� ������ �� -> s1�� ����
		int len2 = s2.size();// s2�� ������ �� -> s2�� ����

							 //���� ���α׷����� ���� ����!
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (i == 0 || j == 0) //s1�� ���̰� 0�̰ų� s2�� ���̰� 0�϶�
				{
					lcs[i][j] = 0;//lcs[i][j]�� 0�� ���
					continue;// �� ��쿡�� ó�� ����
				}

				if (s1[i] == s2[j])// i,j�� �ε����� ����ִ� ���ڰ� ���� ��
					lcs[i][j] = lcs[i - 1][j - 1] + 1;//lcs[i - 1][j - 1] + 1�� lcs[i][j]�� ���

				else//�ߺ� ���ڰ� ���� ��
				{
					if (lcs[i - 1][j] > lcs[i][j - 1])//lcs[i - 1][j]�� ���� lcs[i][j - 1]�� ������ ũ�ٸ�
						lcs[i][j] = lcs[i - 1][j];//lcs�� ���� ���ʿ��� ��������
					else //lcs[i - 1][j]�� ���� lcs[i][j - 1]�� ������ �۰ų� ���ٸ�
						lcs[i][j] = lcs[i][j - 1];//lcs�� ���� ���ʿ��� ��������
				}
			}
		}

		int i = len1 - 1;// len1 - 1���� ��� i����
		int j = len2 - 1;// len2 - 1���� ��� j����
		stack<int> st; // lcs�� ���� ���ڿ��� ã�� ���� �ڷᱸ�� ����, �Ųٷ� ��ܾ� �ϹǷ� stack�� �̿�

					   //��� ������ ���� while��
		while (lcs[i][j] != 0) //lcs[i][j]�� 0�� �ƴ� ���� -> ���� ���ڰ� �ִ� ���
		{
			if (lcs[i][j] == lcs[i][j - 1])//lcs[i][j]�� lcs[i][j - 1]�� ���ٸ� -> ���� ���� ���ʿ� �ִ� ���̶� ���ٸ�
				j--;// �������� �̵�

			else if (lcs[i][j] == lcs[i - 1][j])//lcs[i][j]�� lcs[i - 1][j]�� ���ٸ� -> ���� ���� ���ʿ� �ִ� ���̶� ���ٸ�
				i--;//�������� �̵�

			else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])// lcs[i][j] - 1�� lcs[i - 1][j - 1]�� ���ٸ�  -> ���� ���� ����,���ʿ� �ִ� ���̶� ��� �ٸ��ٸ�
			{
				st.push(i);//���� st�� ������ i�ֱ�
				i--; j--; //�밢�� �������� �̵�
			}
		}

		cout << "\nLCS�� ����: " << lcs[len1 - 1][len2 - 1]; //lcs�� ���� ���
		cout << endl;//���ٶ��
		cout << "LCS�� ���ڿ�: ";//��¹�

		while (!st.empty()) // ���� st�� ������� ���� ����
		{
			cout << s1[st.top()];//������ ������ �ִ� �����Ͱ��� �ε����� �ؼ� �׿� �ش��ϴ� ���� ���
			st.pop();//��� �Ŀ��� pop�Լ��� ���� ������ ����
		}
		QueryPerformanceCounter(&EndCounter); // �ڵ� ���� �� ī��Ʈ ����	

		cout << endl << endl;//����ڰ� ���� ���ϵ��� ���� ���
		cout << "�����ùֹ���_����ð�:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;//����ð� ���
		cout << "----------------------------------------------------------------" << endl;//��¹�
	}
	return 0;//0����
}
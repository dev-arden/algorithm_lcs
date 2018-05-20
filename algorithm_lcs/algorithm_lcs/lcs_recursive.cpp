#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>    
#include <ctime>
#include <vector>
#include <Windows.h>

using namespace std;

string s1, s2;//���Ϸκ��� �о���� �ΰ��� ���ڿ��� ���� ����
double count_[100][100] = { 0 };//�ߺ� ȣ�� Ƚ���� Ȯ���ϱ� ���� ������ �迭



int lcs(int idx, int idy, vector <char> &v)
//lcs�� ���̸� �����ϴ� �Լ�, �Ű����� idx : �о���� ���ڿ� s1-1, idy : s2-1, v : lcs ���ڿ��� Ȯ���ϱ� ���� ����
{

	count_[idx + 1][idy + 1]++;//�ߺ� ȣ���� �߻��ϸ� +1

							   /*���̰� 0 �϶� : idx = m-1 (s1�� ���� - 1),idy = n-1 (s2�� ���� - 1)
							   -> idx, idy�� -1�̶�� ���� sl, s2�� ���̰� 0�̶�� ��
							   */
	if (idx == -1 || idy == -1) {
		return 0;//0 ����
	}

	if (s1[idx] == s2[idy]) { //idx+1(m), idy+1(n)�� �ε����� ����ִ� ���ڰ� ���� �� 
		v.push_back(s1[idx]); // ������ ���� ������ ���� �ڿ� ���ο� ���Ҹ� �߰� -> ���߿� lcs ���ڿ� Ȯ���ؾ��ϴϱ�
		return 1 + lcs(idx - 1, idy - 1, v);//���, 1 + lcs(idx - 1, idy - 1, v);�� ����
	}
	else {// �ߺ� ���ڰ� ���� ��
		vector<char> v1, v2;// v1,v2 ���� ����

		int p1 = lcs(idx - 1, idy, v1);//���� p1 ���� ,���->lcs(idx - 1, idy, v1);�� ����
		int p2 = lcs(idx, idy - 1, v2);//���� p2 ����, ���->lcs(idx, idy - 1, v2);

		if (p1 > p2) {//p1�� ���� p2�� ������ Ŭ ��
			v.insert(v.end(), v1.begin(), v1.end());// ���� v�� ���� v1�� ���Ҹ� ����
			return p1;//p1�� ����
		}
		else { //p1�� ���� p2�� ������ �۰ų� ���� ��
			v.insert(v.end(), v2.begin(), v2.end());// ���� v�� ���� v2�� ���Ҹ� ����
			return p2;//p2�� ����
		}
	}
}

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
		LARGE_INTEGER StartCounter, EndCounter, liFrequency;//�ð� ������ �ϱ� ���� ���� ����
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
			getline(inf, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf, s2); //���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;//���� �� Ż��
		case 2:
		{
			ifstream inf2("input2.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input2.txt���� �б�
			getline(inf2, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf2, s2); //���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;
		case 3:
		{
			ifstream inf3("input3.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input3.txt���� �б�
			getline(inf3, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf3, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 4:
		{
			ifstream inf4("input4.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input4.txt���� �б�
			getline(inf4, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf4, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ����
		}
		break;
		case 5:
		{
			ifstream inf5("input5.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input5.txt���� �б�
			getline(inf5, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf5, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 6:
		{
			ifstream inf6("input6.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input6.txt���� �б�
			getline(inf6, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf6, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 7:
		{
			ifstream inf7("input7.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input7.txt���� �б�
			getline(inf7, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf7, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 8:
		{
			ifstream inf8("input8.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input8.txt���� �б�
			getline(inf8, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf8, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 9:
		{
			ifstream inf9("input9.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input9.txt���� �б�
			getline(inf9, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf9, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 10:
		{
			ifstream inf10("input10.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input10.txt���� �б�
			getline(inf10, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf10, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 11:
		{
			ifstream inf11("input11.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input11.txt���� �б�
			getline(inf11, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf11, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 12:
		{
			ifstream inf12("input12.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input12.txt���� �б�
			getline(inf12, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf12, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 13:
		{
			ifstream inf13("input13.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input13.txt���� �б�
			getline(inf13, s1); //���� �����, ù���� ���ڿ��� �о���� �� s1�� ����
			getline(inf13, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 14:
		{
			ifstream inf14("input14.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input14.txt���� �б�
			getline(inf14, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ���� 
			getline(inf14, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 15:
		{
			ifstream inf15("input15.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input15.txt���� �б�
			getline(inf15, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf15, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		case 16:
		{
			ifstream inf16("input16.txt");//���� �б⸦ ���� ifstream Ŭ������ ��ü ����, input16.txt���� �б�
			getline(inf16, s1);//���� �����, ù���� ���ڿ��� �о���� �� s1�� ����  
			getline(inf16, s2);//���� �����, �� �������� ���ڿ��� �о���� �� s2�� ���� 
		}
		break;
		}

		//����ڰ� ���� ���ϵ��� ��¹� ����
		cout << endl << "----------------------------LCS_��͹���---------------------------------\n" << endl;

		cout << "���Ϸκ��� �Է¹��� ù��° ���ڿ� : " << s1 << "\n";//���Ϸκ��� �Է¹��� ù��° ���ڿ� ���
		cout << "���Ϸκ��� �Է¹��� �ι�° ���ڿ� : " << s2 << "\n";//���Ϸκ��� �Է¹��� �ι�° ���ڿ� ���
		cout << endl;//���ٶ��

		int m = s1.length();//ù��° ���ڿ��� ���̸� ��� ���� m
		int n = s2.length();//�ι�° ���ڿ��� ���̸� ��� ���� n

		QueryPerformanceFrequency(&liFrequency); // 1�ʴ� �����Ǵ� ī��Ʈ���� ���ļ� �� ����. �ð����� �ʱ�ȭ
		QueryPerformanceCounter(&StartCounter); // �ڵ� ���� �� ī��Ʈ ����
		vector<char> v; // lcs�� ���ڿ��� �����ֱ� ���� ���� v ����
		int sol = lcs(m - 1, n - 1, v); //lcs�� ���̸� �˱����� sol���� -> lcs(m - 1, n - 1, v); �Լ� ȣ�� 
		cout << "LCS�� ����: " << sol; //lcs�� ���� ���
		reverse(v.begin(), v.end());//lcs�� ���ڿ��� ���� ���� v�� ���ҵ��� ������ ���� ����
		cout << endl;//���ٶ��
		cout << "LCS�� ���ڿ�: ";//��¹�
							 /*
							 ���� ������ �����ϱ� ���� auto Ű����
							 ���� v�� �����ؼ� ���
							 */
		for (auto showlcs : v) {
			cout << showlcs;
		}

		QueryPerformanceCounter(&EndCounter); // �ڵ� ���� �� ī��Ʈ ����		
		cout << "\n��͹���_����ð�:" << (double)(EndCounter.QuadPart - StartCounter.QuadPart) / (double)liFrequency.QuadPart << endl << endl;//����ð� ���
		cout << "LCS �ߺ� Ƚ��" << endl; //��¹�

									 /*
									 �ߺ� ȣ�� Ƚ���� ����ϱ� ���� for��
									 */
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout.width(15);//������� ����, 15�� ���� ����
				cout << count_[i][j];
			}
			cout << endl;//����ڰ� ���� ���ϵ��� �ϱ�����.
		}
	}
	return 0;

}

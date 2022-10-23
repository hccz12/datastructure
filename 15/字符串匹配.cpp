#include <iostream>
#include <string.h>
using namespace std;
//����ƥ��
bool pipei(char nn[], char mm[], int a)
{
	int  b = strlen(mm);
	int j = 0;
	for (int i = a; i < a + b; i++)
	{
		if (nn[i] != mm[j])
		{
			return false;
		}
		j++;
	}
	return true;

}

int fangfa_1(char nn[], char mm[])
{
	int a = strlen(nn);
	int b = strlen(mm);
	for (int i = 0; i < a; i++)
	{
		if (pipei(nn, mm, i) == true)
		{
			return i + 1;
		}
	}
	return -1;
}
//��ϣ
int fangfa_2(char nn[], char mm[], const int n) 
{
	int b = strlen(mm);//���  mm �ִ��ĳ��� 
	int num[n] = {};//����һ�������Ź�ϣ��
	int sum = 0;//���ڼ���  nn ����Ĺ�ϣ�� 
	for (int i = 0; i < b; i++)//ȷ����һ��sum   ���º���һЩ 
	{
		sum += (int)nn[i];//��һ��ǿת����һЩ 
	}
	int pp = 0;//�����ִ��Ĺ�ϣ����
	for (int i = 0; i < b; i++)//�ִ��Ĺ�ϣ��ֵ���� 
	{
		pp += (int)mm[i];
	}
	//������������ÿ�� ֵ�Ĺ�ϣ��ֵ 
	for (int i = 1; i < n - b; i++)
	{
		sum = sum - nn[i - 1] + nn[i + b - 1];
		num[i] = sum;//��¼ ��ϣֵ 
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] == pp)
		{
			if (pipei(nn, mm, i) == true)
			{
				return i + 1;
			}
		}
	}
	return -1;
}
// kmp �㷨�������ҵ��㷨�ٶ�
//����  next ����
void fangfa_3_1(int* next, char mm[])//next  ���ٿռ���������飬   mm  �ִ�
{
	int i = 0;
	int j = -1;
	next[0] = -1;//��ʼ������
	int a = strlen(mm);
	while (i < a - 1)
	{
		if (j == -1 || mm[i] == mm[j])//���ﱣ֤�������ӣ� ���ַ�����ǰ���� ����һֱ��Աȵ��� ǰ����ַ��� 
		{
			j++;
			i++;
			next[i] = j;//��ֵ��  �����ֵ�� 0  ��ʱ��û�п���������  ���� next[0]  j==-1  ��������	
		}
		else
		{
			j = next[j];
		}
	}
}

int fangfa_3(char nn[], char mm[], int* next)
{
	int i = 0;
	int j = 0;
	int a = strlen(nn);//���ȼ��� 
	int b = strlen(mm);
	while (i < a && j < b)//ֹͣѰ�ҵ����� 
	{
		if (j == -1 || nn[i] == mm[j])//��ǰѰ�ҵ�����������ֵ���  ���� j==-1 ���ִ��� 0��λ��  ��ʼƥ��u 
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//�ƶ��ִ�  ����Ӧ�ĵط� 
		}
	}
	if (j == b)
	{
		return i - j + 1;	//���ؿ�ʼ�ĵ�ַ 
	}
	else
	{
		return -1;	//û�ж�Ӧ�ִ�   ����  -1 
	}

}
int main()
{
	char nn[] = "aabnkiopfspfafafdshdasdsh";
	char mm[] = "nkiop";//��ƥ�䵽���ַ��� 
	char mm1[] = "pppppppppp";//ƥ�䲻�����ִ�
	int n = strlen(nn);
	int a = fangfa_1(nn, mm);
	int a1 = fangfa_1(nn, mm1);
	cout << "a = " << a << endl;
	cout << "a1 = " << a1 << endl;

	int b = fangfa_2(nn, mm, n);
	int b1 = fangfa_2(nn, mm1, n);
	cout << "b = " << b << endl;
	cout << "b1 = " << b1 << endl;

	int* next = new int[sizeof(mm)];//���ٿռ� 
	int* next1 = new int[sizeof(mm1)];//���ٿռ� 

	fangfa_3_1(next, mm);//�õ�next ������ 
	fangfa_3_1(next1, mm1);//�õ�next ������ 

	int c = fangfa_3(nn, mm, next);
	int c1 = fangfa_3(nn, mm1, next1);
	cout << "c = " << c << endl;
	cout << "c1 = " << c1 << endl;


	return 	0;
}
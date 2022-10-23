#include <iostream>
#include <string.h>
using namespace std;
//暴力匹配
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
//哈希
int fangfa_2(char nn[], char mm[], const int n) 
{
	int b = strlen(mm);//求出  mm 字串的长度 
	int num[n] = {};//建立一个数组存放哈希表
	int sum = 0;//用于计算  nn 数组的哈希表 
	for (int i = 0; i < b; i++)//确定第一个sum   等下好算一些 
	{
		sum += (int)nn[i];//加一个强转，好一些 
	}
	int pp = 0;//计算字串的哈希数字
	for (int i = 0; i < b; i++)//字串的哈希数值计算 
	{
		pp += (int)mm[i];
	}
	//计算主串里面每个 值的哈希数值 
	for (int i = 1; i < n - b; i++)
	{
		sum = sum - nn[i - 1] + nn[i + b - 1];
		num[i] = sum;//记录 哈希值 
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
// kmp 算法，首先我的算法速度
//建立  next 数组
void fangfa_3_1(int* next, char mm[])//next  开辟空间的整型数组，   mm  字串
{
	int i = 0;
	int j = -1;
	next[0] = -1;//初始化数据
	int a = strlen(mm);
	while (i < a - 1)
	{
		if (j == -1 || mm[i] == mm[j])//这里保证可以连加， 与字符串的前进， 我们一直相对比的是 前面的字符串 
		{
			j++;
			i++;
			next[i] = j;//赋值，  当这个值是 0  的时候没有可能是跳板  跳到 next[0]  j==-1  到这里来	
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
	int a = strlen(nn);//长度计算 
	int b = strlen(mm);
	while (i < a && j < b)//停止寻找的条件 
	{
		if (j == -1 || nn[i] == mm[j])//往前寻找的条件，，数值相等  或者 j==-1 从字串的 0的位置  开始匹配u 
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//移动字串  到对应的地方 
		}
	}
	if (j == b)
	{
		return i - j + 1;	//返回开始的地址 
	}
	else
	{
		return -1;	//没有对应字串   返回  -1 
	}

}
int main()
{
	char nn[] = "aabnkiopfspfafafdshdasdsh";
	char mm[] = "nkiop";//能匹配到的字符串 
	char mm1[] = "pppppppppp";//匹配不到的字串
	int n = strlen(nn);
	int a = fangfa_1(nn, mm);
	int a1 = fangfa_1(nn, mm1);
	cout << "a = " << a << endl;
	cout << "a1 = " << a1 << endl;

	int b = fangfa_2(nn, mm, n);
	int b1 = fangfa_2(nn, mm1, n);
	cout << "b = " << b << endl;
	cout << "b1 = " << b1 << endl;

	int* next = new int[sizeof(mm)];//开辟空间 
	int* next1 = new int[sizeof(mm1)];//开辟空间 

	fangfa_3_1(next, mm);//得到next 的数组 
	fangfa_3_1(next1, mm1);//得到next 的数组 

	int c = fangfa_3(nn, mm, next);
	int c1 = fangfa_3(nn, mm1, next1);
	cout << "c = " << c << endl;
	cout << "c1 = " << c1 << endl;


	return 	0;
}
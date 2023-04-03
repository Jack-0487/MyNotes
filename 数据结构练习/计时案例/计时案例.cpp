#include<iostream>
#include<time.h>
#include<math.h>
#include<vector>
using namespace std;
//最大子列和问题
//O(n^2)的算法
int maxSubseqSum(int num, int A[], int size)
{
	int maxSum = 0;
	//int size = sizeof(A)/sizeof(int);
	for (int i = 0; i < size; i++)
	{
		int thisSum = 0;
		for (int j = i; j < i+num; j++)
		{
			
			thisSum += A[j];
		if (thisSum > maxSum)
			maxSum = thisSum;
		}
	}
	return maxSum;
}
//分而治之算法（O（nlog n）） 递归算法
//在线处理算法(O(n))

int maxSubseqSum3(int N, int A[], int size)
{
	int thisSum = 0;
	int MaxSum = 0;
	for (int i = 0; i < size; i++)
	{
		thisSum += A[i];
		if (thisSum > MaxSum)
		{
			MaxSum = thisSum;
		}
		else if(thisSum < 0)
		{
			thisSum = 0;
		}
	}
	return MaxSum;
}
int main()
{
	int a[] = { 10, 20, 30, 40, 50, 60, 70 };
	int i = 3;
	int size = sizeof(a) / sizeof(int);
	int max = maxSubseqSum(i, a, size);
	cout << max;
	int max1 = maxSubseqSum3(i, a, size);
	cout << max1;
}
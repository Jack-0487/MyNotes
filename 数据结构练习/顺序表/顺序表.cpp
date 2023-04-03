#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct LNode* List;
struct LNode
{
	int Data[MAXSIZE];
	int last;
};
//初始化顺序表
void Empty(List& PtrL)
{
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->last = -1;
	cout << "初始化成功" << endl;
}
//查找顺序表中某一元素的位置O（n）
int Find(int& Elem, List& Ptrl)
{
	
	for (int i = 0; i < Ptrl->last; i++)
	{
		if (Ptrl->Data[i] == Elem)
		{
			return i;
			break;
		}
	}
}
//在顺序表某个位置插入新元素
void Insert(int& elem, int pos, List& Ptrl)
{
	if (pos < 1 || pos > MAXSIZE)
	{
		cout << "插入位置不合法" << endl;
	}
	else
	{
			for (int i = Ptrl->last; i > pos-1; i--)
		{
			Ptrl->Data[i + 1] = Ptrl->Data[i];

		}
		Ptrl->Data[pos] = elem;
		Ptrl->last++;

		}
	
}
//删除某个位置元素
void Delete(int& pos, List& Ptrl)
{
	if (pos < 1 || pos > Ptrl->last)
	{
		cout << "删除位置不合法" << endl;
	}
	else
	{
		for (int i = pos; i < Ptrl->last; i++)
		{
			Ptrl->Data[i] = Ptrl->Data[i + 1];
		}
		Ptrl->last--;
	}
}
void test()
{

	LNode* L1;
	Empty(L1);
	cout << L1->last << endl;
	for (int i = 0; i < 20; i++)
	{
		L1->Data[i] = i;
		L1->last++;
	}
	cout << L1->last;
	int elem = 3;
	int pos = Find(elem, L1);
	cout << "元素" << elem << "的位置为" << pos << endl;
}
int main()
{
	test();
}
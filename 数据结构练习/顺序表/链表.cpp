//单链表
#include<iostream>
using namespace std;
struct LNode
{
	int Data;
	LNode* next;
};
//初始化链表
void InitList(LNode*& list)
{
	list = (LNode*)malloc(sizeof(LNode));
}
//链表的表长
int Length(LNode*& list)
{
	int j = 0;
	LNode* p = list;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
//按序号查找
LNode* Find(int pos, LNode*& list)
{
	LNode* p = list;
	int i = 1;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (i == pos)
		return p;
	else
	{
		cout << "未找到" << endl;
		return NULL;
	}
		
		
}
//插入
void Insert(int elem, int pos, LNode*& list)
{
	LNode* insert1;
	LNode* p;
	//插入结点在表头
	if (pos == 1)
	{
		insert1 = (LNode*)malloc(sizeof(LNode));
		insert1->Data = elem;
		insert1->next = list;
	}
	else
	{
		p = Find(pos, list);
		if (p == NULL)
		{
			cout << "插入错误" << endl;
		}
		else
		{
			insert1 = (LNode*)malloc(sizeof(LNode));
			insert1->Data = elem;
			insert1->next = p->next;
			p->next = insert1;
		}
	}
	
}
//删除结点
LNode* Delete(int pos, LNode*& list)
{
	LNode* p;
	LNode* p2;
	if (pos == 1)
	{
		p = list;
		if (list != NULL)
		{
			list = list->next;
			free(p);
			return list;
		}
		else
			return NULL;
		
	}
	else
	{
		p = Find(pos, list);
		if (p == NULL || p->next == NULL)
		{
			cout << "未找到该结点" << endl;
		}
		else
		{
			p2 = p->next;
			p->next = p->next->next;
			free(p2);
			return list; //????
		}

	}
}
void test()
{
	LNode* L1;
	InitList(L1);
	Insert(20, 1, L1);
	int length = Length(L1);
	cout << length;
	cout << L1->Data;
}
int main()
{
	test();
}
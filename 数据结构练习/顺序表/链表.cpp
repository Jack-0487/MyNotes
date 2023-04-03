//������
#include<iostream>
using namespace std;
struct LNode
{
	int Data;
	LNode* next;
};
//��ʼ������
void InitList(LNode*& list)
{
	list = (LNode*)malloc(sizeof(LNode));
}
//����ı�
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
//����Ų���
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
		cout << "δ�ҵ�" << endl;
		return NULL;
	}
		
		
}
//����
void Insert(int elem, int pos, LNode*& list)
{
	LNode* insert1;
	LNode* p;
	//�������ڱ�ͷ
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
			cout << "�������" << endl;
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
//ɾ�����
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
			cout << "δ�ҵ��ý��" << endl;
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
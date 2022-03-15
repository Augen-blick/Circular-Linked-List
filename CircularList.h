#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct CDNode
{
	ElemType data;
	struct CDNode* next;
} CDLinkNode;

void InitList(CDLinkNode*& L);                         //��ʼ��ѭ��������
void DestroyList(CDLinkNode*& L);				       //����ѭ��������
bool ListEmpty(CDLinkNode* L);						   //�ж��Ƿ�Ϊ��
int ListLength(CDLinkNode* L);						   //�����
void DispList(CDLinkNode* L);						   //�����
bool GetElem(CDLinkNode* L, int i, ElemType& e);	   //���i��Ԫ��
int LocateElem(CDLinkNode* L, ElemType e);			   //���һ��e�ڱ��е����
bool ListInsert(CDLinkNode*& L, int i, ElemType e);	   //��e���뵽��i��λ��
bool ListDelete(CDLinkNode*& L, int i, ElemType& e);   //ɾ����i��Ԫ��
int count(CDLinkNode* L, ElemType e);				   //ͳ��e����Ŀ
bool deletem(CDLinkNode*& L, ElemType e);			   //ɾ����һ��e
void CreateListF(CDLinkNode*& L, ElemType a[], int n); //ͷ�巨
void CreateListR(CDLinkNode*& L, ElemType a[], int n); //β�巨

void InitList(CDLinkNode*& L)                          //��ʼ��ѭ��������
{
	L = (CDLinkNode*)malloc(sizeof(CDLinkNode));
	L->next = L;									   //����ͷ��㣬��next��ָ���Լ�
}

void DestroyList(CDLinkNode*& L)				       //����ѭ��������
{
	CDLinkNode* pre = L, * p = L->next;				   //preָ��p��ǰ�����
	while (p != L)									   //ɨ��ѭ������
	{
		free(pre);									   //�ͷ�pre���
		pre = p;									   //pre,pͬ������һ�����
		p = p->next;
	}
	free(pre);										   //ѭ������ʱpΪL��preָ�����һ����㣬�ͷ���
}

bool ListEmpty(CDLinkNode* L)						   //�ж��Ƿ�Ϊ��
{
	return(L->next == L);
}

int ListLength(CDLinkNode* L)						   //�����
{
	int n = 0;
	CDLinkNode* p = L;								//pָ��ͷ��㣬n��Ϊ0
	while (p->next != L)
	{
		n++;
		p = p->next;
	}
	return n;										//ѭ����������n
}

void DispList(CDLinkNode* L)						   //�����
{
	CDLinkNode* p = L->next;						//pָ���׽��
	while (p != L)								//p��ΪL�����p����data��
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(CDLinkNode* L, int i, ElemType& e)		   //���i��Ԫ��
{
	int j = 0;
	CDLinkNode* p = L;
	if (i <= 0)
		return false;
	while (j < i && p->next != L)
	{
		j++;
		p = p->next;
	}
	if (p->next == L)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

int LocateElem(CDLinkNode* L, ElemType e)			   //���һ��e�ڱ��е����
{
	int i = 1;
	CDLinkNode* p = L->next;
	while (p != L && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == L)
		return 0;
	else
		return i;
}

bool ListInsert(CDLinkNode*& L, int i, ElemType e)	   //��e���뵽��i��λ��
{
	int j = 0;
	CDLinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p->next != L)
	{
		j++;
		p = p->next;
	}
	if (p->next == L)
		return false;
	else
	{
		s = (CDLinkNode*)malloc(sizeof(CDLinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(CDLinkNode*& L, int i, ElemType& e)    //ɾ����i��Ԫ��
{
	int j = 0;
	CDLinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p->next != L)
	{
		j++;
		p = p->next;
	}
	if (p->next == L)
		return false;
	else
	{
		s = p->next;								//sָ���i�����
		if (s == L)									//�����ڵ�i�����
			return false;
		e = s->data;
		p->next = s->next;
		free(s);
		return true;
	}
}

int count(CDLinkNode* L, ElemType e)				   //ͳ��e����Ŀ
{
	int n = 0;
	CDLinkNode* p = L->next;
	while (p != L)
	{
		if (p->data == e)
			n++;
		p = p->next;
	}
	return n;
}

bool deletem(CDLinkNode*& L, ElemType e)			   //ɾ����һ��e
{
	CDLinkNode* p = L->next, * pre = L;
	while (p != L && p->data != e)
	{
		pre = p;
		p = p->next;
	}
	if (p != L)
	{
		pre->next = p->next;
		free(p);
		return true;
	}
	else
		return false;
}

void CreateListF(CDLinkNode*& L, ElemType a[], int n) //ͷ�巨
{
	CDLinkNode* s;
	L = (CDLinkNode*)malloc(sizeof(CDLinkNode));
	L->next = L;
	for (int i = 0; i < 0; i++)
	{
		s = (CDLinkNode*)malloc(sizeof(CDLinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(CDLinkNode*& L, ElemType a[], int n) //β�巨
{
	CDLinkNode* s, * r;
	L = (CDLinkNode*)malloc(sizeof(CDLinkNode));
	r = L;											//rʼ��ָ��β���
	for (int i = 0; i < n; i++)
	{
		s = (CDLinkNode*)malloc(sizeof(CDLinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}
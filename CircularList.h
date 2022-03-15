#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct CDNode
{
	ElemType data;
	struct CDNode* next;
} CDLinkNode;

void InitList(CDLinkNode*& L);                         //初始化循环单链表
void DestroyList(CDLinkNode*& L);				       //销毁循环单链表
bool ListEmpty(CDLinkNode* L);						   //判断是否为空
int ListLength(CDLinkNode* L);						   //求表长度
void DispList(CDLinkNode* L);						   //输出表
bool GetElem(CDLinkNode* L, int i, ElemType& e);	   //求第i个元素
int LocateElem(CDLinkNode* L, ElemType e);			   //求第一个e在表中的序号
bool ListInsert(CDLinkNode*& L, int i, ElemType e);	   //将e插入到第i个位置
bool ListDelete(CDLinkNode*& L, int i, ElemType& e);   //删除第i个元素
int count(CDLinkNode* L, ElemType e);				   //统计e的数目
bool deletem(CDLinkNode*& L, ElemType e);			   //删除第一个e
void CreateListF(CDLinkNode*& L, ElemType a[], int n); //头插法
void CreateListR(CDLinkNode*& L, ElemType a[], int n); //尾插法

void InitList(CDLinkNode*& L)                          //初始化循环单链表
{
	L = (CDLinkNode*)malloc(sizeof(CDLinkNode));
	L->next = L;									   //创建头结点，其next域指向自己
}

void DestroyList(CDLinkNode*& L)				       //销毁循环单链表
{
	CDLinkNode* pre = L, * p = L->next;				   //pre指向p的前驱结点
	while (p != L)									   //扫描循环链表
	{
		free(pre);									   //释放pre结点
		pre = p;									   //pre,p同步后移一个结点
		p = p->next;
	}
	free(pre);										   //循环结束时p为L，pre指向最后一个结点，释放它
}

bool ListEmpty(CDLinkNode* L)						   //判断是否为空
{
	return(L->next == L);
}

int ListLength(CDLinkNode* L)						   //求表长度
{
	int n = 0;
	CDLinkNode* p = L;								//p指向头结点，n置为0
	while (p->next != L)
	{
		n++;
		p = p->next;
	}
	return n;										//循环结束返回n
}

void DispList(CDLinkNode* L)						   //输出表
{
	CDLinkNode* p = L->next;						//p指向首结点
	while (p != L)								//p不为L，输出p结点的data域
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetElem(CDLinkNode* L, int i, ElemType& e)		   //求第i个元素
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

int LocateElem(CDLinkNode* L, ElemType e)			   //求第一个e在表中的序号
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

bool ListInsert(CDLinkNode*& L, int i, ElemType e)	   //将e插入到第i个位置
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

bool ListDelete(CDLinkNode*& L, int i, ElemType& e)    //删除第i个元素
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
		s = p->next;								//s指向第i个结点
		if (s == L)									//不存在第i个结点
			return false;
		e = s->data;
		p->next = s->next;
		free(s);
		return true;
	}
}

int count(CDLinkNode* L, ElemType e)				   //统计e的数目
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

bool deletem(CDLinkNode*& L, ElemType e)			   //删除第一个e
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

void CreateListF(CDLinkNode*& L, ElemType a[], int n) //头插法
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

void CreateListR(CDLinkNode*& L, ElemType a[], int n) //尾插法
{
	CDLinkNode* s, * r;
	L = (CDLinkNode*)malloc(sizeof(CDLinkNode));
	r = L;											//r始终指向尾结点
	for (int i = 0; i < n; i++)
	{
		s = (CDLinkNode*)malloc(sizeof(CDLinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}
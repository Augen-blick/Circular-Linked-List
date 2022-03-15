#include <iostream>
#include "CircularList.h"
using namespace std;

int main()
{

	//创建循环链表
	CDLinkNode *L;
	int a[10] = { 5,6,3,7,4,5,3,12,0,9 };

	//尾插法建立循环链表
	CreateListR(L, a, 10);

	//遍历循环链表
	DispList(L);

	//求表中第i个元素
	int x = 4;
	int x1;
	GetElem(L, x, x1);
	cout << "表中第4个元素是" << x1 << endl;

	//求第一个e在表中的序号
	int y = 3;
	cout << "第一个3在表中的位置是：" << LocateElem(L, y) << endl;

	//删除第i个元素
	int e;
	ListDelete(L, 2, e);
	cout << "删除的元素是：" << e << endl;

	//遍历循环链表
	DispList(L);

	//统计e的个数
	cout << "\"5\"共有" << count(L, 5) << "个" << endl;

	//删除第一个e
	int e2 = 5;
	cout << "删除第一个5" << endl;
	deletem(L, e2);

	//遍历循环链表
	DispList(L);

	return 0;
}
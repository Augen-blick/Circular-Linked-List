#include <iostream>
#include "CircularList.h"
using namespace std;

int main()
{

	//����ѭ������
	CDLinkNode *L;
	int a[10] = { 5,6,3,7,4,5,3,12,0,9 };

	//β�巨����ѭ������
	CreateListR(L, a, 10);

	//����ѭ������
	DispList(L);

	//����е�i��Ԫ��
	int x = 4;
	int x1;
	GetElem(L, x, x1);
	cout << "���е�4��Ԫ����" << x1 << endl;

	//���һ��e�ڱ��е����
	int y = 3;
	cout << "��һ��3�ڱ��е�λ���ǣ�" << LocateElem(L, y) << endl;

	//ɾ����i��Ԫ��
	int e;
	ListDelete(L, 2, e);
	cout << "ɾ����Ԫ���ǣ�" << e << endl;

	//����ѭ������
	DispList(L);

	//ͳ��e�ĸ���
	cout << "\"5\"����" << count(L, 5) << "��" << endl;

	//ɾ����һ��e
	int e2 = 5;
	cout << "ɾ����һ��5" << endl;
	deletem(L, e2);

	//����ѭ������
	DispList(L);

	return 0;
}
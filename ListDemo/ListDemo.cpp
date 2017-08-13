// ListDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void display(LinkList L) {
	while (L->next !=NULL) {
		L = L->next;
		printf("%d ", L->data);
	}
	printf("\n");
}

int GetElem(LinkList L, int i, int &e) {//��ȡ�����е�i��Ԫ��
	LNode *p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return -1;
	e = p->data;
	return 1;
}

int GetListLength(LinkList L)
{//�������нڵ�ĸ���
	if (L == NULL)
		return 0;
	int Length = 0;
	LinkList pCurrent = L;
	while (pCurrent->next != NULL) {//���һ���ڵ���NULL�����ǲ���������һ���ڵ�
		Length++;
		pCurrent = pCurrent->next;
	}
	return Length;
}

int ListInsert(LinkList &L, int i, int e) {//���뵽��i��֮��,
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1) {//������i��ֵ��СΪ1
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return -1;
	LNode *s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;//�Ƚ��½ڵ�ָ����һ���ڵ㣬�ٽ��ɽڵ�ָ���½ڵ�
	p->next = s;
	return 1;
}


LinkList ListReverse(LinkList L) {//�ǵݹ鷽��ʵ��������ת
	LinkList current, pnext, prev;
	int length = GetListLength(L);
	if (L == NULL || L->next == NULL)
		return L;
	current = L->next;  /* p1ָ������ͷ�ڵ����һ���ڵ� ,��Ϊͷ�ڵ㲻������*/
	pnext = current->next;
	current->next = NULL;
	while (pnext)
	{
		prev = pnext->next;
		pnext->next = current;
		current = pnext;
		pnext = prev;
		printf("������current = %d,next = %d \n", current->data, current->next->data);
	}
	//printf("current = %d,next = %d \n",current->data,current->next->data);
	L->next = current;  /* ������ͷ�ڵ�ָ��p1 */
	return L;
}

void CreteList(LinkList &L, int n) 
{//�����û����봴��������
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i >0; i--) {
		LNode *p = (LinkList)malloc(sizeof(LNode));
		int d;
		scanf("%d", &d);
		p->data = d;
		p->next = L->next;
		L->next = p;
	}
}


int main()
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < 6; i++) {
		ListInsert(L, i+1, i);
	}
	/*for (int i = 0; i < 6; i++) {
		int e;
		GetElem(L, i+1, e);
		printf("%d  ", e);
	}*/
	//CreteList(L, 6);
	//printf("%d  ", L->next->data);
	LNode * p = ListReverse(L);
	display(p);

	printf("%d  ", GetListLength(p));
}

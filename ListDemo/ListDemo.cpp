// ListDemo.cpp : 定义控制台应用程序的入口点。
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

int GetElem(LinkList L, int i, int &e) {//获取链表中第i个元素
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
{//求单链表中节点的个数
	if (L == NULL)
		return 0;
	int Length = 0;
	LinkList pCurrent = L;
	while (pCurrent->next != NULL) {//最后一个节点是NULL，但是不能算作是一个节点
		Length++;
		pCurrent = pCurrent->next;
	}
	return Length;
}

int ListInsert(LinkList &L, int i, int e) {//插入到第i个之后,
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1) {//决定了i的值最小为1
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return -1;
	LNode *s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;//先将新节点指向下一个节点，再将旧节点指向新节点
	p->next = s;
	return 1;
}


LinkList ListReverse(LinkList L) {//非递归方法实现链表反转
	LinkList current, pnext, prev;
	int length = GetListLength(L);
	if (L == NULL || L->next == NULL)
		return L;
	current = L->next;  /* p1指向链表头节点的下一个节点 ,因为头节点不存数据*/
	pnext = current->next;
	current->next = NULL;
	while (pnext)
	{
		prev = pnext->next;
		pnext->next = current;
		current = pnext;
		pnext = prev;
		printf("交换后：current = %d,next = %d \n", current->data, current->next->data);
	}
	//printf("current = %d,next = %d \n",current->data,current->next->data);
	L->next = current;  /* 将链表头节点指向p1 */
	return L;
}

void CreteList(LinkList &L, int n) 
{//根据用户输入创建单链表
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


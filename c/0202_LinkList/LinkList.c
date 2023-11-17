/**************************************************
 * Filename         :LinkList.c
 * Description      :线性表--链表实现
 * Time             :2023/11/16 14:22:29
 * Author           :promenader
 ***************************************************/

#include "LinkList.h"

/*************************************************
 * Description    :初始化链表结构体
 * Arguments      :
 * Returns        :
 *************************************************/
Status InitList(LinkList *l)
{
	l->head = NULL;
	l->length = 0;
	return SUCCESS;
}

/*************************************************
 * Description    :随机初始化链表
 * Arguments      :
 * Returns        :
 *************************************************/
Status RandomInit(LinkList *l)
{
	InitList(l);
	int i = 0;
	pNode p = NULL;

	pNode tail;

	for (i = 0; i < INIT_LENGTH; i++)
	{
		p = (pNode)malloc(sizeof(Node));
		if (p == NULL)
		{
			return ERROR;
		}
		p->data = rand() % 100;
		p->next = NULL;

		if (l->head == NULL)
		{
			l->head = p;
			tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}

		l->length++;
	}
	return SUCCESS;
}

/*************************************************
 * Description    :打印链表
 * Arguments      :
 * Returns        :
 *************************************************/
Status PrintList(LinkList *l)
{
	printf("\n链表长度: %d\n", l->length);
	int i;
	pNode cur = l->head;
	char g = '\0';
	printf("[");
	for (i = 0; i < l->length; i++)
	{
		printf("%c", g);
		printf("%d", cur->data);
		cur = cur->next;
		g = ',';
	}
	printf("]\n");
}
/**************************************************
 * Filename         :LinkList.h
 * Description      :线性表的链式存储结构
 * Time             :2023/11/16 13:54:57
 * Author           :promenader
 ***************************************************/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define INIT_LENGTH 10
// 顺序表元素类型定义
typedef int ElemType;

// 链表节点
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;

// 链表节点指针
typedef Node *pNode;

// 链表结构体
typedef struct LinkList
{
	pNode head;
	int length;
} LinkList;

Status InitList(LinkList *l);
Status RandomInit(LinkList *l);
Status PrintList(LinkList *l);
Status DestroyList(LinkList *l);
Status ClearList(LinkList l);
Status ListEmpty(LinkList l);
int ListLength(LinkList l);
Status GetElem(LinkList l, int i, ElemType *e);
int LocateElem(LinkList l, ElemType e, Status(Compare)(ElemType, ElemType));
Status PriorElem(LinkList l, ElemType cur_e, ElemType *pre_e);
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(LinkList L, int i, ElemType e);
Status ListDelete(LinkList L, int i, ElemType *e);
void ListTraverse(LinkList L, void(Visit)(ElemType));
#endif
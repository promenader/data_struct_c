/**************************************************
 * Filename         :SqList.h
 * Description      :
 * Time             :2023/11/09 09:45:28
 * Author           :promenader
 ***************************************************/

#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>	   //标准IO库
#include <stdlib.h>	   //提供malloc，realloc等内存分配函数
#include "../common.h" //公共常量定义

#define LIST_INIT_SIZE 100 // 顺序表存储空间初始量
#define LIST_INCREMENT 10  // 顺序表存储空间的增量

// 顺序表元素类型定义
typedef int ElemType;

// 顺序表结构体
typedef struct
{
	ElemType *e; // 顺序表存储数据的指针
	int length;	 // 顺序表实际数据长度
	int cap;	 // 顺序表容量大小
} SqList;

Status InitList(SqList *l);
Status RandomInit(SqList *l);
Status DestroyList(SqList *l);
Status ClearList(SqList *l);
Boolean ListEmpty(SqList l);
int ListLength(SqList l);
Status GetElem(SqList l, int i, ElemType *e);
int LocateElem(SqList l, ElemType e, Status(Compare)(ElemType, ElemType));
Status PriorElem(SqList l, ElemType cur_e, ElemType *pre_e);
Status NextElem(SqList l, ElemType cur_e, ElemType *next_e);
Status ListInsert(SqList *l, int i, ElemType e);
Status ListDelete(SqList *l, int i, ElemType *e);
void ListTraverse(SqList l, void(Visit)(ElemType));
void PrintList(SqList l);
Status EqCompare(ElemType m, ElemType n);
void Visit(ElemType e);

void Union(SqList *la, SqList lb);

void BubbleSort(SqList *l);
void MergeSqList(SqList la, SqList lb, SqList *lc);
#endif
/**************************************************
 * Filename         :main.c
 * Description      :顺序表单元测试
 * Time             :2023/11/10 15:55:36
 * Author           :promenader
 ***************************************************/

#include <stdio.h>
#include "SqList.h"

int main(int argc, char const *argv[])
{
	SqList l;

	printf("顺序表初始化\n");
	InitList(&l);
	PrintList(l);

	printf("\n顺序表随机初始化\n");
	RandomInit(&l);
	PrintList(l);

	printf("\n顺序表销毁\n");
	DestroyList(&l);
	PrintList(l);

	printf("\n顺序表清空\n");
	InitList(&l);
	ClearList(&l);
	PrintList(l);

	printf("\n顺序表判空\n");
	RandomInit(&l);
	Boolean s = ListEmpty(l);
	if (s == TRUE)
	{
		printf("顺序表空：TRUE\n");
	}
	else
	{
		printf("顺序表空：FALSE");
	}

	printf("\n顺序表长度\n");
	int length = ListLength(l);
	printf("length:%d\n", length);

	printf("\n顺序表获取元素\n");
	PrintList(l);
	ElemType e;
	int index = 0;
	GetElem(l, index, &e);
	printf("位置:%d,值：%d\n", index, e);

	printf("\n顺序表查找元素\n");
	ElemType f = 83;
	int result;
	result = LocateElem(l, f, EqCompare);
	printf("result: %d\n", result);

	printf("\n顺序表查找前一个元素\n");
	ElemType pre;
	PriorElem(l, f, &pre);
	printf("顺序表查找前一个：%d\n", pre);

	printf("\n顺序表查找后一个元素\n");
	ElemType next;
	NextElem(l, f, &next);
	printf("顺序表查找后一个：%d\n", next);

	printf("\n顺序表插入一个元素\n");
	ListInsert(&l, 0, f);
	PrintList(l);

	printf("\n顺序表删除一个元素\n");
	ElemType del;
	ListDelete(&l, 0, &del);
	PrintList(l);

	printf("\n顺序表遍历\n");
	ListTraverse(l, Visit);

	printf("\n顺序表合并\n");
	SqList la, lb;
	InitList(&la);
	RandomInit(&la);
	InitList(&lb);
	RandomInit(&lb);
	PrintList(la);
	PrintList(lb);
	Union(&la, lb);
	PrintList(la);

	printf("\n顺序表排序\n");
	BubbleSort(&l);
	PrintList(l);

	printf("\n有序顺序表合并\n");
	SqList ld, le;
	InitList(&ld);
	RandomInit(&ld);
	InitList(&le);
	RandomInit(&le);
	BubbleSort(&ld);
	BubbleSort(&le);
	SqList lc;
	PrintList(ld);
	PrintList(le);
	MergeSqList(ld, le, &lc);
	PrintList(lc);

	return 0;
}
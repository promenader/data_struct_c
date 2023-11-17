/**************************************************
 * Filename         :SqList.c
 * Description      :
 * Time             :2023/11/09 13:49:36
 * Author           :promenader
 ***************************************************/

#include "SqList.h"

/*************************************************
 * Description    :初始化顺序表
 * Arguments      :
 * Returns        :
 *************************************************/
Status InitList(SqList *l)
{
	// 分配内存
	l->e = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	// 判断分配内存是否成功
	if (l->e == NULL)
	{
		exit(ERROR);
	}
	// 设置顺序表长度和容量
	l->length = 0;
	l->cap = LIST_INIT_SIZE;
	return SUCCESS;
}

/*************************************************
 * Description    :给顺序表元素随机初始化值
 * Arguments      :
 * Returns        :
 *************************************************/
Status RandomInit(SqList *l)
{
	int i;
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		l->e[i] = rand() % 100;
	}
	l->length = LIST_INIT_SIZE;
	return SUCCESS;
}

/*************************************************
 * Description    :释放顺序表内存
 * Arguments      :
 * Returns        :
 *************************************************/
Status DestroyList(SqList *l)
{
	// 判断指针非空
	if (l == NULL || l->e == NULL)
	{
		return ERROR;
	}

	// 释放存储
	free(l->e);
	// 数据归零
	l->e = NULL;
	l->length = 0;
	l->cap = 0;
	return SUCCESS;
}

/*************************************************
 * Description    :清空数据，不释放内存
 * Arguments      :
 * Returns        :
 *************************************************/
Status ClearList(SqList *l)
{
	if (l == NULL || l->e == NULL)
	{
		return ERROR;
	}
	l->length = 0;
	return SUCCESS;
}

/*************************************************
 * Description    :判断顺序表空
 * Arguments      :
 * Returns        :
 *************************************************/
Boolean ListEmpty(SqList l)
{
	return l.length == 0 ? TRUE : FALSE;
}

/*************************************************
 * Description    :顺序表长度
 * Arguments      :
 * Returns        :
 *************************************************/
int ListLength(SqList l)
{
	return l.length;
}

/*************************************************
 * Description    :从顺序表l中取位置i的值放入*e中
 * Arguments      :
 * Returns        :
 *************************************************/
Status GetElem(SqList l, int i, ElemType *e)
{
	// 数组的位置从0开始到length-1
	if (i < 0 || i > l.length - 1)
	{
		return ERROR;
	}

	// 通过指针取出顺序表中值
	*e = l.e[i];
	return SUCCESS;
}

/*************************************************
 * Description    :返回顺序表中首个满足Compare元素的位置
 * 				  （从0到length-1）
 * Arguments      :
 * Returns        :
 *************************************************/
int LocateElem(SqList l, ElemType e, Status(Compare)(ElemType, ElemType))
{
	// 返回索引值
	int i = 0;
	// 判断非空
	if (l.e == NULL)
	{
		return ERROR;
	}
	// 遍历顺序表
	while (i < l.length && !Compare(l.e[i], e))
	{
		i++;
	}

	if (i < l.length)
	{
		return i;
	}
	// 如果都不满足Compare条件，返回-1
	return ERROR;
}

/*************************************************
 * Description    :获取顺序表中cur_e元素的前一个元素，存入*pre_e
 * Arguments      :
 * Returns        :
 *************************************************/
Status PriorElem(SqList l, ElemType cur_e, ElemType *pre_e)
{
	// 判断非空，且至少2个元素
	if (l.e == NULL || l.length < 2)
	{
		return ERROR;
	}
	int i = 0;
	// 遍历顺序表
	while (i < l.length && l.e[i] != cur_e)
	{
		i++;
	}

	// cur_e是首个元素，或者不存在
	if (i == 0 || i >= l.length)
	{
		return ERROR;
	}
	// 存在时，记录前一个元素
	*pre_e = l.e[i - 1];
	return SUCCESS;
}

/*************************************************
 * Description    :获取顺序表中cur_e元素的后一个元素，存入*next_e
 * Arguments      :
 * Returns        :
 *************************************************/
Status NextElem(SqList l, ElemType cur_e, ElemType *next_e)
{
	// 判断非空，且至少2个元素
	if (l.e == NULL || l.length < 2)
	{
		return ERROR;
	}

	int i = 0;
	// 遍历顺序表
	while (i < l.length - 1 && l.e[i] != cur_e)
	{
		i++;
	}
	// cur_e是最后一个元素或者不存在
	if (i >= l.length - 1)
	{
		return ERROR;
	}

	// 存在时，记录后一个元素
	*next_e = l.e[i + 1];
	return SUCCESS;
}

/*************************************************
 * Description    :向顺序表第i个位置上插入元素e
 * Arguments      :
 * Returns        :
 *************************************************/
Status ListInsert(SqList *l, int i, ElemType e)
{
	// 判断顺序表非空
	if (l == NULL || l->e == NULL)
	{
		return ERROR;
	}

	// 判断位置i合法,i表示当前插入位置
	if (i < 0 || i > l->length)
	{
		return ERROR;
	}
	// 判断是否需要扩容
	if (l->length >= l->cap)
	{
		ElemType *ne = (ElemType *)realloc(l->e, (l->cap + LIST_INCREMENT) * sizeof(ElemType));
		if (ne == NULL)
		{
			return ERROR;
		}
		l->e = ne;
		l->cap += LIST_INCREMENT;
	}

	// 从最后一个元素往前移
	int move;
	for (move = l->length; move >= i; move--)
	{
		l->e[move] = l->e[move - 1];
	}
	// 插入元素
	l->e[i] = e;
	// 长度增长1
	l->length++;
	return SUCCESS;
}

/*************************************************
 * Description    :删除顺序表第i个元素，删除元素放入*e中
 * Arguments      :
 * Returns        :
 *************************************************/
Status ListDelete(SqList *l, int i, ElemType *e)
{
	// 判断顺序表非空
	if (l == NULL || l->e == NULL)
	{
		return ERROR;
	}

	// 判断位置i合法
	if (i < 0 || i > l->length - 1)
	{
		return ERROR;
	}

	*e = l->e[i];

	// 从第i个元素往后遍历
	int move;
	for (move = i; move < l->length; move++)
	{
		l->e[move] = l->e[move + 1];
	}
	l->length--;
	return SUCCESS;
}

/*************************************************
 * Description    :遍历顺序表
 * Arguments      :
 * Returns        :
 *************************************************/
void ListTraverse(SqList l, void(Visit)(ElemType))
{
	int i;
	for (i = 0; i < l.length; i++)
	{
		Visit(l.e[i]);
	}
	printf("\n");
}

/*************************************************
 * Description    :打印顺序表
 * Arguments      :
 * Returns        :
 *************************************************/
void PrintList(SqList l)
{
	printf("顺序表长度：%d，顺序表容量：%d\n", l.length, l.cap);
	if (l.e == NULL)
	{
		printf("顺序表元素指针：NULL\n");
	}
	else
	{
		printf("顺序表的值：[");

		int i;
		char g = '\0';
		for (i = 0; i < l.length; i++)
		{
			printf("%c", g);
			printf("%d", l.e[i]);
			g = ',';
		}
		printf("]\n");
	}
}

/*************************************************
 * Description    :对比函数
 * Arguments      :
 * Returns        :
 *************************************************/
Status EqCompare(ElemType m, ElemType n)
{
	return m == n ? TRUE : FALSE;
}

/*************************************************
 * Description    :访问数据值
 * Arguments      :
 * Returns        :
 *************************************************/
void Visit(ElemType e)
{
	printf("%d ", e);
}

/*************************************************
 * Description    :合并两个顺序表 la = la U lb
 * Arguments      :
 * Returns        :
 *************************************************/
void Union(SqList *la, SqList lb)
{
	int i;
	for (i = 0; i < lb.length; i++)
	{
		int index = LocateElem(*la, lb.e[i], EqCompare);
		if (index == ERROR)
		{
			ListInsert(la, la->length, lb.e[i]);
		}
	}
}

/*************************************************
 * Description    :顺序表的冒泡排序(非递减)
 * Arguments      :
 * Returns        :
 *************************************************/
void BubbleSort(SqList *l)
{
	int i, j;
	// 遍历顺序表
	for (i = 0; i < l->length; i++)
	{
		for (j = i + 1; j < l->length; j++)
		{
			if (l->e[i] > l->e[j])
			{
				// 交换
				int tmp = l->e[i];
				l->e[i] = l->e[j];
				l->e[j] = tmp;
			}
		}
	}
}

/*************************************************
 * Description    :有序顺序表的合并
 * Arguments      :
 * Returns        :
 *************************************************/
void MergeSqList(SqList la, SqList lb, SqList *lc)
{
	int i = 0;
	int j = 0;
	int k = 0;
	InitList(lc);

	while (i < la.length && j < lb.length)
	{
		if (la.e[i] < lb.e[j])
		{
			// lc->e[k] = la.e[i];
			ListInsert(lc, k, la.e[i]);
			k++;
			i++;
		}
		else
		{
			// lc->e[k] = lb.e[j];
			ListInsert(lc, k, lb.e[j]);
			j++;
			k++;
		}
	}

	while (i < la.length)
	{
		// lc->e[k] = la.e[i];
		ListInsert(lc, k, la.e[i]);
		k++;
		i++;
	}
	while (j < lb.length)
	{
		// lc->e[k] = lb.e[j];
		ListInsert(lc, k, lb.e[j]);
		k++;
		j++;
	}
}
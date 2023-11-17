/**************************************************
 * Filename         :main.c
 * Description      :线性表--链表 单元测试
 * Time             :2023/11/16 15:12:08
 * Author           :promenader
 ***************************************************/

#include "LinkList.h"
int main(int argc, char const *argv[])
{
	LinkList l;
	printf("\n链表初始化\n");
	InitList(&l);
	PrintList(&l);

	printf("\n链表随机值初始化\n");
	InitList(&l);
	RandomInit(&l);
	PrintList(&l);

	return 0;
}

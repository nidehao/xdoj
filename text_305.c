//#define _CRT_SECURE_NO_WARNINGS 1
//
////判断堆栈出栈序列是否有效
//
////描述：
////如果以序列“1, 2, 3, 4”作为一个栈（初始为空）的输入，
//// 那么可得到输出序列“1, 2, 3, 4”或“4, 3, 2, 1”或“2, 3, 1, 4”等等，
//// 但是肯定得不到输出序列“4, 1, 2, 3”或“3, 1, 2, 4”等等。
//// 请编写一个程序，判断能否通过一个栈得到给定的输出序列。
//
////输入说明：
////每组数据由两行构成，第一行只有一个整数n（ < 10），表示序列长度，
//// 同时表示栈的输入序列为“1, 2, 3, …, n”；第二行为n个整数，表示需要判断的出栈序列，整数之间以空格分隔。
//
////	输出说明：
////	输出一个yes或no（表示能否通过栈得到该序列）。
//
////	输入样例：
///*
//6
//3 4 2 1 5 6
//*/
//
////	输出样例：
////	yes
//
////	提示
////	根据栈的后进先出特性进行判断
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node
//{
//	int date;
//	struct node* next;
//}Stack;
//
//void Push(Stack** top, int date);
//
//void Pop(Stack** top);
//
//int main()
//{
//	Stack* s = NULL;
//	int n, a[100] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	for (int i = 1, j = 0; j < n && i <= n + 1; )
//	{
//		if (s == NULL || s->date != a[j])
//		{
//			Push(&s, i);
//			i++;
//		}
//		else
//		{
//			Pop(&s);
//			j++;
//		}
//	}
//	if (s == NULL)
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}
//
//void Pop(Stack** top)
//{
//	if (*top == NULL)
//		return;
//	Stack* pt = *top;
//	*top = (*top)->next;
//	free(pt);
//}
//
//
//void Push(Stack** top, int date)
//{
//	Stack* pt = (Stack*)malloc(sizeof(Stack));
//	if (pt == NULL)
//		return;
//	pt->date = date;
//	pt->next = *top;
//	*top = pt;
//}
//



//#define _CRT_SECURE_NO_WARNINGS 1
//
////�ж϶�ջ��ջ�����Ƿ���Ч
//
////������
////��������С�1, 2, 3, 4����Ϊһ��ջ����ʼΪ�գ������룬
//// ��ô�ɵõ�������С�1, 2, 3, 4����4, 3, 2, 1����2, 3, 1, 4���ȵȣ�
//// ���ǿ϶��ò���������С�4, 1, 2, 3����3, 1, 2, 4���ȵȡ�
//// ���дһ�������ж��ܷ�ͨ��һ��ջ�õ�������������С�
//
////����˵����
////ÿ�����������й��ɣ���һ��ֻ��һ������n�� < 10������ʾ���г��ȣ�
//// ͬʱ��ʾջ����������Ϊ��1, 2, 3, ��, n�����ڶ���Ϊn����������ʾ��Ҫ�жϵĳ�ջ���У�����֮���Կո�ָ���
//
////	���˵����
////	���һ��yes��no����ʾ�ܷ�ͨ��ջ�õ������У���
//
////	����������
///*
//6
//3 4 2 1 5 6
//*/
//
////	���������
////	yes
//
////	��ʾ
////	����ջ�ĺ���ȳ����Խ����ж�
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



#define _CRT_SECURE_NO_WARNINGS 1

//����ƥ��ļ���

//������
//����һ�����ʽ��һ�γ����к����������ţ�
// Բ���š������͡������������š�[���͡�]���������š�{ ���͡� }����
// ��дһ�������б�����ı��ʽ����������������Ƿ���ȷ��Գ��֡�

//����˵����
//ÿ��Ϊһ���������ŵı��ʽ��һ�γ���

//���˵����
//���һ��right��wrong��������ȷƥ�����

//����������
/*
while(m<(a[8]+t){m=m+1;t=t-1;}
*/
//���������
//wrong

//��ʾ
//��ջ��ʵ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char date;
	struct node* next;
}Stack;

void Push(Stack** top, char date);

char Pop(Stack** top);

int main()
{
	Stack* top = NULL;
	char str[1000] = {0};
	//scanf("%s", str);
	gets(str);
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(' || str[i] == '[' ||str[i] == '{')
		{
			Push(&top, str[i]);
			continue;
		}

		switch (str[i])
		{	
		case ')':
		{
			if ('(' != Pop(&top))
			{
				printf("wrong");
				return 0;
			}
			break;
		}
		case ']':
		{
			if ('[' != Pop(&top))
			{
				printf("wrong");
				return 0;
			}
			break;
		}
		case '}':
		{
			if ('{' != Pop(&top))
			{
				printf("wrong");
				return 0;
			}
			break;
		}
		default:
			break;
		}
	}
	if (Pop(&top) == '0')
		printf("right");
	else
		printf("wrong");
	return 0;
}


void Push(Stack** top, char date)
{
	Stack* pt = (Stack*)malloc(sizeof(Stack));
	if (pt == NULL)
		return;
	pt->date = date;
	pt->next = *top;
	*top = pt;
}


char Pop(Stack** top)
{
	if (*top == NULL)
		return '0';
	Stack* pt = *top;
	*top = (*top)->next;
	char c = pt->date;
	free(pt);
	return c;
}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[100], stack[100], top;
//	top = -1;//top=-1��ʾջΪ�գ���ջtop��һȻ����ջ����ջtop-1
//	gets(str);
//	int i, len, flag = 1;
//	len = strlen(str);//�ַ����ĳ���
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == '(' || str[i] == '{' || str[i] == '[')//��������ջ
//		{
//			top++;
//			stack[top] = str[i];
//		}
//		if (str[i] == ')')
//		{
//			if (stack[top] == '(')//������ƥ��
//				top--;
//			else//�����Ų�ƥ��
//			{
//				flag = 0; break;
//			}
//		}
//		if (str[i] == '}')
//		{
//			if (stack[top] == '{')
//				top--;
//			else
//			{
//				flag = 0; break;
//			}
//		}
//		if (str[i] == ']')
//		{
//			if (stack[top] == '[')
//				top--;
//			else
//			{
//				flag = 0; break;
//			}
//		}
//	}
//	if (flag == 1 && top == -1)//�������Ŷ�ƥ����ջ��
//		printf("right");
//	else
//		printf("wrong");
//	return 0;
//}

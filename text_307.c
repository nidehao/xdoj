#define _CRT_SECURE_NO_WARNINGS 1

//括号匹配的检验

//描述：
//假设一个表达式或一段程序中含有三种括号：
// 圆括号“（”和“）”、方括号“[”和“]”、花括号“{ ”和“ }”。
// 试写一个程序判别给定的表达式或程序中所含括号是否正确配对出现。

//输入说明：
//每行为一个含有括号的表达式或一段程序。

//输出说明：
//输出一个right或wrong，表明正确匹配与否。

//输入样例：
/*
while(m<(a[8]+t){m=m+1;t=t-1;}
*/
//输出样例：
//wrong

//提示
//用栈来实现

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
//	top = -1;//top=-1表示栈为空，入栈top加一然后入栈，出栈top-1
//	gets(str);
//	int i, len, flag = 1;
//	len = strlen(str);//字符串的长度
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == '(' || str[i] == '{' || str[i] == '[')//左括号入栈
//		{
//			top++;
//			stack[top] = str[i];
//		}
//		if (str[i] == ')')
//		{
//			if (stack[top] == '(')//右括号匹配
//				top--;
//			else//右括号不匹配
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
//	if (flag == 1 && top == -1)//左右括号都匹配且栈空
//		printf("right");
//	else
//		printf("wrong");
//	return 0;
//}

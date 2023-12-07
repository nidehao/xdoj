#define _CRT_SECURE_NO_WARNINGS 1
//后缀表达式求值

//问题描述
//对逆波兰式（即后缀表达式）求值。其中每个操作数的取值范围为0~9，均为个位数。
// 运算符为加减乘除四种（ + 、 - 、 * 、 / ）。如（4 + 5） * 2 - 3的逆波兰式为45 + 2 * 3 - 。
//输入说明：
//一个字符串表示的逆波兰式，如：45 + 2 * 3 - ，表达式的长度不超过100。表达式均没有错误。

//输出说明：
//表达式的值。

//输入样例：
//45+2*3-

//输出样例
//15

//提示
//可采用栈为辅助存储结构，碰到操作数则入栈，碰到操作符则连续两次出栈，然后进行计算。

//队列
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int date;
	struct node* next;
}Stack;

void Push(Stack** top, int date);

int Pop(Stack** top);

int main()
{
	Stack* s = NULL;
	char str[100] = { '0' };
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '+':
		{
			int a = Pop(&s);
			int b = Pop(&s);
			Push(&s, b + a);
			break;
		}
		case '-':
		{
			int a = Pop(&s);
			int b = Pop(&s);
			Push(&s, b - a);
			break;
		}
		case '*':
		{
			int a = Pop(&s);
			int b = Pop(&s);
			Push(&s, b * a);
			break;
		}
		case '/':
		{
			int a = Pop(&s);
			int b = Pop(&s);
			Push(&s, b / a);
			break;
		}
		default:
		{
			Push(&s, (int)(str[i] - '0'));
			break;
		}
		}
	}
	printf("%d\n", Pop(&s));
	return 0;
}


int Pop(Stack** top)
{
	if (*top == NULL)
		return 0;
	Stack* pt = *top;
	*top = pt->next;
	int a = pt->date;
	return a;
}


void Push(Stack** top, int date)
{
	Stack* pt = (Stack*)malloc(sizeof(Stack));
	if (pt == NULL)
		return;
	pt->date = date;
	pt->next = *top;
	*top = pt;
}


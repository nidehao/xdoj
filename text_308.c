#define _CRT_SECURE_NO_WARNINGS 1

//前缀表达式求值

//问题描述
//对前缀表达式求值，其中操作数为正整数，运算符只包含 + -*/ ，
// 运算结果也为整数。如(42 + 8) * (36 - 6) + 9 / 3
// 的前缀表达式为： + *+42 8 – 36 6 / 9 3。

//输入说明：
//输入为一行，一个字符串表示的前缀表达式，如： + *+42 8 – 36 6 / 9 3，
// 表达式的长度不超过100，式中不同元素之间用空格隔开。

//输出说明：
//输出表达式的值（这里只考虑计算结果为整数的情况）。

//输入样例：
//+ * + 42 8 - 36 6 / 9 3


//输出样例
//1503

//提示
//从右到左倒过来处理字符串，采用栈作为辅助存储结构，
//碰到操作数则入栈，碰到操作符则连续两次出栈，然后进行计算，
//所得结果入栈，直至整个字符串处理完毕。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str[100] = { 0 };
	int stack[50] = { 0 };
	int* top = stack;
	gets(str);
	int a = 0, i = 0;
	int n = strlen(str);
	char* p = str + n - 1;
	while (p + 1 != str)
	{
		if (*p == ' ')
			p--;
		else
		{
			switch (*p)
			{
			case '+':
			{
				p--;
				top--;
				*(top - 1) = *top + *(top - 1);
				*top = 0;
				break;
			}
			case '-':
			{
				p--;
				top--;
				*(top - 1) = *top - *(top - 1);
				*top = 0;
				break;
			}
			case '*':
			{
				p--;
				top--;
				*(top - 1) = *top * *(top - 1);
				*top = 0;
				break;
			}
			case '/':
			{
				p--;
				top--;
				*(top - 1) = *top / *(top - 1);
				*top = 0;
				break;
			}
			default:
			{	
				a = 0;
				i = 1;
				while (*p != ' ' && p + 1 != str)
				{
					a = (int)(*p - '0') * i + a;
					p--;
					i = i * 10;
				}
				*top = a;
				top++;
				break;
			}
			}	
		}
	} 
	printf("%d", *(top - 1));
	return 0;
	
}

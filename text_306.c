#define _CRT_SECURE_NO_WARNINGS 1
//��׺���ʽ��ֵ

//��������
//���沨��ʽ������׺���ʽ����ֵ������ÿ����������ȡֵ��ΧΪ0~9����Ϊ��λ����
// �����Ϊ�Ӽ��˳����֣� + �� - �� * �� / �����磨4 + 5�� * 2 - 3���沨��ʽΪ45 + 2 * 3 - ��
//����˵����
//һ���ַ�����ʾ���沨��ʽ���磺45 + 2 * 3 - �����ʽ�ĳ��Ȳ�����100�����ʽ��û�д���

//���˵����
//���ʽ��ֵ��

//����������
//45+2*3-

//�������
//15

//��ʾ
//�ɲ���ջΪ�����洢�ṹ����������������ջ���������������������γ�ջ��Ȼ����м��㡣

//����
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


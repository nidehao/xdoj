
#define _CRT_SECURE_NO_WARNINGS 1
//����ȥ��

//����������
//����һ����ֵΪ�����ĵ����� L������ֵ�ľ���ֵ���ظ��Ľ��ɾ�������������ֵ K��ֻ
//�м�ֵ�������ֵ���� K �ĵ�һ����㱻������ L �С�


//����˵����
//����ĵ�һ�а��������������ֱ��ʾ�����һ�����ĵ�ַ�ͽ����� n��1��n��100������
//���ַ��һ���Ǹ��� 5 λ������NULL ָ���� - 1 ��ʾ��
//��� n �У�ÿ�к� 3 �������������и�ʽ����һ��������Ϣ��
//Address Key Next
//���� Address �ǽ��ĵ�ַ��Key �Ǿ���ֵ������ 10000 ��������Next ����һ�����ĵ�ַ��


//���˵����
//����ĵ�һ��Ϊȥ�غ����� L �ĳ��ȣ����У���������˳����� L �����н�㣬ÿ�����
//ռһ�У����� Address Key Next �ĸ�ʽ�������� 1 ���ո�


//����������
//�������� 1
/*
00100 5
99999 7 87654
23854 -15 00000
87654 -15 -1
00000 15 99999
00100 21 23854
*/


//������� 1
//3
//00100 21 23854
//23854 - 15 99999
//99999 7 -1

#include<stdio.h>
#include<stdlib.h>
 
typedef struct LNode{
	int address;
	int key;
	int next;
	struct LNode* p_next;
}LNode;

/*��ʼ��*/
void Init(LNode* node_head);

/*���*/
void Print(LNode* node_head);

/*����ȥ��*/
void RemoveSame(LNode* node_head);

int main()
{
	LNode node_head = {0, 0, 0, NULL};
	scanf("%d %d", &node_head.next, &node_head.key);
	Init(&node_head);
	RemoveSame(&node_head);
	Print(&node_head);
	return 0;

}

/*����ȥ��*/
void RemoveSame(LNode* node_head)
{
	if (node_head == NULL || node_head->key < 2)
		return;
	LNode* pt = node_head->p_next;
	while (pt != NULL)
	{
		LNode* pt1 = pt;
		while (pt1->p_next != NULL)
		{
			if (abs(pt1->p_next->key) == abs(pt->key))
			{
				LNode* pt2 = pt1->p_next;
				pt1->p_next = pt2->p_next;
				pt1->next = pt2->next;
				free(pt2);
				node_head->key--;
				continue;
			}
			pt1 = pt1->p_next;
		}
		pt = pt->p_next;
	}
}


void Print(LNode* node_head)
{
	if (node_head == NULL)
		return;
	printf("%d\n", node_head->key);
	LNode* pt = node_head->p_next;
	while (pt->p_next != NULL)
	{
		printf("%05d %d %05d\n", pt->address, pt->key, pt->next);
		pt = pt->p_next;
	}
	printf("%05d %d %d\n", pt->address, pt->key, pt->next);
}


void Init(LNode* node_head)
{
	if (node_head == NULL || node_head->key < 1)
		return;
	LNode a[100] = {0};
	for (int i = 0; i < node_head->key; i++) 
	{
		scanf("%d %d %d", &a[i].address, &a[i].key, &a[i].next);
		a[i].p_next = NULL;
	}
	LNode* pt = node_head;
	for (int i = 0; i < node_head->key; i++)
	{
		if (a[i].address == pt->next)
		{
			LNode* pt1 = (LNode*)malloc(sizeof(LNode));
			if (pt1 == NULL)
				return;
			pt1->address = a[i].address;
			pt1->key = a[i].key;
			pt1->next = a[i].next;
			pt1->p_next = a[i].p_next;
			pt->p_next = pt1;
			pt = pt->p_next;
			i = -1;
		}
	}
	pt->p_next = NULL;
}




#define _CRT_SECURE_NO_WARNINGS 1
//链表去重

//问题描述：
//给定一个键值为整数的单链表 L，将键值的绝对值有重复的结点删除：即对任意键值 K，只
//有键值或其绝对值等于 K 的第一个结点被保留在 L 中。


//输入说明：
//输入的第一行包含两个整数，分别表示链表第一个结点的地址和结点个数 n（1≤n≤100）。结
//点地址是一个非负的 5 位整数，NULL 指针用 - 1 表示。
//随后 n 行，每行含 3 个整数，按下列格式给出一个结点的信息：
//Address Key Next
//其中 Address 是结点的地址，Key 是绝对值不超过 10000 的整数，Next 是下一个结点的地址。


//输出说明：
//输出的第一行为去重后链表 L 的长度，换行；接下来按顺序输出 L 的所有结点，每个结点
//占一行，按照 Address Key Next 的格式输出，间隔 1 个空格。


//测试样例：
//输入样例 1
/*
00100 5
99999 7 87654
23854 -15 00000
87654 -15 -1
00000 15 99999
00100 21 23854
*/


//输出样例 1
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

/*初始化*/
void Init(LNode* node_head);

/*输出*/
void Print(LNode* node_head);

/*链表去重*/
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

/*链表去重*/
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



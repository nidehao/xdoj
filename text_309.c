#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ1������ӷ�����
//��������
//��ϡ�����A�ķ���Ԫ������Ϊ�����˳�����һά����V�У����ö�ά����B��ʾA�е���ӦԪ���Ƿ�Ϊ��Ԫ��
//���ʵ��������ʾ���ľ���ӷ����㡣
//�����ʽ
//����������������n��m��Ϊ����ά����Ȼ���������������ֵB1��V1��B2��V2��
//�����ʽ
//�������������B��V��
//��������
/*
3 4
1 0 0 1
0 1 0 0
1 0 0 0
15 22 -6 9
0 1 1 0
0 1 1 0
1 0 0 1
3 2 6 2 -5 8
*/
//�������
//1 1 1 1
//0 0 1 0
//1 0 0 1
//15 3 2 22 4 8


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[100][100] = { 0 }, b[100][100] = { 0 };
	int a1[100] = { 0 }, b1[100] = { 0 }, c[100] = { 0 };
	int i = 0, j = 0, ka = 0, kb = 0, kc = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
				ka++;
		}
	}
	for (i = 0; i < ka; i++)
		scanf("%d", &a1[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);
			if (b[i][j] == 1)
				kb++;
		}
	}
	for (i = 0; i < kb; i++)
		scanf("%d", &b1[i]);

	ka = 0;
	kb = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] == 1 || b[i][j] == 1)
			{
				if (a[i][j] == 0)
				{
					a[i][j] = 1;
					c[kc] = b1[kb];
					kb++;
					kc++;
				}
				else if (b[i][j] == 0)
				{
					c[kc] = a1[ka];
					ka++;
					kc++;
				}
				else
				{
					if (a1[ka] + b1[kb] == 0)
					{
						a[i][j] = 0;
					}
					else
					{
						c[kc] = a1[ka] + b1[kb];
						kc++;
					}
					ka++;
					kb++;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < kc; i++)
		printf("%d ", c[i]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

//有序表的合并去重

//问题描述
//已知两个有序线性表L1和L2，每个线性表中数据元素的值为单调增的正整数（ < 100个），
// 各线性表内部无重复元素。把L2中的元素合并到L1中，要求L1中数据元素的值仍为单调递增，且无重复元素。
	
//问题输入
//第一行输入两个正整数a, b，分别表示第一个线性表L1和第二个线性表L2的长度；
// 第2行依次输入L1中单调增的a个正整数；第3行依次输入L2中单调增的b个正整数。正整数均小于10000。

//问题输出
//共有1行，最终合并并去重后的结果，每个数字之间有一个空格。

//输入样例
/*
6 7
1 2 5 6 10 13
1 3 5 8 19 22 31
*/

//输出样例
//1 2 3 5 6 8 10 13 19 22 31

#include<stdio.h>

void Scanf(int n, int* a ) {
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
}


void Print(int* a) {
	int i;
	for (i = 1; i <= a[0]; i++)
	{
		printf("%d ", a[i]);
	}
}


int* SumList(int* a, int* b)
{//合并a,b,并去重
	int i, j, k;
	int c[201];
	for (i = 1, j = 1, k =1;i <= a[i]||j <= b[j];) {
		if (i > a[i]) {
			c[k] = b[j];
			k++;
			j++;
		}
		else if (j > b[j]) {
			c[k] = a[i];
			i++;
			k++;
		}
		else if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
			k++;
		}
		else{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	
	c[0] = k - 1;
	for (i = 1, j = 1; i <= c[0]; i++) {
		if (c[i] != c[i + 1])
		{
			a[j] = c[i];
			j++;
		}
	}
	a[0] = j-1;
	return a;
}


int main() {
	int L1[101] = { 0 }, L2[101] = {0};
	scanf("%d %d", &L1[0], &L2[0]);
	Scanf(L1[0], L1);
	Scanf(L2[0], L2);

	int* L3 = SumList(L1, L2);
	//printf("%d\n", L3[0]);
	Print(L3);
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//求矩阵中的马鞍点

//问题描述
//所设计的程序能够通过编译。若矩阵Amn中的某个元素aij是第i行中的最小值，
// 同时又是第j列中的最大值，则称此元素为该矩阵中的一个马鞍点。
// 编写程序求出矩阵中的所有马鞍点。

//输入格式
//首先输入两个整数n和m，为矩阵维数，然后输入矩阵的值。

//输出格式
//输出矩阵中的所有马鞍点，输出顺序：行序优先，按行、列序号递增顺序输出。
//，若有多个马鞍点，每个马鞍点一行。也可能没有马鞍点，则输出NO。

//样例输入
/*
4 4
2 7 9 10
1 0 7 12
8 23 13 15
4 6 12 18
*/

//样例输出
//3 1 8
#include<stdio.h>

int min(int* a, int m) {
	int i, j, flag;
	for (i = 0; i < m; i++) {
		for (j = i + 1, flag = 1; j < m; j++) {
			if (a[i] > a[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return i;
		}
		flag = 1;
	}
}

int main() {
	int a[100][100] = {0};
	int i, j, k, m, n, flag1, flag2;
	scanf("%d %d",&n ,&m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0, flag2 = 1; i < n; i++) {
		k = min(a[i], m);
		for (j = 0, flag1 = 1; j < n; j++) {
			if (a[i][k] < a[j][k]) {
				flag1 = 0;
				break;
			}
		}
		if (flag1) {
			printf("%d %d %d\n", i + 1, k + 1, a[i][k]);
			flag2 = 0;
		}
		flag1 = 1;
	}
	if (flag2) {
		printf("NO");
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//������е�����

//��������
//����Ƶĳ����ܹ�ͨ�����롣������Amn�е�ĳ��Ԫ��aij�ǵ�i���е���Сֵ��
// ͬʱ���ǵ�j���е����ֵ����ƴ�Ԫ��Ϊ�þ����е�һ�����㡣
// ��д������������е��������㡣

//�����ʽ
//����������������n��m��Ϊ����ά����Ȼ����������ֵ��

//�����ʽ
//��������е��������㣬���˳���������ȣ����С�����ŵ���˳�������
//�����ж�����㣬ÿ������һ�С�Ҳ����û�����㣬�����NO��

//��������
/*
4 4
2 7 9 10
1 0 7 12
8 23 13 15
4 6 12 18
*/

//�������
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
#define _CRT_SECURE_NO_WARNINGS 1
//���ĶԳƵ��ַ���

//������
//������n���ַ����ַ���������㷨�ж��ַ����Ƿ����ĶԳơ����磬xyzzyx��xyzyx�������ĶԳƵ��ַ�����

//����˵����
//ÿ��������2�У���һ��Ϊ����n����ʾ�ַ��ĸ�����nС��100���ڶ���Ϊn���ַ���ɵ��ַ�����

//���˵����
//�ж�����ַ����Ƿ������ĶԳƵģ��������YES�������������NO����

//����������
/*
12
ThanksThanks
*/

//���������
//NO

#include<stdio.h>

int main() {
	int n, flag, i;
	char str[101];
	scanf("%d", &n);
	scanf("%s", str);
	for (i = 0, flag = 1; i < n - i; i++)
	{
		if (str[i] != str[n -1 - i]) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		printf("YES");
	}
	else {
		printf("NO");
	}

	return 0;
}
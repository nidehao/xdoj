#define _CRT_SECURE_NO_WARNINGS 1
//��С���ڴ�

//������
//���һ���ַ���������ĳ������Ϊk���ַ����ظ���εõ���
// ����˵�ô���kΪ���ڡ����磬abcabcabcabc��3Ϊ���ڣ�ע�⣬��Ҳ��6��12Ϊ���ڣ���
// ����һ�����Ȳ�����80�Ĵ������������С���ڡ�

//����˵����
//ÿ������Ϊһ���ַ�����

//���˵����
//���ÿ���ַ�������С���ڡ�

//����������
//GeeGeeGee

//���������
//3

#include<stdio.h>

int StrMatch(char a[], char b[]) 
{//��b��ƥ��a
	int i, j;
	for (i = 0, j = 0;b[j] != '\0'; i++, j++) {
		if ((a[i] == '\0')) {
			i = -1;
			j--;
		}
		else if (a[i] != b[j])
		{
			return 0;
		}
	}
	return 1;
}

int main() {
	char str1[80], str2[80] = { '\0' };
	scanf("%s", str1);
	int i, j;
	for (i = 0; str1[i] != '\0'; i++)
	{
		str2[i] = str1[i];
		j = StrMatch(str2, str1);
		if (j) {
			printf("%d\n", i+1);
			return 0;
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//最小周期串

//描述：
//如果一个字符串可以由某个长度为k的字符串重复多次得到，
// 我们说该串以k为周期。例如，abcabcabcabc以3为周期（注意，它也以6和12为周期）。
// 输入一个长度不超过80的串，输出它的最小周期。

//输入说明：
//每组数据为一个字符串。

//输出说明：
//输出每组字符串的最小周期。

//输入样例：
//GeeGeeGee

//输出样例：
//3

#include<stdio.h>

int StrMatch(char a[], char b[]) 
{//在b中匹配a
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
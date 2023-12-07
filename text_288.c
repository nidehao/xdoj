#define _CRT_SECURE_NO_WARNINGS 1
//求一个顺寻串的next函数值。

//问题描述：
//所设计的程序能够通过编译。并能够实现从输入一个长度为n的顺序串str，并求出顺序串str的next值。

//输入格式 :
//首先输入串的长度n，然后输入顺序串str.

//输出格式 :
//输出str的next值，以空格分隔。

//样例输入 :
/*
8
a b c a b c b c
*/

//样例输出 :
//-1 0 0 0 1 2 3 0

int main() {
	int n, i;
	char str[100];
	scnaf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &str[i]);
	}

	return 0;
}
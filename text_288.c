#define _CRT_SECURE_NO_WARNINGS 1
//��һ��˳Ѱ����next����ֵ��

//����������
//����Ƶĳ����ܹ�ͨ�����롣���ܹ�ʵ�ִ�����һ������Ϊn��˳��str�������˳��str��nextֵ��

//�����ʽ :
//�������봮�ĳ���n��Ȼ������˳��str.

//�����ʽ :
//���str��nextֵ���Կո�ָ���

//�������� :
/*
8
a b c a b c b c
*/

//������� :
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
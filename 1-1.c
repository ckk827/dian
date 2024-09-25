#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, c, d;
	char b;
	printf("请按通道 名称 单价 数量的格式输入\n");
	scanf("%d %c %d %d", &a, &b, &c, &d);
	getchar();
	printf("--------------------------------\n");
	printf("通道   名称   单价\n");
	printf("%d", a);
	putchar(32);
	for (int i = 0; i < d; i++)
	{
		printf("%c", b);
	}
	putchar(32);
	printf("%d", c);
	getchar();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int pay=0;
int total = 0;
int check()
{
	int input = 0;
	int charge = 0;
	while (pay < total)
	{
		printf("��Ͷ��1 5 10 20 50 100����RMB\n");
		scanf("%d", &input);
		getchar();
		if (input !=1&& input != 5 && input != 10 && input != 20 && input != 50 && input != 100)
		{
			printf("��������������\n");
			continue;
		}
		else
		{
			pay = pay + input;
		}
	}
	charge = pay - total;
	printf("����%dԪ", charge);
	getchar();
}
int main()
{
	printf("�������ܼ�\n");
	int error=scanf("%d", &total);
	getchar();
	if (error!=1||total<1)
		{
		printf("����������");
		main();
		}
	else
	{
		check();
	}
	return 0;
}
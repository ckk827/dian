#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a,c, d;
char b;
int* pa = &a;
char* pb = &b;
int* pc = &c;
int* pd = &d;

void buy()
{
	int tunnel,num;
	char name;
	int total;
	int pay = 0;
	printf(" 购买   请按名称 通道 数量的格式输入\n");
	int error1 = scanf("%c %d %d", &name, &tunnel, &num);
	getchar();
	if (error1 != 3)
	{
		printf("输入有误1\n");
		buy();
	}
	else
	{
		if(name!=b||tunnel!=a||num>d)
		{ 
			printf("输入有误2\n");
			buy();
		}
		else
		{
			total = num * c;
			int input = 0;
			int charge = 0;
			while (pay < total)
			{
				printf("请投入1 5 10 20 50 100面额的RMB\n");
				scanf("%d", &input);
				getchar();
				if (input != 1 && input != 5 && input != 10 && input != 20 && input != 50 && input != 100)
				{
					printf("输入有误，请重试\n");
					continue;
				}
				else
				{
					pay = pay + input;
				}
			}
			charge = pay - total;
			printf("找零%d元", charge);
			getchar();
		}
	}
}
void put(int* pa1,char* pb2,int* pc3,int* pd4)
{
	printf("摆放   请按通道 名称 单价 数量的格式输入\n");
	int error2=scanf("%d %c %d %d", pa1, pb2, pc3, pd4);
	getchar();
	if (error2 != 4)
	{
		printf("请重试\n");
		put(pa, pb, pc, pd);
	
	}
	else
	{
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
		printf("\n--------------------------------\n");
	}
}




int main()
{
	put(pa, pb, pc, pd);
	buy();
	return 0;

}
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
	printf(" ����   �밴���� ͨ�� �����ĸ�ʽ����\n");
	int error1 = scanf("%c %d %d", &name, &tunnel, &num);
	getchar();
	if (error1 != 3)
	{
		printf("��������1\n");
		buy();
	}
	else
	{
		if(name!=b||tunnel!=a||num>d)
		{ 
			printf("��������2\n");
			buy();
		}
		else
		{
			total = num * c;
			int input = 0;
			int charge = 0;
			while (pay < total)
			{
				printf("��Ͷ��1 5 10 20 50 100����RMB\n");
				scanf("%d", &input);
				getchar();
				if (input != 1 && input != 5 && input != 10 && input != 20 && input != 50 && input != 100)
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
	}
}
void put(int* pa1,char* pb2,int* pc3,int* pd4)
{
	printf("�ڷ�   �밴ͨ�� ���� ���� �����ĸ�ʽ����\n");
	int error2=scanf("%d %c %d %d", pa1, pb2, pc3, pd4);
	getchar();
	if (error2 != 4)
	{
		printf("������\n");
		put(pa, pb, pc, pd);
	
	}
	else
	{
		printf("--------------------------------\n");
		printf("ͨ��   ����   ����\n");
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
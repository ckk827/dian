#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//--------------------------------  �ڷŻ��ﴢ������
int number = 0;
int price = 0;
int tunnel = 0;
char name;
char* namep = &name;
int* numberp = &number;
int* tunnelp = &tunnel;
int* pricep = &price;
FILE* fp1; //�ж��ļ�����
FILE* fp2;//д��ָ��
FILE* fp3;//�Ķ�ָ��
char fp4[100];//��������ָ��
int record[5] = { 0 };
int total = 0;
int* totalp = &total;
int pay = 0;
//------------------END--------------------------
int end(char* namep3)
{
	if (*namep3 = "end\0")
	{
		main();
	}

	else
	{
		return 0;
	}
}
//-----------------����-------------------------
void checkout(int* totalp1)
{
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

//void funname(int* namep2)
//{
//
//
//	/*FILE* fp;
//	fp = fopen("goods.txt", "w");*/
//	printf("������Ҫ��ӵ���Ʒ����A-Z)\n");
//
//	*namep2 = getchar();
//
//	if (*namep2 == -1)
//	{
//		printf("������������������\n");
//		funname(namep);
//	}
//	else
//	{
//		if (*namep2 < 65 || *namep2>90)
//		{
//			printf("������������������\n");
//			funname(namep);
//		}
//	}
//}
//
//
//
//void funtunnel(int* tunnelp2)
//{
//
//	getchar();
//	printf("��������Ʒ�ڷŵ�ͨ����1-5)\n");
//	scanf("%d", &*tunnelp2);
//	if (*tunnelp2 < 1 || *tunnelp2>5)
//	{
//		printf("����ʧ�ܣ�����������\n");
//		funtunnel(tunnelp);
//	}
//}
//
//
//
//void funprice(int* pricep2)
//{
//
//	getchar();
//	printf("��������Ʒ����\n");
//	scanf("%d", &*pricep2);
//	if (*pricep2 < 1)
//	{
//		printf("���������뵥��\n");
//		funprice(pricep);
//	}
//}
//
//void funnumber(int* numberp2)
//{
//
//	getchar();
//	printf("��������Ʒ����\n");
//	scanf("%d", &*numberp2);
//	if (*numberp2 < 1)
//	{
//		printf("��������������\n");
//		funnumber(numberp);
//	}
//}
//----------------------��������------------------------
void enter(char* namep2,int* tunnelp2,int* pricep2,int* numberp2)
{
	
	printf("�밴���¸�ʽ����\n");
	printf("�밴��ͨ��1-5��˳������\n");
	printf("����end����\n");
	printf("����  ͨ��  ����  ����\n");
	scanf("%s", namep2);
	if (strlen(namep2) != 1)
	{
		if (end(namep2) == 0);
		{
			printf("����������\n");
			enter(namep, tunnelp, pricep, numberp);
		}

	}
	int error = scanf(" %d %d %d",  tunnelp2, pricep2, numberp2);
	getchar();
	if (error != 3)
	{
		printf("����������\n");
		enter(namep, tunnelp, pricep, numberp);
	}
	
	

}


 
void write(char name2, int tunnel2, int price2, int number2)
{
	fp1 = fopen("g.txt", "r");
	if (fp1 == NULL)
	{
		fclose(fp1);
		fp2 = fopen("g.txt", "w");
	}
	else
	{
		fclose(fp1);
		fp2 = fopen("g.txt", "a");
		fseek(fp2, 0, SEEK_SET);
	}
	fputs("\n", fp2);
	/*for (int i = tunnel2;i>1; i--)
	{
		fputs("\n", fp2);
		
	}*/
	char goodsinf[] = { tunnel+48,32,name,32,price2 + 48,32,number2 + 48,"\0" };
	fputs(goodsinf, fp2);
	fclose(fp2);
}
void input()
{
	/*funname(namep);
	funtunnel(tunnelp);
	funprice(pricep);
	funnumber(numberp);*/
	enter(namep,tunnelp,pricep,numberp);
	write(name, tunnel, price, number);
	printf("--------------�������-------------\n");
	input();
}
//---------------------��ӡ�б�----------------------------------------
void print()
{
	printf("------------------�Զ��ۻ���-----------------\n");
	printf("ͨ�� ��Ʒ ���� ����\n");
	fp1 = fopen("g.txt", "r");
	if (fp1 == NULL)
	{
		printf("��ǰ����Ʒ�ڷ�\n");
		fclose(fp1);
	}                                     //���ļ�ʱ
	else
	{
		fclose(fp1);
		fp3 = fopen("g.txt", "r");
		  //�����ļ�
		while (fgets(fp4, 100, fp3)!= NULL)
		{
			printf("%s", fp4);
		}
		fclose(fp3);
		int num = 0;
		for (int i = 0; i < 5; i++)
		{
			fp3 = fopen("g.txt", "r");
			if (fgets(fp4, 100, fp3) != NULL)        //�ļ�Ϊ��ʱ
			{
				num++;
			}
		}
		if (num == 0)
		{
			printf("��ǰ����Ʒ�ڷ�\n");
		}
		
		char fp4[] = { 0 };
	}
	printf("\n----------------------------------------------\n");
	printf("����������ѡ��\n");
	printf("1.������Ʒ\n");
	printf("2.�ڷ���Ʒ\n");
	printf("3.�����Ʒ���˳�\n");
}
	//-------------------------------------���� -------------------------------------------------------------------------------------------------
//-----------------------------�ռ�����------------------------
void buy(int* totalp2,int* arr)
{
	char buyname;
	int buytunnel;
	int buynum;
	struct goods
	{
		char gname;
		int gtunnel;
		int gnum;
		int gprice;
	}tunnel1, tunnel2, tunnel3, tunnel4, tunnel5;
	fp3 = fopen("g.txt", "r");
	rewind(fp3);
	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1:
			fscanf(fp3, "%d %s %d %d", &tunnel1.gtunnel, &tunnel1.gname, &tunnel1.gnum, &tunnel1.gprice);
			break;
		case 2:
			fscanf(fp3, "%d %s %d %d", &tunnel2.gtunnel, &tunnel2.gname, &tunnel2.gnum, &tunnel2.gprice);
			break;
		case 3:
			fscanf(fp3, "%d %s %d %d", &tunnel3.gtunnel, &tunnel3.gname, &tunnel3.gnum, &tunnel3.gprice);
			break;
		case 4:
			fscanf(fp3, "%d %s %d %d", &tunnel4.gtunnel, &tunnel4.gname, &tunnel4.gnum, &tunnel4.gprice);
			break;
		case 5:
			fscanf(fp3, "%d %s %d %d", &tunnel5.gtunnel, &tunnel5.gname, &tunnel5.gnum, &tunnel5.gprice);
		}
	}
	fclose(fp3);
			//----------------------������-------------------
	printf("�����¸�ʽ���빺��\n");
	printf("����OK����\n");
	printf("��������  ͨ��  ����\n");
	scanf("%s", &buyname);
	if (strlen(&buyname)!=1)
	{
		if (buyname = "OK\0")
		{
			checkout(totalp);
		}
		else
		{
			printf("��������\n");
		}
	}
	scanf("%d %d", &buytunnel, &buynum);
	getchar();
	fp1 = fopen("g.txt", "r");
	if (fp1 == NULL)
	{
		printf("��ǰ����Ʒ�ڷ�\n");
		fclose(fp1);
		main();
	}
	//���ļ�ʱ
	//------------------------------------------------------------
	else
	{

		fp3 = fopen("g.txt", "r");
		for (int i = 0; i < buytunnel; i++)
		{
			fgets(fp4, 100, fp3);
		}
		if (fp4 == NULL)
		{
			printf("�Ҳ�������\n");
			fclose(fp3);
			main();
		}//---------------------�����ݴ�����
		else
		{

			if (fp4[2] != buyname)
			{
				printf("��ͨ���޴˲�Ʒ\n");
				fclose(fp3);
				main();
			}//------------------------------��Ʒ������
			else
			{
				if (fp4[6] - 48 < buynum)
				{
					printf("��������\n");//-------------------------����������
					fclose(fp3);
					main();
				}//---------------------------------����۸�------------------------------
				else
				{
					if (arr  [buytunnel - 1] != 0)
					{
						printf("�Ѿ�������û���\n");
						buy(totalp, record);
					}
					else
					{
						fclose(fp3);
						arr[buytunnel - 1] = 1;
						switch (buytunnel)
						{
						case 1:
							break;
							*totalp = tunnel1.gprice * buynum + *totalp;
							tunnel1.gnum = tunnel1.gnum - buynum;
						case 2:
							*totalp = tunnel2.gprice * buynum + *totalp;
							tunnel2.gnum = tunnel2.gnum - buynum;
							break;
						case 3:
							*totalp = tunnel3.gprice * buynum + *totalp;
							tunnel3.gnum = tunnel3.gnum - buynum;
							break;
						case 4:
							*totalp = tunnel4.gprice * buynum + *totalp;
							tunnel4.gnum = tunnel4.gnum - buynum;
							break;
						case 5:
							*totalp = tunnel5.gprice * buynum + *totalp;
							tunnel5.gnum = tunnel5.gnum - buynum;
							break;
						}

						printf("����ɹ�����ǰ�ܼ�Ϊ%d\n", *totalp);
						buy(totalp, record);
						

					}
				}
			}


		}

	}
	//---------------------------------------------------------
	//---------------------------������-----------------------------
	fclose(fp3);
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		fp3 = fopen("g.txt", "r");
		if (fgets(fp4, 100, fp3) != NULL)        //�ļ�Ϊ��ʱ
		{
			num++;
		}
	}
	if (num == 0)
	{
		printf("��ǰ����Ʒ�ڷ�\n");
	}
	fclose(fp1);
	main();
}
//------------------------������---------------------------------------
int main()
{
	int record[5] = { 0 };
	fp1 = fopen("g.txt", "a");
	fclose(fp1);
	print();
	int choice;
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1:
		buy(totalp,record);
		break;
	case 2:
		input();
		break;
	case 3:
	    fp1 = fopen("g.txt", "w");
		fclose(fp1);
		break;
	default:

		main();
	}


	return 0;
}

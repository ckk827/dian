#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//--------------------------------  摆放货物储存数据
int number = 0;
int price = 0;
int tunnel = 0;
char name;
char* namep = &name;
int* numberp = &number;
int* tunnelp = &tunnel;
int* pricep = &price;
FILE* fp1; //判断文件存在
FILE* fp2;//写入指针
FILE* fp3;//阅读指针
char fp4[100];//返回数据指针
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
//-----------------结算-------------------------
void checkout(int* totalp1)
{
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

//void funname(int* namep2)
//{
//
//
//	/*FILE* fp;
//	fp = fopen("goods.txt", "w");*/
//	printf("请输入要添加的商品名（A-Z)\n");
//
//	*namep2 = getchar();
//
//	if (*namep2 == -1)
//	{
//		printf("发生错误，请重新输入\n");
//		funname(namep);
//	}
//	else
//	{
//		if (*namep2 < 65 || *namep2>90)
//		{
//			printf("发生错误，请重新输入\n");
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
//	printf("请输入商品摆放的通道（1-5)\n");
//	scanf("%d", &*tunnelp2);
//	if (*tunnelp2 < 1 || *tunnelp2>5)
//	{
//		printf("输入失败，请重新输入\n");
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
//	printf("请输入商品单价\n");
//	scanf("%d", &*pricep2);
//	if (*pricep2 < 1)
//	{
//		printf("请重新输入单价\n");
//		funprice(pricep);
//	}
//}
//
//void funnumber(int* numberp2)
//{
//
//	getchar();
//	printf("请输入商品数量\n");
//	scanf("%d", &*numberp2);
//	if (*numberp2 < 1)
//	{
//		printf("请重新输入数量\n");
//		funnumber(numberp);
//	}
//}
//----------------------储存数据------------------------
void enter(char* namep2,int* tunnelp2,int* pricep2,int* numberp2)
{
	
	printf("请按如下格式输入\n");
	printf("请按照通道1-5的顺序输入\n");
	printf("输入end结束\n");
	printf("名称  通道  单价  数量\n");
	scanf("%s", namep2);
	if (strlen(namep2) != 1)
	{
		if (end(namep2) == 0);
		{
			printf("请重新输入\n");
			enter(namep, tunnelp, pricep, numberp);
		}

	}
	int error = scanf(" %d %d %d",  tunnelp2, pricep2, numberp2);
	getchar();
	if (error != 3)
	{
		printf("请重新输入\n");
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
	printf("--------------输入完成-------------\n");
	input();
}
//---------------------打印列表----------------------------------------
void print()
{
	printf("------------------自动售货机-----------------\n");
	printf("通道 商品 单价 数量\n");
	fp1 = fopen("g.txt", "r");
	if (fp1 == NULL)
	{
		printf("当前无商品摆放\n");
		fclose(fp1);
	}                                     //无文件时
	else
	{
		fclose(fp1);
		fp3 = fopen("g.txt", "r");
		  //读出文件
		while (fgets(fp4, 100, fp3)!= NULL)
		{
			printf("%s", fp4);
		}
		fclose(fp3);
		int num = 0;
		for (int i = 0; i < 5; i++)
		{
			fp3 = fopen("g.txt", "r");
			if (fgets(fp4, 100, fp3) != NULL)        //文件为空时
			{
				num++;
			}
		}
		if (num == 0)
		{
			printf("当前无商品摆放\n");
		}
		
		char fp4[] = { 0 };
	}
	printf("\n----------------------------------------------\n");
	printf("请输入数字选择\n");
	printf("1.购买商品\n");
	printf("2.摆放商品\n");
	printf("3.清空商品并退出\n");
}
	//-------------------------------------购买 -------------------------------------------------------------------------------------------------
//-----------------------------收集数据------------------------
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
			//----------------------错误处理-------------------
	printf("按以下格式输入购买\n");
	printf("输入OK结算\n");
	printf("货物名称  通道  数量\n");
	scanf("%s", &buyname);
	if (strlen(&buyname)!=1)
	{
		if (buyname = "OK\0")
		{
			checkout(totalp);
		}
		else
		{
			printf("输入有误\n");
		}
	}
	scanf("%d %d", &buytunnel, &buynum);
	getchar();
	fp1 = fopen("g.txt", "r");
	if (fp1 == NULL)
	{
		printf("当前无商品摆放\n");
		fclose(fp1);
		main();
	}
	//无文件时
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
			printf("找不到数据\n");
			fclose(fp3);
			main();
		}//---------------------无数据错误处理
		else
		{

			if (fp4[2] != buyname)
			{
				printf("该通道无此产品\n");
				fclose(fp3);
				main();
			}//------------------------------产品错误处理
			else
			{
				if (fp4[6] - 48 < buynum)
				{
					printf("数量不足\n");//-------------------------数量错误处理
					fclose(fp3);
					main();
				}//---------------------------------计算价格------------------------------
				else
				{
					if (arr  [buytunnel - 1] != 0)
					{
						printf("已经购买过该货物\n");
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

						printf("输入成功，当前总价为%d\n", *totalp);
						buy(totalp, record);
						

					}
				}
			}


		}

	}
	//---------------------------------------------------------
	//---------------------------错误处理-----------------------------
	fclose(fp3);
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		fp3 = fopen("g.txt", "r");
		if (fgets(fp4, 100, fp3) != NULL)        //文件为空时
		{
			num++;
		}
	}
	if (num == 0)
	{
		printf("当前无商品摆放\n");
	}
	fclose(fp1);
	main();
}
//------------------------主函数---------------------------------------
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

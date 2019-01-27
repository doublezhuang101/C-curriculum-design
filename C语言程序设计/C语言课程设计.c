#include<stdio.h>
#define line 14
void square(void);//打印line数量个方框

void main()
{
	printf("		学生信息信息管理系统");
	printf("	制作人;苗壮");

	getchar();
}
void square(void)
{
	int i = 0;
	for (i = 0; i < line; i++)
		printf("%2c", 3);
	printf("\n");
}
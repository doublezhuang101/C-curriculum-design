#include<stdio.h>
#include<stdlib.h>
#define line 17
void square(void);//打印line数量个方框
void menu(void);//开始菜单
void typein(void);//学生信息录入
void main()
{
	printf("	学生信息信息管理系统\n");
	printf("	制作人;苗壮\n");
	menu();
	getchar();
}
void square(void)
{
	int i = 0;
	for (i = 0; i < line; i++)
		printf("%2c", 3);
	printf("\n");
}
void menu()
{
	int choice = 0;
	square();
	printf("	请选择功能:\n");
	printf("	1.录入学生信息\n");
	printf("	2.保存学生信息\n");
	printf("	3.删除学生信息\n");
	printf("	4.修改学生信息\n");
	printf("	5.学生成绩排序（降序）\n");
	printf("	6.学生成绩排序（升序）\n");
	printf("	7.显示学生信息\n");
	printf("	8.查找学生信息\n");
	printf("	9.退出系统\n");
	square();
	printf("	请输入数字进行功能选择:");
	scanf_s("%d",&choice);
	getchar();
	switch (choice)
	{
	case 1:
		typein();
	default:
		system("CLS");
		printf("	输入选项错误！请重新输入\n");
			menu();
	}
}
void typein()
{

}
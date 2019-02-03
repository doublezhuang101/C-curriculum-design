#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define line 17
#define MAX 50//学生人数
void square(void);//打印line数量个方框
void menu(void);//开始菜单
void typein(void);//学生信息录入
void rank1(void);//冒泡排序按学号
void rank2(void);//选择排序按高数成绩排序
void rank3(void);//快速排序按英语成绩排序
void rank4(void);//插入排序按C语言成绩排序
void rank5(void);//快速排序按体育成绩排序
void rank6(void);//快速排序按课程设计成绩排序
int count = 0;
void main()
{
	square();
	printf("	学生信息信息管理系统\n");
	printf("	制作人;苗壮\n");
	square();
	printf("\t");
	system("pause");
	system("CLS");
	menu();
}
typedef struct
{
	long int number;
	char name[20];
	char sex[9];
	int age;
	char phone;
	int score1;//高数
	int score2;//英语
	int score3;//C语言
	int score4;//体育
	int score5;//课程设计
}STUDENT;
STUDENT student[MAX];
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
	printf("\n");
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
	printf("请输入学号:");
	scanf("%ld", &student[count].number);
	printf("请输入姓名:");
	scanf("%s", &student[count].name);
	getchar();
	printf("请输入性别:");
	scanf("%s", &student[count].sex);
	getchar();
	printf("请输入年龄:");
	scanf("%d", &student[count].age);
	getchar();
	printf("请输入手机号码:");
	scanf("%s", &student[count].phone);
	getchar();
	printf("请输入高等数学成绩:");
	scanf("%d", &student[count].score1);
	getchar();
	printf("请输入英语成绩:");
	scanf("%d", &student[count].score2);
	getchar();
	printf("请输入C语言成绩:");
	scanf("%d", &student[count].score3);
	getchar();
	printf("请输入体育成绩:");
	scanf("%d", &student[count].score4);
	getchar();
	printf("请输入课程设计成绩:");
	scanf("%d", &student[count].score5);
	getchar();
	count++;
}
void rank1(void)//冒泡排序
{
	int i = 0, j = 0, c = 0;
	int flag = 0;
	STUDENT t;
	for (i = count-1; i >0; i--)
	{
		flag = 0;
		for (j = 0; j < i; j++)
		{
			if (student[j].number < student[j+1].number)
			{
				/*swap(a[j], a[j + 1]);*/
				c = student[j].number;
				student[j].number = student[j + 1].number;
				student[j + 1].number = c;
				flag = 1;
			}
		}
		if (flag == 0) break;	
	}
	printf("\n学号\t姓名\t性别\t年龄\t手机号码   高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
				student[i].age, student[i].phone,student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void rank2(void)//选择排序
{
	int i, j;
	
	for (i = 0; i < count; i++)
	{
		int max = i; /*每次循环后将第i大的元素放好*/
		//记录第i个到第count - 1个元素中，最大的元素的下标
		for (j = i + 1; j < count; j++)
		{
			if (student[j].score1 > student[max].score1)
				max = j;
		}
		//下面将第i大的元素放在第i个位置上，并将原来第i个位置的元素挪到后面
		int c = student[i].score1;
		student[i].score1 = student[max].score1;
		student[max].score1 = c;
	}
	printf("\n学号\t姓名\t性别\t年龄\t手机号码   高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void rank3(void)//快速排序
{
	int i=0, j=count;    //定义变量为基本整型
    //将每组首个元素赋给i
	//将每组末尾元素赋给j
	s[0] = s[max];    //设置基准值
	while (i < j)
	{
		while (i < j&&s[0] < s[j])
			j--;    //位置左移
		if (i < j)
		{
			s[i] = s[j];    //将s[j]放到s[i]的位置上
			i++;    //位置右移
		}
		while (i < j&&s[i] <= s[0])
			i++;    //位置左移
		if (i < j)
		{
			s[j] = s[i];    //将大于基准值的s[j]放到s[i]位置
			j--;    //位置左移
		}
	}
	printf("\n学号\t姓名\t性别\t年龄\t手机号码   高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void exit()
{

}
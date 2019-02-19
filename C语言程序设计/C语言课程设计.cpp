#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define line 17
#define MAX 50//学生人数
void square(void);//打印line数量个方框
void menu(void);//开始菜单
void typein(void);//学生信息录入
void save(void);//保存学生信息
void deletemenu(void);//删除学生信息菜单
void delete_number(void);//按学号删除学生信息
void revise(void);//修改学生信息
void revise_number(void);//学号修改学生信息
void swap(int a, int b);//交换两数
void rank_menu(void);//排序菜单
void rank1(void);//冒泡排序按学号
void rank2(void);//选择排序按高数成绩排序
void rank3(void);//快速排序按英语成绩排序
void quick_sort(int left,int right);//英语快速排序主函数
void rank4(void);//插入排序按C语言成绩排序
void rank5(void);//快速排序按体育成绩排序
void rank6(void);//快速排序按课程设计成绩排序
void display(void);//显示学生信息
void search_menu(void);//查找学生信息菜单
void name_search(void);//查询-姓名
void phone_search(void);//查询-手机号码
void number_search(void);//查询-成绩
void age_search(void);//查询-年龄
void score1_search(void);//查询-高数
void score2_search(void);//查询-英语
void score3_search(void);//查询-C语言
void score4_search(void);//查询-体育
void score5_search(void);//查询-课设
void EXIT(void);//退出函数
int count = 0;
void main()
{
	square();
	printf("	学生信息管理系统\n");
	printf("	制作人:苗壮\n");
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
	char phone[15];
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
		printf("%2c", 4);
	printf("\n");
}
void menu()//主菜单
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
	printf("	6.显示学生信息\n");
	printf("	7.查找学生信息\n");
	printf("	8.退出系统\n");
	square();
	printf("	请输入数字进行功能选择:");
	scanf("%d",&choice);
	getchar();
	switch (choice)
	{
	case 1:
		typein();
		break;
	case 2:
		save();
		break;
	case 3:
		deletemenu();
		break;
	case 4:
		revise();
		break;
	case 5:
		rank_menu();
		break;
	case 6:
		display();
		break;
	case 7:
		search_menu();
		break;
	case 8:
		EXIT();
		break;
	default:
		system("CLS");
		printf("	输入选项错误！请重新输入\n");
			menu();
	}
}
void typein()//输入函数
{
	int choice = 0;
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
	printf("	您已输入完成，请选择是否继续输入:\n\t");
	printf("1.继续输入\n\t");
	printf("2.返回菜单\n\t");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1:
		typein();
		break;
	case 2:
		menu();
		break;
	default:
		printf("	输入错误，将返回菜单.\n\t");
		system("pause");
		menu();
		break;
	}
}
void save()//保存文件
{
	int i = 0;
	FILE *fp;
	fp = fopen("D:\\student.txt", "w+");
	for (i = 0; i < count; i++)
		if (fwrite(&student[i], sizeof(STUDENT), 1, fp) != 1)
			printf("无法保存文件！\n");
	printf("	你已成功保存文件！\n\t文件位置D:\\sutdent.txt\n");
	fclose(fp);
	system("pause");
}
void deletemenu(void)//删除主菜单
{
	int c;
	square();
	printf("	输入数字进行功能选择:\n");
	printf("	1.输入学号选择删除条目\n");
	printf("	2.取消删除返回上一级菜单\n");
	square();
	printf("请输入数字选择：");
	scanf("%d", &c);
	getchar();
	switch (c)
	{
	case 1:
		delete_number();
		break;
	case 2:
		menu();
		break;
	default:
		system("CLS");
		printf("	输入错误，请重新输入\n");
		deletemenu();
	}
}
void delete_number(void)//按学号删除函数
{
	long int number;
	int i, j;
	int match=0;
	printf("请输入学生学号:");
	scanf("%ld", &number);
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			for (j = i; j < count; j++)
				student[j].number = student[j + 1].number;
			printf("已经成功删除！");
			match++;
		}
	if (match == 0)
	{
		printf("无法查到相关数据\n");
		deletemenu();
	}
}
void revise(void)//编辑功能主菜单
{
	int choice;
	square();
	printf("	请输入数字选择功能\n");
	printf("	1.输入学号查找编辑对象\n");
	printf("	2.返回上一级菜单\n");
	square();
	printf("	请输入数字选择：");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
		case 1: 
			revise_number(); 
			break;
		case 2:
			menu(); 
			break;
		default:
		{
			printf("	输入错误！请重新输入\n");
			revise();
		}
	}
}
void revise_number()//按学号编辑函数
{
	long int number;
	int match = 0;
	printf("	请输入查询的学号:");
	scanf("%ld", &number);
	getchar();
	int i=0;
	printf("\n");
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			match++;
			square();
			printf("	查找到的学生信息\n");
			printf("学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("	输入数字选择要更改的内容\n");
			printf("	0.放弃修改并返回上一级菜单\n");
			printf("	1.修改姓名\n");
			printf("	2.修改性别\n");
			printf("	3.修改年龄\n");
			printf("	4.修改手机号码\n");
			printf("	5.修改高等数学成绩\n");
			printf("	6.修改英语成绩\n");
			printf("	7.修改C语言成绩\n");
			printf("	8.修改体育成绩\n");
			printf("	9.修改课程设计成绩\n");
			int choice=0;
			scanf("%d", &choice);
			getchar();
			switch (choice)
			{
			case 0: 
				revise();  
				break;
			case 1:
				printf("将修改姓名为:");
				scanf("%s", &student[i].name);
				break;
			case 2:
				printf("将修改性别为:");
				scanf("%s", &student[i].sex);
				break;
			case 3:
				printf("将修改年龄为:");
				scanf("%d", &student[i].age);
				break;
			case 4:
				printf("将修改手机号码为:");
				scanf("%s", &student[i].phone);
				break;
			case 5:
				printf("将修改高等数学成绩为:");
				scanf("%d", &student[i].score1);
				break;
			case 6:
				printf("将修改英语成绩为:");
				scanf("%d", &student[i].score2);
				break;
			case 7:
				printf("将修改C语言成绩为:");
				scanf("%d", &student[i].score3);
				break;
			case 8:
				printf("将修改体育成绩为:");
				scanf("%d", &student[i].score4);
				break;
			case 9:
				printf("将修改课程设计为:");
				scanf("%d", &student[i].score5);
				break;
			default:
				{
					printf("输入错误！即将返回修改菜单。\n");
					system("pause");
					revise();
				}
			}
		}
	if (match == 0)
	{
		printf("错误！无法查找到匹配数据,将返回修改菜单\n");
		system("pause");
		revise();
	}
}
void rank_menu()//排序主菜单
{
	int choice;
	square();
	printf("	请输入数字进行选择:\n");
	printf("	1.按学号排序\n");
	printf("	2.按高等数学成绩排序\n");
	printf("	3.按英语成绩排序\n");
	printf("	4.按C语言成绩排序\n");
	printf("	5.按体育成绩排序\n");
	printf("	6.按课程设计成绩排序\n");
	square();
	printf("	请输入数字:");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1:
		rank1();
		break;
	case 2:
		rank2();
		break;
	case 3:
		rank3();
		break;
	case 4:
		rank4();
		break;
	case 5:
		rank5();
		break;
	case 6:
		rank6();
		break;
	default:
		system("CLS");
		printf("	输入错误！请重新输入\n");
		rank_menu();
		break;
	}
}
void rank1(void)//冒泡排序排学号
{
	int i = 0, j = 0, c = 0;
	int flag = 0;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
	{
		flag = 0;
		for (i = j + 1; i < count; i++)
			if (student[i].number < student[j].number)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
		if (flag == 0) //若此轮没发生数据交换则已经有序
			break;
	}
	printf("\n学号\t姓名\t性别\t年龄\t手机号码   高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %4d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
				student[i].age, student[i].phone,student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	getchar();
}
void rank2(void)//选择排序排高数
{
	int i=0, j=0;
	for (i = 0; i < count; i++)
	{
		int max = i; //循环后将第i大的元素放好
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
void rank3(void)//快速排序英语
{
	int end = 0;
	for (int i = 0; student[i].score2 != 0; i++)
		end++;
	printf("%d", end);
		quick_sort(student[0].score2, student[end].score2);
	printf("\n学号 姓名 性别 年龄 手机号码 高等数学成绩 英语成绩 C语言成绩 体育成绩 课程设计成绩\n");
	for (int i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %4d   %4d   %4d   %4d   %4d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	getchar();
	menu();
}
void quick_sort(int left, int right)//英语快排主函数
{
	int i = 0, j = 0, temp = 0;
	if (left > right)
		return;
	temp = student[left].score2;//暂存基准数
	i = left;
	j = right;
	while (i != j)
	{
		while (student[j].score2 <= temp && i < j)
			j--;
		while (student[j].score2 >= temp && i < j)
			i++;
		int t = 0;
		if (i < j)//交换两数位置
		{
			t = student[i].score2;
			student[i].score2 = student[j].score2;
			student[j].score2 = t;
		}
	}
	student[left].score2 = student[i].score2;//基准数归位
	student[i].score2 = temp;
	quick_sort(left, i - 1);//递归处理基准数左边的
	quick_sort(i + 1, right);//递归处理基准数右边的
}
void rank4(void)//
{

}
void rank5(void)//
{

}
void rank6(void)//
{

}

void display()
{
	int i;
	FILE *fp;
	printf("	请确认打开文件位置位于D\\student.txt\n");
	system("pause");
	fp = fopen("D:\\student.txt", "r+");
	if (fp == NULL)
	{
		printf("	寻找文件失败!将返回主菜单\n");
		system("pause");
		menu();
	}
	else
	{
		printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n"); 
		i = 0;
		while (fread(&student[i], sizeof(STUDENT), 1, fp)==1)//如果读到数据，就显示；否则退出
		{
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		}
	}
	getchar();
	menu();
}
void search_menu()
{
	square();
	printf("	请输入数字选择查询方式：\n");
	printf("	1.学号查询\n");
	printf("	2.姓名查询\n");
	printf("	3.年龄查询\n");
	printf("	4.手机号码查询\n");
	printf("	5.数学成绩查询\n");
	printf("	6.英语成绩查询\n");
	printf("	7.C语言成绩查询\n");
	printf("	8.体育成绩查询\n");
	printf("	9.课程设计成绩查询\n");
	printf("	10.返回上一级菜单\n");
	square();
	printf("	请输入数字进行选择");
	int choice;
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
		case 1: 
			number_search();  
			break;
		case 2: 
			name_search();  
			break;
		case 3: 
			age_search(); 
			break;
		case 4: 
			phone_search(); 
			break;
		case 5: 
			score1_search(); 
			break;
		case 6: 
			score2_search(); 
			break;
		case 7: 
			score3_search(); 
			break;
		case 8: 
			score4_search(); 
			break;
		case 9: 
			score5_search(); 
			break;
		case 10: 
			menu();
			break;
		default:
		{
			printf("	输入错误！将返回查询界面\n");
			system("pause");
			search_menu();
		}
	}
}
void name_search()
{
	char name[20];
	int flag = 0;//确认是否查询到
	printf("	请输入查询的姓名");
	scanf("%s", &name);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void phone_search()
{
	char phone[20];
	int flag = 0;
	printf("	请输入查询的手机号码");
	scanf("%s", &phone);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].phone, phone) == 0)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void number_search()
{
	long int number;
	int flag = 0;
	printf("	请输入查询的学号");
	scanf("%ld", &number);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void age_search()
{
	int age;
	int flag = 0;
	printf("	请输入查询的年龄");
	scanf("%d", &age);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].age == age)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void score1_search()
{
	int score1;
	int flag = 0;
	printf("	请输入查询的高等数学成绩");
	scanf("%d", &score1);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score1 == score1)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void score2_search()
{
	int score2;
	int flag = 0;
	printf("	请输入查询的英语成绩:");
	scanf("%d", &score2);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
	{
		flag++;
		square();
		printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		square();
	}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void score3_search()
{
	int score3;
	int flag = 0;
	printf("	请输入查询的C语言成绩");
	scanf("%d", &score3);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score3 == score3)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void score4_search()
{
	int score4;
	int flag = 0;
	printf("	请输入查询的体育成绩");
	scanf("%d", &score4);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score4 == score4)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void score5_search()
{
	int score5;
	int flag = 0;
	printf("	请输入查询的课程设计成绩");
	scanf("%d", &score5);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score5 == score5)
		{
			flag++;
			square();
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	错误！无法查找到匹配数据");
}
void EXIT(void)
{
	int a;
	square();
	printf("	确认要退出本系统吗？\n\t输入数字进行确认\n");
	printf("	1.确认退出\n");
	printf("	2.返回上一级菜单\n");
	square();
	printf("	请输入数字进行选择：");
	scanf("%d", &a);
	getchar();
	switch (a)
	{
	case 1:
		printf("	感谢你的使用，谢谢！\n");
		system("pause");
		exit(0);
		break;
	case 2:
		menu();
		break;
	default:
		printf("	输入错误请重新输入:");
		EXIT();
	}
}
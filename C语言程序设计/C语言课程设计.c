#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define line 17
#define MAX 50//ѧ������
void square(void);//��ӡline����������
void menu(void);//��ʼ�˵�
void typein(void);//ѧ����Ϣ¼��
void save(void);//����ѧ����Ϣ
void deletemenu(void);//ɾ��ѧ����Ϣ�˵�
void delete_number(void);//��ѧ��ɾ��ѧ����Ϣ
void revise(void);//�޸�ѧ����Ϣ
void rank_menu(void);//����˵�
void rank1(void);//ð������ѧ��
void rank2(void);//ѡ�����򰴸����ɼ�����
void rank3(void);//��������Ӣ��ɼ�����
void quick_sort(void);//��������������
void rank4(void);//��������C���Գɼ�����
void rank5(void);//�������������ɼ�����
void rank6(void);//�������򰴿γ���Ƴɼ�����
void display(void);//��ʾѧ����Ϣ
void search_menu(void);//����ѧ����Ϣ�˵�
void EXIT(void);//�˳�����
int count = 0;
void main()
{
	square();
	printf("	ѧ����Ϣ��Ϣ����ϵͳ\n");
	printf("	������;��׳\n");
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
	int score1;//����
	int score2;//Ӣ��
	int score3;//C����
	int score4;//����
	int score5;//�γ����
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
	printf("	��ѡ����:\n");
	printf("	1.¼��ѧ����Ϣ\n");
	printf("	2.����ѧ����Ϣ\n");
	printf("	3.ɾ��ѧ����Ϣ\n");
	printf("	4.�޸�ѧ����Ϣ\n");
	printf("	5.ѧ���ɼ����򣨽���\n");
	printf("	6.��ʾѧ����Ϣ\n");
	printf("	7.����ѧ����Ϣ\n");
	printf("	8.�˳�ϵͳ\n");
	square();
	printf("	���������ֽ��й���ѡ��:");
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
		printf("	����ѡ���������������\n");
			menu();
	}
}
void typein()
{
	printf("������ѧ��:");
	scanf("%ld", &student[count].number);
	printf("����������:");
	scanf("%s", &student[count].name);
	getchar();
	printf("�������Ա�:");
	scanf("%s", &student[count].sex);
	getchar();
	printf("����������:");
	scanf("%d", &student[count].age);
	getchar();
	printf("�������ֻ�����:");
	scanf("%s", &student[count].phone);
	getchar();
	printf("������ߵ���ѧ�ɼ�:");
	scanf("%d", &student[count].score1);
	getchar();
	printf("������Ӣ��ɼ�:");
	scanf("%d", &student[count].score2);
	getchar();
	printf("������C���Գɼ�:");
	scanf("%d", &student[count].score3);
	getchar();
	printf("�����������ɼ�:");
	scanf("%d", &student[count].score4);
	getchar();
	printf("������γ���Ƴɼ�:");
	scanf("%d", &student[count].score5);
	getchar();
	count++;
}
void save()
{

}
void deletemenu(void)
{
	int c;
	square();
	printf("	�������ֽ��й���ѡ��:\n");
	printf("	1.����ѧ��ѡ��ɾ����Ŀ\n");
	printf("	2.ȡ��ɾ��������һ���˵�\n");
	square();
	printf("����������ѡ��");
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
		printf("	�����������������\n");
		deletemenu();
	}
}
void delete_number(void)
{
	long int number;
	int i, j;
	int match=0;
	printf("������ѧ��ѧ��:");
	scanf("%ld", &number);
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			for (j = i; j < count; j++)
				student[j].number = student[j + 1].number;
			printf("�Ѿ��ɹ�ɾ����");
			match++;
		}
	if (match == 0)
	{
		printf("�޷��鵽�������\n");
		deletemenu();
	}
}
void revise(void)
{

}
void rank_menu()
{
	int choice;
	square();
	printf("	���������ֽ���ѡ��:\n");
	printf("	1.��ѧ������\n");
	printf("	2.���ߵ���ѧ�ɼ�����\n");
	printf("	3.��Ӣ��ɼ�����\n");
	printf("	4.��C���Գɼ�����\n");
	printf("	5.�������ɼ�����\n");
	printf("	6.���γ���Ƴɼ�����\n");
	suqure();
	printf("	����������:");
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
		ranke3();
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
		printf("	�����������������\n");
		rank_menu();
		break;
	}
}
void rank1(void)//ð������
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
	printf("\nѧ��\t����\t�Ա�\t����\t�ֻ�����   �ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
				student[i].age, student[i].phone,student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void rank2(void)//ѡ������
{
	int i, j;
	
	for (i = 0; i < count; i++)
	{
		int max = i; /*ÿ��ѭ���󽫵�i���Ԫ�طź�*/
		//��¼��i������count - 1��Ԫ���У�����Ԫ�ص��±�
		for (j = i + 1; j < count; j++)
		{
			if (student[j].score1 > student[max].score1)
				max = j;
		}
		//���潫��i���Ԫ�ط��ڵ�i��λ���ϣ�����ԭ����i��λ�õ�Ԫ��Ų������
		int c = student[i].score1;
		student[i].score1 = student[max].score1;
		student[max].score1 = c;
	}
	printf("\nѧ��\t����\t�Ա�\t����\t�ֻ�����   �ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void rank3(void)//��������
{
	
	printf("\nѧ��\t����\t�Ա�\t����\t�ֻ�����   �ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (int i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %6d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
}
void quick_sort()
{
	0.0
}
void EXIT(void)
{
	int a;
	square();
	printf("	ȷ��Ҫ�˳���ϵͳ��\n\t�������ֽ���ȷ��\n");
	printf("	1.ȷ���˳�\n");
	printf("	2.������һ���˵�\n");
	square();
	printf("	���������ֽ���ѡ��");
	scanf("%d", &a);
	getchar();
	switch (a)
	{
	case 1:
		printf("	��л���ʹ�ã�лл��\n");
		system("pause");
		exit(0);
		break;
	case 2:
		menu();
		break;
	default:
		printf("	�����������������:");
		EXIT();
	}
}
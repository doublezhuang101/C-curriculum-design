#include<stdio.h>
#include<stdlib.h>
#define line 17
void square(void);//��ӡline����������
void menu(void);//��ʼ�˵�
void typein(void);//ѧ����Ϣ¼��
void rank1(void);//ð������ѧ��
void rank2(void);//ѡ�����򰴸����ɼ�����
void rank3(void);//��������Ӣ��ɼ�����
void rank4(void);//��������C���Գɼ�����
void rank5(void);//
void rank6(void);//
void main()
{
	printf("	ѧ����Ϣ��Ϣ����ϵͳ\n");
	printf("	������;��׳\n");
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
	printf("	��ѡ����:\n");
	printf("	1.¼��ѧ����Ϣ\n");
	printf("	2.����ѧ����Ϣ\n");
	printf("	3.ɾ��ѧ����Ϣ\n");
	printf("	4.�޸�ѧ����Ϣ\n");
	printf("	5.ѧ���ɼ����򣨽���\n");
	printf("	6.ѧ���ɼ���������\n");
	printf("	7.��ʾѧ����Ϣ\n");
	printf("	8.����ѧ����Ϣ\n");
	printf("	9.�˳�ϵͳ\n");
	square();
	printf("	���������ֽ��й���ѡ��:");
	scanf_s("%d",&choice);
	getchar();
	switch (choice)
	{
	case 1:
		typein();
	default:
		system("CLS");
		printf("	����ѡ���������������\n");
			menu();
	}
}
void typein()
{

}

void exit()
{

}
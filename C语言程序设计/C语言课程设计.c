#include<stdio.h>
#include<stdlib.h>
#define line 17
#define MAX 50//ѧ������
void square(void);//��ӡline����������
void menu(void);//��ʼ�˵�
void typein(void);//ѧ����Ϣ¼��
void rank1(void);//ð������ѧ��
void rank2(void);//ѡ�����򰴸����ɼ�����
void rank3(void);//��������Ӣ��ɼ�����
void rank4(void);//��������C���Գɼ�����
void rank5(void);//�������������ɼ�����
void rank6(void);//�������򰴿γ���Ƴɼ�����
void main()
{
	printf("	ѧ����Ϣ��Ϣ����ϵͳ\n");
	printf("	������;��׳\n");
	menu();
	getchar();
}
typedef struct
{
	long int number;
	char name[20];
	char sex[9];
	int age;
	char phone;
	int score1;//��ѧ
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
void rank1(void)//ð������
{
	int i = 0;
	int c = 0;
	int flag = 0;
	for (i = n - 1; i > 0; i--)
	{
		flag = 0;
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				/*swap(a[j], a[j + 1]);*/
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}
void rank2()//ѡ������
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		int min = i; /*ÿ��ѭ���󽫵�iС��Ԫ�طź�*/
		//��¼��i������size - 1��Ԫ���У���С��Ԫ�ص��±�
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		//���潫��iС��Ԫ�ط��ڵ�i��λ���ϣ�����ԭ����i��λ�õ�Ԫ��Ų������
		int c = a[i];
		a[i] = a[min];
		a[min] = c;
}
void rank3()//��������
{
	int i, j;    //�������Ϊ��������
	i = 0;    //��ÿ���׸�Ԫ�ظ���i
	j = ;    //��ÿ��ĩβԪ�ظ���j
	s[0] = s[max];    //���û�׼ֵ
	while (i < j)
	{
		while (i < j&&s[0] < s[j])
			j--;    //λ������
		if (i < j)
		{
			s[i] = s[j];    //��s[j]�ŵ�s[i]��λ����
			i++;    //λ������
		}
		while (i < j&&s[i] <= s[0])
			i++;    //λ������
		if (i < j)
		{
			s[j] = s[i];    //�����ڻ�׼ֵ��s[j]�ŵ�s[i]λ��
			j--;    //λ������
		}
	}
}
void exit()
{

}
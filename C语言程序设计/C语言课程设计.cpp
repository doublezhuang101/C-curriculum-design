#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define line 17
#define MAX 50//ѧ������
void square(void);//��ӡline����������
void menu(void);//��ʼ�˵�
void typein(void);//ѧ����Ϣ¼��
void save(void);//����ѧ����Ϣ
void deletemenu(void);//ɾ��ѧ����Ϣ�˵�
void delete_number(void);//��ѧ��ɾ��ѧ����Ϣ
void revise(void);//�޸�ѧ����Ϣ
void revise_number(void);//ѧ���޸�ѧ����Ϣ
void swap(int a, int b);//��������
void rank_menu(void);//����˵�
void rank1(void);//ð������ѧ��
void rank2(void);//ѡ�����򰴸����ɼ�����
void rank3(void);//��������Ӣ��ɼ�����
void quick_sort(int left,int right);//Ӣ���������������
void rank4(void);//��������C���Գɼ�����
void rank5(void);//�������������ɼ�����
void rank6(void);//�������򰴿γ���Ƴɼ�����
void display(void);//��ʾѧ����Ϣ
void search_menu(void);//����ѧ����Ϣ�˵�
void name_search(void);//��ѯ-����
void phone_search(void);//��ѯ-�ֻ�����
void number_search(void);//��ѯ-�ɼ�
void age_search(void);//��ѯ-����
void score1_search(void);//��ѯ-����
void score2_search(void);//��ѯ-Ӣ��
void score3_search(void);//��ѯ-C����
void score4_search(void);//��ѯ-����
void score5_search(void);//��ѯ-����
void EXIT(void);//�˳�����
int count = 0;
void main()
{
	square();
	printf("	ѧ����Ϣ����ϵͳ\n");
	printf("	������:��׳\n");
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
		printf("%2c", 4);
	printf("\n");
}
void menu()//���˵�
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
void typein()//���뺯��
{
	int choice = 0;
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
	printf("	����������ɣ���ѡ���Ƿ��������:\n\t");
	printf("1.��������\n\t");
	printf("2.���ز˵�\n\t");
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
		printf("	������󣬽����ز˵�.\n\t");
		system("pause");
		menu();
		break;
	}
}
void save()//�����ļ�
{
	int i = 0;
	FILE *fp;
	fp = fopen("D:\\student.txt", "w+");
	for (i = 0; i < count; i++)
		if (fwrite(&student[i], sizeof(STUDENT), 1, fp) != 1)
			printf("�޷������ļ���\n");
	printf("	���ѳɹ������ļ���\n\t�ļ�λ��D:\\sutdent.txt\n");
	fclose(fp);
	system("pause");
}
void deletemenu(void)//ɾ�����˵�
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
void delete_number(void)//��ѧ��ɾ������
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
void revise(void)//�༭�������˵�
{
	int choice;
	square();
	printf("	����������ѡ����\n");
	printf("	1.����ѧ�Ų��ұ༭����\n");
	printf("	2.������һ���˵�\n");
	square();
	printf("	����������ѡ��");
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
			printf("	�����������������\n");
			revise();
		}
	}
}
void revise_number()//��ѧ�ű༭����
{
	long int number;
	int match = 0;
	printf("	�������ѯ��ѧ��:");
	scanf("%ld", &number);
	getchar();
	int i=0;
	printf("\n");
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			match++;
			square();
			printf("	���ҵ���ѧ����Ϣ\n");
			printf("ѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("	��������ѡ��Ҫ���ĵ�����\n");
			printf("	0.�����޸Ĳ�������һ���˵�\n");
			printf("	1.�޸�����\n");
			printf("	2.�޸��Ա�\n");
			printf("	3.�޸�����\n");
			printf("	4.�޸��ֻ�����\n");
			printf("	5.�޸ĸߵ���ѧ�ɼ�\n");
			printf("	6.�޸�Ӣ��ɼ�\n");
			printf("	7.�޸�C���Գɼ�\n");
			printf("	8.�޸������ɼ�\n");
			printf("	9.�޸Ŀγ���Ƴɼ�\n");
			int choice=0;
			scanf("%d", &choice);
			getchar();
			switch (choice)
			{
			case 0: 
				revise();  
				break;
			case 1:
				printf("���޸�����Ϊ:");
				scanf("%s", &student[i].name);
				break;
			case 2:
				printf("���޸��Ա�Ϊ:");
				scanf("%s", &student[i].sex);
				break;
			case 3:
				printf("���޸�����Ϊ:");
				scanf("%d", &student[i].age);
				break;
			case 4:
				printf("���޸��ֻ�����Ϊ:");
				scanf("%s", &student[i].phone);
				break;
			case 5:
				printf("���޸ĸߵ���ѧ�ɼ�Ϊ:");
				scanf("%d", &student[i].score1);
				break;
			case 6:
				printf("���޸�Ӣ��ɼ�Ϊ:");
				scanf("%d", &student[i].score2);
				break;
			case 7:
				printf("���޸�C���Գɼ�Ϊ:");
				scanf("%d", &student[i].score3);
				break;
			case 8:
				printf("���޸������ɼ�Ϊ:");
				scanf("%d", &student[i].score4);
				break;
			case 9:
				printf("���޸Ŀγ����Ϊ:");
				scanf("%d", &student[i].score5);
				break;
			default:
				{
					printf("������󣡼��������޸Ĳ˵���\n");
					system("pause");
					revise();
				}
			}
		}
	if (match == 0)
	{
		printf("�����޷����ҵ�ƥ������,�������޸Ĳ˵�\n");
		system("pause");
		revise();
	}
}
void rank_menu()//�������˵�
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
	square();
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
		printf("	�����������������\n");
		rank_menu();
		break;
	}
}
void rank1(void)//ð��������ѧ��
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
		if (flag == 0) //������û�������ݽ������Ѿ�����
			break;
	}
	printf("\nѧ��\t����\t�Ա�\t����\t�ֻ�����   �ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %4d   %4d   %4d   %4d   %6d ", student[i].number, student[i].name, student[i].sex,
				student[i].age, student[i].phone,student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	getchar();
}
void rank2(void)//ѡ�������Ÿ���
{
	int i=0, j=0;
	for (i = 0; i < count; i++)
	{
		int max = i; //ѭ���󽫵�i���Ԫ�طź�
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
void rank3(void)//��������Ӣ��
{
	int end = 0;
	for (int i = 0; student[i].score2 != 0; i++)
		end++;
	printf("%d", end);
		quick_sort(student[0].score2, student[end].score2);
	printf("\nѧ�� ���� �Ա� ���� �ֻ����� �ߵ���ѧ�ɼ� Ӣ��ɼ� C���Գɼ� �����ɼ� �γ���Ƴɼ�\n");
	for (int i = 0; i < count; i++)
		printf("\n%ld\t%s\t%s\t%d\t%s   %4d   %4d   %4d   %4d   %4d ", student[i].number, student[i].name, student[i].sex,
			student[i].age, student[i].phone, student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	getchar();
	menu();
}
void quick_sort(int left, int right)//Ӣ�����������
{
	int i = 0, j = 0, temp = 0;
	if (left > right)
		return;
	temp = student[left].score2;//�ݴ��׼��
	i = left;
	j = right;
	while (i != j)
	{
		while (student[j].score2 <= temp && i < j)
			j--;
		while (student[j].score2 >= temp && i < j)
			i++;
		int t = 0;
		if (i < j)//��������λ��
		{
			t = student[i].score2;
			student[i].score2 = student[j].score2;
			student[j].score2 = t;
		}
	}
	student[left].score2 = student[i].score2;//��׼����λ
	student[i].score2 = temp;
	quick_sort(left, i - 1);//�ݹ鴦���׼����ߵ�
	quick_sort(i + 1, right);//�ݹ鴦���׼���ұߵ�
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
	printf("	��ȷ�ϴ��ļ�λ��λ��D\\student.txt\n");
	system("pause");
	fp = fopen("D:\\student.txt", "r+");
	if (fp == NULL)
	{
		printf("	Ѱ���ļ�ʧ��!���������˵�\n");
		system("pause");
		menu();
	}
	else
	{
		printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n"); 
		i = 0;
		while (fread(&student[i], sizeof(STUDENT), 1, fp)==1)//����������ݣ�����ʾ�������˳�
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
	printf("	����������ѡ���ѯ��ʽ��\n");
	printf("	1.ѧ�Ų�ѯ\n");
	printf("	2.������ѯ\n");
	printf("	3.�����ѯ\n");
	printf("	4.�ֻ������ѯ\n");
	printf("	5.��ѧ�ɼ���ѯ\n");
	printf("	6.Ӣ��ɼ���ѯ\n");
	printf("	7.C���Գɼ���ѯ\n");
	printf("	8.�����ɼ���ѯ\n");
	printf("	9.�γ���Ƴɼ���ѯ\n");
	printf("	10.������һ���˵�\n");
	square();
	printf("	���������ֽ���ѡ��");
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
			printf("	������󣡽����ز�ѯ����\n");
			system("pause");
			search_menu();
		}
	}
}
void name_search()
{
	char name[20];
	int flag = 0;//ȷ���Ƿ��ѯ��
	printf("	�������ѯ������");
	scanf("%s", &name);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void phone_search()
{
	char phone[20];
	int flag = 0;
	printf("	�������ѯ���ֻ�����");
	scanf("%s", &phone);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].phone, phone) == 0)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void number_search()
{
	long int number;
	int flag = 0;
	printf("	�������ѯ��ѧ��");
	scanf("%ld", &number);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void age_search()
{
	int age;
	int flag = 0;
	printf("	�������ѯ������");
	scanf("%d", &age);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].age == age)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void score1_search()
{
	int score1;
	int flag = 0;
	printf("	�������ѯ�ĸߵ���ѧ�ɼ�");
	scanf("%d", &score1);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score1 == score1)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void score2_search()
{
	int score2;
	int flag = 0;
	printf("	�������ѯ��Ӣ��ɼ�:");
	scanf("%d", &score2);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
	{
		flag++;
		square();
		printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		square();
	}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void score3_search()
{
	int score3;
	int flag = 0;
	printf("	�������ѯ��C���Գɼ�");
	scanf("%d", &score3);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score3 == score3)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void score4_search()
{
	int score4;
	int flag = 0;
	printf("	�������ѯ�������ɼ�");
	scanf("%d", &score4);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score4 == score4)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
}
void score5_search()
{
	int score5;
	int flag = 0;
	printf("	�������ѯ�Ŀγ���Ƴɼ�");
	scanf("%d", &score5);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score5 == score5)
		{
			flag++;
			square();
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			square();
		}
	if (flag == 0)
		printf("	�����޷����ҵ�ƥ������");
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
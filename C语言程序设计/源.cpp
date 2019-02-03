#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define STARS "*****************"
#define MAX 50
void menu(void);//�˵�
void typein(void);//����
void display(void);//��ȡ
void save(void);//����
void search(void);//��ѯ
void exit(void);//�˳�
void deletedata(void);//ɾ��
void deletedate_number(void);//ɾ��-ѧ�ż���
void deletedate_name(void);//ɾ��-��������
void name_search(void);//��ѯ-����
void phone_search(void);//��ѯ-�ֻ�����
void number_search(void);//��ѯ-�ɼ�
void age_search(void);//��ѯ-����
void score1_search(void);//��ѯ-����
void score2_search(void);//��ѯ-Ӣ��
void score3_search(void);//��ѯ-C����
void score4_search(void);//��ѯ-����
void score5_search(void);//��ѯ-����
void revise(void);//�༭
void rank(void);//����
void rank_number(void);//����-ѧ��
void rank_course1(void);//����-�ߵ���ѧ
void rank_course2(void);//����-Ӣ��
void rank_course3(void);//����-C����
void rank_course4(void);//����-����
void rank_course5(void);//����-�γ����
void revise_number(void);//�༭-ѧ�Ų�ѯ
void revise_name(void);//�༭-������ѯ
int revise_number_choice(void);//�༭-ѧ�Ų�ѯ-ѡ����
int revise_name_choice(void);//�༭-������ѯ-ѡ����
int count = 0;
int main()
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ��ӭʹ��ѧ����Ϣ����ϵͳ\n");
	printf("       �����ˣ���ƽ ������\n");
	menu();
	return 0;
}
typedef struct
{
	long int number;
	char name[20];
	char sex[10];
	int  age;
	char phone[20];
	int score1;//MATH
	int score2;//ENGLISH
	int score3;//C LANGUAGE
	int score4;//PE
	int score5;//COURESE PROJECT
}STUDENT;
STUDENT student[MAX];
void menu(void)
{
	int choice;
	printf("\n%s%s\n", STARS, STARS);
	printf("       ����������ѡ���ܣ�\n");
	printf("       1)ѧ����Ϣ¼��\n");//���
	printf("       2)����ѧ����Ϣ\n");//���
	printf("       3)��ʾѧ����Ϣ\n");//���
	printf("       4)�༭ѧ����Ϣ\n");//���
	printf("       5)ɾ��ѧ����Ϣ\n");//���
	printf("       6)ѧ����Ϣ����\n");//���
	printf("       7)����ѧ����Ϣ\n");//���
	printf("       8)�˳�ϵͳ\n");//���
	printf("%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	scanf("%d", &choice);
	getchar();//��ֹ��������³�����ѭ��
	switch (choice)
	{
	case 1:
		typein();
		menu();
		break;
	case 2:
		save();
		menu();
		break;
	case 3:
		display();
		menu();
		break;
	case 4:
		revise();
		menu();
		break;
	case 5:
		deletedata();
		menu();
		break;
	case 6:
		rank();
		menu();
		break;
	case 7:
		search();
		menu();
		break;
	case 8:
		exit();
		return;
	default:
		printf("�����������������\n");
		menu();
	}
}
void typein(void)
{
	printf("����ѧ��");
	scanf("%ld", &student[count].number);
	printf("��������");
	scanf("%s", &student[count].name);
	printf("�����Ա�");
	scanf("%s", &student[count].sex);
	printf("��������");
	scanf("%d", &student[count].age);
	getchar();//��ֹ��������³�����ѭ��
	printf("�����ֻ�����");
	scanf("%s", &student[count].phone);
	getchar();
	printf("����ߵ���ѧ�ɼ�");
	scanf("%d", &student[count].score1);
	getchar();
	printf("����Ӣ��ɼ�");
	scanf("%d", &student[count].score2);
	getchar();
	printf("����C���Գɼ�");
	scanf("%d", &student[count].score3);
	getchar();
	printf("���������ɼ�");
	scanf("%d", &student[count].score4);
	getchar();
	printf("����γ���Ƴɼ�");
	scanf("%d", &student[count].score5);
	getchar();
	count++;
}
void display()
{
	int i;

	FILE *fp;
	fp = fopen("D:\\student.txt", "r+");
	if (fp == NULL)
		printf("���ļ�ʧ��!");
	else
	{
		i = 0;
		while (!feof(fp))
		{
			fread(&student[i], sizeof(STUDENT), 1, fp);
			i++;
			count++;
		}
		count--;
		printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
		for (i = 0; i < count; i++)
		{
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		}
	}
}
void save()
{
	int i = 0; FILE *fp;
	fp = fopen("D:\\student.txt", "w+");
	for (i = 0; i < count; i++)
		if (fwrite(&student[i], sizeof(STUDENT), 1, fp) != 1)
			printf("�޷������ļ�!\n");
	printf("���Ѿ��ɹ������ļ�!"); fclose(fp);
}
void search(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ����������ѡ���ѯ��ʽ��\n");
	printf("       1)ѧ�Ų�ѯ\n");
	printf("       2)������ѯ\n");
	printf("       3)�����ѯ\n");
	printf("       4)�ֻ������ѯ\n");
	printf("       5)��ѧ�ɼ���ѯ\n");
	printf("       6)Ӣ��ɼ���ѯ\n");
	printf("       7)C���Գɼ���ѯ\n");
	printf("       8)�����ɼ���ѯ\n");
	printf("       9)�γ���Ƴɼ���ѯ\n");
	printf("       10)������һ���˵�\n");
	printf("%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	int n;
	scanf("%d", &n);
	getchar();
	switch (n)
	{
	case 1: number_search();  break;
	case 2: name_search();  break;
	case 3: age_search(); break;
	case 4: phone_search(); break;
	case 5: score1_search(); break;
	case 6: score2_search(); break;
	case 7: score3_search(); break;
	case 8: score4_search(); break;
	case 9: score5_search(); break;
	case 10: break;
	default:
	{
		printf("�����������������\n");
		search();
	}
	}
}
void name_search()
{
	char name[20];
	int match = 0;
	printf("�������ѯ������");
	scanf("%s", &name);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void phone_search()
{
	char phone[20];
	int match = 0;
	printf("�������ѯ���ֻ�����");
	scanf("%s", &phone);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].phone, phone) == 0)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void number_search()
{
	long int number;
	int match = 0;
	printf("�������ѯ��ѧ��");
	scanf("%ld", &number);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void age_search()
{
	int age;
	int match = 0;
	printf("�������ѯ������");
	scanf("%d", &age);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].age == age)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void score1_search()
{
	int score1;
	int match = 0;
	printf("�������ѯ�ĸߵ���ѧ�ɼ�");
	scanf("%d", &score1);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score1 == score1)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void score2_search()
{
	int score2;
	int match = 0;
	printf("�������ѯ��Ӣ��ɼ�");
	scanf("%d", &score2);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
	{
		match++;
		printf("\n%s%s\n", STARS, STARS);
		printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		printf("\n%s%s\n", STARS, STARS);
	}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void score3_search()
{
	int score3;
	int match = 0;
	printf("�������ѯ��C���Գɼ�");
	scanf("%d", &score3);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score3 == score3)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void score4_search()
{
	int score4;
	int match = 0;
	printf("�������ѯ�������ɼ�");
	scanf("%d", &score4);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score4 == score4)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void score5_search()
{
	int score5;
	int match = 0;
	printf("�������ѯ�Ŀγ���Ƴɼ�");
	scanf("%d", &score5);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].score5 == score5)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("�����޷����ҵ�ƥ������");
}
void revise()
{
	int choice;
	printf("\n%s%s\n", STARS, STARS);
	printf("       ����������ѡ����\n");
	printf("       1)����ѧ�Ų��ұ༭����\n");
	printf("       2)�����������ұ༭����\n");
	printf("       3)������һ���˵�\n");
	printf("\n%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1: revise_number(); break;
	case 2: revise_name(); break;
	case 3:menu(); break;
	default:
	{
		printf("�����������������\n");
		revise();
	}
	}
}
void rank(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ����������ѡ������ʽ\n");
	printf("       1)����ѧ�Ž�������\n");
	printf("       2)���ݸߵ���ѧ�ɼ�����\n");
	printf("       3)����Ӣ��ɼ�����\n");
	printf("       4)����C���Գɼ�����\n");
	printf("       5)���������ɼ���������\n");
	printf("       6)���ݿγ���Ƴɼ���������\n");
	printf("       7)������һ���˵�\n");
	printf("%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	int t;
	scanf("%d", &t);
	getchar();
	switch (t)
	{
	case 1:
		rank_number();
		break;
	case 2:
		rank_course1();
		break;
	case 3:
		rank_course2();
		break;
	case 4:
		rank_course3();
		break;
	case 5:
		rank_course4();
		break;
	case 6:
		rank_course5();
		break;
	case 7:
		menu();
		break;
	default:
		printf("�����������������\n");
		rank();
	}
}
void rank_number(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].number < student[j].number)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course1(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].score1 < student[j].score1)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course2(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].score2 < student[j].score2)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course3(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].score3 < student[j].score3)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course4(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].score4 < student[j].score4)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course5(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (student[i].score5 < student[j].score5)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
	for (i = 0; i < count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void revise_number(void)
{
	long int number;
	int match = 0;
	int n;
	printf("�������ѯ��ѧ��");
	scanf("%ld", &number);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("���ҵ���ѧ����Ϣ");
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			n = revise_number_choice();
			switch (n)
			{
			case 0: revise();  break;
			case 1:
				printf("�޸ĺ������Ϊ");
				scanf("%s", &student[i].name);
				break;
			case 2:
				printf("�޸ĺ���Ա�Ϊ");
				scanf("%s", &student[i].sex);
				break;
			case 3:
				printf("�޸ĺ������Ϊ");
				scanf("%d", &student[i].age);
				break;
			case 4:
				printf("�޸ĺ���ֻ�����Ϊ");
				scanf("%s", &student[i].phone);
				break;
			case 5:
				printf("�޸ĺ�ĸߵ���ѧ�ɼ�Ϊ");
				scanf("%d", &student[i].score1);
				break;
			case 6:
				printf("�޸ĺ��Ӣ��ɼ�Ϊ");
				scanf("%d", &student[i].score2);
				break;
			case 7:
				printf("�޸ĺ��C���Գɼ�Ϊ");
				scanf("%d", &student[i].score3);
				break;
			case 8:
				printf("�޸ĺ�������ɼ�Ϊ");
				scanf("%d", &student[i].score4);
				break;
			case 9:
				printf("�޸ĺ�Ŀγ����Ϊ");
				scanf("%d", &student[i].score5);
				break;
			default:
			{
				printf("�����������������\n");
				revise_number_choice();
			}
			}
		}

	if (match == 0)
	{
		printf("�����޷����ҵ�ƥ������");
		revise();
	}
}
int revise_number_choice(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ��������ѡ��Ҫ���ĵ�����\n");
	printf("       0)�����޸Ĳ�������һ���˵�\n");
	printf("       1)�޸�����\n");
	printf("       2)�޸��Ա�\n");
	printf("       3)�޸�����\n");
	printf("       4)�޸��ֻ�����\n");
	printf("       5)�޸ĸߵ���ѧ�ɼ�\n");
	printf("       6)�޸�Ӣ��ɼ�\n");
	printf("       7)�޸�C���Գɼ�\n");
	printf("       8)�޸������ɼ�\n");
	printf("       9)�޸Ŀγ���Ƴɼ�\n");
	printf("\n%s%s\n", STARS, STARS);
	int t;
	scanf("%d", &t);
	getchar();
	return t;
}
void revise_name(void)
{
	char name[20];
	int match = 0;
	int n;
	printf("�������ѯ������");
	scanf("%s", &name);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("���ҵ���ѧ����Ϣ");
			printf("\nѧ��\t\t����\t�Ա�\t����\t�ֻ�����\t�ߵ���ѧ�ɼ�   Ӣ��ɼ�   C���Գɼ�   �����ɼ�   �γ���Ƴɼ�\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			n = revise_name_choice();
			switch (n)
			{
			case 0: revise();  break;
			case 1:
				printf("�޸ĺ��ѧ��Ϊ");
				scanf("%ld", &student[i].number);
				break;
			case 2:
				printf("�޸ĺ���Ա�Ϊ");
				scanf("%s", &student[i].sex);
				break;
			case 3:
				printf("�޸ĺ������Ϊ");
				scanf("%d", &student[i].age);
				break;
			case 4:
				printf("�޸ĺ���ֻ�����Ϊ");
				scanf("%s", &student[i].phone);
				break;
			case 5:
				printf("�޸ĺ�ĸߵ���ѧ�ɼ�Ϊ");
				scanf("%d", &student[i].score1);
				break;
			case 6:
				printf("�޸ĺ��Ӣ��ɼ�Ϊ");
				scanf("%d", &student[i].score2);
				break;
			case 7:
				printf("�޸ĺ��C���Գɼ�Ϊ");
				scanf("%d", &student[i].score3);
				break;
			case 8:
				printf("�޸ĺ�������ɼ�Ϊ");
				scanf("%d", &student[i].score4);
				break;
			case 9:
				printf("�޸ĺ�Ŀγ����Ϊ");
				scanf("%d", &student[i].score5);
				break;
			default:
				printf("�����������������\n");
				revise_number_choice();
			}
		}
	if (match == 0)
	{
		printf("�����޷����ҵ�ƥ������");
		revise();
	}
}
int revise_name_choice(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ��������ѡ��Ҫ���ĵ�����\n");
	printf("       0)�����޸Ĳ�������һ���˵�\n");
	printf("       1)�޸�ѧ��\n");
	printf("       2)�޸��Ա�\n");
	printf("       3)�޸�����\n");
	printf("       4)�޸��ֻ�����\n");
	printf("       5)�޸ĸߵ���ѧ�ɼ�\n");
	printf("       6)�޸�Ӣ��ɼ�\n");
	printf("       7)�޸�C���Գɼ�\n");
	printf("       8)�޸������ɼ�\n");
	printf("       9)�޸Ŀγ���Ƴɼ�\n");
	printf("\n%s%s\n", STARS, STARS);
	int t;
	scanf("%d", &t);
	getchar();
	return t;
}
void deletedata(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       ��������ѡ����\n");
	printf("       1)����ѧ��ѡ��ɾ����Ŀ\n");
	printf("       2)��������ѡ��ɾ����Ŀ\n");
	printf("       3)ȡ��ɾ��������һ���˵�");
	printf("\n%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	int t;
	scanf("%d", &t);
	getchar();
	switch (t)
	{
	case 1:
		deletedate_number();
		break;
	case 2:
		deletedate_name();
		break;
	case 3:
		menu();
		break;
	default:
		printf("�����������������\n");
		deletedata();
	}
}
void deletedate_number(void)
{
	printf("������ѧ��ѧ��");
	long int number;
	int match = 0;
	int i, j;
	scanf("%ld", &number);
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			for (j = i; j < count; j++)
				student[j] = student[j + 1];
			printf("�ѳɹ�ɾ����");
			match++;
			break;
		}
	if (match == 0)
	{
		printf("�����޷����ҵ�ƥ������\n");
		deletedata();
	}
}
void deletedate_name(void)
{
	printf("������ѧ������");
	char name[20];
	int match = 0;
	scanf("%s", &name);
	int i, j;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			for (j = i; j < count; j++)
				student[j] = student[j + 1];
			printf("�ѳɹ�ɾ����");
			match++;
			break;
		}
	if (match == 0)
	{
		printf("�����޷����ҵ�ƥ������");
		deletedata();
	}
}
void exit()
{
	int choice;
	printf("\n%s%s\n", STARS, STARS);
	printf("ȷ��Ҫ�˳���ϵͳô��\n");
	printf("       ���������־����Ƿ��˳�\n");
	printf("       1)ȷ���˳�\n");
	printf("       2)������һ���˵�\n");
	printf("\n%s%s\n", STARS, STARS);
	printf("����������ѡ��");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1: {printf("��л����ʹ�ã��ټ���"); break; break; }
	case 2: menu(); break;
	default:
	{
		printf("�����������������\n");
		exit();
	}
	}
}
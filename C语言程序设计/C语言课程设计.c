#include<stdio.h>
#define line 14
void square(void);//��ӡline����������

void main()
{
	printf("		ѧ����Ϣ��Ϣ����ϵͳ");
	printf("	������;��׳");

	getchar();
}
void square(void)
{
	int i = 0;
	for (i = 0; i < line; i++)
		printf("%2c", 3);
	printf("\n");
}
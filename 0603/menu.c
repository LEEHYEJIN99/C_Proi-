#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int menu_display();
void hamburger();
void spaghetti();
void press_any_key();

int main()
{
	int c;
	while((c=menu_display()) != 3)
	{
		switch(c)
		{
			case 1 : hamburger();
						break;
			case 2 : spaghetti();
						break;
			defult : break;
		}
	}
	return 0;
}

int menu_display()
{
	int select;
	system("cls");
	printf("���� �����\n\n");
	printf("1. �ܹ���\n");
	printf("2. ���İ�Ƽ\n");
	printf("3. ���α׷� ����\n");
	printf("�޴���ȣ �Է�>");
	select=getch() - 48;   //'0' = 48 = 30h, '1' = 48 = 31h, '2' = 50 = 32h
	return select;
}

void hamburger()
{
	system("cls");
	printf("�ܹ��� ����� ���\n");
	printf("�߷�\n");
	press_any_key();
}

void spaghetti()
{
	system("cls");
	printf("���İ�Ƽ ����� ���\n");
	printf("�߷�\n");
	press_any_key();
}

void press_any_key()
{
	printf("\n\n");
	printf("�ƹ�Ű�� ������ ���� �޴���...");
	getch(); 
}

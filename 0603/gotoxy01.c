#include<stdio.h>
#include<windows.h>

int gotoxy(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
	gotoxy(2,4);
	printf("Hello");
	gotoxy(40,20);
	printf("Hello\n");
	
	return 0;
}

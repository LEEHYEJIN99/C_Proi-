#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void intro_game(void);
void horizontal_slide(int x, int y, char *c2);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count);
void game_control(int* r_c, int rnd);
void gotoxy(int x, int y);

int main(void)
{
   int count=0, rnd;	//count는 시행횟수 
   int r_count=0;	//성공한 횟수 
   char *target="□";
   srand(time(NULL));
   intro_game();	
   do
   {
      system("cls");
      draw_rectangle(20, 20);
      rnd=rand()%35+4;
      gotoxy(rnd, 2);
      printf("%s", target);
      count++;
      display_text(count, r_count);
      game_control(&r_count, rnd);
   }while(count<10);
   return 0;
}

void intro_game(void)	//게임에 대한 설명 
{
	printf("말타며 화살쏘기\n\n");
	printf("말을 타고 이동하면서 \n");
	printf("목표물(□)을 맞추는 게임입니다. \n");
	printf("화살은 스페이스키로 발사합니다. \n\n");
	printf("아무키나 누르면 시작합니다. ");
	getch();

}
void horizontal_slide(int x, int y, char *c2)	//말의 움직임을 표시 
{
		gotoxy(x, y);
		printf("%s", c2);
		Sleep(50);
		printf("\b ");
}
void draw_rectangle(int r, int c)	//사각형 표시 
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   	b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c;i++)
  	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
		printf("  ");
	printf("%c%c",a, b[2]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
void display_text(int count, int r_count)	//지시문과 성공에 대한 점수 표시 
{
	gotoxy(46, 2);
	printf("스페이스키를 누르면\n");
	gotoxy(46, 3);
	printf("화살이 발사됩니다.\n");
	gotoxy(46, 5);
	printf("횟수 : %d", count);		//시행횟수 
	gotoxy(46, 6);
	printf("성공 : %d", r_count);	//성공횟수 
}

void game_control(int* r_c, int rnd)	//게임 제어 부분 
{
	int i=1, k=1, y;
	char *horse="▲", chr;
	do
	{
		i+=k;
		if (i>39)	//말을 좌우로 이동시킴 
			k=-1;
		else if (i<3)
			k=+1;
		horizontal_slide(i+1, 21, horse);
	}while(!kbhit());
	chr=getch();	  
	y=21;
	//누른 키가 SpaceBar키 이면 화살을 발사하고 화살을 연서속적으로 화면에 출력 
	if (chr==32)
	{
		while(y>2)
		{
			y-=1;
			gotoxy(i+1, y);
			printf("↑");
			Sleep(50);
			printf("\b  ");
		}
		if ((rnd<=i) && (i<=(rnd+1)))	//rnd는 목표물의 x축 위치 
		{	
			//목표물이 맞았는지를 확인
			gotoxy(rnd, 2);
			printf("☆");
			gotoxy(46, 8);	
			printf("맞았습니다. ");	
			Sleep(50);
			*r_c=*r_c+1;	
		}
		gotoxy(1, 24);	//맞았으면 맞은 개수를 증가 
		printf("아무키나 누르면 다음 진행...");
		getch();
	}

}
void gotoxy(int x, int y)	//커서의 위치 이동 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

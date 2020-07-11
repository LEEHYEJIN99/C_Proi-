#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define cake_number 30  //과자의 개수 

void intro_game(void);
void input_participant(char user_name[][8]);
void game_control(char name[][8], int condition[], int *left, int user, int *start, int *end);
void cake_display(char name[][8], int condition[], int left, int start, int end);
void gotoxy(int x, int y);

//주사위로 과자먹기 게임 
int main(void)
{	
	//변수 초기화 
	int i, start, end, cake_left=cake_number, winner;	//변수 left-남아있는 과자의 개수를 저장 
	int cake_condition[cake_number]={0};	//과자의 상태를 구분하는 배열 
	char user_name[2][8];	//게임 참가자의 이름이 저장된 배열 
	srand(time(NULL));
   
	intro_game();
	input_participant(user_name);

	start=0;
	end=cake_number-1;

	system("cls");
	game_control(user_name, cake_condition, &cake_left, 2,  &start, &end);  //user의 값을 2로 하여 과자의 초기상태를 출력

	gotoxy(10, 12);
	printf("아무키나 누르면 다음 순서를 진행합니다. ");
	getch();
	
	//게임 초기화 
	do
	{
		for(i=0;i<2;i++)
		{
			system("cls");
			game_control(user_name, cake_condition, &cake_left, i, &start, &end);
			if (cake_left<2)
			{
				winner=i;
				break;
			}
			gotoxy(10, 12);
			printf("아무키나 누르면 다음 순서를 진행합니다. ");
			getch();
		}
	}while(cake_left>2);	//게임의 승자를 출력 

	gotoxy(10, 12);
	printf("%s님이 이겼습니다. ", user_name[winner]);
	gotoxy(10, 13);
	printf("게임을 종료합니다. \n");
	return 0;
}

void intro_game(void)	//게임 설명(게임의 소개와 규칙을 출력)
{
	system("cls");
	printf("주사위로 과자먹기 게임 \n\n");
	printf("두사람이 서로 양끝의 주사위 숫자만큼\n");
	printf("과자를 먹는 게임입니다. \n");
	printf("마지막 남은 과자를 먹는 사람이 이깁니다. \n\n");
	printf("아무키나 누르면 게임참가자를\n");
	printf("입력합니다.\n");
	getch();

}

void input_participant(char user_name[][8])	//2명의 참가자 이름 입력 
{
	system("cls");
	printf("1번 참가자의 이름을 입력하고 Enter>");
	scanf("%s", user_name[0]);
	printf("2번 참가자의 이름을 입력하고 Enter>");
	scanf("%s", user_name[1]);
	printf("아무키나 누르면 게임을 시작합니다...");
	getch();

}
void game_control(char name[][8], int condition[],  int *left, int user, int *s, int *e)	//게임 제어 
{
	int i, dice_number;
	//변수 s는 배열 condition에 대해 먹지 않은 과자의 시작 위치(index)를, e는 끝 위치(index)를 표시함. 
	cake_display(name, condition, *left, *s, *e);
	if (user==2)
		return;  //user가 2가 되는 경우는 main으로 복귀 
	dice_number=rand()%6+1;  //주사위 난수 생성
	*left-=dice_number;
	gotoxy(10, 11);
        printf("%s님의 주사위 숫자는 %d입니다.",name[user],dice_number); 
			
	if (user==0)
	{
		for(i=*s;i<dice_number+*s;i++)
			condition[i]=1;
		*s+=dice_number;
	}
	else
	{ 
		for(i=*e;i>(*e-dice_number);i--)
			condition[i]=1;
		*e-=dice_number;
	}
	cake_display(name, condition, *left, *s, *e);
}
void cake_display(char name[][8], int condition[], int left, int s, int e)	//먹었거나 남아있는 과자를 표시 
{
	int i;
	//먹은 과자 배열 condition[] 의 값이 1 이 되는 경우로서 기호 ■ 로 표현하고, 
	//남아 있는 과자는 배열 condition[] 의 값이 0인 상태로 기호 □ 로 구분
	char *eat_cake="■", *remain_cake="□";

	gotoxy(30,5);
	if (left<0)
		left=0;
	printf("남은 과자의 수 : %2d 개 ", left);

	for(i=0;i<2;i++)
	{
		gotoxy(i*50+10, 6);
		printf("%s", name[i]);
	}

	for(i=0;i<30;i++)
		if (condition[i]==1)
		{
			gotoxy(10+i*2, 8);
			printf("%s", eat_cake);
		}
		else
		{
			gotoxy(10+i*2, 8);
			printf("%s", remain_cake);
		}

	gotoxy(10, 9);
	printf("먹은 과자 수: %2d", s);
	gotoxy(52, 9);
	printf("먹은 과자 수: %2d", 29-e);
}

void gotoxy(int x, int y)	//커서의 위치 제어 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

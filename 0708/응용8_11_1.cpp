#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y);
void game_control(int order, char name[7], char sol[][10], double check[][10], int quest);
void display_result(int user, int order[], double check[][10], char name[][7], char sol[][10], int quest);
void display_rule(void);

int main(void)
{
	int i, user_number, quest_number, rnd, temp;
	int order[4]={0, 1, 2, 3};
	char solution[4][10]={0}; 
	double time_check[4][10]={0};
	char user_name[4][7];
	srand(time(NULL));	//변수 초기화 

	printf("청기/백기 게임\n\n");
	printf("게임에 참가할 인원수를 입력하고 Enter>");	  
	scanf("%d", &user_number);		//참가 인원수 입력 
	printf("\n문제의 개수를 입력하고 Enter>");	
	scanf("%d", &quest_number);		//문제의 개수 입력 

	for(i=0;i<user_number;i++)
	{
		printf("%d번 참가자의 이름을 입력하고 Enter>", i+1);
		scanf("%s", &user_name[i]);		//참가자의 이름 입력 
	}
	printf("만약 한글을 사용하였다면 영문키로 바꾸십시오.\n");	 
	printf("아무키나 누르시오.\n");		
	getch();	//참가자의 게임순서를 임의로 변경 
   printf("\n게임의 순서는 다음과 같습니다. \n");		 
   for(i=0;i<user_number;i++)
   {
 	rnd=rand()%user_number;
	temp=order[i];
	order[i]=order[rnd];
	order[rnd]=temp;
   }
   for(i=0;i<user_number;i++)
   {
	printf("%d번 : %s\n", i+1, user_name[order[i]]);
   }
   printf("아무키나 누르시오.\n");
   getch();

   for(i=0;i<user_number;i++)
	game_control(order[i], user_name[order[i]], solution, 
		time_check, quest_number);

   printf("\n\n");
   printf("모든 게임이 끝났습니다. \n");	//게임의 종료 표시
   printf("아무키나 누르면 결과를 표시합니다. \n");		//게임 결과 출력
   getch();
   display_result(user_number, order, time_check, user_name, 
	solution, quest_number);
   getch();
   return 0;
}

void gotoxy(int x, int y)	//커서의 위치 제어 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_control(int order, char name[7], char sol[][10], double check[][10], int quest)	//청기 백기 게임 제어 
{
   char *flag[]={"청기", "백기"};		//문제 용어를 배열에 저장 
   char *question[]={"내려!", "올려!", "내리지말고", "올리지말고"};		//게임규칙 출력 
   clock_t start, end;
   int i, rnd[4];
   char key;
   system("cls");
   gotoxy(1, 3);
   printf("%s님 순서입니다. 키 조작은 다음과 같습니다.", name);
   display_rule();	//입력한 키가 정답인지를 확인 
   for(i=0;i<quest;i++)
   {
  	system("cls");
	rnd[0]=rand()%2;	 
	rnd[1]=rand()%4;
	start=clock();		 
	gotoxy(5, 10);		
	if (rnd[1]>1)	//청기백기 문제 생성과 출력
	{
	       rnd[2]=rand()%2;
	       rnd[3]=rand()%2;
	       printf("%d: %s %s %s %s", i+1, flag[rnd[0]], question[rnd[1]], flag[rnd[2]], question[rnd[3]]);
  	}
	else		
	printf("%d: %s %s", i+1, flag[rnd[0]], question[rnd[1]]);	
    	key=getch();
	end=clock();
	check[order][i]=(double)(end-start)/CLK_TCK;	//문제출력과 답 입력 사이의 경과시간을 계산 
	if (rnd[1]>1)		//키와 입력 확인 
	{
		if ((rnd[2]==0) && (rnd[3]==0) && (key=='z'))
			sol[order][i]=1;
		else if ((rnd[2]==0) && (rnd[3]==1) && (key=='a'))	
			sol[order][i]=1;
		else if ((rnd[2]==1) && (rnd[3]==0) && (key=='m'))	
			sol[order][i]=1;
		else if ((rnd[2]==1) && (rnd[3]==1) && (key=='k'))	
	                             sol[order][i]=1;
		else
			sol[order][i]=0;
	}
	else	//맞았는지 확인 
	{
		if ((rnd[0]==0) && (rnd[1]==0) && (key=='z'))
			sol[order][i]=1;
		else if ((rnd[0]==0) && (rnd[1]==1) && (key=='a'))	
			sol[order][i]=1;
		else if ((rnd[0]==1) && (rnd[1]==0) && (key=='m'))	
			sol[order][i]=1;
		else if ((rnd[0]==1) && (rnd[1]==1) && (key=='k'))	
			sol[order][i]=1;
		else
			sol[order][i]=0;
	}
    }
}

void display_result(int user, int order[], double check[][10], char name[][7], char sol[][10], int quest)	//결과 표시(시간, 맞은 개수) 
{
   int i, j, result[4]={0};
   double min_time[4]={0};
   system("cls");
   printf("       ");
   for(i=0;i<user;i++)
	printf("%8s  ", name[order[i]]);	//사용자 이름 출력 
   printf("\n");
   for(j=0;j<quest;j++)		//각 문제당 정오표시와 반응시간 출력 
   {
	printf("    %d번 : ", j+1);
	for(i=0;i<user;i++)
	{   
		if (sol[order[i]][j]  && check[order[i]][j]<1)
		{
			printf("O");
			result[order[i]]+=1;
		}
		else
			printf("X");
		printf("%5.2f     ",check[order[i]][j]);
		if ((sol[order[i]][j]==1) && (check[order[i]][j]<1))
			min_time[order[i]]+=check[order[i]][j];
	}
	printf("\n");
   }
   printf("\n");
   printf("맞은개수:");
   for(i=0;i<user;i++)		//맞은 문제의 개수 출력 
	 printf("%7d    ", result[order[i]]);
   printf("\n");
   printf("소요시간:");	
   for(i=0;i<user;i++)		//문제 푸는 데 총 소요시간 출력 
	 printf("%7.2f    ", min_time[order[i]]);
   printf("\n");
}

void display_rule(void)	//키의 조작 방법 설명 
{
	gotoxy(1,4);
	printf("게임시작전까지 키를 누르지 마세요!");
	gotoxy(1, 6);
	printf("청기 올려 : a    백기 올려 : k");
	gotoxy(1, 7);
	printf("청기 내려 : z    백기 내려 : m");
	Sleep(2000);
	gotoxy(1, 8);
	printf("5초 후에 게임을 시작합니다. 준비하세요.");
	Sleep(5000);

}

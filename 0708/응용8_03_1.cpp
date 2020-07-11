#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start);
void display_time(long nhour, long nmin, long nsecond);
void control_watch(void);

int main(void)
{
	display_time(0, 0, 0);
	getch();
	control_watch();
	return 0;
}

void control_watch(void)	//키를 입력받아 stopwatch를 제어 
{
   char key;
   time_t start;
   start=time(NULL);	
   time_pass(start);	 
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 :
		time_pass(start);	//enter키를 누르면 시작 또는 정지 
	   case 32 : 
		start=time(NULL);	//SpaceBar를 누르면 시작 시간을 0으로 초기화하여 재시작 
		time_pass(start);
		break;
	   case 27 : 	//esc키를 누르면 프로그램 종료 
		exit(0);
		break;
	}
   }while(key!=27);

}

void time_pass(time_t start)	//시작시간과 현재시간 사이의 차이를 계산 
{
	double hour, min, second;
	long nhour, nmin, nsecond;	 
	time_t now;			//시작 시간 start와 현재 시간(now)과의 차이계산
	while(!kbhit())		//시간 형식에 맞게 출력
	{
		now=time(NULL);
		second=difftime(now, start);
		hour= (second/3600.);
		nhour= (long) hour;
		min= fmod(second, 3600.)/60;
		nmin= (long) min;
		second= fmod(second, 60);
		nsecond= (long) second;
		display_time(nhour, nmin, nsecond);
	 }
	}
	
void display_time(long nhour, long nmin, long nsecond)	//경과된 시간을 표시 
{
	system("cls");
	printf("stopwatch\n\n");
	printf("%.2ld시 %.2ld분 %.2ld초 \n\n", nhour, nmin, nsecond);
	printf("Enter:(시작/정지), SPACE:재시작, Esc:종료\n");

}

#include<stdio.h>
int main()
{
	char a, b;
	
	printf("대문자 입력 : ");
	scanf("%c", &a); 
	getchar();
	//fflush(stdin);
	printf("소문자 입력 : ");
	scanf("%c", &b);
	
	//A = 65, a = 97 '0' = 47
	printf("당신이 입력한 %c의 소문자는 %c입니다.\n",a,a+32);
	printf("당신이 입력한 %c의 대문자는 %c입니다.\n",b,b-32);
	return 0;
}

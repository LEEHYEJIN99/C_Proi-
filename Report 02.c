#include<stdio.h>

void swapNumber(int a, int b)  //int형 매개변수- int a(첫번째 변수), int b(두번째 변수), 
{
	int imsibogwan;  //임시 보관 변수
	
	imsibogwan = a; 
	a = b;
	b = imsibogwan;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	
	swapNumber(num1, num2); //변수 num1과 num2를 넣어줌 
	
	printf("%d %d\n", num1, num2);   // 10 20: swapNumber 함수와는 상관없이
									 // 처음 저장한 10과 20이 출력됨
	
	return 0;
}

#include<stdio.h>

void swapNumber(int *a, int *b)  //int형 포인터 매개변수 두개 지정- int a(첫번째 변수), int b(두번째 변수)
								 
{
	int imsibogwan;  //임시 보관 변수
	
	// 역참조로 값을 가져오고, 값을 지정함 
	imsibogwan = *a;  
	*a = *b;
	*b = imsibogwan;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	
	swapNumber(&num1, &num2);  // &를 사용하여 num1과 num2의 메모리 주소를 넣어줌
	
	printf("%d %d\n", num1, num2);   // 20 10: swapNumber에 의해서 num1과 num2의 값이 서로 바뀜
	
	return 0;
}

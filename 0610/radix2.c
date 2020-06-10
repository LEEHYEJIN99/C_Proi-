#include<stdio.h>
long dec_to_bin(long n)
{
	long bin, sum=0, i=1;
	while(n>0)
	{
		bin=n%2;
		sum+=bin*i;
		n/=2;
		i*=10;
	}
	return sum;
}

int main()
{
	int a;
	
	printf("정수 입력 : ");
	scanf("%d", &a);
	
	printf("%d는 이진수 %ld 입니다.\n", a, dec_to_bin(a));
	
	return 0;
}



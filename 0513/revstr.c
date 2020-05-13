#include<stdio.h>
#include<string.h>
int main()
{
	char str[80];
	int i;
	
	printf("문자열 입력 : ");
	scanf("%s", str);
	
	//printf("%s", str);
	for(i = strlen(str); i >= 0; i--)
		putchar(str[i]);
	
	
	return 0;
}

#include<stdio.h>
#include<string.h>

int main(void) 
{
	char str1[] = "Testing";
	int i;
	
	printf("%d\n", strlen(str1));
	printf("%d\n", sizeof(str1));
	
	
	for(i = 0; i <= strlen(str1); i++)
	{
		printf("str1[%d] = %d\n", i, str1[i]);
	}
	
	return 0;
}

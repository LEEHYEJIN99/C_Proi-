#include<stdio.h>
#include<string.h>

void mystrcpy(char dest[3], const char source[3]);  //매개변수가 일차원 배열일때 

void main()
{
	char str[255] = "abcdefg";
	mystrcpy(str, "abcd");     //함수 호출 
	printf("%s\n", str);
	
}

void mystrcpy(char dest[3], const char source[3])
{ 
	printf("dest의 주소 : %d\ndest의 크기 : %d\n", dest, sizeof(dest));
	int i = 0;
	while(source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = NULL;
}

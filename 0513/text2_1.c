#include<stdio.h>
#include<string.h>
int main()
{
	char s[] = "swimming";
	char t[5] = "야구";
	char v[10] = {'a', 'b', 'c', '\0', 'd', 'e'};
	
	printf("배열 s의 크기는 %d 입니다.\n", sizeof(s));
	printf("배열 t의 크기는 %d 입니다.\n", sizeof(t));
	printf("배열 v의 크기는 %d 입니다.\n", sizeof(v));
	printf("배열의 길이는 %d입니다. \n", strlen(s));
	printf("배열의 길이는 %d입니다. \n", strlen(v));
	
	printf("배열 v의 내용 : %s\n", v);
	
	printf("s : %s\n", s);
	printf("s[2] : %c\n", s[2]);
	printf("t : %s\n", t);
	printf("t : %c%c\n", t[2], t[3]);
	
	return 0;
}

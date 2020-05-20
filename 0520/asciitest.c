#include<stdio.h>
#include<string.h>

int main()
{
	int i;
	char buf[80] = "abc";
	
	for(i=0; i<strlen(buf); i++)
	{
		scanf("%c", buf[i]);
		if(buf[i]=='0')
			break;
	}
	puts(buf);
	
	return 0;
}

#include <Stdio.h>
#include <Stdlib.h>

int main()
{
	int i;
	srand(10);
	for(i=1;i<=15;i++)
		printf("%2d:%5d\n", i, rand());
		
	return 0;
}

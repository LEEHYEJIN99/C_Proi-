#include<stdio.h>
#include<string.h>

void Array(int(*array)[3]);

void main()
{
	int i, j;
	int array[5][3];
	
	Array(array);	//�Լ� ȣ�� 
	
	//2�����迭 ���
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void Array(int(*array)[3])
{
	int i, j; 
	for (i = 0; i < 5; i++)
	{
		for(j = 0; j < 3; j++)
		{
			array[i][j] = 10;
		}
	}
}

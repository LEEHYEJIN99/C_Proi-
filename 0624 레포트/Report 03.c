#include<stdio.h>

void swapNumber(int *a, int *b)  //int�� ������ �Ű����� �ΰ� ����- int a(ù��° ����), int b(�ι�° ����)
								 
{
	int imsibogwan;  //�ӽ� ���� ����
	
	// �������� ���� ��������, ���� ������ 
	imsibogwan = *a;  
	*a = *b;
	*b = imsibogwan;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	
	swapNumber(&num1, &num2);  // &�� ����Ͽ� num1�� num2�� �޸� �ּҸ� �־���
	
	printf("%d %d\n", num1, num2);   // 20 10: swapNumber�� ���ؼ� num1�� num2�� ���� ���� �ٲ�
	
	return 0;
}

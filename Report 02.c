#include<stdio.h>

void swapNumber(int a, int b)  //int�� �Ű�����- int a(ù��° ����), int b(�ι�° ����), 
{
	int imsibogwan;  //�ӽ� ���� ����
	
	imsibogwan = a; 
	a = b;
	b = imsibogwan;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	
	swapNumber(num1, num2); //���� num1�� num2�� �־��� 
	
	printf("%d %d\n", num1, num2);   // 10 20: swapNumber �Լ��ʹ� �������
									 // ó�� ������ 10�� 20�� ��µ�
	
	return 0;
}

#include <stdio.h>

int factorial(int n)
{
	printf("%d", n);
    if (n == 1)      // n�� 1�� ��
        return 1;    // 1�� ��ȯ�ϰ� ���ȣ���� ����

    return n * factorial(n-1);		//n�� factorial �Լ��� n-1�� �־ ��ȯ�� ���� ����
    //factorial(n-1);
	//printf("%d", n);
}

int main()
{
    printf("%d", factorial(5));

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS   // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>               // strcpy �Լ��� ����� ��� ����

struct Profile{
    char name[20];
    int age;		
    char address[100];
};

void printProfile(struct Profile p)    // ��ȯ�� ����, ����ü �Ű����� �� �� ����
{
    // ����ü �Ű����� ����� �� ���
    printf("�̸�: %s\n", p.name);       // �̸�: ȫ�浿
    printf("����: %d\n", p.age);        // ����: 30
    printf("�ּ�: %s\n", p.address);    // �ּ�: �λ�� �ż��� ������
}

int main()
{
    struct Profile p1;

    strcpy(p1.name, "������");
    p1.age = 30;
    strcpy(p1.address, "�λ�� �ż��� ������");

    printProfile(p1);    // �Լ��� ȣ���� �� ����ü ���� ����, ����� �����

    return 0;
}

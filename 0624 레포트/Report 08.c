#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>    // strcpy �Լ��� ����� ��� ����

struct Profile {
    char name[20];
    int age;
    char address[100];
};

void setProfile(struct Profile *p)    // ��ȯ�� ����, ����ü ������ �Ű����� �� �� ����
{
    // �Ű������� ���� �����Ϳ��� ����ü ����� �� ����
    strcpy(p->name, "������");
    p->age = 40;
    strcpy(p->address, "�λ�� �ż��� ������");
}

int main()
{
    struct Profile p1;

    strcpy(p1.name, "ȫ�浿");
    p1.age = 30;
    strcpy(p1.address, "�λ�� �ż��� ������");

    setProfile(&p1);    // �Լ��� ȣ���� �� ����ü ������ �޸� �ּҸ� ����

    // setPerson���� ������ ���� ��µ�
    printf("�̸�: %s\n", p1.name);       // �̸�: ��浿
    printf("����: %d\n", p1.age);        // ����: 40
    printf("�ּ�: %s\n", p1.address);    // �ּ�: �λ�� �ż��� ������

    return 0;
}

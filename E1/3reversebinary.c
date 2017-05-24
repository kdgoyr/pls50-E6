#include <stdio.h>
#include <stdlib.h>

void pr(void);                                              /* ������ ����������� */
void calcbin(int num);

int main()
{
    int num;                                                /* ��������� ������� �������� ������� */
    while(1)                                                /* ����� ��������� ������� ���� �� ��������� ��������� �� ��������� �� ������ �� ���� ������ */
    {
        printf("Dwste enan thetiko akeraio arithmo: ");     /* ������ ������� ��� �� ������������ */
        scanf(" %d", &num);                                 /* ������� ������� ��� �� ������������ */
        (num<0)?pr():calcbin(num);                          /* ����� ��������� ������� ��� �� ��������� ��� ������� � ��� �������� ��������� ���� ����� */
    }
}

void pr(void)                                               /* ��������� ��������� ��������� ��������� ��� ����� ��������� ������� */
{
    printf("Dwsate arnhtiko arithmo!\n");
}

void calcbin(int num)                                       /* ��������� ����������� ����������� �������� ������������� ������� */
{
    const int dyo=2;                                        /* ������� ��� 2 �� ������� */
    printf("O arithmos poy dwsate, se antistrofh dyadikh anaparastash einai: ");
    while (num>-1)
    {
        num%dyo==1?putchar('1'):putchar('0');               /* ����� ��������� ������� ��� putchar ��� ��� �������� ���� bit */
        num=num/dyo;                                        /* ����������� ��������� �������� ������� �� �� 2 */
        if (num==0)
        {
            exit(0);                                        /* �������� ������ */
        }
    }
}

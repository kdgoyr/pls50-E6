#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ytetr(float v1);              /* ��������     */
float yparal(float v1, float v2);   /*              */
float yotrig(float v1, float v2);   /*              */
float ykykl(float v1);              /* �����������  */

int main()
{
    char choice;                    /* ��������� ����������� �������� */
    float t1,t2;                    /* ���������� ���������� ��� ������ ����� �������� ��� �� ������������ */
    while(1)                        /* ������� ������� */
    {
        printf("Menu epilogwn ypologismoy perimetroy\n");   /* �����          */
        printf("0. Exodos\n");                              /*                */
        printf("1. Tetragwno\n");                           /*                */
        printf("2. Parallhlogrammo\n");                     /*                */
        printf("3. Orthogwnio trigwno\n");                  /*                */
        printf("4. Kyklos\n");                              /*                */
        printf("Eisagete thn epilogh sas: ");               /* ��������       */
        scanf(" %c", &choice);                              /* ������� ��� �������� ������ ��� �� ������������ */
        printf("\n");
        if (choice=='0')                                    /* ������ �� ��������� ��������� 0 ��� ��� ������ */
        {
            exit(0);
        }
        else if (choice=='1')                                           /* ������� ������ ������� ��� ����������� ���������� ���������� �� ��������� */
            {                                                           /* ��� � ������� �������� 1 */
            printf("Dwste to mhkos ths pleyras toy tetragwnoy: ");
            scanf("%f" , &t1);
            printf("H perimetros toy tetragwnoy einai: %f",ytetr(t1));
            exit(0);
            }
        else if (choice=='2')                                               /* ������� ������ ��� ������� ��� ����������� ���������� ���������������� �� ��������� */
            {                                                               /* ��� � ������� �������� 2 */
            printf("Dwste to mhkos kai to platos toy parallhlogrammoy: ");
            scanf("%f %f" , &t1, &t2);
            printf("H perimetros toy parallhlogrammoy einai: %f",yparal(t1,t2));
            exit(0);
            }
        else if (choice=='3')                                                           /* ������� ������ ������� ������� ��� ����������� ���������� ���������� �������� �� ��������� */
            {                                                                           /* ��� � ������� �������� 3 */
            printf("Dwste to mhkos twn 2 kathetwn pleyrwn toy orthogwnioy trigwnoy: ");
            scanf("%f %f" , &t1, &t2);
            printf("H perimetros toy orthogwnioy trigwnoy einai: %f",yotrig(t1,t2));
            exit(0);
            }
        else if (choice=='4')                                                       /* ������� ��� ����������� ���������� ������ �� ��������� */
            {                                                                       /* ��� � ������� �������� 4 */
            printf("Dwste to mhkos ths aktinas toy kykloy: ");
            scanf("%f", &t1);
            printf("H perimetros toy kykloy einai: %f",ykykl(t1));
            exit(0);
            }
    }
}

float ytetr(float v1)       /* ��������� ����������� ���������� ���������� */
    {
        return 4*v1;
    }
float yparal(float v1, float v2)    /* ��������� ����������� ���������� ���������������� */
    {
        return 2*(v1+v2);
    }
float yotrig(float v1, float v2)    /* ��������� ����������� ���������� ���������� �������� */
    {
        return v1+v2+sqrt(v1*v1+v2*v2);
    }
float ykykl(float v1)   /* ��������� ����������� ���������� ������ */
    {
        return 2*M_PI*v1;
    }

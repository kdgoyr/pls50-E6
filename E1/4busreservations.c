#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char pinakida[7];                   /* ��������� ���� ������������ � ������� ��� ��������� ��� �� ������ bus.txt */
    int numSeats, choice, choice2;      /* numSeats: ��������� ���� ������������ � ������� ��� ������ ��� ���������� ��� �� ������ bus.txt, choice ��� choice2: ���������� ����������� �������� ������ ����� ��� ������� ����� ��� �������� */
    int k, l, seats[53], nSeats[53];    /* k: ��������� ��� ����� ������� �������, l: ��������� ��� �� ������ ��� ����� ������, seats[53]: ������� �������� ������, nSeats[53]: ������� ����������� ������� ���������� ����� */
    for(k=0;k<=52;k++)                  /* ������������ ������ ��������� 53 ������ �� 0 */
    {
        seats[k]=0;
    }
    FILE *fp;
    if ((fp = fopen("bus.txt","r")) == NULL)            /* ������� ������� bus.txt ��� ������� ��������� ���������� */
        {
        printf("Sfalma sto anoigma toy arxeioy bus.txt! Prepei na einai ston idio fakelo.");
        exit(1);
        }
    fscanf(fp,"%s %d", pinakida, &numSeats);            /* �������� ��� �� ������ ������� ��������� ��� ��������� ������� ������ */
    printf("%s %d \n", pinakida, numSeats);             /* �������� ���� ����� ��� ������� ��������� ��� ��������� ������� ������ */
    if (numSeats>53)                                    /* ������� ��� � ��������� ������� ������ ����� ����������� ��� 53 */
    {
        printf("Sfalma! O arithmos twn thesewn einai megalyteros apo 53!");
        exit(1);
    }
    if ((numSeats-5)%4!=0)  /* ������� ��� �  ������� ������ ������ ��� ������ 4�+5 */
    {
        printf("Sfalma! O arithmos twn thesewn den symbadizei me thn katanomh!");
        exit(1);
    }
    while(1) /* ������� ������� ���� � ������� �� ���������� �� ��������� ���� ���� ��� �� ����� */
    {
        printf("\n1. Emfnish synolikoy plhthoys kenwn thesewn kai o arithmos toys: \n");        /* ����� ������ */
        printf("2. Krathsh theshs me sygkekrimeno arithmo: \n");
        printf("3. Eyresh kai krathsh ths prwths kenhs theshs se parathyro \n");
        printf("4. Akyrwsh krathshs theshs me sygkekrimeno arithmo \n");
        printf("5. Anazhthsh krathmenhs theshs me sygkekrimeno arithmo \n");
        printf("6. Emfanish listas krathmenwn thesewn taxinomhmenhs kata arithmo theshs \n");
        printf("7. Emfanish pinakidas kykloforias kai diagrammatos lewforeioy \n");
        printf("8. Apothikeysh pinakidas kykloforias kai diagrammatos lewforeioy \n");
        printf("0. Termatismos programmatos \n");
        printf("Dwste thn epilogh sas: ");
        choice = getch();           /* �������� ��� �� ������������ ��� �������� ������ */
        printf("\n\n");
        if (choice=='0')            /* ������ ��� �� ��������� �� ��������� ��� � ������� �������� 0 */
        {
            exit(0);                /* �������� ������ */
        }
        else if (choice=='1')           /* ������� ��� � ������� ������ ����� 1 */
        {
            l=0;                        /* � ������� ��� ����� ������ �������������� �� 0 ��� �� ������������ �� ��� ������� ������ */
            for(k=0;k<=numSeats-1;k++)  /* ������� ���������� ���� ��� �� ������ ��� ���������� ��� ������� ������� ����� ������ ��� ���������� ��� ���� ������� ����� ����� */
            {
                if (seats[k]==0)        /* ������� ��� � ���� ����� ���� */
                {
                    l++;                /* ���� �� ����� ��� ����������� �� �������� �� ������ ��� ����� ������ */
                    nSeats[l-1]=k+1;    /* ���������� ������� ����� ����� ���� ������ ������� ����� ������ */
                }
            }
            printf("Plhthos kewnwn thesewn: %d\n", l);  /* �������� ���� ����� ��� ������� ����� ������ */
            printf("Arithmoi kewnwn thesewn: ");        /* �������� ���� ����� ��� ������� ����� ������ */
            for(k=0;k<=l-1;k++)                         /* ������� ��������� ������� ����� ������ */
            {
                printf("%d ", nSeats[k]);
            }
            printf("\n");
        }
        else if (choice=='2')       /* ������� ��� � ������� ������ ����� 2 */
        {
            printf("Dwste ton arithmo ths theshs pros krathsh: ");  /* �������� ��������� ��������� ������� ����� ���� ������� */
            scanf("%d", &choice2);                                  /* �������� ��� �� ������������ ��� ������� ����� ���� ������� */
            if ((choice2<1) || (choice2>numSeats))                  /* ������� ��� � ��������� ������� ������ ����� ����� ��� ����� */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!");
                exit(1);
            }
            else if (seats[choice2-1]==1)                           /* ������� ��� � ���� ����� ��� ��������� */
            {
                printf("H thesh einai hdh krathmenh!\n");
            }
            else
            {
                seats[choice2-1]=1;                                 /* ������� ����� */
                printf("H thesh kraththike!\n");
            }
        }
        else if (choice=='3')           /* ������� ��� � ������� ������ ����� 3 */
        {
            for (k=1;k<=numSeats;k++)
            {
                if ((((k-1)%4==0) || (k%4==0)) && (k<=(numSeats-4)) && (seats[k-1]==0))  /* ������� ��� � ���� ����� �� �������� ��� ��� ��������� ����� ��� ���������� ����� ������ 1 ���� �������� ��� ��� ����������� �� �������� */
                {
                    seats[k-1]=1;                                   /* ������� ����� �� �������� */
                    printf("Kraththike h thesi: %d\n", k);
                    break;
                }
                else if ((k==numSeats && (seats[k-1]==0)))          /*  ������� ��� � ��������� ���� ��� ����� ��������� */
                {
                    seats[k-1]=1;                                   /* ������� ���������� ����� �� ��������� ��� ��� ����� ��������� */
                    printf("Kraththike h thesi: %d\n", k);
                }
                else if ((k==numSeats && (seats[k-1]==1)))          /*  ������� ��� � ��������� ���� ����� ��������� ��� �������� ��� ���� �� ������ �� �������� ����� ���������� */
                {
                    printf("Oles oi theseis sto parathyro einai krathmenes!\n"); /* �������� ��������� ���������� ������ �� �������� */
                }
            }
        }
        else if (choice=='4')                       /* ������� ��� � ������� ������ ����� 4 */
        {
            printf("Dwste ton arithmo ths theshs pros akyrwsh: ");  /* �������� ���� ����� ��������� ��� �������� ������� ����� ���� ������� */
            scanf("%d", &choice2);                                  /* �������� ��� �� ������������ ��� ������� ����� ��� ������� */
            if ((choice2<1) || (choice2>numSeats))                  /* ������� ��� � ��������� ������� ������ ����� ����� ��� ����� */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                exit(1);
            }
            else if (seats[choice2-1]==0)                           /* ������� ��� � ���� ��� ����� ��� ��������� */
            {
                printf("H thesh den einai krathmenh!\n");           /* �������� ���� ����� �������� ��������� */
            }
            else                                                    /* ������� �������� ����� */
            {
                seats[choice2-1]=0;
                printf("H thesh akyrwthike\n");
            }
        }
        else if (choice=='5')                       /* ������� ��� � ������� ������ ����� 5 */
        {
            printf("Dwste ton arithmo ths theshs pros anazhthsh: ");
            scanf("%d", &choice2);
            if ((choice2<1) || (choice2>numSeats))          /* ������� ��� � ��������� ������� ������ ����� ����� ��� ����� */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                exit(1);
            }
            else if (seats[choice2-1]==0)                   /* ������� ��� � ���� ��� ����� ��� ��������� */
            {
                printf("H thesh den einai krathmenh!\n");   /* �������� */
            }                                               /* ����     */
            else                                            /* �����    */
            {                                               /* �������� */
                printf("H thesh einai krathmenh!\n");       /* ��������� */
            }
        }
        else if (choice=='6')                   /* ������� ��� � ������� ������ ����� 6 */
        {
            printf("Lista krathmenwn thesewn: ");   /* �������� */
            for(k=0;k<=numSeats-1;k++)              /* ����     */
            {                                       /* �����    */
                if (seats[k]==1)                    /* ���      */
                {                                   /* ������   */
                    printf("%d ", k+1);             /* ���������� */
                }                                   /* ������   */
            }
            printf("\n\n");
        }
        else if (choice=='7')                       /* ������� ��� � ������� ������ ����� 7 */
        {
            for(k=0;k<7;k++)                        /* ������� 7 ����������� ��� �������� ���� ����� ��� ������� ��������� */
            {
                printf("%c",pinakida[k]);
            }
            printf("\n");
            for(k=0;k<=numSeats-1;k++)
            {
                if ((k%4==0) && (k<numSeats-3))     /* ������� �� */
                {
                    printf("\n");                   /* ���������� */
                }
                if ((k%4==2) && (k<numSeats-4))     /* if ���� �� */
                {
                    printf(" ");                    /* ������     */
                }
                if (seats[k]==1)                    /* ���������  */
                {
                    printf("*");                    /* �������    */
                }
                if (seats[k]==0)                    /* ��� ����   */
                {
                    printf("_");                    /* ���� ��� k */
                }
            }
            printf("\n\n");
        }
        else if (choice=='8')                       /* ������� ��� � ������� ������ ����� 8 */
        {
            FILE *fp;                               /* ������� ������� layout.txt ��� ������� */
            fp=fopen("layout.txt","w");
            for(k=0;k<7;k++)
            {
                fprintf(fp,"%c",pinakida[k]);       /* �������      */
            }
            fprintf(fp,"\n");                       /* ����������   */
            for(k=0;k<=numSeats-1;k++)              /* ��           */
            {
                if ((k%4==0) && (k<numSeats-3))     /* ���          */
                {
                    fprintf(fp,"\n");               /* �����������  */
                }
                if ((k%4==2) && (k<numSeats-4))     /* �������      */
                {
                    fprintf(fp," ");                /* ��  ��       */
                }
                if (seats[k]==1)                    /* �������      */
                {
                    fprintf(fp,"*");                /* ��� ��       */
                }
                if (seats[k]==0)                    /* ����������   */
                {
                    fprintf(fp,"_");                /* �������� ��� */
                }
            }                                       /* ������       */
            fclose(fp);                             /* layoyt.txt   */
            printf("To diagramma apothikeythke sto arxeio layout.txt\n");
        }
    }
    return 0;
}

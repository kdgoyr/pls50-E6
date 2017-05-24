#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct {                                            /* ������ struct seats2 ��� ��� ���������� ��� ��������� ��� �������� */
    char name[40];
    unsigned short thl[10];
    unsigned int seatNumber;
}seats2;

void savethl (unsigned short *r, long long unsigned int j); /* �������� ����������� */
void printthl (unsigned short m[]);
unsigned long long int getthl (unsigned short *r);

int main()
{
    char pinakida[7];                   /* ��������� ���� ������������ � ������� ��� ��������� ��� �� ������ bus.txt */
    int numSeats, choice, choice2;      /* numSeats: ��������� ���� ������������ � ������� ��� ������ ��� ���������� ��� �� ������ bus.txt, choice ��� choice2: ���������� ����������� �������� ������ ����� ��� ������� ����� ��� �������� */
    int k, p, sn;                       /* k: ��������� ��� ����� ������� �������, p: ��������� ��� �� ������ ��� ����� ������, sn: ��������� ��� ��� ���������� ��� ����� ������� */
    unsigned long long int t, t1;       /* ���������� ����������� ��� ��� ���������� ����������� ������� 10 ������ */
    seats2 s2[53];                      /* ������� ������ 53 ������ �� �������� ����� struct seats2 */

    for(k=0;k<53;k++)                           /* ������������ ������ ��������� 53 ������ */
    {
        s2[k].name[0] = '\0';                   /* ������������ �� ���� ����� */
        savethl (s2[k].thl, 0000000000);        /* ������������ �� �������� 0000000000 */
        s2[k].seatNumber = k+1;                 /* ������������ �� ������������ ��� ��������� ��� ������ �� ���� ���������� */
    }

    FILE *fp;
    if ((fp = fopen("bus.txt","r")) == NULL)                /* ������� ������� bus.txt ��� ������� ��������� ���������� */
    {
        printf("Error! opening file");                      /* ������ ��������� �� ��������� �� ��������� ��� ������� */
        exit(1);
    }
    fscanf(fp,"%s %d\n", pinakida, &numSeats);              /* �������� ��� �� ������ ������� ��������� ��� ��������� ������� ������ */

    char *c1, *c2, *c3;                                     /* ���������� ��� ��� ����������� ��� ��������, �������� ��� �������������� */
    c1 = malloc(20*sizeof(char*));                          /* �������� ������ ��� ��� �������� ���������� */
    c2 = malloc(20*sizeof(char*));                          /* ������� � �������� ��� ��� ���� 40 ���������� ��� �������������� */
    c3 = malloc(40*sizeof(char*));                          /* 20 ���������� ������������ �� ����� ��� 20 �� ������� */

    for(k=0;k<53;k++)                                       /* �������� ��������� ��� ������� bus.txt */
    {
        if (feof(fp))
        {
            fclose(fp);
            break;
        }
        else
        {
            fscanf(fp,"%s %s %u %I64u\n", c1, c2, &sn, &t); /* �������� ��������, ��������, ����� ��� ��������� */
            c3 = strcat(strcat(c1," "), c2);                /* ��������� �������� ��� �������� �� concatenation */
            strcpy(s2[sn-1].name, c3);                      /* ���������� ��������� ��� ������� ��� �������� ��� ������ seats2 */
            s2[sn-1].seatNumber = sn;
            savethl (s2[sn-1].thl, t);
        }
    }
    fclose(fp);

    printf("%s %d \n", pinakida, numSeats);             /* �������� ���� ����� ��� ������� ��������� ��� ��������� ������� ������ */
    for(k=0;k<53;k++)
        {
            if ((*s2[k].name)=='\0')
            {
                continue;
            }
            printf("%s ", s2[k].name);                  /* �������� ���� ����� ��� ��������� ��� �������� */
            printf("%d ", s2[k].seatNumber);
            printthl(s2[k].thl);
            printf("\n");
        }

    while(1) /* ������� ������� ���� � ������� �� ���������� �� ��������� ���� ���� ��� �� ����� */
    {
        printf("\n1. Emfanish synolikoy plhthoys kenwn thesewn kai taxinomhmenhs listas twn arithmwn toys: \n");        /* ����� ������ */
        printf("2. Krathsh theshs me sygkekrimeno arithmo gia stoixeia epibath pou tha parexei o xrhsths: \n");
        printf("3. Anazhthsh gia to an einai krathmenh thesi me sygkekrimeno onomatepwnymo h thlefwno epibath:\n");
        printf("4. Akyrwsh krathshs theshs me sygkekrimeno arithmo \n");
        printf("5. Emfanidh listas krathmenwn theswn me taxinomhsh kata arithmo theshs \n");
        printf("0. Termatismos programmatos \n\n");
        printf("Dwste thn epilogh sas: ");
        choice = getch();           /* �������� ��� �� ������������ ��� �������� ������ */
        printf("\n\n");
        if (choice=='0')            /* ������ ��� �� ��������� �� ��������� ��� � ������� �������� 0 */
        {
            FILE *fp;                               /* ������� ������� bus.txt ��� ������� ��� ��������� ��� ������ seats2 ��� ������ */
            fp=fopen("bus.txt","w");
            for(k=0;k<7;k++)
            {
                fprintf(fp,"%c",pinakida[k]);       /* ������� ��������� */
            }
            fprintf(fp," %d\n", numSeats);          /* ������� ������� ������ */

            for(k=0;k<numSeats;k++)
            {
                if ((*s2[k].name)=='\0')
                {
                    continue;
                }

                fprintf(fp,"%s ", s2[k].name);       /* ������� ��������� �������� */
                fprintf(fp,"%d ", s2[k].seatNumber);
                t = getthl(s2[k].thl);
                fprintf(fp,"%I64u", t);
                fprintf(fp,"\n");

            }
            fclose(fp);
            exit(0);                /* �������� ������ */
        }
        else if (choice=='1')           /* ������� ��� � ������� ������ ����� 1 */
        {
            p=numSeats;
            for(k=0;k<numSeats;k++)
            {
                if (*s2[k].name!='\0')
                {
                    p--;
                }
            }
            printf("Plhthos kewnwn thesewn: %d\n", p);          /* �������� ���� ����� ��� ������� ����� ������ */
            printf("Arithmoi kewnwn thesewn: ");                /* �������� ���� ����� ��� ������� ��� ����� ������ */
            for(k=0;k<=numSeats-1;k++)                          /* ������� ��������� ������� ����� ������ */
            {
                if (s2[k].name[0] == '\0')
                printf("%u ", s2[k].seatNumber);
            }
            printf("\n");

        }
        else if (choice=='2')       /* ������� ��� � ������� ������ ����� 2 */
        {
            printf("Dwste ton arithmo ths theshs pros krathsh: ");  /* �������� ��������� ��������� ������� ����� ���� ������� */
            scanf("%d", &choice2);                                  /* �������� ��� �� ������������ ��� ������� ����� ���� ������� */
            if ((choice2<1) || (choice2>numSeats))                  /* ������� ��� � ��������� ������� ������ ����� ����� ��� ����� */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                continue;
            }
            else if (s2[choice2-1].name[0] != '\0')                          /* ������� ��� � ���� ����� ��� ��������� */
            {
                printf("H thesh einai hdh krathmenh!\n");
            }
            else
            {
                printf("Dwste to Epwnymo kai to Onoma diaxwrismena me ena keno: "); /* ���������� ����������� ��������� ������� ��� �� ���� ���� ������� */
                scanf("%s %s", c1, c2);
                printf("Dwste to thlefwno: ");
                scanf("%I64u", &t);
                c3 = strcat(strcat(c1," "),c2);
                strcpy(s2[choice2-1].name, c3);
                s2[choice2-1].seatNumber = choice2;
                savethl(s2[choice2-1].thl, t);
                printf("H thesh kraththike!\n");
            }
        }
        else if (choice=='3')           /* ������� ��� � ������� ������ ����� 3 */
        {
            printf("1: Anazhthsh krathmenhs theshs me bash to onomatepwnymo\n2: Anazhthsh krathmenhs theshs me bash ton arithmo thlefwnou\nDwste thn epilogh sas: ");
            scanf("%d", &choice2);
            if (choice2==1)                    /* ������� ��� � ������� �������� ��������� �� ���� �� ������������� */
            {
                printf("Dwste to Epwnymo kai to Onoma diaxwrismena me ena keno: ");     /* �������� �������������� ��� �� ������ */
                scanf("%s %s", c1, c2);
                c3 = strcat(strcat(c1," "),c2);

                for(k=0;k<=numSeats-1;k++)                          /* ������� ���������� ���������� ����� �� ���� �� ������������� */
                {
                    if (strcmp(s2[k].name, c3) == 0)
                    {
                        printf("\nYparxei krathsh me ayto to onoma\n");
                        break;
                    }
                    if ((strcmp(s2[k].name, c3) != 0) && (k==numSeats-1))
                    {
                        printf("\nDen yparxei krathsh me ayto to onoma\n");
                    }
                }
            }
            if (choice2==2)                     /* ������� ��� � ������� �������� ��������� �� ���� �� �������� */
            {
                printf("Dwste to thlefwno: ");  /* �������� ��������� ��� �� ������ */
                scanf("%I64u", &t);
                for(k=0;k<=numSeats-1;k++)                          /* ������� ���������� ���������� ����� �� ���� �� �������� */
                {

                    t1 = getthl(s2[k].thl);
                    if (t1 == t)
                    {
                        printf("\nYparxei krathsh me ayto to thlefwno epibath\n");
                        break;
                    }
                    if ((t1 != t) && (k==numSeats-1))
                    {
                        printf("\nDen yparxei krathsh me ayto to thlefwno epibath\n");
                    }
                }
            }
        }
        else if (choice=='4')                                       /* ������� ��� � ������� ������ ����� 4 */
        {
            printf("Dwste ton arithmo ths theshs pros akyrwsh: ");  /* �������� ���� ����� ��������� ��� �������� ������� ����� ���� ������� */
            scanf("%d", &choice2);                                  /* �������� ��� �� ������������ ��� ������� ����� ��� ������� */

            if ((choice2<1) || (choice2>numSeats))                  /* ������� ��� � ��������� ������� ������ ����� ����� ��� ����� */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                continue;
            }
            else if (s2[choice2-1].name[0] == '\0')                          /* ������� ��� � ���� ����� ��� ��������� */
            {
                printf("H thesh den einai krathmenh!\n");
            }
            else
            {
                s2[choice2-1].name[0]='\0';                         /* ������� �������� ����� �������������� ��� */
                savethl (s2[choice2-1].thl, 0000000000);
                printf("H thesh akyrwthike\n");
            }
        }
        else if (choice=='5')                       /* ������� ��� � ������� ������ ����� 5 */
        {
            for(k=0;k<numSeats;k++)                 /* ������� ��������� ��������� �������� */
            {
                if (s2[k].name[0]!='\0')
                {
                    printf("%s", s2[k].name);
                    printf(" %d ", s2[k].seatNumber);
                    printthl(s2[k].thl);
                    printf("\n");
                }

            }
        }
    }
    return 0;
}

void savethl (unsigned short *r, long long unsigned int j)  /* ��������� � ����� ���������� ���� ����� ���� ������� unsigned long long int 10 ������ */
{                                                           /* �� ������ 10 ������ ���� �� ���� �������� ����� short int */
    r[0]=(j%10000000000/1000000000);
    r[1]=(j%1000000000/100000000);
    r[2]=(j%100000000/10000000);
    r[3]=(j%10000000/1000000);
    r[4]=(j%1000000/100000);
    r[5]=(j%100000/10000);
    r[6]=(j%10000/1000);
    r[7]=(j%1000/100);
    r[8]=(j%100/10);
    r[9]=(j%10);
}

void printthl (unsigned short m[])                          /* ��������� � ����� ������� ���� ����� �� ������ 10 ������ ���� ������ ������������ �� */
{                                                           /* ������ 10 ������ ���� �� ���� �������� ����� short int */
    int k;
    for(k=0;k<10;k++)
    {
        printf("%u", m[k]);
    }
}

unsigned long long int getthl (unsigned short *r)           /* ��������� � ����� ����� ���������� ��� savethl(). ������� ���� ������ 10 ������ ���� �� ���� �������� ����� short int */
{                                                           /* ��� �� ���������� �� ���� ������ unsigned long long int 10 ������ */
    unsigned long long int t2;
    t2 = (unsigned long long)r[0]*1000000000+r[1]*100000000+r[2]*10000000+r[3]*1000000+r[4]*100000+r[5]*10000+r[6]*1000+r[7]*100+r[8]*10+r[9];
    return t2;
}

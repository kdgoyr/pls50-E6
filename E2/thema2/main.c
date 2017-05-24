#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

struct seats2{                                            /* ������ struct seats2 ��� ��� ���������� ��� ��������� ��� �������� */
    char name[40];
    unsigned short thl[10];
    unsigned int seatNumber;
};

struct llnode{                                              /* ������ struct llnode ��� ��� ���������� ��� ��������� ��� ������������ ������ */
    struct seats2 *psgr;
    struct llnode *next;
};

void savethl (unsigned short *r, long long unsigned int j); /* �������� ����������� */
void printthl (unsigned short m[]);
unsigned long long int getthl (unsigned short *r);

int main()
{
    char pinakida[7];                   /* ��������� ���� ������������ � ������� ��� ��������� ��� �� ������ bus.txt */
    int numSeats, choice, choice2;      /* numSeats: ��������� ���� ������������ � ������� ��� ������ ��� ���������� ��� �� ������ bus.txt, choice ��� choice2: ���������� ����������� �������� ������ ����� ��� ������� ����� ��� �������� */
    int k, p, sn;                       /* k: ��������� ��� ����� ������� �������, p: ��������� ��� �� ������ ��� ����� ������, sn: ��������� ��� ��� ���������� ��� ����� ������� */
    unsigned long long int t, t1;       /* ���������� ����������� ��� ��� ���������� ����������� ������� 10 ������ */
    struct seats2 *s1, temp[1];                                      /* ������� ������ 53 ������ �� �������� ����� struct seats2 */

    char *c1, *c2, *c3;                                     /* ���������� ��� ��� ����������� ��� ��������, �������� ��� �������������� */
    c1 = malloc(20*sizeof(char*));                          /* �������� ������ ��� ��� �������� ���������� */
    c2 = malloc(20*sizeof(char*));                          /* ������� � �������� ��� ��� ���� 40 ���������� ��� ��������������... */
    c3 = malloc(40*sizeof(char*));                          /* ...20 ���������� ������������ �� ����� ��� 20 �� ������� */

    FILE *fp;
    if ((fp = fopen("bus.txt","r")) == NULL)                /* ������� ������� bus.txt ��� ������� ��������� ���������� */
    {
        printf("Error! opening file");                      /* ������ ��������� �� ��������� �� ��������� ��� ������� */
        exit(1);
    }

    fscanf(fp,"%s %d\n", pinakida, &numSeats);              /* �������� ��� �� ������ ������� ��������� ��� ��������� ������� ������ */
    /*struct seats2 s1[numSeats];*/
    s1 = malloc((numSeats)*sizeof(struct seats2));          /* �������� �������� ������ ������� �� ��� ������ ������ ��� ���������� */

    for(k=0;k<numSeats;k++)                                 /* ������������ ������ ��������� 53 ������ */
    {
        s1[k].name[0] = '\0';                               /* ������������ �� ���� ����� */
        savethl (s1[k].thl, 0000000000);                    /* ������������ �� �������� 0000000000 */
        s1[k].seatNumber = k+1;                             /* ������������ �� ������������ ��� ��������� ��� ������ �� ���� ���������� */
    }

    for(k = 0; k < numSeats; k++)                                 /* �������� ��������� ��� ������� bus.txt */
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
            strcpy(s1[sn-1].name, c3);                      /* ���������� ��������� ��� ������� ��� �������� ��� ������ s1 */
            s1[sn-1].seatNumber = sn;
            savethl (s1[sn-1].thl, t);
        }
    }

    printf("%s %d \n", pinakida, numSeats);             /* �������� ���� ����� ��� ������� ��������� ��� ��������� ������� ������ */
    for(p=0;p<numSeats;p++)
        {
            if ((*s1[p].name)=='\0')
            {
                continue;
            }
            printf("%s ", s1[p].name);                  /* �������� ���� ����� ��� ��������� ��� �������� */
            printf("%d ", s1[p].seatNumber);
            printthl(s1[p].thl);
            printf("\n");
        }

    while(1) /* ������� ������� ���� � ������� �� ���������� �� ��������� ���� ���� ��� �� ����� */
    {
        printf("\n1. Emfanish synolikoy plhthoys kenwn thesewn kai taxinomhmenhs listas twn arithmwn toys: \n");        /* ����� ������ */
        printf("2. Krathsh theshs me sygkekrimeno arithmo gia stoixeia epibath pou tha parexei o xrhsths: \n");
        printf("3. Anazhthsh gia to an einai krathmenh thesi me sygkekrimeno onomatepwnymo h thlefwno epibath:\n");
        printf("4. Akyrwsh krathshs theshs me sygkekrimeno arithmo \n");
        printf("5. Emfanidh listas krathmenwn theswn me taxinomhsh kata arithmo theshs h onomatepwnymo\n");
        printf("0. Termatismos programmatos \n\n");
        printf("Dwste thn epilogh sas: ");
        choice = getch();           /* �������� ��� �� ������������ ��� �������� ������ */
        printf("\n\n");
        if (choice=='0')            /* ������� �� ��������� ��� � ������� �������� 0 */
        {
            struct llnode *head;
            head = malloc(sizeof(struct llnode));
            head->psgr = malloc(sizeof (struct seats2));

            if (head == NULL)
            {
                exit(1);
            }

            head->psgr->name[0]='\0';
            head->psgr->seatNumber=0;
            savethl (head->psgr->thl, 0000000000);
            head->next = NULL;

            struct llnode *current;
            current = malloc(sizeof(struct llnode));
            current->psgr = malloc(sizeof (struct seats2));

            for(p=0;p<numSeats;p++)
                {
                    for(k=p+1;k<numSeats;k++)                 /* ������� ��������� ��������� �������� */
                    {
                        strcpy(temp[0].name, s1[p].name);
                        temp[0].seatNumber = s1[p].seatNumber;
                        t1 = getthl(s1[p].thl);
                        savethl (temp[0].thl, t1);

                        if (((*s1[k].name!='\0') && (strcmp(s1[k].name, temp[0].name)<0)))          /* ���������� ����������� */
                        {

                            strcpy(temp[0].name, s1[k].name);                                       /*                         */
                            temp[0].seatNumber = s1[k].seatNumber;
                            t1 = getthl(s1[k].thl);
                            savethl (temp[0].thl, t1);
/*                         */
                            strcpy(s1[k].name, s1[p].name);                                         /*                         */
                            s1[k].seatNumber = s1[p].seatNumber;
                            t1 = getthl(s1[p].thl);
                            savethl (s1[k].thl, t1);

                            strcpy(s1[p].name, temp[0].name);                                       /*                         */
                            s1[p].seatNumber = temp[0].seatNumber;
                            t1 = getthl(temp[0].thl);
                            savethl (s1[p].thl, t1);
                        }
                    }
                }

            for(k=0;k<numSeats;k++)                 /* ������� ��������� ��������� �������� */
                {
                    if (*s1[k].name!='\0')
                    {
                        current = head;
                        while (current->next != NULL)
                        {
                            current = current->next;
                        }

                        strcpy(current->psgr->name, s1[k].name);
                        current->psgr->seatNumber=s1[k].seatNumber;
                        t1 = getthl(s1[k].thl);
                        savethl (current->psgr->thl, t1);
                        current->next = NULL;

                        printf("%s", current->psgr->name);
                        printf(" %d ", current->psgr->seatNumber);
                        printthl(current->psgr->thl);
                        printf("\n");
                    }
                }

        }
        else if (choice=='1')           /* ������� ��� � ������� ������ ����� 1 */
        {
            p=numSeats;
            for(k=0;k<numSeats;k++)
            {
                if (*s1[k].name!='\0')
                {
                    p--;
                }
            }
            printf("Plhthos kewnwn thesewn: %d\n", p);          /* �������� ���� ����� ��� ������� ����� ������ */
            printf("Arithmoi kewnwn thesewn: ");                /* �������� ���� ����� ��� ������� ��� ����� ������ */
            for(k=0;k<=numSeats-1;k++)                          /* ������� ��������� ������� ����� ������ */
            {
                if (s1[k].name[0] == '\0')
                printf("%u ", s1[k].seatNumber);
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
            else if (s1[choice2-1].name[0] != '\0')                          /* ������� ��� � ���� ����� ��� ��������� */
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
                strcpy(s1[choice2-1].name, c3);
                s1[choice2-1].seatNumber = choice2;
                savethl(s1[choice2-1].thl, t);
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
                    if (strcmp(s1[k].name, c3) == 0)
                    {
                        printf("\nYparxei krathsh me ayto to onoma\n");
                        break;
                    }
                    if ((strcmp(s1[k].name, c3) != 0) && (k==numSeats-1))
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

                    t1 = getthl(s1[k].thl);
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
            else if (s1[choice2-1].name[0] == '\0')                          /* ������� ��� � ���� ����� ��� ��������� */
            {
                printf("H thesh den einai krathmenh!\n");
            }
            else
            {
                s1[choice2-1].name[0]='\0';                         /* ������� �������� ����� �������������� ��� */
                savethl (s1[choice2-1].thl, 0000000000);
                printf("H thesh akyrwthike\n");
            }
        }
        else if (choice=='5')                       /* ������� ��� � ������� ������ ����� 5 */
        {
            printf("1: Taxinomhsh listas epibatwn me bash ton arithmo thesis \n2: Taxinomhsh listas epibatwn me bash to onomatepwnymo\nDwste thn epilogh sas: ");
            scanf("%d", &choice2);
            if (choice2==1)                    /* ������� ��� � ������� �������� ��������� �� ���� �� ������������� */
            {
                for(k=0;k<numSeats;k++)                 /* ������� ��������� ��������� �������� */
                {
                    if (*s1[k].name!='\0')
                    {
                        printf("%s", s1[k].name);
                        printf(" %d ", s1[k].seatNumber);
                        printthl(s1[k].thl);
                        printf("\n");
                    }
                }
            }
            if (choice2==2)                     /* ������� ��� � ������� �������� ��������� �� ���� �� �������� */
            {
                for(p=0;p<numSeats;p++)
                {
                    for(k=p+1;k<numSeats;k++)
                    {
                        strcpy(temp[0].name, s1[p].name);                                       /* ���������� ����������� */
                        temp[0].seatNumber = s1[p].seatNumber;
                        t1 = getthl(s1[p].thl);
                        savethl (temp[0].thl, t1);

                        if (((*s1[k].name!='\0') && (strcmp(s1[k].name, temp[0].name)<0)))      /*      �� ����           */
                        {
                            strcpy(temp[0].name, s1[k].name);
                            temp[0].seatNumber = s1[k].seatNumber;
                            t1 = getthl(s1[k].thl);
                            savethl (temp[0].thl, t1);

                            strcpy(s1[k].name, s1[p].name);                                     /*       ��              */
                            s1[k].seatNumber = s1[p].seatNumber;
                            t1 = getthl(s1[p].thl);
                            savethl (s1[k].thl, t1);

                            strcpy(s1[p].name, temp[0].name);                                   /*      �������������      */
                            s1[p].seatNumber = temp[0].seatNumber;
                            t1 = getthl(temp[0].thl);
                            savethl (s1[p].thl, t1);
                        }
                    }
                }
                for(k=0;k<numSeats;k++)                 /* ������� ��������� ��������� �������� */
                {
                    if (*s1[k].name!='\0')
                    {
                        printf("%s", s1[k].name);
                        printf(" %d ", s1[k].seatNumber);
                        printthl(s1[k].thl);
                        printf("\n");
                    }
                }
                for(p=0;p<numSeats;p++)
                {
                    for(k=p+1;k<numSeats;k++)                                                   /* ���������� ����������� */
                    {
                        strcpy(temp[0].name, s1[p].name);
                        temp[0].seatNumber = s1[p].seatNumber;
                        t1 = getthl(s1[p].thl);
                        savethl (temp[0].thl, t1);                                              /* ���                   */

                        if (((*s1[k].name!='\0') && (s1[k].seatNumber<temp[0].seatNumber)))
                        {
                            strcpy(temp[0].name, s1[k].name);
                            temp[0].seatNumber = s1[k].seatNumber;                              /* ���������             */
                            t1 = getthl(s1[k].thl);
                            savethl (temp[0].thl, t1);

                            strcpy(s1[k].name, s1[p].name);                                     /* �� ����                */
                            s1[k].seatNumber = s1[p].seatNumber;
                            t1 = getthl(s1[p].thl);
                            savethl (s1[k].thl, t1);

                            strcpy(s1[p].name, temp[0].name);                                   /* ��� ������ �����        */
                            s1[p].seatNumber = temp[0].seatNumber;
                            t1 = getthl(temp[0].thl);
                            savethl (s1[p].thl, t1);
                        }
                    }
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

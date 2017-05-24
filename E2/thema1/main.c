#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct {                                            /* Δήλωση struct seats2 για την καταχώριση των στοιχείων των επιβατών */
    char name[40];
    unsigned short thl[10];
    unsigned int seatNumber;
}seats2;

void savethl (unsigned short *r, long long unsigned int j); /* Δηλώσεις συναρτήσεων */
void printthl (unsigned short m[]);
unsigned long long int getthl (unsigned short *r);

int main()
{
    char pinakida[7];                   /* Μεταβλητή όπου καταχωρείται ο αριθμός της πινακίδας από το αρχείο bus.txt */
    int numSeats, choice, choice2;      /* numSeats: μεταβλητή όπου καταχωρείται ο αριθμός των θέσεων του λεωφορείου από το αρχείο bus.txt, choice και choice2: μεταβλητές καταχώρισης επιλογών χρήστη μενού και αριθμός θέσης στο υπομενού */
    int k, p, sn;                       /* k: μεταβλητή για χρήση μετρητή βρόγχων, p: μεταβλητή για το πλήθος των κενών θέσεων, sn: μεταβλητή για την αποθήκευση της θέσης επιβάτη */
    unsigned long long int t, t1;       /* Μεταβλητές απαραίτητες για την καταχώριση τηλεφωνικών αριθμών 10 ψηφιών */
    seats2 s2[53];                      /* Ορισμός πίνακα 53 θέσεων με στοιχεία τύπου struct seats2 */

    for(k=0;k<53;k++)                           /* Αρχικοποίηση πίνακα κρατήσεων 53 θέσεων */
    {
        s2[k].name[0] = '\0';                   /* Αρχικοποίηση με κενό όνομα */
        savethl (s2[k].thl, 0000000000);        /* Αρχικοποίηση με τηλέφωνο 0000000000 */
        s2[k].seatNumber = k+1;                 /* Αρχικοποίηση με αντιστοίχιση του στοιχείου του πίνακα σε θέση λεωφορείου */
    }

    FILE *fp;
    if ((fp = fopen("bus.txt","r")) == NULL)                /* Άνοιγμα αρχείου bus.txt και έλεγχος σφάλματος ανοίγματος */
    {
        printf("Error! opening file");                      /* Μήνυμα σφάλματος σε περίπτωση μη ανάγνωσης του αρχείου */
        exit(1);
    }
    fscanf(fp,"%s %d\n", pinakida, &numSeats);              /* Ανάγνωση από το αρχείο αριθμού πινακίδας και συνολικού αριθμού θέσεων */

    char *c1, *c2, *c3;                                     /* Μεταβλητές για την καταχώρισης των ονομάτων, επιθέτων και ονοματεπωνύμων */
    c1 = malloc(20*sizeof(char*));                          /* Δέσμευση μνήμης για τις παραπάνω μεταβλητές */
    c2 = malloc(20*sizeof(char*));                          /* Γίνεται η παραδοχή ότι από τους 40 χαρακτήρες του ονοματεπωνύμου */
    c3 = malloc(40*sizeof(char*));                          /* 20 χαρακτήρες καταλαμβάνει το όνομα και 20 το επώνυμο */

    for(k=0;k<53;k++)                                       /* Ανάγνωση δεδομένων του αρχείου bus.txt */
    {
        if (feof(fp))
        {
            fclose(fp);
            break;
        }
        else
        {
            fscanf(fp,"%s %s %u %I64u\n", c1, c2, &sn, &t); /* Ανάγνωση επιθέτου, ονόματος, θέσης και τηλεφώνου */
            c3 = strcat(strcat(c1," "), c2);                /* Ενοποίηση επιθέτου και ονόματος με concatenation */
            strcpy(s2[sn-1].name, c3);                      /* Αποθήκευση δεδομένων του αρχείου στα στοιχεία του πίνακα seats2 */
            s2[sn-1].seatNumber = sn;
            savethl (s2[sn-1].thl, t);
        }
    }
    fclose(fp);

    printf("%s %d \n", pinakida, numSeats);             /* Εκτύπωση στην οθόνη του αριθμού πινακίδας και συνολικού αριθμού θέσεων */
    for(k=0;k<53;k++)
        {
            if ((*s2[k].name)=='\0')
            {
                continue;
            }
            printf("%s ", s2[k].name);                  /* Εκτύπωση στην οθόνη των στοιχείων των επιβατών */
            printf("%d ", s2[k].seatNumber);
            printthl(s2[k].thl);
            printf("\n");
        }

    while(1) /* Ατέρμων βρόγχος ώστε ο χρήστης να τερματίζει το πρόγραμμα μόνο μέσα από το μενού */
    {
        printf("\n1. Emfanish synolikoy plhthoys kenwn thesewn kai taxinomhmenhs listas twn arithmwn toys: \n");        /* Μενού χρήστη */
        printf("2. Krathsh theshs me sygkekrimeno arithmo gia stoixeia epibath pou tha parexei o xrhsths: \n");
        printf("3. Anazhthsh gia to an einai krathmenh thesi me sygkekrimeno onomatepwnymo h thlefwno epibath:\n");
        printf("4. Akyrwsh krathshs theshs me sygkekrimeno arithmo \n");
        printf("5. Emfanidh listas krathmenwn theswn me taxinomhsh kata arithmo theshs \n");
        printf("0. Termatismos programmatos \n\n");
        printf("Dwste thn epilogh sas: ");
        choice = getch();           /* Ανάγνωση από το πληκτρολόγιο της επιλογής χρήστη */
        printf("\n\n");
        if (choice=='0')            /* Έξοδος από το πρόγραμμα σε περίπτωση που ο χρήστης επιλέξει 0 */
        {
            FILE *fp;                               /* Άνοιγμα αρχείου bus.txt για εγγραφή των δεδομένων του πίνακα seats2 και έξοδος */
            fp=fopen("bus.txt","w");
            for(k=0;k<7;k++)
            {
                fprintf(fp,"%c",pinakida[k]);       /* Εγγραφή πινακίδας */
            }
            fprintf(fp," %d\n", numSeats);          /* Εγγραφή αριθμού θέσεων */

            for(k=0;k<numSeats;k++)
            {
                if ((*s2[k].name)=='\0')
                {
                    continue;
                }

                fprintf(fp,"%s ", s2[k].name);       /* Εγγραφή στοιχείων επιβατών */
                fprintf(fp,"%d ", s2[k].seatNumber);
                t = getthl(s2[k].thl);
                fprintf(fp,"%I64u", t);
                fprintf(fp,"\n");

            }
            fclose(fp);
            exit(0);                /* Επιτυχής έξοδος */
        }
        else if (choice=='1')           /* Έλεγχος εάν η επιλογή χρήστη είναι 1 */
        {
            p=numSeats;
            for(k=0;k<numSeats;k++)
            {
                if (*s2[k].name!='\0')
                {
                    p--;
                }
            }
            printf("Plhthos kewnwn thesewn: %d\n", p);          /* Εκτύπωση στην οθόνη του πλήθους κενών θέσεων */
            printf("Arithmoi kewnwn thesewn: ");                /* Εκτύπωση στην οθόνη των αριθμών των κενών θέσεων */
            for(k=0;k<=numSeats-1;k++)                          /* Βρόγχος εκτύπωσης αριθμού κενών θέσεων */
            {
                if (s2[k].name[0] == '\0')
                printf("%u ", s2[k].seatNumber);
            }
            printf("\n");

        }
        else if (choice=='2')       /* Έλεγχος εάν η επιλογή χρήστη είναι 2 */
        {
            printf("Dwste ton arithmo ths theshs pros krathsh: ");  /* Εκτύπωση μηνύματος εισαγωγής αριθμού θέσης προς κράτηση */
            scanf("%d", &choice2);                                  /* Ανάγνωση από το πληκτρολόγιο του αριθμού θέσης προς κράτηση */
            if ((choice2<1) || (choice2>numSeats))                  /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι εντός των ορίων */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                continue;
            }
            else if (s2[choice2-1].name[0] != '\0')                          /* Έλεγχος εάν η θέση είναι ήδη κρατημένη */
            {
                printf("H thesh einai hdh krathmenh!\n");
            }
            else
            {
                printf("Dwste to Epwnymo kai to Onoma diaxwrismena me ena keno: "); /* Διαδικασία καταχώρισης στοιχείων επιβάτη για τη θέση προς κράτηση */
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
        else if (choice=='3')           /* Έλεγχος εάν η επιλογή χρήστη είναι 3 */
        {
            printf("1: Anazhthsh krathmenhs theshs me bash to onomatepwnymo\n2: Anazhthsh krathmenhs theshs me bash ton arithmo thlefwnou\nDwste thn epilogh sas: ");
            scanf("%d", &choice2);
            if (choice2==1)                    /* Έλεγχος εάν ο χρήστης επιθυμεί αναζήτηση με βάση το ονοματεπώνυμο */
            {
                printf("Dwste to Epwnymo kai to Onoma diaxwrismena me ena keno: ");     /* Εισαγωγή ονοματεπώνυμου από το χρήστη */
                scanf("%s %s", c1, c2);
                c3 = strcat(strcat(c1," "),c2);

                for(k=0;k<=numSeats-1;k++)                          /* Βρόγχος αναζήτησης κρατημένης θέσης με βάση το ονοματεπώνυμο */
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
            if (choice2==2)                     /* Έλεγχος εάν ο χρήστης επιθυμεί αναζήτηση με βάση το τηλέφωνο */
            {
                printf("Dwste to thlefwno: ");  /* Εισαγωγή τηλεφώνου από το χρήστη */
                scanf("%I64u", &t);
                for(k=0;k<=numSeats-1;k++)                          /* Βρόγχος αναζήτησης κρατημένης θέσης με βάση το τηλέφωνο */
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
        else if (choice=='4')                                       /* Έλεγχος εάν η επιλογή χρήστη είναι 4 */
        {
            printf("Dwste ton arithmo ths theshs pros akyrwsh: ");  /* Εκτύπωση στην οθόνη μηνύματος για εισαγωγή αριθμού θέσης προς ακύρωση */
            scanf("%d", &choice2);                                  /* Ανάγνωση από το πληκτρολόγιο του αριθμού θέσης για ακύρωση */

            if ((choice2<1) || (choice2>numSeats))                  /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι εντός των ορίων */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                continue;
            }
            else if (s2[choice2-1].name[0] == '\0')                          /* Έλεγχος εάν η θέση είναι ήδη κρατημένη */
            {
                printf("H thesh den einai krathmenh!\n");
            }
            else
            {
                s2[choice2-1].name[0]='\0';                         /* Ακύρωση κράτησης θέσης αρχικοποιώντας την */
                savethl (s2[choice2-1].thl, 0000000000);
                printf("H thesh akyrwthike\n");
            }
        }
        else if (choice=='5')                       /* Έλεγχος εάν η επιλογή χρήστη είναι 5 */
        {
            for(k=0;k<numSeats;k++)                 /* Βρόγχος εκτύπωσης στοιχείων επιβατών */
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

void savethl (unsigned short *r, long long unsigned int j)  /* Συνάρτηση η οποία αποθηκεύει κάθε ψηφίο ενός αριθμού unsigned long long int 10 ψηφίων */
{                                                           /* σε πίνακα 10 θέσεων όπου το κάθε στοιχείο είναι short int */
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

void printthl (unsigned short m[])                          /* Συνάρτηση η οποία τυπώνει στην οθόνη ως αριθμό 10 ψηφίων έναν αριθμό αποθηκευμένο σε */
{                                                           /* πίνακα 10 θέσεων όπου το κάθε στοιχείο είναι short int */
    int k;
    for(k=0;k<10;k++)
    {
        printf("%u", m[k]);
    }
}

unsigned long long int getthl (unsigned short *r)           /* Συνάρτηση η οποία είναι αντίστροφη της savethl(). Παίρνει έναν πίνακα 10 θέσεων όπου το κάθε στοιχείο είναι short int */
{                                                           /* και το επιστρέφει ως έναν αριθμό unsigned long long int 10 ψηφίων */
    unsigned long long int t2;
    t2 = (unsigned long long)r[0]*1000000000+r[1]*100000000+r[2]*10000000+r[3]*1000000+r[4]*100000+r[5]*10000+r[6]*1000+r[7]*100+r[8]*10+r[9];
    return t2;
}

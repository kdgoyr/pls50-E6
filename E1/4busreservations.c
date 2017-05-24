#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char pinakida[7];                   /* Μεταβλητή όπου καταχωρείται ο αριθμός της πινακίδας από το αρχείο bus.txt */
    int numSeats, choice, choice2;      /* numSeats: μεταβλητή όπου καταχωρείται ο αριθμός των θέσεων του λεωφορείου από το αρχείο bus.txt, choice και choice2: μεταβλητές καταχώρισης επιλογών χρήστη μενού και αριθμός θέσης στο υπομενού */
    int k, l, seats[53], nSeats[53];    /* k: μεταβλητή για χρήση μετρητή βρόγχων, l: μεταβλητή για το πλήθος των κενών θέσεων, seats[53]: πίνακας κράτησης θέσεων, nSeats[53]: Πίνακας καταχώρισης αριθμού κρατημένης θέσης */
    for(k=0;k<=52;k++)                  /* Αρχικοποίηση πίνακα κρατήσεων 53 θέσεων με 0 */
    {
        seats[k]=0;
    }
    FILE *fp;
    if ((fp = fopen("bus.txt","r")) == NULL)            /* ’νοιγμα αρχείου bus.txt και έλεγχος σφάλματος ανοίγματος */
        {
        printf("Sfalma sto anoigma toy arxeioy bus.txt! Prepei na einai ston idio fakelo.");
        exit(1);
        }
    fscanf(fp,"%s %d", pinakida, &numSeats);            /* Ανάγνωση από το αρχείο αριθμού πινακίδας και συνολικού αριθμού θέσεων */
    printf("%s %d \n", pinakida, numSeats);             /* Εκτύπωση στην οθόνη του αριθμού πινακίδας και συνολικού αριθμού θέσεων */
    if (numSeats>53)                                    /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι μεγαλύτερος από 53 */
    {
        printf("Sfalma! O arithmos twn thesewn einai megalyteros apo 53!");
        exit(1);
    }
    if ((numSeats-5)%4!=0)  /* Έλεγχος εάν ο  αριθμός θέσεων πληρεί τον κανόνα 4Ν+5 */
    {
        printf("Sfalma! O arithmos twn thesewn den symbadizei me thn katanomh!");
        exit(1);
    }
    while(1) /* Ατέρμων βρόγχος ώστε ο χρήστης να τερματίζει το πρόγραμμα μόνο μέσα από το μενού */
    {
        printf("\n1. Emfnish synolikoy plhthoys kenwn thesewn kai o arithmos toys: \n");        /* Μενού χρήστη */
        printf("2. Krathsh theshs me sygkekrimeno arithmo: \n");
        printf("3. Eyresh kai krathsh ths prwths kenhs theshs se parathyro \n");
        printf("4. Akyrwsh krathshs theshs me sygkekrimeno arithmo \n");
        printf("5. Anazhthsh krathmenhs theshs me sygkekrimeno arithmo \n");
        printf("6. Emfanish listas krathmenwn thesewn taxinomhmenhs kata arithmo theshs \n");
        printf("7. Emfanish pinakidas kykloforias kai diagrammatos lewforeioy \n");
        printf("8. Apothikeysh pinakidas kykloforias kai diagrammatos lewforeioy \n");
        printf("0. Termatismos programmatos \n");
        printf("Dwste thn epilogh sas: ");
        choice = getch();           /* Ανάγνωση από το πληκτρολόγιο της επιλογής χρήστη */
        printf("\n\n");
        if (choice=='0')            /* Έξοδος από το πρόγραμμα σε περίπτωση που ο χρήστης επιλέξει 0 */
        {
            exit(0);                /* Επιτυχής έξοδος */
        }
        else if (choice=='1')           /* Έλεγχος εάν η επιλογή χρήστη είναι 1 */
        {
            l=0;                        /* Ο αριθμός των κενών θέσεων αρχικοποιείται με 0 και θα καταμετρηθεί με τον επόμενο βρόγχο */
            for(k=0;k<=numSeats-1;k++)  /* Βρόγχος επανάληψης όσες και οι θέσεις του λεωφορείου για μέτρηση πλήθους κενών θέσεων και καταχώριση του κάθε αριθμού κενής θέσης */
            {
                if (seats[k]==0)        /* Έλεγχος εάν η θέση είναι κενή */
                {
                    l++;                /* Μετά το τέλος των επαναλήψεων θα περιέχει το πλήθος των κενών θέσεων */
                    nSeats[l-1]=k+1;    /* Καταχώριση αριθμού κενής θέσης στον πίνακα αριθμών κενών θέσεων */
                }
            }
            printf("Plhthos kewnwn thesewn: %d\n", l);  /* Εκτύπωση στην οθόνη του πλήθους κενών θέσεων */
            printf("Arithmoi kewnwn thesewn: ");        /* Εκτύπωση στην οθόνη των αριθμών κενών θέσεων */
            for(k=0;k<=l-1;k++)                         /* Βρόγχος εκτύπωσης αριθμού κενών θέσεων */
            {
                printf("%d ", nSeats[k]);
            }
            printf("\n");
        }
        else if (choice=='2')       /* Έλεγχος εάν η επιλογή χρήστη είναι 2 */
        {
            printf("Dwste ton arithmo ths theshs pros krathsh: ");  /* Εκτύπωση μηνύματος εισαγωγής αριθμού θέσης προς κράτηση */
            scanf("%d", &choice2);                                  /* Ανάγνωση από το πληκτρολόγιο του αριθμού θέσης προς κράτηση */
            if ((choice2<1) || (choice2>numSeats))                  /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι εντός των ορίων */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!");
                exit(1);
            }
            else if (seats[choice2-1]==1)                           /* Έλεγχος εάν η θέση είναι ήδη κρατημένη */
            {
                printf("H thesh einai hdh krathmenh!\n");
            }
            else
            {
                seats[choice2-1]=1;                                 /* κράτηση θέσης */
                printf("H thesh kraththike!\n");
            }
        }
        else if (choice=='3')           /* Έλεγχος εάν η επιλογή χρήστη είναι 3 */
        {
            for (k=1;k<=numSeats;k++)
            {
                if ((((k-1)%4==0) || (k%4==0)) && (k<=(numSeats-4)) && (seats[k-1]==0))  /* Έλεγχος εάν η θέση είναι σε παράθυρο και όχι κρατημένη εκτός της τελευταίας διότι απέχει 1 θέση παραπάνω από την προηγούμενη σε παράθυρο */
                {
                    seats[k-1]=1;                                   /* Κράτηση θέσης σε παράθυρο */
                    printf("Kraththike h thesi: %d\n", k);
                    break;
                }
                else if ((k==numSeats && (seats[k-1]==0)))          /*  Έλεγχος εάν η τελευταία θέση δεν είναι κρατημένη */
                {
                    seats[k-1]=1;                                   /* Κράτηση τελευταίας θέσης σε περίπτωση που δεν είναι κρατημένη */
                    printf("Kraththike h thesi: %d\n", k);
                }
                else if ((k==numSeats && (seats[k-1]==1)))          /*  Έλεγχος εάν η τελευταία θέση είναι κρατημένη που σημαίνει ότι όλες οι θέσεις σε παράθυρο είναι κρατημένες */
                {
                    printf("Oles oi theseis sto parathyro einai krathmenes!\n"); /* Εκτύπωση μηνύματος πληρότητας θέσεων σε παράθυρο */
                }
            }
        }
        else if (choice=='4')                       /* Έλεγχος εάν η επιλογή χρήστη είναι 4 */
        {
            printf("Dwste ton arithmo ths theshs pros akyrwsh: ");  /* Εκτύπωση στην οθόνη μηνύματος για εισαγωγή αριθμού θέσης προς ακύρωση */
            scanf("%d", &choice2);                                  /* Ανάγνωση από το πληκτρολόγιο του αριθμού θέσης για ακύρωση */
            if ((choice2<1) || (choice2>numSeats))                  /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι εντός των ορίων */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                exit(1);
            }
            else if (seats[choice2-1]==0)                           /* Έλεγχος εάν η θέση δεν είναι ήδη κρατημένη */
            {
                printf("H thesh den einai krathmenh!\n");           /* Εκτύπωση στην οθόνη σχετικού μηνύματος */
            }
            else                                                    /* Ακύρωση κράτησης θέσης */
            {
                seats[choice2-1]=0;
                printf("H thesh akyrwthike\n");
            }
        }
        else if (choice=='5')                       /* Έλεγχος εάν η επιλογή χρήστη είναι 5 */
        {
            printf("Dwste ton arithmo ths theshs pros anazhthsh: ");
            scanf("%d", &choice2);
            if ((choice2<1) || (choice2>numSeats))          /* Έλεγχος εάν ο συνολικός αριθμός θέσεων είναι εντός των ορίων */
            {
                printf("O arithmos ths theshs den einai entos twn oriwn!\n");
                exit(1);
            }
            else if (seats[choice2-1]==0)                   /* Έλεγχος εάν η θέση δεν είναι ήδη κρατημένη */
            {
                printf("H thesh den einai krathmenh!\n");   /* Εκτύπωση */
            }                                               /* στην     */
            else                                            /* οθόνη    */
            {                                               /* σχετικών */
                printf("H thesh einai krathmenh!\n");       /* μηνυμάτων */
            }
        }
        else if (choice=='6')                   /* Έλεγχος εάν η επιλογή χρήστη είναι 6 */
        {
            printf("Lista krathmenwn thesewn: ");   /* Εκτύπωση */
            for(k=0;k<=numSeats-1;k++)              /* στην     */
            {                                       /* οθόνη    */
                if (seats[k]==1)                    /* της      */
                {                                   /* λίστας   */
                    printf("%d ", k+1);             /* κρατημένων */
                }                                   /* θέσεων   */
            }
            printf("\n\n");
        }
        else if (choice=='7')                       /* Έλεγχος εάν η επιλογή χρήστη είναι 7 */
        {
            for(k=0;k<7;k++)                        /* Βρόγχος 7 επαναλήψεων για εκτύπωση στην οθόνη του αριθμού πινακίδας */
            {
                printf("%c",pinakida[k]);
            }
            printf("\n");
            for(k=0;k<=numSeats-1;k++)
            {
                if ((k%4==0) && (k<numSeats-3))     /* Έλεγχος με */
                {
                    printf("\n");                   /* συνεχόμενα */
                }
                if ((k%4==2) && (k<numSeats-4))     /* if ώστε να */
                {
                    printf(" ");                    /* γίνουν     */
                }
                if (seats[k]==1)                    /* πολλαπλοί  */
                {
                    printf("*");                    /* έλεγχοι    */
                }
                if (seats[k]==0)                    /* για κάθε   */
                {
                    printf("_");                    /* τιμή του k */
                }
            }
            printf("\n\n");
        }
        else if (choice=='8')                       /* Έλεγχος εάν η επιλογή χρήστη είναι 8 */
        {
            FILE *fp;                               /* ’νοιγμα αρχείου layout.txt για εγγραφή */
            fp=fopen("layout.txt","w");
            for(k=0;k<7;k++)
            {
                fprintf(fp,"%c",pinakida[k]);       /* Ανάλογη      */
            }
            fprintf(fp,"\n");                       /* διαδικασία   */
            for(k=0;k<=numSeats-1;k++)              /* με           */
            {
                if ((k%4==0) && (k<numSeats-3))     /* την          */
                {
                    fprintf(fp,"\n");               /* προηγούμενη  */
                }
                if ((k%4==2) && (k<numSeats-4))     /* επιλογή      */
                {
                    fprintf(fp," ");                /* με  τη       */
                }
                if (seats[k]==1)                    /* διαφορά      */
                {
                    fprintf(fp,"*");                /* ότι το       */
                }
                if (seats[k]==0)                    /* αποτέλεσμα   */
                {
                    fprintf(fp,"_");                /* εξάγεται στο */
                }
            }                                       /* αρχείο       */
            fclose(fp);                             /* layoyt.txt   */
            printf("To diagramma apothikeythke sto arxeio layout.txt\n");
        }
    }
    return 0;
}

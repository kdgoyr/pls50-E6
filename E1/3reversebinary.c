#include <stdio.h>
#include <stdlib.h>

void pr(void);                                              /* Δήλωση συναρτήσεων */
void calcbin(int num);

int main()
{
    int num;                                                /* Μεταβλητή θετικού ακέραιου αριθμού */
    while(1)                                                /* Χρήση ατ΄ρμωνου βρόγχου ώστε σε περίπτωση σφάλματος το πρόγραμμα να ζητάει εκ νέου αριθμό */
    {
        printf("Dwste enan thetiko akeraio arithmo: ");     /* Μήνυμα εισόδου από το πληκτρολόγιο */
        scanf(" %d", &num);                                 /* Είσοδος αριθμού από το πληκτρολόγιο */
        (num<0)?pr():calcbin(num);                          /* Χρήση τριαδικού τελεστή για τη μετατροπή του αριθμού ή την εκτύπωση σφάλματος στην οθόνη */
    }
}

void pr(void)                                               /* Συνάρτηση εκτύπωσης μηνύματος σφάλματος έαν δωθεί αρνητικός αριθμός */
{
    printf("Dwsate arnhtiko arithmo!\n");
}

void calcbin(int num)                                       /* Συνάρτηση υπολογισμού αντίστροφης δυαδικής αναπαράστασης θετικού */
{
    const int dyo=2;                                        /* Ορισμός του 2 ως σταθερά */
    printf("O arithmos poy dwsate, se antistrofh dyadikh anaparastash einai: ");
    while (num>-1)
    {
        num%dyo==1?putchar('1'):putchar('0');               /* Χρήση τριαδικού τελεστή και putchar για την εκτύπωση ενός bit */
        num=num/dyo;                                        /* Υπολογισμός διαίρεσης τρέχοντα αριθμού με το 2 */
        if (num==0)
        {
            exit(0);                                        /* Επιτυχής έξοδος */
        }
    }
}

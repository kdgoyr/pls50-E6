#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ytetr(float v1);              /* Δηλώσεις     */
float yparal(float v1, float v2);   /*              */
float yotrig(float v1, float v2);   /*              */
float ykykl(float v1);              /* συναρτήσεων  */

int main()
{
    char choice;                    /* Μεταβλητή καταχώρισης επιλογής */
    float t1,t2;                    /* Προσωρινές μεταβλητές για είσοδο μηκών σχημάτων από το πληκτρολόγιο */
    while(1)                        /* Ατέρμων βρόγχος */
    {
        printf("Menu epilogwn ypologismoy perimetroy\n");   /* Μενού          */
        printf("0. Exodos\n");                              /*                */
        printf("1. Tetragwno\n");                           /*                */
        printf("2. Parallhlogrammo\n");                     /*                */
        printf("3. Orthogwnio trigwno\n");                  /*                */
        printf("4. Kyklos\n");                              /*                */
        printf("Eisagete thn epilogh sas: ");               /* επιλογών       */
        scanf(" %c", &choice);                              /* Είσοδος της επιλογής χρήστη από το πληκτρολόγιο */
        printf("\n");
        if (choice=='0')                                    /* Έξοδος σε περίπτωση εισαγωγής 0 από τον χρήστη */
        {
            exit(0);
        }
        else if (choice=='1')                                           /* Είσοδος μήκους πλευράς και υπολογισμός περιμέτρου τετραγώνου σε περίπτωση */
            {                                                           /* που ο χρήστης επιλέξει 1 */
            printf("Dwste to mhkos ths pleyras toy tetragwnoy: ");
            scanf("%f" , &t1);
            printf("H perimetros toy tetragwnoy einai: %f",ytetr(t1));
            exit(0);
            }
        else if (choice=='2')                                               /* Είσοδος μήκους και πλάτους και υπολογισμός περιμέτρου παραλληλογράμμου σε περίπτωση */
            {                                                               /* που ο χρήστης επιλέξει 2 */
            printf("Dwste to mhkos kai to platos toy parallhlogrammoy: ");
            scanf("%f %f" , &t1, &t2);
            printf("H perimetros toy parallhlogrammoy einai: %f",yparal(t1,t2));
            exit(0);
            }
        else if (choice=='3')                                                           /* Είσοδος μήκους καθέτων πλευρών και υπολογισμός περιμέτρου ορθογωνίου τριγώνου σε περίπτωση */
            {                                                                           /* που ο χρήστης επιλέξει 3 */
            printf("Dwste to mhkos twn 2 kathetwn pleyrwn toy orthogwnioy trigwnoy: ");
            scanf("%f %f" , &t1, &t2);
            printf("H perimetros toy orthogwnioy trigwnoy einai: %f",yotrig(t1,t2));
            exit(0);
            }
        else if (choice=='4')                                                       /* Είσοδος και υπολογισμός περιμέτρου κύκλου σε περίπτωση */
            {                                                                       /* που ο χρήστης επιλέξει 4 */
            printf("Dwste to mhkos ths aktinas toy kykloy: ");
            scanf("%f", &t1);
            printf("H perimetros toy kykloy einai: %f",ykykl(t1));
            exit(0);
            }
    }
}

float ytetr(float v1)       /* Συνάρτηση υπολογισμού περιμέτρου τετραγώνου */
    {
        return 4*v1;
    }
float yparal(float v1, float v2)    /* Συνάρτηση υπολογισμού περιμέτρου παραλληλογράμμου */
    {
        return 2*(v1+v2);
    }
float yotrig(float v1, float v2)    /* Συνάρτηση υπολογισμού περιμέτρου ορθογωνίου τριγώνου */
    {
        return v1+v2+sqrt(v1*v1+v2*v2);
    }
float ykykl(float v1)   /* Συνάρτηση υπολογισμού περιμέτρου κύκλου */
    {
        return 2*M_PI*v1;
    }

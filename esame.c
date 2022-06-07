#include <stdio.h>
#include <stdlib.h>
#define anno_iniziale 2000
#define anno_corrente 2022
#define giorno_iniziale 5

//definisco una struct formata da 3 interi ed un char per la data con associato il corrispondente giorno della settimana
typedef struct
 {
    int giorno;
    int mese;
    int anno;
    char giorno_della_settimana [15];
 }
 data;

 //inizio a scrivere una funzione riempimento che assegna ad ogni data il giorno della settimana corrispondente
void riempimento (data date[], int* n_date)
{
    //definisco quattro indici per la data
    int g;
    int m;
    int a;
    int gs;
    //definisco un indice i che mi servira' in seguito
    int i=0;
    // definisco un array settimana formato da 7 stringhe pgnuna con lughezza massima di 15 caratteri
    char settimana [7] [15] = {"lunedi'","martedi'","mercoledi'","giovedi'","venerdi'","sabato","domenica"};
    // definisco un vettore anno normale di 12 interi corrispondenti ai giorni di ogni mese di un anno normale (dove per normale si intende non bisestile)
    int anno_normale [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //definisco un vettore anno bisestile di 12 interi corrispondenti ai giorni di ogni mese di un anno bisestile
    int anno_bisestile [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    //definisco un vettore anno generico di 12 interi che andro' a riempire con dei valori una volta che ho capito se tale anno e' bisestile o meno
    int anno_generico [12];
    // inizio un ciclo di for per assegnare i valori all'array anno generico in base a delle divisioni con resto
    for (a=anno_iniziale; a<=anno_corrente; a++)
    {
        if(a%4==0) // siccome l'anno 2000 è bisestile, se l'anno in esame nel ciclo di for è divisibile per 4, allora sara' bisestile
        {
            for(int j=0; j<12; j++)
                anno_generico[j] = anno_bisestile[j]; // l'anno generico ha nella posizione j lo stesso numero dell'array anno bisestile
        }
        else // tramite questo else dico che se l'anno in esame nell ciclo di for iniziale NON e' divisibile per 4, allora non è bisestile
        {
            for(int j=0; j<12; j++)
                anno_generico[j] = anno_normale[j]; // all'anno generico vengono assegnati i giorni dei mesi di un anno normale (non bisestile)
        }
    /* con questi cicli di for e le istruzioni condizionali if else, partendo dall'anno 2000
       sono riuscito a far capire al programma quali anni sono bisestili e quali no sulla base di una semplice
       divisione per 4.
       adesso tramite un meccanismo simile assegno anche i giorni e i mesi */
       for (m=1; m<=12; m++) // apro questo ciclo di for per assegnare i mesi, inizializzo la variabile m ad 1 poiche' nonn esiste il mese 0
       {
           for (g=1; g<=anno_generico[m-1]; g++) //questo ciclo è analogo e assegna i giorni, anch'esso inizializzato ad 1 poichè non esiste il giiorno 0
           {
               gs = (i+giorno_iniziale)%7; //calcolo gs come resto di i+giorno iniziale diviso 7
               //assegno all'array date i corrispondenti interi g m a e la stringa corrispondente al giorno della settimana
               date[i].giorno = g;
               date[i].mese = m;
               date[i].anno = a;
               int j=0;
               while (settimana[gs][j]!=0) // questo ciclo while fa continuare l'assegnazione dei giorni della settimana fino a che non si arriva allo stesso giorno
               {
                   date[i].giorno_della_settimana[j]= settimana[gs][j];
                   j++;
               }
               date[i].giorno_della_settimana[j]=0; // una volta giunti alla fine della settimana si incrementa la data
               i++;
           }
       }
    //infine assegno al parametro n_date il valore di i+1
    *n_date = i+1;
    }

}


void cerca_giorno (data date[], char giorno_cercato [], int n_date)
{
    //definisco la variabile data cercata di tipo data e la inizializzo all' 1 gennaio 2000 che era sabato
    data data_cercata = {1, 1, 2000, "sabato"} ;
    //chiedo all'utente di inserire anno mese e giorno e li assegno ai rispettivi campi nella variabile data_cercata
    printf("INSERISCI IL GIORNO DEL MESE\n");
    scanf("%d" , &data_cercata.giorno);
    printf("INSERISCI IL MESE (DA 1 A 12)\n");
    scanf("%d" , &data_cercata.mese);
    printf("INSERISCI L'ANNO\n");
    scanf("%d" , &data_cercata.anno);
    //non c'e bisogno di nessun controllo sulla data in quanto se il giorno selezionato non esiste, per come impostata la funzione riempimento, il programma restituira' non trovato

    //infine, per ogni elemento del parametro date, se i primi tre campi corrispondono a quelli del paramettro data cercata, assegno la stringa contenuta nel campo giorno della settimana al parametro giorno cercato
    for (int i=0; i<n_date; i++)
        if(data_cercata.anno==date[i].anno)
            if(data_cercata.mese==date[i].mese)
                if(data_cercata.giorno==date[i].giorno)
                {
                    int j=0;
                    while (date[i].giorno_della_settimana[j] != 0)
                    {
                        giorno_cercato[j]=date[i].giorno_della_settimana[j];
                        j++;
                    }
                    giorno_cercato[j]= 0;
                    }
}

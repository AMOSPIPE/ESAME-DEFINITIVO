#include <stdio.h>
#include <stdlib.h>
#include "Esame.h"
#define anno_iniziale 2000
#define anno_corrente 2022
#define giorno_iniziale 5


int main()
{
    //definisco la variabile date come un array di 10000 elementi di tipo data
    const int n_max= 74000;
    data date[n_max];
    //definisco la variabile stringa "giorno_cercato" e la inizializzo a "non_trovato"
    char giorno_cercato [15]= "non trovato";
    //definisco un intero n_date
    int n_date=0;
    // faccio stampare un messaggio iniziale cosi che l'utente possa capire a cosa serve il programma
    printf("QUESTO PROGRAMMA TROVA IL GIORNO DELLA SETTIMANA CORRISPONDENTE AD UNA QUALSIASI DATA A PARTIRE DALL' 1/1/2000\n");
    //richiamo la funzione riempimento
    riempimento(date, &n_date);
    // richiamo la funzione cerca giorno
    cerca_giorno(date, giorno_cercato, n_date);
    //stampo il risultato della ricerca
    printf("IL GIORNO CORRSIPONDENTE E' %s\n" , giorno_cercato);
    return 0;
}

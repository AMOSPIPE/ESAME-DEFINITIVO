#ifndef ESAME_H_INCLUDED
#define ESAME_H_INCLUDED
#define anno_iniziale 2000
#define anno_corrente 2022
#define giorno_iniziale 5


typedef struct
{
    int giorno;
    int mese;
    int anno;
    char giorno_della_settimana [15];
}
data;
void riempimento (data date[], int* n_date);
void cerca_giorno (data date[], char giorno_cercato [], int n_date);








#endif // ESAME_H_INCLUDED

/*
 La FIT (Federazione Italiana Tennis)gestisce lâ€™esito delle partite dei vari tornei utilizzando
 una struttura dati Partitaper la memorizzazione dei risultati di una partita (al meglio dei tre set).
 Tale struttura Ã¨ composta da un identificativo id_partita di tipo stringa della partita disputata
 (massimo 11 caratteri utili, di cui i primi 3 rappresentano il torneo), da due stringhe giocatore1 e giocatore2
 contenenti i nominativi dei due giocatori (massino 20 caratteriutili) e da due vettori ris1e ris2di interi di tre
 elementi ciascuno contenenti i punti effettuati in ciascun set dal giocatore 1 e dal giocatore 2, rispettivamente.
 Se una partita Ã¨ finita in 2 set, la terza locazione di ris1e ris2conterrÃ  il valore 0.Le informazioni relative
 allâ€™esito di tutte le partite di un torneo sono memorizzate in un vettore partitedi strutture Partita,
 che contiene inogni elementole informazioni di una singola partita nel formato della struttura Partita.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Partita{     //dichiaro la struttura dati "Partita"
    char id_partita[12];
    char giocatore1[21];
    char giocatore2[21];
    int ris1[4];
    int ris2[4];
};

struct listaPartite{
    char lid_partita[12];
    char lgiocatore1[21];
    char lgiocatore2[21];
    int lris1[4];
    int lris2[4];
    struct listaPartite* next;
};

void creaVettore(struct Partita* partite, int n)        //Creo la funzione per l'inserimento del vettore
{
    for(int k = 0 ; k < n ; ++k)        //ciclo per la dimensione del vettore
    {
        printf("\n\nInserisci l'ID della partita:");
        scanf("%s",partite[k].id_partita);
        fflush(stdin);      //pulisco il buffer

        printf("\nInserisci il giocatore 1:");
        scanf("%s",partite[k].giocatore1);
        fflush(stdin);

        printf("\nInserisci il giocatore 2:");
        scanf("%s",partite[k].giocatore2);
        fflush(stdin);
        printf("\nInserisci ris1(3 interi):\n");
        for(int j = 0 ; j < 3 ; ++j) {      //faccio un ciclo per ogni sotto-vettore
            scanf("%d",&partite[k].ris1[j]);
        }printf("\nInserisci il risultato 2:\n");
        for(int j = 0 ; j < 3 ; ++j) {
            scanf("%d",&partite[k].ris2[j]);
        }
    }
}

struct listaPartite* leggi_partite(struct Partita* partite, int n)      //funzione per l'assegnamento nella lista
{
    struct listaPartite* temp = NULL;       //inizializzo 2 variabili di tipo listapartite temporanee
    struct listaPartite* testa = NULL;
    for(int k = 0 ; k < n ; ++k)        //ciclo per passare per tutto il vettore
    {
        temp = (struct listaPartite*)malloc(sizeof(struct listaPartite));       //memoria dinamica della lista
        strcpy(temp->lid_partita,partite[k].id_partita);        //assegno all'id della lista l'id del vettore
        strcpy(temp->lgiocatore1,partite[k].giocatore1);
        strcpy(temp->lgiocatore2,partite[k].giocatore2);
        for(int j = 0 ; j < 3 ; ++j)        //ciclo per i sotto-vettori
        {
            temp->lris1[j] = partite[k].ris1[j];
            temp->lris2[j] = partite[k].ris2[j];
        }
        temp->next = testa;
        testa = temp;
    }
    return temp;
}
void leggiV(struct Partita* partite, int n)
{
    for(int k = 0 ; k < n ; ++k)
    {
        printf("\n\n%s",partite[k].id_partita);
        printf("\t%s",partite[k].giocatore1);
        printf("\t%s\t",partite[k].giocatore2);
        for(int j = 0 ; j < 3 ; ++j) {
            printf("%d ",partite[k].ris1[j]);
        }
        printf("\t");
        for(int j = 0 ; j < 3 ; ++j) {
            printf("%d ",partite[k].ris2[j]);
        }
    }
}
void leggiL(struct listaPartite* lista)
{
    struct listaPartite* temp = lista;
    while(temp != NULL)
    {
        printf("\n\n%s",temp->lid_partita);
        printf("\t%s",temp->lgiocatore1);
        printf("\t%s\t",temp->lgiocatore2);
        for(int j = 0 ; j < 3 ; ++j) {
            printf("%d ",temp->lris1[j]);
        }
        printf("\t");
        for(int j = 0 ; j < 3 ; ++j) {
            printf("%d ",temp->lris2[j]);
        }
        temp = temp->next;
    }
}

int vittorie_giocatore_torneo(struct listaPartite* lista, char nome[], char id[])
{
    int numwin = 0, setg1 = 0, setg2 = 0;
    struct listaPartite* temp = lista;

    while(temp != NULL)
    {
        setg1 = 0;
        setg2 = 0;
        //controllo se le prime 3 lettere dell'id sono uguali
        if((temp->lid_partita[0] == id[0]) && (temp->lid_partita[1] == id[1]) && (temp->lid_partita[2] == id[2]))
        {
            if(strcmp(temp->lgiocatore1,nome) == 0)     //controllo se il nome Ã¨ quello del giocatore1
            {
                for(int j = 0 ; j < 3 ; ++j)
                {
                    if(temp->lris1[j] > temp->lris2[j])
                        setg1+=1;       //se il ris1 Ã¨ > del ris2 sommo a setg1 altrimenti sommo a setg2
                    else if(temp->lris1[j] < temp->lris2[j])
                        setg2+=1;
                }
                if(setg1 > setg2)
                    numwin+=1;      //se alla fine il numero di set vinti da 1 Ã¨ > del numero dei set vinti da 2
                                    // allora dÃ² la vittoria al giocatore1
            }
            else if(strcmp(temp->lgiocatore2,nome) == 0)        //controllo se il nome Ã¨ quello del giocatore2
            {
                for(int j = 0 ; j < 3 ; ++j)
                {
                    if(temp->lris1[j] < temp->lris2[j])
                        setg2+=1;
                    else if(temp->lris1[j] > temp->lris2[j])
                        setg1+=1;
                }
                if(setg2 > setg1)
                    numwin+=1;
            }
        }
        temp = temp->next;      //mando avanti la lista facendo puntare all'elemento successivo
    }
    return numwin;
}

int main()
{
    int n;
    char nome[21], id[4];
    printf("Quante partite vuoi inserire?");
    scanf("%d",&n);

    struct Partita partite[n+1];        //Dichiaro il vettore di strutture
    creaVettore(partite,n);     //inserisco i valori nel vettore di strutture
   //leggiV(partite,n);      //visualizzo il vettore

    struct listaPartite* lista = leggi_partite(partite,n);      //Dichiaro la lista di partite e la inzializzo
    leggiL(lista);
    printf("\n\nInserisci il nome del gicatore da cercare:");
    scanf("%s",nome);
    fflush(stdin);
    printf("\n\nInserisci l'id da cercare':");
    scanf("%s",id);
    fflush(stdin);

    printf("\n\n\nIl giocatore: %s nel torneo: %s ha vinto: %d partite",nome,id,vittorie_giocatore_torneo(lista,nome,id));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct osoba
{
    int id; // identifikator osobe
    double tezina, visina;
    char ime[512], prezime[512];
} OSOBA;

OSOBA* ucitaj();
OSOBA* ucitaj_n(int *pn);
void pisi(const OSOBA *a);
int pronadji(const OSOBA *niz, int n, int id);

int main()
{
    int n;
    OSOBA *osobe = ucitaj_n(&n);

    if (osobe == NULL) {
        return 1;  // Greška pri alokaciji memorije
    }

    int id;
    printf("\nUnesite ID osobe za pretragu: ");
    scanf("%d", &id);

    int indeks = pronadji(osobe, n, id);
    if (indeks != -1) {
        printf("\nPodaci o osobi sa ID %d:\n", id);
        pisi(&osobe[indeks]);
    } else {
        printf("Osoba sa ID %d nije pronađena.\n", id);
    }

    // Oslobađanje memorije
    free(osobe);

    return 0;
}


OSOBA* ucitaj()
{
    OSOBA* osoba=(OSOBA*) malloc(sizeof(OSOBA));
    if(osoba==NULL)
    {
        printf("Greska pri lokaciji memorije");
        return NULL;
    }

    printf("Id");
    scanf("%d",&osoba->id);
    printf("Tezina");
    scanf("%lf",&osoba->tezina);
    printf("Visina");
    scanf("%lf",&osoba->visina);
    printf("Ime");
    scanf("%s",osoba->ime);
    printf("Prezime");
    scanf("%s",osoba->prezime);

    return osoba;
}

OSOBA* ucitaj_n(int *pn)
{
    printf("Unesite broj osoba: ");
    scanf("%d", pn);

    OSOBA* niz = (OSOBA*)malloc((*pn)*sizeof(OSOBA));
    if(niz==NULL)
    {
        printf("Greska pri lokaciji memorije");
        return NULL;
    }

    for(int i=0; i<*pn; i++)
    {
        OSOBA* o = ucitaj();
        if(o != NULL)
        {
            niz[i] = *o;
            free(o);
        }
    }

    return niz;
}

int pronadji(const OSOBA *niz, int n, int id)
{

    for(int i=0; i<n; i++)
    {

        if(niz[i].id==id)
        {
            return i;
        }
    }
    return -1;
}

void pisi(const OSOBA *a)
{

    if(a!=NULL)
        printf("Id: %d, Ime: %s, Prezime: %s, Visina: %lf, Tezina: %lf",a->id,a->ime,a->prezime,a->tezina,a->visina);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct osoba
{
    int id; // identifikator osobe
    double tezina, visina;
    char ime[512], prezime[512];
} OSOBA;


OSOBA* ucitaj(){
    OSOBA *osoba = (OSOBA *)malloc(sizeof(OSOBA));
    if (osoba == NULL) {
        printf("Greška pri alokaciji memorije.\n");
        return NULL;
    }

    printf("ID:");
    scanf("%d", &osoba->id);

    printf("Tezina:");
    scanf("%lf", &osoba->tezina);

    printf("Visina:");
    scanf("%lf", &osoba->visina);

    printf("Ime:");
    scanf("%s", osoba->ime);

    printf("Prezime:");
    scanf("%s", osoba->prezime);

    return osoba;
}

OSOBA* ucitaj_n(int *pn) {
    printf("Unesite broj osoba: ");
    scanf("%d", pn);

    OSOBA *niz = (OSOBA *)malloc((*pn) * sizeof(OSOBA));
    if (niz == NULL) {
        printf("Greška pri alokaciji memorije.\n");
        return NULL;
    }

    for (int i = 0; i < *pn; i++) {
        printf("\nUčitavanje podataka za osobu %d:\n", i + 1);
        OSOBA *osoba = ucitaj();
        if (osoba != NULL) {
            niz[i] = *osoba;
            free(osoba);  // Oslobađamo privremeni objekat
        }
    }

    return niz;
}

void pisi(const OSOBA *a) {
    if (a != NULL) {
        printf("ID: %d\n", a->id);
        printf("Ime: %s\n", a->ime);
        printf("Prezime: %s\n", a->prezime);
        printf("Težina: %.2lf\n", a->tezina);
        printf("Visina: %.2lf\n", a->visina);
    }
}

int pronadji(const OSOBA *niz, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (niz[i].id == id) {
            return i;
        }
    }
    return -1;  // Osoba nije pronađena
}

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

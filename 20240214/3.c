#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datum
{
    int d, m, g;
} DATUM;

typedef struct rezervacija
{
    char restoran[256]; // naziv restorana
    int broj_osoba;
    DATUM datum;
} REZERVACIJA;

void ucitaj2(REZERVACIJA *r) {
    printf("REZERVACIJA\n");
    printf("Naziv restorana: ");
    getchar();  // Da bi se uklonio novi red nakon prethodnog unosa
    fgets(r->restoran, sizeof(r->restoran), stdin);
    // Uklonite novi red ako je prisutan
    size_t len = strlen(r->restoran);
    if (len > 0 && r->restoran[len - 1] == '\n') {
        r->restoran[len - 1] = '\0';
    }
    printf("Broj osoba: ");
    scanf("%d", &r->broj_osoba);
    printf("Datum (dd.mm.yyyy): ");
    scanf("%d.%d.%d", &r->datum.d, &r->datum.m, &r->datum.g);
}

// Napomena: Samo za restorane koji imaju jednu riječ u svom nazivu. U suprotnom koristiti funkciju iznad.
void ucitaj(REZERVACIJA *r)
{
    printf("REZERVACIJA\n");
    printf("Naziv restorana: ");
    scanf("%s", r->restoran);
    printf("Broj osoba: ");
    scanf("%d", &r->broj_osoba);
    printf("Datum: ");
    scanf("%d.%d.%d", &r->datum.d, &r->datum.m, &r->datum.g);
    //scanf("%s %d %d.%d.%d", r->restoran, &r->broj_osoba, &r->datum.d, &r->datum.m, &r->datum.g);
}

void dodaj(REZERVACIJA **p, int n, REZERVACIJA r)
{
    REZERVACIJA *novi_niz = (REZERVACIJA *)realloc(*p, (n + 1) * sizeof(REZERVACIJA));

    if (novi_niz == NULL)
    {
        printf("Greska kod alokacije memorije.\n");
        return;
    }

    *p = novi_niz;

    (*p)[n] = r;
}

void ispisi(REZERVACIJA *niz, int n, DATUM datum)
{
    printf("REZERCACIJE za uneseni datum su\n");
    int ima = 0;
    for(int i = 0; i<n; i++)
    {
        DATUM d = niz[i].datum;
        if(d.d == datum.d && d.m == datum.m && d.g == datum.g)
        {
            printf("%s %d\n", niz[i].restoran, niz[i].broj_osoba);
            ima = 1;
        }
    }
    if(!ima)
    {
        printf("Nema rezervacija za trazeni datum.");
    }
}

int main()
{
    int n;
    printf("Unesite broj rezervacija: ");
    scanf("%d", &n);

    REZERVACIJA *rezervacije = (REZERVACIJA *)malloc(n * sizeof(REZERVACIJA));
    if (rezervacije == NULL) {
        printf("Greska kod alokacije memorije.\n");
        return 1;
    }

    // Učitavanje n rezervacija
    for (int i = 0; i < n; i++) {
        ucitaj(&rezervacije[i]);
    }

    REZERVACIJA r1 = {"ETF 1", 4, {18, 8, 2024}};
    dodaj(&rezervacije, n++, r1);

    DATUM trazeni_datum = {18, 8, 2024};
    ispisi(rezervacije, n, trazeni_datum);

    // Oslobađanje memorije!
    free(rezervacije);

    return 0;
}


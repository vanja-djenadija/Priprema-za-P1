#include <stdio.h>


int prebroji(const char *s)
{
    int broj_rijeci = 0;
    int u_rijeci = 0;  // Indikator da li smo trenutno unutar riječi

    while (*s != '\0')
    {
        if (*s != ' ')
        {
            if (!u_rijeci)
            {
                broj_rijeci++;  // Našli smo novu riječ
                u_rijeci = 1;   // Sada smo unutar riječi
            }
        }
        else
        {
            u_rijeci = 0;  // Ako smo naišli na razmak, izlazimo iz riječi
        }
        s++;  // Pomjeramo se na sljedeći karakter
    }

    return broj_rijeci;
}

void sortiraj(char **niz, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prebroji(niz[i]) > prebroji(niz[j]))
            {
                char *temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}


int main()
{
    char str1[101], str2[101], str3[101];
    char *niz[3];

    // Učitavanje stringova od korisnika
    printf("Unesite prvi string: ");
    fgets(str1, 101, stdin);
    printf("Unesite drugi string: ");
    fgets(str2, 101, stdin);
    printf("Unesite treci string: ");
    fgets(str3, 101, stdin);

    // Postavljamo pokazivače na stringove u niz
    niz[0] = str1;
    niz[1] = str2;
    niz[2] = str3;

    // Sortiramo stringove prema broju reči
    sortiraj(niz, 3);

    // Ispisujemo sortirani niz stringova
    printf("\nSortirani stringovi prema broju reci:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s", niz[i]);
    }

    return 0;
}

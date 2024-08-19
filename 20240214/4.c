#include <stdio.h>
#include <stdlib.h>

int prirodan(const char *s) {
    int broj = 0;
    int ima_cifru = 0;

    // 2c3
    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') { // ispitati da li je cifra broj
            broj = broj * 10 + (*s - '0'); // konverzija znak - broj
            ima_cifru = 1;
        }
        s++;
    }

    return ima_cifru ? broj : 0;
}


void sortiraj(char **niz, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (prirodan(niz[j]) > prirodan(niz[j + 1])) {
                // Zamjena stringova
                char *temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char *niz[] = {
        "23abc",
        "007",
        "abc12",
        "0013",
        "42xyz"
    };
    int n = 5;

    // Sortiramo niz
    sortiraj(niz, n);

    // Ispisujemo sortirani niz
    printf("Sortirani niz stringova:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", niz[i]);
    }

    return 0;
}


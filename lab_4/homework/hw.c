#include <stdio.h>
#include <string.h>

const char* diakok[] = {"Anita", "Laci", "Bela", "Adam", "Agota"};
int diakokSzama = 5;
const char* tiltottNev = "Bela";
int v = 3;

const char* jelenlegiCsapat[10]; 
int csapatMeret = 0;

void fug1(int start) {
    if (csapatMeret == v) {
        for (int i = 0; i < v; i++) {
            printf("%s ", jelenlegiCsapat[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < diakokSzama; i++) {
        if (strcmp(diakok[i], tiltottNev) == 0) {
            continue;
        }

        jelenlegiCsapat[csapatMeret] = diakok[i];
        csapatMeret++;

        fug1(i + 1);

        csapatMeret--;
    }
}

int main() {
    printf("Lehetseges csapatok (kiveve %s):\n", tiltottNev);
    fug1(0);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BTP(int *x, int n, int k, int v, int mod);
bool valid(int *x, int k, int mod);
void kiir(int *x, int v);
char gyumolcsok[][15] = {"Alma", "Banan", "Citrom", "Dio", "Eper"};
typedef struct INFO{
    int value; 
    double score;
    char name[12];
}INFO;
int main(void) {
    int n, v, mod;
    int *x;

    printf("1. Permutacio\n2. Variacio\n3. Kombinacio\nValasztas: ");
    if (scanf("%d", &mod) != 1) return 1;

    printf("n: ");
    scanf("%d", &n);

    if (mod == 1) {
        v = n;
    } else {
        printf("v: ");
        scanf("%d", &v);
    }

    x = (int*)malloc(v * sizeof(int));
    
    printf("\nEredmenyek:\n");
    BTP(x, n, 0, v, mod);

    free(x);
    return 0;
}

void BTP(int *x, int n, int k, int v, int mod) {
    int start = (mod == 3 && k > 0) ? x[k - 1] + 1 : 1;

    for (x[k] = start; x[k] <= n; x[k]++) {
        if (valid(x, k, mod)) {
            if (k < v - 1) {
                BTP(x, n, k + 1, v, mod);
            } else {
                kiir(x, v);
            }
        }
    }
}

bool valid(int *x, int k, int mod) {
    if (mod == 1 || mod == 2) {
        for (int i = 0; i < k; i++) {
            if (x[i] == x[k]) return false;
        }
    }
    return true;
}

void kiir(int *x, int v) {
    for (int i = 0; i < v; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
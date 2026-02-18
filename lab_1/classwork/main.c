//
// Created by timig on 2/18/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"


int readElementsRecursive(int *v, int n) {
    if (n <= 0) {
        return 0;
    }

    readElementsRecursive(v, n - 1);
    scanf("%d", &v[n - 1]);

    return n;
}

void printElementsRecursive(int *v, int n) {

    if (n <= 0) {
        return;
    }
    printElementsRecursive(v, n - 1);
    printf ("%d ", v[n - 1]);

}

int sumElementsRecursive(int *v, int n) {
    if (n <= 0) {
        return 0;
    }
        return sumElementsRecursive(v, n - 1) + v[n - 1];
}


int main(void) {
    if (freopen("elements.txt", "r", stdin) == NULL) {
        printf("ERROR: file not found\n");
        return 1;  // Exit if file not found
    }
    int n ;
    scanf ("%d", &n);
    int *v = (int*) malloc (n * sizeof(int));
    readElementsRecursive(v, n);

    printf ("The elements are: ");
    printElementsRecursive(v, n);

    printf("\nSum is: %d", sumElementsRecursive(v, n));



    free (v);
    return 0;
}
//
// Created by timig on 2/18/2026.
//

#ifndef FUNCIONS_H
#define FUNCIONS_H

// 1.Tömb elemeinek beolvasása rekurzívan
int readElementsRecursive(int *v, int n);
// 2.Tömb elemeinek kiíratása rekurzívan
void printElementsRecursive(int *v, int n);
// 3.Tömb elemeinek összege rekurzívan
int sumElementsRecursive(int *v, int n);
// 4.Tömb elemei közül a minimális érték rekurzívan
int minElementRecursive(int *v, int n);
// 5.Pozitív elemek száma a tömbben rekurzívan
int countPositiveElementsRecursive(int *v, int n);

// 6.Számjegyek szorzata rekurzívan
int prodDigitsNumber(int e);
// 7.Számjegyek közül a legkisebb rekurzívan
int minDigitNumber(int e);
// 8.Számjegyek fordított sorrendben rekurzívan

// 9.Mátrix elemeinek beolvasása billentyűzetről rekurzívan
void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
// 10.Mátrix elemeinek kiíratása képernyőre rekurzívan
void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
// 11.Mátrix sorainak összege rekurzívan
int sumMatrixRowsRecursive(int **matrix, int cols, int currentRow, int currentCol);
//  12.Mátrix oszlopainak összege rekurzívan
int sumMatrixColsRecursive(int **matrix, int rows, int currentRow, int currentCol);
// 13.Mátrix főátlójának összege rekurzívan
int sumMainDiagonalRecursive(int **matrix, int size, int currentIndex);
// 14.Mátrix mellékátlójának összege rekurzívan
int sumSecondaryDiagonalRecursive(int **matrix, int size, int currentIndex);
// 15.Mátrix elemeinek összege rekurzívan
int sumMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
// 16.Mátrix elemeinek maximális értéke rekurzívan
int maxMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
// 17.Mátrix elemeinek minimális értéke rekurzívan
int minMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
//18.Mátrixban található pozitív elemek száma rekurzívan
int countPositiveMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow, int
currentCol);

#endif //FUNCIONS_H

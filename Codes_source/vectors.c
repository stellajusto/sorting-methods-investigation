#include <stdio.h>
#include "vectors.h"

void init(int a[], int n, int step, int range) {
    srand(time(0));
    int i;
    for (i = 0; i < n; i++) {
        int base = i * step;
        int offset = rand() % range;
        a[i] = base + offset;
    }
}

void randomic(int a[], int n) {
    init(a,n,0,5*n);
    return;
}
void nearlySorted(int a[], int n) {
    init(a,n,10,100);
    return;
}

void reversedNearlySorted(int a[], int n) {
    init(a,n,-1,100);
    return;
}

void fewUnique(int a[], int n) {
    init(a,n,0,n/10);
    return;
}


void printArray(int arr[], int size) {
    printf("Vetor ordenado:\n");
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printNum(double nc, double na) {
    printf("\tNúmero de comparações: %.0f\n",nc);
    printf("\tNúmero de atribuições: %.0f\n",na);
}

void printResult(double avg_c,double avg_a) {
    printf("RESULTADO:");
    printf("\n\tMédia de comparações: %.0f",avg_c);
    printf("\n\tMédia de atribuições: %.0f\n",avg_a);
}

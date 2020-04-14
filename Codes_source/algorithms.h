#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp, double *numatr);
void bubbleSort(int arr[], int n, double *numcomp, double *numatr);
void bubbleSortSent(int arr[], int n, double *numcomp, double *numatr);
void bubbleSortCocktail(int arr[], int n, double *numcomp, double *numatr);
void insertionSort(int arr[], int n, double *numcomp, double *numatr);
void selectionSort(int arr[], int n, double *numcomp, double *numatr);
void mergeSort(int arr[], int n, double *numcomp, double *numatr);
void heapSort(int arr[], int n, double *numcomp, double *numatr);
void heapfy(int arr[], int n, int i, double *numcomp, double *numatr);
void quickSort(int arr[],int lower, int higher, double *numcomp, double *numatr);
int findPivot(int arr[],int left,int right, double *numcomp, double *numatr);

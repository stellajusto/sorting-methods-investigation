#include "algorithms.h"

/* Função troca
 * Inverte as chaves de posição
 * Faz 3 movimentos e atualiza o número de atribuicoes*/
void swap(int *x, int *y, double *numatr) {
    int temp = *x;
    *x = *y;
    *y = temp;
    (*numatr)+=3;
}

/* Algoritmo Bolha*/
void bubbleSort(int arr[], int n, double *numcomp, double *numatr) {
   int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1],numatr);
            }
            (*numcomp)++;
        }
    }
}

/* Algoritmo Bolha com Sentinela*/
void bubbleSortSent(int arr[],int n, double *numcomp, double *numatr) {
    int i = n-1;
    while(i>0) {
        int s = -1;
        int j;

        for(j=0; j<i; j++) {
            if(arr[j]>arr[j+1]) {
                s=j;
                swap(&arr[j],&arr[j+1],numatr);
            }
            (*numcomp)++;
        }
        i = s;
    }
}

/* Algoritmo Bolha Coquetel*/
void bubbleSortCocktail(int arr[], int n, double *numcomp, double *numatr) {
    int swapped = 1;
    int start = 0;
    int end = n -1;

    while(swapped) {
        swapped=0;

        for(int i=start; i<end; i++) {
            if(arr[i]>arr[i+1]) {
                swap(&arr[i],&arr[i+1],numatr);
                swapped=1;
                (*numcomp)++;
            }
        }

        if(!swapped) {
            break;
        }
        swapped = 0;
        end--;

        for(int i=end-1; i>=start; i--) {
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1],numatr);
                swapped=1;
                (*numcomp)++;
            }
        }
        start++;
    }
}

/* Algoritmo de Inserção */
void insertionSort(int arr[], int n, double *numcomp, double *numatr) {
    int i, tmp, j;

    for(int i = 1; i < n; i++) {
        tmp = arr[i];
        (*numatr)++;

        for(j=i-1; j>=0 && arr[j]>tmp; j--) {
            (*numcomp)++;
            arr[j+1] = arr[j];
            (*numatr)++;
        }
        arr[j+1] = tmp;
        (*numatr)++;
    }
}

/* Algoritmo de Seleção */
void selectionSort(int arr[], int n, double *numcomp, double *numatr){
    for(int i = 0; i < n - 1; i++) {
        int m = i;
        int j;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[m]) {
                m = j;
            }
            (*numcomp)++;
        }
        swap(&arr[i],&arr[m],numatr);
    }
}


/* Algoritmo MergeSort */
void mergeSort(int arr[],int n, double *numcomp, double *numatr) {
    int *buf = (int *) malloc(n*sizeof(int));

    if (buf == NULL) {
        exit(1);
    }

    int block_len;

    for(block_len = 1; block_len < n; block_len *= 2) {
        int pos = 0;
        for(pos = 0; pos < n; pos++) {
            buf[pos] = arr[pos];
            (*numatr)++;
        }
        pos = 0;
        while(pos < n) {
            int cl1 = pos;
            int cl2 = cl1 + block_len;
            int fl1 = cl1 + block_len;
            int fl2 = cl2 + block_len;
        if (fl1 > n) {
            fl1 = n;
        }
        if (fl2 > n) {
            fl2 = n;
        }

        while(cl1 < fl1 && cl2 < fl2) {
            if (buf[cl1] <= buf[cl2]) {
                arr[pos++] = buf[cl1++];
                (*numatr)++;
            }
            else {
                arr[pos++] = buf[cl2++];
                (*numatr)++;
            }
            (*numcomp)++;
        }

        while(cl1 < fl1) {
            arr[pos++] = buf[cl1++];
            (*numatr)++;
        }

        while(cl2 < fl2) {
            arr[pos++] = buf[cl2++];
            (*numatr)++;
        }

        }
    }
    free(buf);
}


/* Algoritmo HeapSort
 * Duas funções: heapSort e heapfy */
void heapSort(int arr[],int n, double *numcomp, double *numatr) {
    for (int i= n/2-1; i>=0; i--) {
        heapfy(arr,n,i,numcomp,numatr);
    }

    for (int i = n-1; i >= 0; i--) {
        swap(&arr[0],&arr[i],numatr);
        heapfy(arr,i,0,numcomp,numatr);
    }
}

void heapfy(int arr[],int n,int i, double *numcomp, double *numatr) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
        (*numcomp)++;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        (*numcomp)++;
    }

    if (largest!=i) {
        swap(&arr[i],&arr[largest],numatr);
        heapfy(arr,n,largest,numcomp,numatr);
    }
}

/* Algoritmo QuickSort
 * Duas funções: quickSort e findPivot
 * Nessa implementação o pivô escolhido é sempre o valor central do intervalo
 * Para um vetor aleatório, isso é indiferente,
 * mas para um quase-ordenado, o valor central tende a ser mais próximo da mediana*/
void quickSort(int arr[], int left, int right, double * numcomp, double * numatr) {
    int pivot;

    if(left<right) {
        (*numcomp)++;
        pivot = findPivot(arr,left,right,numcomp,numatr);
        quickSort(arr,left,pivot-1,numcomp,numatr);
        quickSort(arr,pivot+1,right,numcomp,numatr);
    }
}

int findPivot(int arr[],int left, int right, double * numcomp, double * numatr) {
    int pivotValue;
    int leftMostEnd;
    int middlePoint;

    middlePoint = (left+right)/2;

    swap(&arr[left],&arr[middlePoint],numatr);

    pivotValue = arr[left];
    (*numatr)++;

    leftMostEnd = left;
    (*numatr)++;

    for(int scan = left+1; scan <=right; scan++) {
        if (arr[scan] < pivotValue){
            (*numcomp)++;
            leftMostEnd++;
            swap(&arr[leftMostEnd],&arr[scan],numatr);
        }
    (*numcomp)++;
    }

    swap(&arr[left],&arr[leftMostEnd],numatr);

    return leftMostEnd;
}
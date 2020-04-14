/**************************************************************************************
Nome do Programa: Estudo comparativo dos métodos de ordenação.
Objetivo: Analisar o número de comparações e atribuições de cada método de ordenação.
***************************************************************************************/

#include "vectors.h"
#include "algorithms.h"
#include <unistd.h>

int main(){
    int n; //número de elementos do vetor
    int opsize; //opção referente ao tamanho do vetor
    int vectype; //opção para o tipo de vetor
    int algtype; //opção para o tipo de algoritmo
    int exec; //número de execuções
    int *arr=NULL; //ponteiro para criação de vetor dinâmico

    //Entrada de dados
    printf("Digite a opção correspondente ao número de elementos do vetor:\n"
            "\t[1] 100 (10E2)\n \t[2] 1.000 (10E3) \n\t[3] 10.000 (10E4) \n\t[4] 100.000 (10E5) \n\t[5] 1.000.000 (10E6)\n");
    printf("Opção:\t");
    scanf("%d", &opsize);

    printf("\nDigite a opção correspondente ao tipo de vetor a ser criado:\n"
            "\t[1] Vetor aleatório \n \t[2] Vetor quase ordenado\n"
            "\t[3] Vetor quase inversamente ordenado\n \t[4] Vetor com muitos valores repetidos\n");
    printf("Opção:\t");
    scanf("%d",&vectype);

    printf("\nDigite a opção correspondente ao algoritmo de ordenação a ser usado:\n"
            "\t[1] Bolha\n \t[2] Bolha com Sentinela\n \t[3] Bolha Coquetel\n \t[4] Inserção\n"
            "\t[5] Seleção\n \t[6] Intercalação\n \t[7] HeapSort\n \t[8] QuickSort\n");
    printf("Opção:\t");
    scanf("%d",&algtype);

    printf("\nDigite o número de execuções a serem realizadas:\n");
    printf("Quantidade: ");
    scanf("%d",&exec);

    //Formatação de texto
    printf("\n");
    printf("*******************************************************************************\n");
    switch(algtype) {
        case 1: printf("\tAlgoritmo Bolha - "); break;
        case 2: printf("\tAlgoritmo Bolha com Sentinela - "); break;
        case 3: printf("\tAlgortimo Bolha Cocktail - "); break;
        case 4: printf("\tAlgoritmo de Inserção - "); break;
        case 5: printf("\tAlgoritmo de Seleção - "); break;
        case 6: printf("\tAlgoritmo de Intercalação - "); break;
        case 7: printf("\tAlgoritmo HeapSort - "); break;
        case 8: printf("\tAlgoritmo QuickSort - "); break;
    }
    switch(vectype) {
        case 1: printf("Vetor Aleatório - "); break;
        case 2: printf("Vetor Quase Ordenado - "); break;
        case 3: printf("Vetor Quase Inversamente Ordenado - "); break;
        case 4: printf("Vetor com Muitos Valores Repetidos - "); break;
    }
    switch(opsize) {
        case 1: n = 100; printf("%d elementos\n",n); break;
        case 2: n = 1000; printf("%d elementos\n",n); break;
        case 3: n = 10000; printf("%d elementos\n",n); break;
        case 4: n = 100000; printf("%d elementos\n",n); break;
        case 5: n = 1000000; printf("%d elementos\n",n); break;
    }

    //Início das execuções
    int i=1; //contador de execuções
    double sumcomp=0,sumatr =0; //acumulado do no. de comp. e atrib. por execução
    while(i <= exec) {
        double numcomp=0; //número de comparações
        double numatr=0; //número de atribuições

        printf("\n%da. execução\n", i);
        arr = (int *) malloc (n* sizeof(int));

        sleep(1); //delay de 1s para criar vetores distintos entre uma execução e outra

        switch(vectype) {
            case 1: randomic(arr,n);
                    break;
            case 2: nearlySorted(arr,n);
                    break;
            case 3: reversedNearlySorted(arr,n);
                    break;
            case 4: fewUnique(arr,n);
                    break;
        }
        switch(algtype) {
            case 1: bubbleSort(arr, n, &numcomp, &numatr);
                    break;
            case 2: bubbleSortSent(arr, n, &numcomp, &numatr);
                    break;
            case 3: bubbleSortCocktail(arr, n, &numcomp, &numatr);
                    break;
            case 4: insertionSort(arr, n, &numcomp, &numatr);
                    break;
            case 5: selectionSort(arr, n, &numcomp, &numatr);
                    break;
            case 6: mergeSort(arr, n, &numcomp, &numatr);
                    break;
            case 7: heapSort(arr, n, &numcomp, &numatr);
                    break;
            case 8: quickSort(arr, 0,n-1, &numcomp, &numatr);
                    break;
        }

        /*Para imprimir o vetor ordenado, tire o comentário da linha abaixo*/
        //printArray(arr,n);

        printNum(numcomp, numatr);
        sumcomp += numcomp;
        sumatr += numatr;
        i++;
        free(arr);
    }

    double averagecomp = sumcomp/exec; //media das comparacoes
    double averageatr = sumatr/exec; //media das atribuicoes

    printf("*******************************************************************************\n");
    printResult(averagecomp,averageatr);
    return 0;
}

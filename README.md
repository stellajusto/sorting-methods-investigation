# Estudo analítico de diversos métodos de ordenação

Realizou-se um estudo comparativo entre os mais conhecidos métodos de ordenação (Bolha, Bolha com Sentinela, Bolha Coquetel, Inserção, Seleção, MergeSort, HeapSort e QuickSort) averiguando o número de comparações e de atribuições realizadas por cada um deles quando inseridos em vetores com diferentes características como input (i.e, vetores com números aleatórios, vetores quase-ordenados, vetores inversamente quase-ordenados e vetores com muitos valores repetidos). O programa permite escolher o tamanho do vetor a ser ordenado e o número de execuções a serem realizadas; ao final faz-se uma média do número de comparações e atribuições de cada um dos métodos de ordenação.

Diretórios:
* Codes_source: algoritmos de ordenação (algorithms.c), criação de diferentes tipos de vetores (vectors.c) e entrada de dados (main.c). 
* R_source: código em R para o plot dos arquivos csv, representando os diferentes cenários obtidos a considerar os algoritmos de ordenação, o tipo de vetor e o número de execuções.
* Plots: plots gerados a partir dos arquivos csv.

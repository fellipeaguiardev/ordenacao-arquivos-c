#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int lerInteiro() {
    int numero, lido, c;

    lido = scanf("%d", &numero);
    while (lido != 1) {
        if (lido == EOF) {
            exit(0);
        }
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Valor invalido, digite um numero: ");
        lido = scanf("%d", &numero);
    }
    return numero;
}

void mostrarVetor(int v[], int n) {
    int i;

    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}


void bubbleSort(int v[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(&v[j], &v[j + 1]);
            }
        }
    }
}

void insertionSort(int v[], int n) {
    int i, j, atual;

    for (i = 1; i < n; i++) {
        atual = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > atual) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = atual;
    }
}

void selectionSort(int v[], int n) {
    int i, j, menor;

    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        trocar(&v[i], &v[menor]);
    }
}

void intercalar(int v[], int inicio, int meio, int fim) {
    int aux[MAX];
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        v[inicio + i] = aux[i];
    }
}

void mergeSort(int v[], int inicio, int fim) {
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        intercalar(v, inicio, meio, fim);
    }
}


int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }
    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

void quickSort(int v[], int inicio, int fim) {
    int p;

    if (inicio < fim) {
        p = particionar(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}

void criarArquivo() {
    FILE *arquivo;
    int valores[] = {4, 3, 7, 2, 1, 6};
    int n = 6;
    int i;

    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar dados.txt\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(arquivo, "%d ", valores[i]);
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);

    printf("Arquivo dados.txt criado com os valores:\n");
    mostrarVetor(valores, n);
}

int lerArquivo(int v[]) {
    FILE *arquivo;
    int n = 0;

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir dados.txt. Crie o arquivo primeiro (opcao 1).\n");
        return 0;
    }
    while (n < MAX && fscanf(arquivo, "%d", &v[n]) == 1) {
        n++;
    }
    fclose(arquivo);

    if (n == 0) {
        printf("O arquivo dados.txt esta vazio.\n");
    }
    return n;
}

void salvarArquivo(char nome[], int v[], int n) {
    FILE *arquivo;
    int i;

    arquivo = fopen(nome, "w");
    if (arquivo == NULL) {
        printf("Erro ao gravar %s\n", nome);
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(arquivo, "%d ", v[i]);
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);
}

void ordenarESalvar(int v[], int n) {
    int opcao;

    printf("\nEscolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("Opcao: ");
    opcao = lerInteiro();
    while (opcao < 1 || opcao > 5) {
        printf("Opcao invalida, digite de 1 a 5: ");
        opcao = lerInteiro();
    }

    switch (opcao) {
        case 1:
            bubbleSort(v, n);
            break;
        case 2:
            insertionSort(v, n);
            break;
        case 3:
            selectionSort(v, n);
            break;
        case 4:
            mergeSort(v, 0, n - 1);
            break;
        case 5:
            quickSort(v, 0, n - 1);
            break;
    }

    salvarArquivo("ordenado.txt", v, n);
    printf("\nValores ordenados (salvos em ordenado.txt):\n");
    mostrarVetor(v, n);
}

void alterarValor(int v[]) {
    int n, posicao, novoValor;

    n = lerArquivo(v);
    if (n == 0) {
        return;
    }

    printf("\nValores de dados.txt:\n");
    mostrarVetor(v, n);

    printf("Qual posicao deseja alterar (0 a %d)? ", n - 1);
    posicao = lerInteiro();
    while (posicao < 0 || posicao > n - 1) {
        printf("Posicao invalida, digite de 0 a %d: ", n - 1);
        posicao = lerInteiro();
    }

    printf("Novo valor: ");
    novoValor = lerInteiro();

    v[posicao] = novoValor;
    salvarArquivo("dados.txt", v, n);
    printf("Valor alterado em dados.txt!\n");

    ordenarESalvar(v, n);
}

int main() {
    int v[MAX];
    int n, opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Criar dados.txt\n");
        printf("2 - Ler dados.txt\n");
        printf("3 - Ordenar e salvar em ordenado.txt\n");
        printf("4 - Alterar um valor e reordenar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                criarArquivo();
                break;
            case 2:
                n = lerArquivo(v);
                if (n > 0) {
                    printf("\nValores de dados.txt:\n");
                    mostrarVetor(v, n);
                }
                break;
            case 3:
                n = lerArquivo(v);
                if (n > 0) {
                    ordenarESalvar(v, n);
                }
                break;
            case 4:
                alterarValor(v);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

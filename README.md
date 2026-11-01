# Ordenação com Arquivos em C

Programa de console em C que une **algoritmos de ordenação** e **manipulação de arquivos**. Ele grava um vetor em um arquivo, lê esses dados de volta, ordena com o algoritmo escolhido e salva o resultado em um novo arquivo. Também permite alterar um valor e reordenar.

## Funcionalidades

- Cria o arquivo `dados.txt` com valores desordenados
- Lê os dados do arquivo e mostra na tela
- Oferece cinco algoritmos: Bubble, Insertion, Selection, Merge e Quick Sort
- Salva o resultado em `ordenado.txt`, sem alterar `dados.txt`
- Altera um valor de `dados.txt` pela posição, começando do 0, e reordena em seguida

## Como compilar e executar

É preciso ter o [GCC](https://gcc.gnu.org/) instalado.

```bash
gcc -Wall -Wextra -std=c99 ordenacao.c -o ordenacao
```

No Windows:

```bash
./ordenacao.exe
```

No Linux ou macOS:

```bash
./ordenacao
```

## Como usar

```text
===== MENU =====
1 - Criar dados.txt
2 - Ler dados.txt
3 - Ordenar e salvar em ordenado.txt
4 - Alterar um valor e reordenar
0 - Sair
```

Comece pela opção **1**, que cria o `dados.txt` com o vetor `[4,3,7,2,1,6]`.

### Exemplo

Depois de criar os dados, a opção **3** mostra:

```text
Valores ordenados (salvos em ordenado.txt):
[1,2,3,4,6,7]
```

Na opção **4**, alterar a posição 3 para o valor 9 troca o número 2:

| Posição | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| Antes | 4 | 3 | 7 | 2 | 1 | 6 |
| Depois | 4 | 3 | 7 | **9** | 1 | 6 |

Ao reordenar, o resultado fica `[1,3,4,6,7,9]`.

## Arquivos gerados

Os arquivos são criados na pasta em que o programa é executado, com os valores em uma única linha.

| Arquivo | Conteúdo | Exemplo |
|---|---|---|
| `dados.txt` | Valores originais | `4 3 7 2 1 6` |
| `ordenado.txt` | Valores ordenados | `1 2 3 4 6 7` |

## Algoritmos

| Algoritmo | Como funciona | Melhor caso | Caso médio | Pior caso |
|---|---|---|---|---|
| Bubble Sort | Compara vizinhos e leva o maior para o final | O(n²) | O(n²) | O(n²) |
| Insertion Sort | Insere cada valor no lugar certo da parte já ordenada | O(n) | O(n²) | O(n²) |
| Selection Sort | Seleciona o menor valor restante a cada passada | O(n²) | O(n²) | O(n²) |
| Merge Sort | Divide o vetor ao meio, ordena as metades e intercala | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | Separa os valores em torno de um pivô, o último elemento | O(n log n) | O(n log n) | O(n²) |

## Limitações

- O programa lê no máximo 100 valores (`#define MAX 100`).
- Se o `dados.txt` for editado à mão e tiver texto no meio, a leitura para nesse ponto. Usar a opção 4 depois disso regrava o arquivo só com o que foi lido.
- Criar um novo `dados.txt` não apaga o `ordenado.txt` antigo, que só muda na próxima ordenação.

## Autoria

Projeto da faculdade de Engenharia de Software. O código e este README foram escritos com a ajuda do [Claude Code](https://claude.com/claude-code).

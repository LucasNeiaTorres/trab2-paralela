// Autores: Lucas Néia Torres, Inaiê Moscal Zambonin

#include <stdio.h>
#include "verifica_particoes.h"

void verifica_particoes(long long *Input, int n, long long *P, int np, long long *Output, int *Pos)
{
    int i, j;

    for (i = 0; i < np; i++)
    {
        // se a partição i começa depois do final do vetor de entrada, então o particionamento está errado
        if (Pos[i] > n)
        {
            printf("particionamento COM ERROS\n");
            printf("1 - Pos[%d] = %d > %d\n", i, Pos[i], n);
            return;
        }

        // teste para não acessar posição inválida
        if (i + 1 < np)
        {
            // se a partição i+1 começa antes da partição i, então o particionamento está errado
            if (Pos[i] > Pos[i + 1])
            {
                printf("particionamento COM ERROS\n");
                printf("2 - Pos[%d] = %d > Pos[%d] = %d\n", i, Pos[i], i + 1, Pos[i + 1]);
                return;
            }
            for (j = Pos[i]; j < Pos[i + 1]; j++)
            {
                if (Output[j] >= P[i])
                {
                    printf("particionamento COM ERROS\n");
                    printf("3 - Output[%d] = %lld >= P[%d] = %lld\n", j, Output[j], i, P[i]);
                    return;
                }
            }
        }
        else
        {
            // caso seja ultima partição, for não pode ir até Pos[i + 1] pois não existe
            for (j = Pos[i]; j < n; j++)
            {
                if (Output[j] >= P[i])
                {
                    printf("particionamento COM ERROS\n");
                    printf("4 - Output[%d] = %lld >= P[%d] = %lld\n", j, Output[j], i, P[i]);
                    return;
                }
            }
        }
    }
    printf("particionamento CORRETO\n");
}
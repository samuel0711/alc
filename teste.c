#include <stdio.h>

int multiplicamatrix(int n, int matriz [][n], int vetorb[], int vetorx[]);

int multiplicamatrix(int n, int matriz[][n], int vetorb[], int vetorx[])
{
    int vetorr[n], aux = 0, resultado = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            aux += vetorx[j]*matriz[i][j];
            //printf("aux = %d\n", aux);
        }
        vetorr[i] = aux;                       //RECEBENDO O RESULTADO DE A*X
        aux = 0;
        //printf("vetorr = %d\n", vetorr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if( vetorr[i] != vetorb[i])
        {
            resultado = 1;
            return resultado;
        }
    }
    return resultado;

}


int main(void)
{
    int i, j, n;//, resul;

    puts("Entre com a norma da matriz:");
    scanf("%d", &n);

    int matriz[n][n], vetorx[n], vetorb[n];
    printf("----------------------------------\n");

    for(i = 0; i < n; i++)          //OBTENDO A MATRIZ
    {
        for(j = 0; j < n; j++)
        {
            printf("Entre com o elemento [%d][%d] da matriz:\n", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");

    printf("Matriz A:\n");      //IMPRIMINDO A MATRIZ

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {

            printf("%d ", matriz[i][j]);

            if(j == n-1)         //SO PRA MATRIZ FICAR BONITINHA
            {
                printf("\n");
            }
        }
    }

    printf("----------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("Entre com o elemento %d do vetor 'b':", i+1);
        scanf("%d", &vetorb[i]);
    }

    printf("----------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("Entre com o elemento %d do vetor 'x':", i+1);
        scanf("%d", &vetorx[i]);
    }



    FILE *pa;
    pa = fopen("matriz.txt", "w");

    if(pa == NULL)
    {
        puts("Impossivel abrir o arquivo");
    }
    fprintf(pa, "Matriz :\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)                              //ESCREVENDO MATRIZ NO ARQUIVO
        {

            fprintf(pa,"%d ", i+1, j+1, matriz[i][j]);
            if(j == n-1)         //SO PRA MATRIZ FICAR BONITINHA
            {
                fprintf(pa,"\n");
            }
        }
    }

    fclose(pa);



    pa = fopen("vetorx.txt", "w");         //ESCREVENDO VETOR X NO ARQUIVO

    if(pa == NULL)
    {
        puts("Impossivel abrir o arquivo");
    }
    fprintf(pa, "Vetor x:\n");


    for(i = 0; i < n; i++)
    {
        fprintf(pa, "%d ", vetorx[i]);
    }
    fclose(pa);




    pa = fopen("vetorb.txt", "w");                //ESCREVENDO VETOR B NO ARQUIVO

    if(pa == NULL)
    {
        puts("Impossivel abrir o arquivo");
    }
    fprintf(pa, "Vetor b:\n");

    for(i = 0; i < n; i++)
    {
        fprintf(pa, "%d ", vetorb[i]);
    }
    fclose(pa);



    printf("----------------------------------\n");


    if(multiplicamatrix(n, matriz, vetorb, vetorx) == 1)
    {
        printf("Ax é diferente de b!\n");
    }
    else
    {
        printf("Ax = b!\n");
    }


    return 0;
}


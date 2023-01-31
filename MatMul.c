#include<stdio.h>    
#include<stdlib.h>  
#include<time.h>

void fillArray1(int a1[][3], int rows, int cols);
void fillArray2(int a2[][2], int rows, int cols);
void printArray1(int a1[][3], int rows, int cols);
void printArray2(int a2[][2], int rows, int cols);
void MatMul(int a1[][3], int a2[][2], int mul[][2], int r1, int r2, int  c1, int c2);
void printMatMul(int mul[][2], int rows, int cols);

int main()
{
    int a1[2][3];
    int a2[3][2];
    int mul[2][2];
    int r1, r2, c1, c2;
    srand(time(NULL));

    fillArray1(a1, 2, 3);
    fillArray2(a2, 3, 2);
    
    printf("-------------\n");
    printArray1(a1, 2, 3);
    printf("-------------\n");
    printArray2(a2, 3, 2);
    printf("-------------\n");

    MatMul(a1, a2, mul, r1, r2, c1, c2);
    printMatMul(mul, r1, c2);
    

    return 0;
}

void printArray1(int a1[][3], int rows, int cols)
{
    int i, j;
    for (i=0;i<rows; i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%4d", a1[i][j]);
        }
        printf("\n");
    }
}

void printArray2(int a2[][2], int rows, int cols)
{
    int k, l;
    for (k=0;k<rows; k++)
    {
        for(l=0;l<cols;l++)
        {
            printf("%4d", a2[k][l]);
        }
        printf("\n");
    }
}

void fillArray1(int a1[][3], int rows, int cols)
{
    int i, j;
    for (i=0;i<rows;i++)
    {
        for (j=0;j<cols;j++)
        {
            a1[i][j] = rand() % 101;
        }
    }
}

void fillArray2(int a2[][2], int rows, int cols)
{
    int k, l;
    for (k=0;k<rows;k++)
    {
        for (l=0;l<cols;l++)
        {
            a2[k][l] = rand() % 101;
        }
    }
}

void MatMul(int a1[][3], int a2[][2], int mul[][2], int r1, int r2, int  c1, int c2)
{
    for (int i=0;i<r1;i++) 
    {
      for (int j=0;j<c2;j++) 
      {
         mul[i][j] = 0;
      }
    }

    for (int i=0;i<r1;i++) 
    {
      for (int j=0;j<c2;j++)
      {
         for (int k=0;k<c1;k++)
         {
            mul[i][j] += a1[i][k] * a2[k][j];
         }
      }
   }
} 

void printMatMul(int mul[][2], int rows, int cols)
{
   for (int i=0;i<rows;i++)
   {
      for (int j=0;j<cols; j++)
      {
         printf("%d  ", mul[i][j]);
         if (j == cols - 1)
            printf("\n");
      }
   }
}
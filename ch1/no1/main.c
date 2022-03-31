/**************************************************
 * Filename         :main.c
 * Description      :
 * Time             :2022/03/28 21:41:04
 * Author           :promenader
***************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

void initRandomArray(int *arr, int length);
void printArray(int *arr, int length);
void bubbleSort(int *arr, int length);

int main(int argc, char const *argv[])
{
    int a[N];
    initRandomArray(a, N);
    printArray(a, N);
    bubbleSort(a, N);
    printArray(a, N);

    printf("k %d", a[3]);
    return 0;
}

void printArray(int *arr, int length)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            int temp;
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void initRandomArray(int *arr, int length)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
}

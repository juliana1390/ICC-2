#include<stdio.h>
#include<stdlib.h>

int *readArray(int n);
void destroyArray(int *array);
void selection(int *array[], int n);
void printArray(int *array[], int n);

int main()
{
    int n; // size of array
    scanf("%d", &n);

    int *array = readArray(n); // allocation method

    selectionSort(array, n);

    printf("array in order: ");
    
    printArray(array, n);

    destroyArray(array);

    exit(0);
}

int *readArray(int n)
{
    int *array = malloc(sizeof(int) * n);

    if(array == NULL)
    {
        printf("INSUFFICIENT MEMORY\n");
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        array[i] = x;
    }
    return array;
}

void destroyArray(int *array)
{
    free(array);
}

void selectionSort(int *array[], int n)
{
    int smallest, temp;

    for (int i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if(array[smallest] > array[j])
            {
                smallest = j;
            }
            if(i != smallest) // swap
            {
                temp = array[i];
                array[i] = array[smallest];
                array[smallest] = temp;
            }
        }        
    }    
}

void printArray(int *array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
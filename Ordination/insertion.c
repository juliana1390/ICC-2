#include<stdio.h>
#include<stdlib.h>

int *readArray(int n);
void destroyArray(int *array);
void insertionSort(int array[], int n);
void printArray(int array[], int n);

int main(int argc, char *argv[])
{
    int n; // size of array
    scanf("%d", &n);

    int *array = readArray(n); // allocation method

    insertionSort(array, n);
    
    printf("array in order: ");
    printArray(array, n);
    
    destroyArray(array);

    exit(0);
}

int *readArray(int n)
{
    int *array = malloc(sizeof(int) * n);
    if(array == NULL) // checks if there is available memory
    {
        printf("INSUFFICIENT MEMORY\n");
    }
    for(int i = 0; i < n; i++) // reads the elements end puts them in the array
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

void insertionSort(int array[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int x = array[i];
        int j = i - 1;
        
        while(j >= 0 && array[j] > x)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = x;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
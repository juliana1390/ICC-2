#include<stdio.h>
#include<stdlib.h>

int *readArray(int n)
{
    int *a = malloc(sizeof(int) * n);
    if(a == NULL) // checks if there is available memory
    {
        printf("INSUFFICIENT MEMORY\n");
    }
    for(int i = 0; i < n; i++) // reads the elements end puts them in the array
    {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    return a;
}

void destroyArray(int *a)
{
    free(a);
}

void insertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        
        while(j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int n; // size of array
    scanf("%d", &n);

    int *a = readArray(n); // allocation method

    insertionSort(a, n);
    
    printf("array in order: ");
    printArray(a, n);
    
    destroyArray(a);

    exit(0);
}
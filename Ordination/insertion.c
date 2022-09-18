#include<stdio.h>
#include<stdlib.h>

int *readArray(int n)
{
    int *a = malloc(sizeof(int) * n);
    if(a == NULL) // checks if there is memory space enough
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

int inOrder(int a[], int n) // checks if the array is in order
{
    for(int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + i])
        {
            return 0;
        }
    }
    return 1;

    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
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

    printArray(a, n);
    
    if(inOrder(a, n))
    {
        printf("it's in order\n");
    }else
    {
        printf("it isn't in order\n");
    }

    insertionSort(a, n);

    printArray(a, n);
    
    destroyArray(a);

    exit(0);
}
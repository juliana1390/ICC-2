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

void _merge2Arrays(int a[], int start1, int end1, int start2, int end2, int b[])
{
    int i1 = start1;
    int i2 = start2;
    int j = 0;

    while (i1 <= end1 && i2 <= end2)
    {
        if (a[i1] <= a[i2])
        {
            b[j] = a[i1];
            j++;
            i1++;
        }
        else
        {
            b[j] = a[i2];
            j++;
            i2++;
        }            
    }

    while(i1 <= end1)
    {
        b[j] = a[i1];
        j++;
        i1++;
    }

    while(i2 <= end2)
    {
        b[j] = a[i2];
        j++;
        i2++;
    }

    j = 0;
    
    for(int i = start1; i <= end2; i++, j++) // joins the two arrays and takes the elements to the array a[i]
    {
        a[i] = b[j];
    }
}

void _merge(int a[], int start, int end, int b[])
{
    // base case
    if(start >= end)
    {
        return;
    }

    int middle = ((start + end) / 2);
    _merge(a, start, middle, b); // from start to middle, using b as temp
    _merge(a, middle + 1, end, b); // from middle + 1 to end, using b as temp
    _merge2Arrays(a, start, middle, middle + 1, end, b); // from start to middle, from middle + 1 to end, using b as temp
}

void mergeSort(int a[], int n)
{
    int *b = malloc(sizeof(int) * n);
    if(b == NULL)
    {
        printf("INSUFFICIENT MEMORY\n");
        exit(-1);
    }

    _merge(a, 0, n - 1, b);

    free(b);
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

    mergeSort(a, n);

    printf("array in order: ");
    printArray(a, n);

    destroyArray(a);

    exit(0);
}
#include<stdio.h>
#include<stdlib.h>

int *readArray(int n);
void destroyArray(int *array);
void _merge2Arrays(int array[], int start1, int end1, int start2, int end2, int temp[]);
void _merge(int array[], int start, int end, int temp[]);
void mergeSort(int array[], int n);
void printArray(int array[], int n);



int main(int argc, char *argv[])
{
    int n; // size of array
    scanf("%d", &n);

    int *array = readArray(n); // allocation method   

    mergeSort(array, n);

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

void _merge2Arrays(int array[], int start1, int end1, int start2, int end2, int temp[])
{
    int i1 = start1;
    int i2 = start2;
    int j = 0;

    while (i1 <= end1 && i2 <= end2)
    {
        if (array[i1] <= array[i2])
        {
            temp[j] = array[i1];
            j++;
            i1++;
        }
        else
        {
            temp[j] = array[i2];
            j++;
            i2++;
        }            
    }

    while(i1 <= end1)
    {
        temp[j] = array[i1];
        j++;
        i1++;
    }

    while(i2 <= end2)
    {
        temp[j] = array[i2];
        j++;
        i2++;
    }

    j = 0;
    
    for(int i = start1; i <= end2; i++, j++) // joins the two arrays and takes the elements to the array a[i]
    {
        array[i] = temp[j];
    }
}

void _merge(int array[], int start, int end, int temp[])
{
    // base case
    if(start >= end)
    {
        return;
    }

    int middle = ((start + end) / 2);
    _merge(array, start, middle, temp); // from start to middle, using b as temp
    _merge(array, middle + 1, end, temp); // from middle + 1 to end, using b as temp
    _merge2Arrays(array, start, middle, middle + 1, end, temp); // from start to middle, from middle + 1 to end, using b as temp
}

void mergeSort(int array[], int n)
{
    int *temp = malloc(sizeof(int) * n);
    if(temp == NULL)
    {
        printf("INSUFFICIENT MEMORY\n");
        exit(-1);
    }

    _merge(array, 0, n - 1, temp);

    free(temp);
}

void printArray(int array[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
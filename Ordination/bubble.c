#include<stdio.h>
#include<stdlib.h>

int *readArray(int n);
void destroyArray(int *array);
void bubbleSort(int array[], int n);
void printArray(int array[], int n);



int main(int argc, char *argv[])
{
    int n; // size of array
    scanf("%d", &n);

    int *array = readArray(n); // allocation method   

    bubbleSort(array, n);

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

void bubbleSort(int array[], int n)
{
    int sentinel = n - 1, end = n;
    int _continue, temp;

    do
    {
        _continue = 0;
        for(int i = 0; i < sentinel; i++)
        {
            if(array[i] > array[i + 1]) // swap
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                _continue = i;
            }
            end--;
        }
        sentinel = _continue;
    } while (_continue != 0);
}

void printArray(int array[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
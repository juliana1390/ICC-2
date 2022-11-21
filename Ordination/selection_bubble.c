/*
Write a C program that receives the name of the sorting method (in this case, selection or bubble), the number of 
elements and an array. After that, read the elements and print the indications and all comparisons and swaps 
performed by the chosen method, followed by the ordered array.
Comparisons and swaps must be printed according to the indices of the elements involved in the operation.
For example, if the element of index 3 was compared with the element of index 7, then it would print C 3 7.
If the element of index 2 was swapped with the element of index 5, it would print T 2 5.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === METHODS ===

void selectionSort(int size, int array[]);
void bubbleSort(int size, int array[]);

// === MAIN ===

int main()
{
    char type[15], s[15]= "selection", b[15] = "bubble";
    scanf("%s", &type);
    fflush(stdin);
    int size;
    scanf("%d",&size);
    int array[size];
    
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    
    if(!strcmp(type, s))
        selectionSort(size, array);
    else if(!strcmp(type, b))
        bubbleSort(size, array);

    return 0;
}

// === SELECTION SORT ===

void selectionSort(int size, int array[])
{
    int smallest, swap = 0, temp;

    for(int i = 0; i < size-1; i++)
    {
        smallest = i;
        
        for(int j = i; j < size; j++)
        {
            if(j != i)
                printf("C %d %d\n", smallest, j);

            if(array[j] < array[smallest])
            {
                smallest = j;
                swap = 1;
            }
        }
        if(swap == 1)
        {
            printf("T %d %d\n", i, smallest);
            swap = 0;
        }

        temp = array[smallest];
        array[smallest] = array[i];
        array[i] = temp;

    }
    
    for(int i = 0; i < size; i++)
        printf("%d ",array[i]);

    printf("\n");
}

// BUBBLE SORT ===

void bubbleSort(int size,int array[])
{
    int sentinel = size-1;
    int change;

    while(sentinel){
        change = 0;

        for(int j = 0; j < sentinel; j++)
        {
            printf("C %d %d\n", j, j+1);

            if(array[j] > array[j+1])
            {
                printf("T %d %d\n", j, j+1);
                array[j] ^= array[j+1];
                array[j+1] ^= array[j];
                array[j] ^= array[j+1];
                change = j;
            }
        } 
        sentinel = change;
    }
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n");
}
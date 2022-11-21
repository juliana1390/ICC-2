/*
Write a C program that reads the number of elements of an array. After that, read the elements of the array.
The program must sort all sub-arrays using the Shell Sort and Quick Sort methods. For each sub-array,
print which method did the least operations (comparison + copies), printing Q when it is Quick Sort, S when it is 
Shell Sort and the hyphen character when the number of counts is equal. Shell must use gaps in the form 2^k - 1, and 
Quick Sort must use the middle element as a pivot.
For example, consider the following array A: [3, 6, 5, 2]. The sub-arrays of A are: A1: [3], A2: [3, 6], A3: [3, 6, 5],
and A4 = [3, 6, 5, 2]. For A1, the number of operations is the same for both methods. For A2, A3 and A4, Shell Sort 
performs fewer operations. So your program should print: - S S S
*/

#include <stdio.h>
#include <stdlib.h>

// === METHODS ===

void _quick(int array[], int beginning, int end);
int quickSort(int array[], int n);
int shellSort(int array[], int n);

// === COUNTER / COMPARISONS / SWAPS === (QuickSort) ===

    int qCounter = 0;
    int qComparisons = 0;
    int qSwaps = 0;
    
// === MAIN ===

int main()
{
    int numOfElements;
    int numOfCounters;

    if(!scanf("%d", &numOfElements))
    {
        printf("Reading error!");
        exit(-1);
    }

    int *_array = (int *) calloc(numOfElements, sizeof(int)); 

    for(int i = 0; i < numOfElements; i++)
    {
        if(!scanf("%d", &_array[i]))
        {
            printf("Reading error!");
            exit(-1);
        }
    }

    for(numOfCounters = 1; numOfCounters <= numOfElements; numOfCounters++)
    {
        int *arrayCopy = (int *) calloc(numOfCounters, sizeof(int));

        for(int j = 0; j < numOfCounters; j++)
        {
            arrayCopy[j] = _array[j];
        }

        int sCounter = shellSort(arrayCopy, numOfCounters);
        for(int j = 0; j < numOfCounters; j++)
        {
            arrayCopy[j] = _array[j];
        }

        int qCounter = quickSort(arrayCopy, numOfCounters);
        if (qCounter > sCounter)
        {
            printf("S ");
        }
        else if(sCounter > qCounter)
        {
            printf("Q ");
        }
        else if (sCounter == qCounter)
        {
            printf("- ");
        }
        free(arrayCopy);
    }    
    free(_array);
    return 0;
}

// === QUICKSORT ===

void _quick(int array[], int beginning, int end)
{
    if (beginning >= end)
    {
        return;
    }
    int middle = (beginning + end) / 2;
    int pivot = array[middle];
    qSwaps++;
    int i = beginning;
    int j = end;

    while (1)
    {
        while (array[i] < pivot)
        {
            qComparisons++;
            i++;
        }
        
        while (array[j] > pivot)
        {
            qComparisons++;
            j--;
        }

        qComparisons += 2;

        if (j <= i)
        {            
            break;
        }
    
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        qSwaps += 3;
        i++;
        j--;
    }
    _quick(array, beginning, j); 
    _quick(array, j + 1, end);      
}

int quickSort(int array[], int n)
{
    qCounter = 0;
    qComparisons = 0;
    qSwaps = 0;
    
    _quick(array, 0, n - 1);
    qCounter = qSwaps + qComparisons;
    return qCounter;
}

// === SHELLSORT ===

int shellSort(int array[], int n)
{
    int sCounter = 0;
    int sSwaps = 0;
    int sComparisons = 0;
    int gap = 1;

    while(gap <= n)
    {
        gap *= 2;
    }

    gap = gap / 2 - 1;
    
    while(gap > 0)
    {
        for (int i = gap; i < n; i+=gap)
        {      
            int x = array[i];
            sSwaps++;
            int j = i - gap;  

            while(j >= 0 && array[j] > x)
            {    
                sComparisons++;
                array[j + gap] = array[j];
                sSwaps++;
                j -= gap;
            }

            if(j >= 0 && array[j] <= x)
            {
                sComparisons++;   
            }

            array[j + gap] = x;
            sComparisons++;
        }
        gap /= 2;
    }
    sCounter = sSwaps + sComparisons;
    return sCounter;
}
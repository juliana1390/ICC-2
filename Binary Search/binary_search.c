/*
Faça um programa em C que leia um número N(size1) de elementos de um vetor de inteiros array1,
e em seguida leia os N(size2) elementos de array2. Após isso, leia um número inteiro K,
seguido da leitura de K inteiros. O seu programa deverá busca todos os K números no vetor array1,
e escrever 1 se o elemento foi encontrado em array1 e 0 caso contrário.
*/

#include <stdio.h>
#include <stdlib.h>

// === METHODS ===
int *read(int size);
void merge(int array[], int l, int mid, int r);
void mergeSort(int array[], int l, int r);
int recursiveBinarySearch(int *array, int l, int r, int item);

// === MAIN ===
int main()
{
  int size1, size2;

  printf("Type the size of array1: ");
  scanf("%d", &size1);
  printf("\nType the elements of array1: ");
  int *array = read(size1);

  printf("\nType the size of array2: ");
  scanf("%d", &size2);
  printf("\nType the elements of array2: ");
  int *array2 = read(size2);

  mergeSort(array, 0, size1 - 1);

  for (int i = 0; i < size2; i++)
  {
    int result;
    result = recursiveBinarySearch(array, 0, size1 - 1, array2[i]);
    printf("\n%d", result);
  }

  free(array);
  free(array2);

  return 0;
}

// === READ ARRAY ===
int *read(int size)
{
  int *array = malloc(size * sizeof(int));

  if(array == NULL){
    printf("INSUFFICIENT MEMORY\n");
  }

  for (int i = 0; i < size; i++)
  {
    int x;
    scanf("%d", &x);
    array[i] = x;
  }
  return array;
}

// === MERGESORT ===
/*
Merges two sub-arrays of array[].
1st sub-array: array[l..mid]
2nd sub-array: array[mid + 1..r]
l = left, r = right
*/
void merge(int array[], int l, int mid, int r)
{
  int i, j, k;
  int n1 = mid - l + 1;
  int n2 = r - mid;

  /* creating temp arrays */
  int L[n1], R[n2];

/* Copying data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = array[l + i];
  for (j = 0; j < n2; j++)
    R[j] = array[mid + 1 + j];

  /* Merging the temp arrays back into array[l..r]*/
  i = 0; // Initial index of first sub-array
  j = 0; // Initial index of second sub-array
  k = l; // Initial index of merged sub-array

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copying the remaining elements of L[], in case there any */
  while (i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  /* Copying the remaining elements of R[], in case there any */
  while (j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }
}

/* l is for l index and r is r index of the
sub-array of array to be sorted */
void mergeSort(int array[], int l, int r)
{
  if (l < r)
  {
    int mid = l + (r - l) / 2; // This is the same as (l+r)/2, but avoids overflow for large l and h

    // Sort 1st and 2nd halves
    mergeSort(array, l, mid);
    mergeSort(array, mid + 1, r);

    merge(array, l, mid, r);
  }
}

// === BINARY SEARCH ===
int recursiveBinarySearch(int *array, int l, int r, int item)
{
  int mid = (l + r) / 2;
  if (l > r) /* Not found */
    return 0;

  if (array[mid] == item) /* Item found */
    return 1;

  if (array[mid] < item) /* Item is in sub-array at r */
    return recursiveBinarySearch(array, mid + 1, r, item);

  else /* array[mid] > item. Item is in sub-array at l */
    return recursiveBinarySearch(array, l, mid - 1, item);
}
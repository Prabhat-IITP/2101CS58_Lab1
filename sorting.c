#include <stdio.h> 
#include <math.h> 

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_index; 
    for (i = 0; i < n-1; i++) { 
        min_index = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_index]) 
            min_index = j; 
        swap(&arr[min_index], &arr[i]); 
    } 
} 

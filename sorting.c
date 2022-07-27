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

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j], &arr[j + 1]); 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i=0, j=0, k=l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 

void quickSort(int arr[],int first,int last){ 
   int i, j, pivot, temp; 
   if(first<last){ 
      pivot=first; 
      i=first; 
      j=last; 
      while(i<j){ 
         while(arr[i]<=arr[pivot]&&i<last) 
         i++; 
         while(arr[j]>arr[pivot]) 
         j--; 
         if(i<j){ 
            temp=arr[i]; 
            arr[i]=arr[j]; 
            arr[j]=temp; 
         } 
      } 
      temp=arr[pivot]; 
      arr[pivot]=arr[j]; 
      arr[j]=temp; 
      quickSort(arr,first,j-1); 
      quickSort(arr,j+1,last); 
   } 
} 

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() { 
    int n,m, arr[1000]; 
    printf("Enter size of array: "); 
    scanf("%d", &n); 
    printf("Enter the array: "); 
    for(int i= 0; i<n; ++i){ 
        scanf("%d", &arr[i]); 
    } 
    printf("1- Insertion Sort \n"); 
    printf("2- Selection Sort \n"); 
    printf("3- Bubble Sort \n"); 
    printf("4- Merge Sort \n"); 
    printf("5- Quick Sort \n"); 
    printf("Enter Sorting Method: "); 
    scanf("%d", &m); 
    switch(m) { 
        case 1: 
        insertionSort(arr, n); 
        printArray(arr,n); 
        break; 
        case 2: 
        selectionSort(arr, n); 
        printArray(arr, n); 
        break; 
        case 3: 
        bubbleSort(arr, n); 
        printArray(arr, n); 
        break; 
        case 4: 
        mergeSort(arr, 0, n-1); 
        printArray(arr, n); 
        break; 
        case 5: 
        quickSort(arr, 0, n-1); 
        printArray(arr, n); 
        break; 
        default: 
        printf("Please input a valid Sorting Method"); 
        break; 
    } 
return 0; 
} 
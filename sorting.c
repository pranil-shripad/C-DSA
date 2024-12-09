#include <stdio.h>

void printArray(int arr[], int size){
    for(int i=0, i<size; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int temp = arr[i];
        int j = i-1;
        while( j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[i] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main(){
    int i, choice, size;
    printf("Enter number of elements in array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter a choice for 1. Instertion Sort, 2. Selection Sort: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: insertionSort(arr,size);
                printf("sorted Array in ascending order: \n");
                printArray(arr,size);
                break;

        case 2: selectionSort(arr, size);
                printf("Sorted array in ascending order: \n");
                printArray(arr, size);
                break;
    }
    return 0;
}
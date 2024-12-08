#include <stdio.h>

int linearSearch(int arr[],int n, int key){
    int found = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            printf("key found at index: %d", i);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Key not found!");
}

int binarySearch(int arr[], int n, int key){
    int l = 0, r = n-1;
    while(l<r){
        int mid = (l+r)/2;

        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
    
}

int main(){
    int num, choice,key;
    printf("Enter size of array: ");
    scanf("%d", &num);

    int arr[num];
    for(int i=0; i<num; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter Key: ");
    scanf("%d", &key);
    
    printf("What do you want to perform?\n1. Linear Search, 2. Binary Search: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: linearSearch(arr,num,key);
                break;

        case 2: printf("Key found at index %d" ,binarySearch(arr, num, key));
                break;
    }
}
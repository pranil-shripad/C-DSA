#include <stdio.h>
#define SIZE 6

int top = -1;
int arr[SIZE];

void push(){
    int data;
    if (top >= SIZE - 1){
        printf("Stack Overflow!\n");
        return;
    }
    else{      
        printf("Enter Data: ");
        scanf("%d", &data);

        top = top + 1;
        arr[top] = data;

        printf("Data is pushed into the stack.\n");
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow!\n");
    }
    else{
        printf("Deleted data: %d\n", arr[top]);
        top = top - 1;
    }
}

void displayArray(){

    for (int i = SIZE; i >= 0; i--){

        printf("%d\n", arr[i]);
    }
}

int main(){
    push();
    push();
    push();
    push();
    push();
    push();
    displayArray();
    pop();
    pop();
    printf("Name: Pranil\n");
    printf("Roll no.: 36");

}
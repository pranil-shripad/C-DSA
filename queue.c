#include <stdio.h>

#define SIZE 5

int rear = -1;
int front = -1;
int queue[SIZE];


void enqueue(int data){
    if(rear == SIZE - 1){
        printf("Queue is full!");
        return;
    }else{
    rear++;
    queue[rear] = data;
    }
}

int dequeue(){
    if(rear == -1){
        printf("Queue is empty");
        return -1;
    }else{
    int front = queue[0];
    for(int i=0; i<rear; i++){
        queue[i] = queue[i+1];
    }
    rear--;
    return front;
    }
}

void printQueue(){
    if(rear == -1)
        printf("\nqueue is empty!");
    else{
        int i;
        
        for(i = front+1; i <= rear; i++)
	        printf("%d ",queue[i]);
   }
}

int main(){
    int data, dequeueSize;

    for(int i = 0; i<SIZE; i++){
        printf("Enter data: ");
        scanf("%d", &data);
        enqueue(data);
    }
    printf("\nQueue after Enqueuing: ");
    printQueue();

    printf("\nEnter number of elements to be dequeued: ");
    scanf("%d", &dequeueSize);

    for(int i=0; i<dequeueSize; i++){
        dequeue();
    }
    printf("\nQueue after dequeuing: ");
    printQueue();

    printf("Pranil Shripad | 36");

    return 0;
}
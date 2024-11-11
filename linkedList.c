#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int newData){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode -> data = newData;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        * head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp ->next = newNode;
    newNode -> prev = temp;
}

void deletePositon(struct Node** head, int position){
    if(*head == NULL){
        printf("The list is empty");
        return;
    }
    struct Node* temp = *head;
    for(int i = 0; temp != NULL && i < position; i++){
        temp = temp -> next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp -> prev;
    }
    if(temp ->prev != NULL){
        temp->prev->next = temp->next;
    }
    free(temp);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int n, data, pos;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    displayList(head);

    printf("Enter a position of node to be deleted: ");
    scanf("%d", &pos);
    deletePositon(&head,pos);
    printf("List After Deletion:\n");
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }


    return 0;
}

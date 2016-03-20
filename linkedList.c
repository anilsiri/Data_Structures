#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void reverse(struct node **head){
    struct node* current = *head;
    struct node* prev = NULL;
    
    
    while(current!=NULL){
        current->next=prev;
        prev=current;
        current=current->next;
        }
        *head=prev;
}



void printis(struct node **head){
    printf("starting to print \n");
    struct node* current;
    current = *head;
    
    while(current!=NULL){
        printf("data is %d\n", current->data);
        current = current->next;
        }
}


void push(struct node** head, int data){
    
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode-> data = data;
    newNode->next = *head;
    *head = newNode;
}

int main(){
    struct node* a = NULL;
    push(&a, 4);
    push(&a, 1);
    push(&a, 2);
    push(&a, 6);
   // push(&a, 0);
//    push(&a, 3);
   // printis(&a);
   reverse(&a);
   printis(&a);

    printf("finished\n");
    return 0;
}
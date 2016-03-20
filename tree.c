#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct queue{
    int rear, first, size;
    struct node* array;
};

struct queue* createQ(int size){
    struct queue* myqueue = (struct queue*) malloc(sizeof(struct node*));
    myqueue->size=size;
    myqueue->rear = size;
    myqueue->first = -1;
    myqueue->array = (struct node*) malloc(sizeof(int) * size);
    return myqueue;
}


void enqueue(struct node* ptr, struct queue* myqueue)
{
    myqueue->rear = (myqueue->rear + 1)% myqueue->size;
    myqueue->array[myqueue->rear] = ptr;
    myqueue->size = myqueue->size + 1;
    
}


struct node* dequeue(struct queue* myqueue) {
    struct node* ptr = array[myqueue->first]; 
    myqueue->first = (myqueue->first + 1)%queue->capacity
    myqueue->size = myqueue->size -1;
    return ptr;
}


struct node* create(int item) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


void levelfirst(struct node* ptr) {
    struct queue* myqueue = createQ(100);
    
    while(!ptr)
    {
    printf("data is %d", ptr->data);
        if(ptr->left != NULL)
        {
            enqueue(ptr->left, myqueue);
        }
        if(ptr->right != NULL) 
        {
            enqueue(ptr->right, myqueue);
        }
        ptr = dequeue(myqueue);
    }
}
int main(){
    struct node* root = create(1);
    struct node* first = create(2);
    struct node* second = create(3);
    struct node* third = create(4);
    struct node* fourth = create(5);
    
    root->left = first;
    root->right = second;
    first->right = third;
    first->left = fourth;
    return 1;

    levelfirst(root);
}



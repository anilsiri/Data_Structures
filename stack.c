#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct stack 
{ 
    int top;
    char* array;
    int capacity;
};

struct stack* createStack(){
    struct stack* stackptr = (struct stack*) malloc(sizeof(struct stack));
    stackptr->capacity = 10;
    stackptr->top=1;
    stackptr->array = (char*) malloc (sizeof(char) * 10);
    return stackptr;
}


bool isFull(struct stack* stackptr){
    if(stackptr->top == stackptr-> capacity)
    return true;
    else
    return false;
}

bool isEmpty(struct stack* stackptr){
    if(stackptr->top==-1)
    return true;
    else 
    return false;
}

void push(struct stack* stackptr, char item){
    if(stackptr->top==stackptr->capacity)
    return;
    stackptr->array[++stackptr->top]=item;
}

int peek(struct stack* structptr){
    return structptr->array[structptr->top];
}

int pop(struct stack* stackptr){
    int data;
    data = stackptr->array[stackptr->top];
    --stackptr->top;
    return data;
}


int prec(char op){
    
    switch (op)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
    
    
    bool isOperand(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    





void infixToPostfix(char* exp){
    
     struct stack* stackpointer = createStack();
     char newexp[20];
     int k, i;
     
     for(i=0, k=-1; exp[i]; i++ )
     {
         if(isOperand(exp[i])==1)
         newexp[++k]=exp[i];
     printf("%c", newexp[k]);
         else if(exp[i]=='(')
         push(stackpointer, '(');
         
        
        else if (exp[i]==')')
        {
        while(isEmpty(stackpointer)!=0 && peek(stackpointer) != '(')
        {
           i++;
        newexp[++k] = pop(stackpointer);
        printf("%c", newexp[k]);
        }
        char lastbracket  = pop(stackpointer);
        }
        
        else 
        {
            if(prec(exp[i]) > prec(peek(stackpointer)))
            {
                push(stackpointer, exp[i]);
            }
            else
            {
            while(prec(exp[i]) <= prec(peek(stackpointer)))
            exp[++k] = pop(stackpointer);
            printf("%c", newexp[k]);
            }    
        }
    
}


printf("the post fix string is %s", newexp);
}



int main(){
   
    infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");

    return 1;
}

----------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct stack 
{ 
    int top;
    char* array;
    int capacity;
};

struct stack* createStack(){
    struct stack* stackptr = (struct stack*) malloc(sizeof(struct stack));
    stackptr->capacity = 10;
    stackptr->top=1;
    stackptr->array = (char*) malloc (sizeof(char) * 10);
    return stackptr;
}


int isFull(struct stack* stackptr){
    if(stackptr->top == stackptr-> capacity)
    return 1;
    else
    return 0;
}

int isEmpty(struct stack* stackptr){
    if(stackptr->top==-1)
    return 1;
    else 
    return 0;
}

void push(struct stack* stackptr, char item){
    if(stackptr->top==stackptr->capacity)
    return;
    stackptr->array[++stackptr->top]=item;
}

int peek(struct stack* structptr){
    return structptr->array[structptr->top];
}

int pop(struct stack* stackptr){
    int data;
    data = stackptr->array[stackptr->top];
    --stackptr->top;
    return data;
}


int prec(char op){
    
    switch (op)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
    
    
    int isOperand(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    



void reverseString(char* mystring){
    struct stack* mystack = createStack();
    char newstring[10];
    
    int i=0;
    while(mystring!='\0') { 
        push(mystack, mystring[i]);
        i++;
    }
    
    while(isEmpty!=0){
        int k=0;
        newstring[k]=pop(mystack);
        printf("%c", newstring[k]);
        k++;
    }
    
    
}



int main(){
    char convert[] = "hiplease";
   printf("%s", convert);
    reverseString(convert);

    return 1;
}


----------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<stdlib.h>


using namespace std; 

class twostacks {
    int top1, top2;
    int* array;
    int size;
    
    public: 
    twostacks(int n)
    {
    size = n;
    top1 = -1;
    top2=n;
    array = new int[n];
    }
    

    
    void push1(int x)
    {
        if(((size - top2) - top1) < size)
        array[++top1] =x;
    }

void push2(int x){
        if(((size - top2) - top1) < size)
        array[--top2] =x;
    }
    
    void pop1(){
        top1--;
    }
        
        void pop2(){
            top2++;
        }
        
        int peek1() {
            return array[top1];
        }
        
        int peek2() {
            return array[top2];
        }
        
        
};



int main(){
    twostacks ts(10);
    ts.push1(1);
    ts.push1(3);
    ts.push1(7);
    ts.pop1();
    int data = ts.peek1();
    printf("last is %d", data);
    
 return 0;
}
-------------------------------------------------------------------------------------------------------------------

// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// A structure to represent a stack
struct StackNode
{
	char data;
	struct StackNode* next;
};

struct StackNode* newNode(char data)
{
	struct StackNode* stackNode =
			(struct StackNode*) malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode *root)
{
	return !root;
}

void push(struct StackNode** root, char data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%c pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	char popped = temp->data;
	free(temp);
    printf("popped from stack %c", popped);
	return popped;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

bool open(char ch){
    switch(ch) {
        case '{':
        case '[':
        case '(' :
        return true;
    }
    return false;
}

bool close(char ch){
    switch(ch) {
        case '}':
        case ']':
        case ')' :
        return true;
    }
    return false;
}



bool balance(){
    
    char str[] = "(";
    
    char ch;
    char comp;
    
    struct StackNode* root = NULL;
    
    int n = strlen(str);
    for(int i=0; i<= n; i++) {
        if(open(str[i]))
        push(&root, str[i]);
        
        else if(close(str[i]))
        {
            ch=str[i];
            if(ch == ']')
            {
                comp = peek(root);
                if(comp != '[')
                    return false;
                else
                pop(&root);
                    
            }
            else if (ch == ')')
            {
                comp = peek(root);
                if(comp != '(')
                     return false;
                else 
                pop(&root);
            }
    
            else if (ch == '}')
            {
                comp == peek(root);
                if(comp != '{')
                return false;
                else
                pop(&root);
            }
        }
        
        
    }
    if(isEmpty(root)!=true)
            return false;
            else 
            return true;
}




int main()
{
   bool yes =  balance();
   printf(yes ? "true" : "false");
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------






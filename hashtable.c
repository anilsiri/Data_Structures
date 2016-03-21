#include<stdio.h>
#include<stdlib.h>

int table[10];

void initialize(){
    for(int i=0; i< 10; i++) {
        table[i]=0;
    }
    
}

int hash(int item){
    int index;
    index = item % 10;
    return index;
}



void insert(int item) {
    int index = hash(item);
    table[index] = item;
}



void print () {
    for(int i=0; i<10; i++) {
        printf("%d\n", table[i]);
    }
}

int main(){
    initialize();
    insert(5);
   insert(1);
   insert(9);
    print();
return 0; 
    
}


#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // Include Data and Address
    int data;
    struct node *next;
} node;

node* makeNode(int x){ //Function makeNode
    node *newNode = (node*)malloc(sizeof(node)); // Khai báo ban đầu 
    newNode->data = x;              // Data
    newNode->next = NULL;           // Next -> NULL
    return newNode;
}
   


int main(){


    return 0;
}
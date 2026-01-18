#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
};

void duyet(node *head){             //Di chuyen con tro head
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next; 
    }
};

int count(node *head){ //HAM DEM SO NODE VA IN RA GIA TRI
    int dem = 0;
    while(head != NULL){
        ++dem;
        head = head-> next;
    }
    return dem;
};

void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head; // Địa chỉ của node Head  *head (Không phải là con trỏ head đôuu)
    *head = newNode;
}

int main(){
    node *head = NULL;
    for(int i = 1; i <= 5; i++){
        pushFront(&head,i);
    }
    duyet(head);
    printf("%d", count(head));

     return 0;
}
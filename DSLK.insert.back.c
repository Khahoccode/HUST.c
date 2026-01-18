#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node* makeNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
};

void duyet(node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
};

void pushBack(node **head, int x){
    node *tmp = *head;
    node *newNode = makeNode(x);
    if(*head == NULL){ // Nếu danh sách trống, cho head = newNode luôn!!
        *head = newNode; 
        return;
    }

    while(tmp->next != NULL){ //Thuật toán duyệt đến cuối danh sách
        tmp = tmp->next;
    }
    tmp->next = newNode; // Nối tay node cuối cùng vào newNode
};

int main(){
    node *head = NULL;
    for(int i = 1; i < 5; i++){
        pushBack(&head,i);
    }
    duyet(head);
    return 0;
}
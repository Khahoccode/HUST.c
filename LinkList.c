#include <stdio.h>
#include <stdlib.h> // Cho phep su dung con tro

// Bài toán: Game xếp hạng từ thấp đến cao, với Node số  6 mới nhất vào thứ tự [2] -> [5] -> [8] -> NULL
// thành [2] -> [5] -> [6] -> [8]

typedef struct node{
    int data;
    struct node *next;
    } node;

    node *head = NULL;

    // --- HÀM CHÈN NODE (Logic của bạn nằm ở đây) ---
void insertNode(int value) {
    node *cur = NULL;
     // 1. Tạo Node mới.
   node *newNode = (node*)malloc(sizeof(node));
   newNode->data = value;
   newNode->next = NULL;

    //1.1 Kiểm tra giá trị của head
     if(head == NULL || newNode->data < head->data){                  // Khi danh sách trống   
        newNode->next = head;
        head = newNode;
    } else{
        cur = head;
    // 3. Vòng lặp tìm vị trí
    while((cur->next != NULL && cur->next->data < newNode->data)){
        cur = cur->next;
    }
        newNode->next = cur-> next;
        cur->next = newNode;
        };
    };


int main(){
    // Thử chèn các số lộn xộn để xem nó có tự sắp xếp không
    // Mong đợi: 1 -> 5 -> 6 -> 10 -> NULL
    printf("Dang chen so 5...\n");
    insertNode(5);
    
    printf("Dang chen so 10...\n");
    insertNode(10);
    
    printf("Dang chen so 1 (nho nhat)...\n");
    insertNode(1); 
    
    printf("Dang chen so 6 (o giua)...\n");
    insertNode(6);

       // --- In kết quả ---
    printf("\n=== DANH SACH CUOI CUNG ===\n");
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
    }
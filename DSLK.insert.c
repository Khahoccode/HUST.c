#include <stdio.h>
#include <stdlib.h>

// struct node{
//     int data;
//     struct node *next;
// };

// typedef struct node node;

typedef struct SinhVien{
    char name[100];
    char lop[100];
    double GPA;
} SinhVien;

struct node{
    SinhVien data;
    struct node *next;
};



int main(){

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a; //Lưu giá trị của con trỏ a vào biến tmp
    *a = *b;      // Lưu giá trị của con trỏ b cho con trỏ a
    *b = tmp;   // Lưu trở lại giá trị của tmp cho con trỏ b
}

int main(){
    int x = 1000, y = 2000;
    swap(&x,&y);
    printf("x = %d \ny = %d", x,y);

    return 0;
}
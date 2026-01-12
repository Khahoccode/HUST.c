#include <stdio.h>
int main(){
    float a;
    char kitu = 'k';
    printf("Nhap vao gia tri cua a: ");
    scanf("%f",&a);
    printf("Gia tri cua a: %.2f la ngay sinh cua %c", a, kitu);
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void tang1(int a){
    a += 100;
}

void tang2(int *a){
    *a += 100;
}

int main(){
    int a;
    printf("a = ");
    scanf("%d", &a);
    tang1(a);
        printf("Gia tri cua bien a sau khi ham tang 1 ket thuc : %d\n", a);
    tang2(&a);
        printf("Gia tri cua bien a sau khi ham tang 2 ket thuc : %d\n", a);
    return 0;
}
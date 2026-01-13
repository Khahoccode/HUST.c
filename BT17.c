#include <stdio.h>
#include <math.h>

int main(){
    int a = 300;
    int *ptr;
    ptr = &a;
    printf("%d\n", a);
    printf("Gia tri cua con tro ptr: %d", ptr);
    printf("%d\n", *ptr);

    return 0;
}
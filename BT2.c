#include <stdio.h>
#include <math.h>

int main(){
    char kitu;
    scanf("%c", &kitu);
    if((kitu >= 'a') && (kitu <= 'z')){
        printf("Chu in thuong");
    } else {
        printf("Khong phai chu in thuong");
    }
    return 0;
}
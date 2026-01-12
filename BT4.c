#include <stdio.h>
#include <math.h>
int main(){
    char kitu;
    scanf("%c", &kitu);
    if((kitu >= 'a') && (kitu <= 'z') || (kitu >= 'A') && (kitu <= 'Z')){
        printf("Day la chu cai");
    } else {
        printf("Day khong phai la chu cai");
    }
    return 0;
}
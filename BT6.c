#include <stdio.h>
#include <math.h>
int main(){
    char kitu;
    scanf("%c", &kitu);
    if(kitu >= 'a' && kitu <= 'z'){
        kitu -= 32;
        printf("%c", kitu);
    } else {
        printf("%c", kitu);
    }
    return 0;
}

// Chương trình chuyển chữ cái in thường thành chữ cái in hoa
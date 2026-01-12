#include <stdio.h>
#include <math.h>
int main(){
    char kitu;
    scanf("%c", &kitu);
    if(kitu >= 'A' && kitu <= 'Z'){
        kitu +=32;
        printf("%c", kitu);
    } else {
        printf("%c", kitu);
    }
    return 0;
}

// Chương trình chuyển tchữ cái in hoa thành chữ cái in thường
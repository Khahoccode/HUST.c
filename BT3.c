#include <stdio.h>
#include <math.h>
int main(){
    char kitu;
    scanf("%c", &kitu);
    if((kitu <= '9') && (kitu >= '1')){
        printf("Day la so");
    } else {
        printf("Day khong phai la so");
    }
    return 0;
}

// Char chỉ so sánh nhận chữ số đầu tiên, ví dụ "1a" kết quả sẽ sai, vì chtrình nhận 1 là chữ số và bỏ qua a luôn 

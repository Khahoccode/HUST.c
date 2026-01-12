#include <stdio.h>
#include <math.h>

int main (){
    int n;
    scanf("%d", &n);
    switch(n){
        case 1:
            printf("31");
            break;
        case 2:
            printf("29");
            break;
        case 3:
            printf("31");
            break;
        case 4: 
            printf("30");
            break;
        
        case 5:
            printf("31");
            break;
        case 6:
            printf("30");
            break;

        default: 
            printf("Du lieu nhap vo khong hop le!");
            break;
    }
    return 0;
}
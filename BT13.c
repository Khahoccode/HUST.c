#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);

    int a[n];
    

    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
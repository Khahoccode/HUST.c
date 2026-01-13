#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    int *ptr = (int*)malloc(10000*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}
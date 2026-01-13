#include <stdio.h>
#include <math.h>
int main(){
    int n, m;
    printf("n = "); scanf("%d", &n);
    printf("m = "); scanf("%d", &m);

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("a[%d][%d] = ", i,j);
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d " , a[i][j]);
        }
    }
    return 0;
}
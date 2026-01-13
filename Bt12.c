#include <stdio.h>
#include <math.h>

void solve(int n){
    long long fibo[n];
    fibo[0] = 0; 
    fibo[1] = 1;
    for(int i = 2; i <n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    for(int i = 0; i<n; i++){
        printf("%lld", fibo[i]);
    }
}


int main(){
    int t;
    t = 1;
    while(t--){
        int n;
        scanf("%d", &n);
        solve(n);
    }
}
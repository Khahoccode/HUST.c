#include <stdio.h>
#include <math.h>

int sumDigit(long long n){
    int sum = 0;
    while (n != 0){
        sum += n%10;
        n/=10;
    }
    return sum;
};

int main(){
    int t; 
    scanf ("%d", &t); 
    while(t--){ 
        long long n;
        scanf ("%lld" , &n);
        printf("%d\n", sumDigit(n));
    }
}
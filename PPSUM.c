#include<stdio.h>
 
 
long long int sum(long long int n){
    return (n*(n+1))/2;
}
 
long long int answer(long long int D, long long int N){
    long long int i;
    long long int previousAns = sum(N);
    long long int ans = previousAns;
    for(i=1;i<D;i++){
        ans = sum(previousAns);
        previousAns = ans;
    }
    return ans;
}
 
int main(){
    
    int tc,T;
    scanf("%d",&T);
    for(tc=0;tc<T;tc++){
        long long int D, N;
        scanf("%lld%lld",&D,&N);
        printf("%lld\n",answer(D, N));
    }
    
    return 0;
} 

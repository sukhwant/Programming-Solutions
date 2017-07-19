#include<stdio.h>
#define N_MAX 100000

long long int sum[N_MAX];

void precompute(){
    int i;
    sum[0]=0;
    for(i=1;i<N_MAX;i++){
        sum[i]=sum[i-1]+i;
    }
}

long long int search(long long int n){
    int start=0,end=N_MAX-1;
    int mid;
    while(1){
        mid = (start+end)/2;
        if(sum[mid] == n){
            return mid;
        }else if(sum[mid]< n && sum[mid+1]>n){
            return mid;
        }else if(sum[mid]>n){
            end=mid;
        } else if(sum[mid]<n){
            start=mid;
        }
    }
    return -1;
}

int main(){
    
    precompute();
    int tc,T;
    scanf("%d",&T);
    for(tc=0;tc<T;tc++){
        long long int n,i, height;
        scanf("%lld", &n);
        height = search(n);
        printf("%lld\n",height);
    }
    
    return 0;
}

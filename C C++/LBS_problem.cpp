#include <iostream>
#define INF 2100000000
//Longest Bitonic Subsequence
//ref:
//https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
//LIS_problem.cpp
int MAX(int arg1,int arg2){
    return arg1 > arg2?arg1:arg2;
}
int main(int argc, char const *argv[]){
    int n,ans = -1;
    scanf("%d",&n);
    int arr[n],lis[n],lds[n];
    for(int i = 0;i < n;i++){
        scanf("%d",(arr + i));
        lis[i] = lds[i] = 1;
    }
    for(int i = 1;i < n;i++)
        for(int j = 0;j < i;j++){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)//i:1->n-1,j:0->i
                lis[i] = lis[j] + 1;
            if(arr[n - 1 - i] > arr[n - 1 - j] && lds[n - 1 - i] < lds[n - 1 - j] + 1)//i:n-2->0,j:n-1->i
                lds[n - 1 - i] = lds[n - 1 - j] + 1;
        }
    for(int i = 0;i < n;i++)
        ans = MAX(ans,lis[i] + lds[i] - 1);
    printf("%d\n",ans);
    return 0;
}

#include <iostream>
#define INF 2100000000
//Longest Increasing Subsequence
//ref:
//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
//https://nctuitsc-my.sharepoint.com/personal/mzshieh_o365_nctu_edu_tw/_layouts/15/Doc.aspx?sourcedoc={b32aeb14-18c9-4516-9b5f-ef9dfd141b8b}&action=view&wd=target%28Dynamic%20Programming.one%7C17c47b55-2317-4fb1-a1fa-3e6e211781d2%2FLongest%20Increasing%20Subsequence%7C7fb447bf-e65f-460f-be02-ec67f0209cf2%2F%29
//    NCTU 107_2 CP 903.cpp
int MAX(int arg1,int arg2){
    return arg1 > arg2?arg1:arg2;
}
int main(int argc, char const *argv[]){
    int n,ans = -1;
    scanf("%d",&n);
    int arr[n],dp[n];
    for(int i = 0;i < n;i++){
        scanf("%d",(arr + i));
        dp[i] = INF;
    }
    dp[0] = arr[0];
    for(int i = 1;i < n;i++){
        int l = 0,r = n - 1,mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(arr[i] < dp[mid])
                r = mid;
            else
                l = mid + 1;
        }
        dp[l] = arr[i];
        ans = MAX(ans,l);
    }

    printf("%d\n",ans + 1);
    return 0;
}

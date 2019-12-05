#include <iostream>
#include <algorithm>

int ans;
int arr[10000];
void partINT(int rem,int max_part,int len){
    /*
    //print all partion
    if(!rem){
        ans++;
        for(int i = 0;i < len;i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    if(max_part == 1){
        ans++;
        for(int i = 0;i < len;i++)
            printf("%d ",arr[i]);
        while(rem--)
            printf("1 ");
        printf("\n");
        return;
    }
    */
    //only count
    if(max_part == 1 || (!rem)){
        ans++;
        return;
    }
    for(int i = std::min(max_part,rem);i >= 1;i--){
        arr[len] = i;
        partINT(rem - i,i,len + 1);
    }
}
int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    ans = 0;
    partINT(n,n,0);
    printf("ANS: %d\n",ans);
}

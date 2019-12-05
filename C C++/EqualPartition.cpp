#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<long long int>& v1,std::vector<long long int>& v2){
    if(v1.size() < v2.size())
        return true;
    else if(v1.size() > v2.size())
        return false;
    return v1 < v2;
}
std::vector<std::vector<long long int> > v;
long long int arr[30],n;
bool findAns(int pos,int tar,std::vector<long long int> subset){
    if(!tar){
        v.push_back(subset);
        return true;
    }
    if(pos >= n)
        return false;
    bool b = findAns(pos + 1,tar,subset);
    subset.push_back(arr[pos]);
    return findAns(pos + 1,tar - arr[pos],subset) || b;
}
int main(int argc,char* const argv[]){
    char c;
    while(scanf("%c",&c) == 1){
        if(c == '.')
            break;
        if(c != '{')
            continue;
        long long int num,total = 0;
        n = 0;
        v.clear();
        while(scanf("%lld",&num) == 1){
            arr[n++] = num;
            total += num;
        }
        if(total & 1){
            printf("No such subset\n\n");
            continue;
        }
        total >>= 1;
        std::vector<long long int> sub;
        if(findAns(0,total,sub)){
            printf("%d subsets\n",v.size());
            std::sort(v.begin(),v.end(),compare);
            for(int i = 0;i < v.size();i++){
                printf("{%lld",v[i][0]);
                for(int j = 1;j < v[i].size();j++)
                    printf(" %lld",v[i][j]);
                printf("}\n");
            }
        }
        else
            printf("No such subset\n");
        printf("\n");
    }
    return 0;
}
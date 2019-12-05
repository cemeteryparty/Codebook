#include <iostream>

int group[10001];
int FindGroup(int key){
    while(key != group[key])
        key = group[key];
    return key;
}
void UNION(int key1,int key2){
    if(key1 < key2)
        group[key2] = key1;
    else 
        group[key1] = key2;
}
int main(int argc, char const *argv[]){
    int n,m,q,a,b;
    scanf("%d%d%d",&n,&m,&q);
    for(int gi = 1;gi <= n;gi++)
        group[gi] = gi;
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        a = FindGroup(a);
        b = FindGroup(b);
        UNION(a,b);
    }
	for(int i = 0;i < q;i++){
		scanf("%d%d",&a,&b);
        if(FindGroup(a) != FindGroup(b))
            printf("Different group\n");
        else
			printf("Same group\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
	int t = 0;
	while(scanf("%d",&t) == 1){
		int ti = 1;
		while(t--){
			int n = 0,k = 0,ans = 0;
			scanf("%d%d",&n,&k);
			for(int i = 1;i <= n;i++)
				ans = (ans + k) % i;
			printf("Case %d: %d\n",ti,ans + 1);
			ti++;
		}
	}
	return 0;
}

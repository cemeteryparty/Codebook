#include <iostream>

long long int f[5000][100] = {0};
int main(int argc, char const *argv[]){
	f[0][0] = 1;
	f[1][0] = 1;
	for(int i = 2;i < 5000;i++)
		for(int j = 0;j < 100;j++){
			f[i][j] += (f[i - 1][j] + f[i - 2][j]);
			if(!f[i][j])
				break;
			if(f[i][j] > 100000000000000000){
				f[i][j + 1] += (f[i][j] / 100000000000000000);
				f[i][j] %= 100000000000000000;
			}
		}
	int n;
	while(scanf("%d",&n) == 1){
		printf("The Fibonacci number for %d is ",n);
		int i = 99;
		for(i = 99;i >= 0;i--)
			if(f[n - 1][i])
				break;
		printf("%lld",f[n - 1][i]);
		for(int j = i - 1;j >= 0;j--)
			printf("%.17lld",f[n - 1][j]);
		printf("\n");
	}
	return 0;
}

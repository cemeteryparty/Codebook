#include <iostream>
#include <vector>
#define INF 2147483647
//6.4.3 All-Pairs Shortest Paths p367
//Floyd-Warshall algorithm
int main(int argc,char const *argv[]){
	int n,m;//n verteies m edge
	scanf("%d%d",&n,&m);
	int dis[n][n];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			if(i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}
	for(int i = 0;i < m;i++){
		int p1,p2,Cost;
		scanf("%d%d%d",&p1,&p2,&Cost);
		dis[p1][p2] = Cost;
	}
	for(int mid = 0;mid < n;mid++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(dis[i][mid] + dis[mid][j] < dis[i][j])
					dis[i][j] = dis[i][mid] + dis[mid][j];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			if(dis[i][j] == INF)
				printf("No path from %d to %d\n",i,j);
			else
				printf("Min cost from %d to %d = %d\n",i,j,dis[i][j]);
		}
	return 0;
}

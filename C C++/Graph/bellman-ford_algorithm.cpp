#include <iostream>
#include <vector>
#define INF 2147483647
//6.4.2 Single Source/All Destination: General Weights p367
//Bellman-Ford algorithm
//no negative cycle
class Edge{//no head,with direction
	public:
		int end;
		int cost;
		Edge(int b,int value){
			end = b;
			cost = value;
		};
		~Edge(){};
};
int main(int argc,char const *argv[]){
	int n,m;//n verteies m edge
	scanf("%d%d",&n,&m);
	std::vector<Edge> adj_list[n];//adjacency lists
	for(int i = 0;i < m;i++){
		int p1,p2,cost;
		scanf("%d%d%d",&p1,&p2,&cost);
		adj_list[p1].push_back(Edge(p2,cost));//p1--->p2 with cost
	}
	printf("set the begin:");
	int begin;//0 ~ n - 1
	scanf("%d",&begin);//from begin to all destination 
	int dis[n];
	//initialize
	for(int i = 0;i < n;i++)
		dis[i] = INF;
	dis[begin] = 0;
	for(int t = 0;t < n - 1;t++){
		bool conti = false;
		for(int i = 0;i < n;i++)
			for(int vi = 0;vi < adj_list[i].size() && dis[i] != INF;vi++)
				if(dis[i] + adj_list[i][vi].cost < dis[adj_list[i][vi].end]){
					dis[adj_list[i][vi].end] = dis[i] + adj_list[i][vi].cost;
					conti = true;
				}
		if(!conti)
			break;
	}
	for(int i = 0;i < n;i++){
		if(dis[i] == INF)
			printf("No path from %d to %d\n",begin,i);
		else
			printf("Min cost from %d to %d = %d\n",begin,i,dis[i]);
	}
	return 0;
}

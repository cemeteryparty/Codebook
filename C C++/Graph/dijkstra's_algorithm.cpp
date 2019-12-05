#include <iostream>
#include <vector>
//6.4.1 Single Source/All Destinations: Nonnegative Edge Costs p360
//Dijkstra's algorithm
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
	printf("set the begin");
	int begin;//0 ~ n - 1
	scanf("%d",&begin);//from begin to all destination 
	int dis[n];
	bool getAns[n];
	//initialize
	for(int i = 0;i < n;i++){
		dis[i] = 2147483647;
		getAns[i] = false;
	}
	dis[begin] = 0;
	getAns[begin] = true;

	int select = begin;
	while(select >= 0){
		for(int i = 0;i < adj_list[select].size();i++)
			if(adj_list[select][i].cost + dis[select] < dis[adj_list[select][i].end])
				dis[adj_list[select][i].end] = adj_list[select][i].cost + dis[select];
		int mindis = 2147483647;
		select = -1;
		for(int i = 0;i < n;i++)
			if(!(getAns[i]) && dis[i] < mindis){
				mindis = dis[i];
				select = i;
			}
		if(select >= 0)
			getAns[select] = true;	
	}
	for(int i = 0;i < n;i++){
		if(dis[i] == INF)
			printf("No path from %d to %d\n",begin,i);
		else
			printf("Min cost from %d to %d = %d\n",begin,i,dis[i]);
	}
	return 0;
}

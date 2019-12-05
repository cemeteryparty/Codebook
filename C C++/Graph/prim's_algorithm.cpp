#include <iostream>
#include <vector>
//6.3.2 Prim's algorithm p357
class Edge{//no head
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
	int dis[n];//distance between vertex to MST
	bool inMST[n];//is vertex in MST
	for(int i = 0;i < m;i++){
		int p1,p2,cost;
		scanf("%d%d%d",&p1,&p2,&cost);
		adj_list[p1].push_back(Edge(p2,cost));
		adj_list[p2].push_back(Edge(p1,cost));
	}
	//initialize
	for(int i = 0;i < n;i++){
		dis[i] = 2147483647;
		inMST[i] = false;
	}
	
	//put vertex 0 in MST,see it as root
	dis[0] = 0;
	inMST[0] = true;

	int min_cost = 0,edge_count = 0,newVertex = 0;
	while(newVertex >= 0){
		for(int i = 0;i < adj_list[newVertex].size();i++)
			if(adj_list[newVertex][i].cost < dis[adj_list[newVertex][i].end])
				dis[adj_list[newVertex][i].end] = adj_list[newVertex][i].cost;
		int mindis = 2147483647;
		newVertex = -1;
		for(int i = 0;i < n;i++)
			if(!(inMST[i]) && dis[i] < mindis){
				mindis = dis[i];
				newVertex = i;
			}
		if(newVertex >= 0){
			inMST[newVertex] = true;
			dis[newVertex] = 0;
			min_cost += mindis;
			edge_count++;
			printf("Connect %d with cost = %d\n",newVertex,mindis);
		}
	}
	if(edge_count < n - 1)
		printf("No spanning tree\n");
	else
		printf("Get min-cost spanning tree with cost = %d\n",min_cost);
	return 0;
}

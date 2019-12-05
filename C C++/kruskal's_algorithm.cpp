#include <iostream>
#include <algorithm>
//6.3.1 Kruskal's algorithm p353
class Edge{
	public:
		int begin;
		int end;
		int cost;
		Edge(){};
		~Edge(){};
		void setValue(int a,int b,int value){
			begin = a;
			end = b;
			cost = value;
		}
		friend bool operator<(Edge e1, Edge e2){
			return e1.cost < e2.cost;
		}
};
class DisjointSet{
	public:
		int size;
		int *set;
		DisjointSet(int SIZE){
			size = SIZE;
			set = new int [size];
			for(int i = 0;i < size;i++)
				set[i] = i;//initialize
		}
		~DisjointSet(){
			delete [] set;
		}
		void Union(int key1,int key2){
			if(key1 < key2)
        		set[key2] = key1;
    		else 
       			set[key1] = key2;
		}
		int Find(int key){
			while(key != set[key])
        		key = set[key];
    		return key;
		}
};
int main(int argc,char const *argv[]){
	int n,m;//n verteies m edge
	scanf("%d%d",&n,&m);
	DisjointSet set(n);
	Edge e[m];
	for(int i = 0;i < m;i++){
		int p1,p2,cost;
		scanf("%d%d%d",&p1,&p2,&cost);
		e[i].setValue(p1,p2,cost);
	}
	std::sort(e,e + m);
	int min_cost = 0,edge_count = 0;
	for(int i = 0;i < m;i++){
		int key1 = set.Find(e[i].begin),key2 = set.Find(e[i].end);
		if(key1 == key2)
			continue;
		set.Union(key1,key2);
		printf("Add new edge : (%d <-> %d) = %d\n",e[i].begin,e[i].end,e[i].cost);
		edge_count++;
		min_cost += e[i].cost;
	}
	if(edge_count < n - 1)
		printf("No spanning tree\n");
	else
		printf("Get min-cost spanning tree with cost = %d\n",min_cost);
	return 0;
}
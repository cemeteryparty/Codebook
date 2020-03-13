#include <iostream>
#include <vector>

class DisjointSet{
public:
	std::vector<int> group;
	DisjointSet(){
		group.push_back(0);
	}
	int Search(int key){
		while(group[key] != key)
			key = group[key];
		return key;
	}
	void UNION(int key1,int key2){
		if(key1 < key2)
			group[key2] = key1;
		else 
			group[key1] = key2;
	}
};
int main(int argc, char const *argv[]){
	int n,m,q,a,b;
	scanf("%d%d%d",&n,&m,&q);
	DisjointSet d;
	for(int gi = 1;gi <= n;gi++)
		d.group.push_back(gi);
	for(int i = 0;i < m;i++){
		scanf("%d%d",&a,&b);
		a = d.Search(a);
		b = d.Search(b);
		if(a != b)
		d.UNION(a,b);
	}
	for(int i = 0;i < q;i++){
		scanf("%d%d",&a,&b);
		printf(d.Search(a) != d.Search(b)?"Different group\n":"Same group\n");
	}
	return 0;
}

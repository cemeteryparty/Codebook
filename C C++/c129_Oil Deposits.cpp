#include <iostream>
#include <queue>
//bfs
class Dot{
	public:
		int x;
		int y;
		Dot(){};
		Dot(int _x,int _y){
			x = _x;
			y = _y;
		}
		~Dot(){};
};
int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {-1,1,-1,0,1,-1,0,1};
int main(int argc,char const *argv[]){
	int m,n;
	while(scanf("%d%d",&m,&n) == 2){
		if(!(m | n))
			break;
		Dot v[m * n];
		char map[m][n];
		int v_size = 0;
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j] == '@'){
					Dot mark(i,j);
					v[v_size++] = mark;
				}
				if(map[i][j] == '\n')
					j--;
			}
		int ans = 0;
		for(int vi = 0;vi < v_size;vi++)
			if(map[v[vi].x][v[vi].y] == '@'){
				map[v[vi].x][v[vi].y] = '#';
				ans++;
				Dot p(v[vi].x,v[vi].y);
				std::queue<Dot> q;
				q.push(p);
				while(!q.empty()){
					int fx = q.front().x,fy = q.front().y;
					q.pop();
					for(int i = 0;i < 8;i++)
						if(fx + dx[i] >= 0 && fx + dx[i] < m && fy + dy[i] >= 0 && fy + dy[i] < n && map[fx + dx[i]][fy + dy[i]]=='@'){
							p.x = fx + dx[i];
							p.y = fy + dy[i];
							map[p.x][p.y] = '#'; 
							q.push(p);
						}
					
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
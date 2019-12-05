#include <iostream>
#include <vector>

struct Dot{
	int x;
	int y;
};
char map[101][101];
int x_border,y_border;
void travel(int x,int y){
	if(x < 0 || y < 0 || x >= x_border || y >= y_border || map[x][y] != '@')
		return;
	map[x][y] = '#';
	travel(x - 1,y - 1);
	travel(x - 1,y);
	travel(x - 1,y + 1);
	travel(x,y - 1);
	travel(x,y + 1);
	travel(x + 1,y - 1);
	travel(x + 1,y);
	travel(x + 1,y + 1);	
}
int main(int argc,char const *argv[]){
	int m,n;
	while(scanf("%d%d",&m,&n) == 2){
		if(!(m | n))
			break;
		x_border = m;
		y_border = n;
		std::vector<Dot> v;
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j] == '@'){
					Dot mark;
					mark.x = i;
					mark.y = j;
					v.push_back(mark);
				}
				if(map[i][j] == '\n')
					j--;
			}
		int ans = 0;
		for(int vi = 0;vi < v.size();vi++)
			if(map[v[vi].x][v[vi].y] == '@'){
				ans++;
				travel(v[vi].x,v[vi].y);
			}
		printf("%d\n",ans);
	}
	return 0;
}
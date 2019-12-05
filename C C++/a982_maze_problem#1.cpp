#include <iostream>
#include <queue>
//a982 maze shortest path bfs
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(int argc,char const *argv[]){
	int n;
	while(scanf("%d",&n) == 1){
		char map[n * n];
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++){
				scanf("%c",(map + (n * i + j)));
				if(map[n * i + j] == '\n')
					j--;
			}
		int ans = -1;
		std::queue<int> q;
		std::queue<int> step;
		q.push(n + 1);
		step.push(1);
		while(!q.empty() && ans == -1){
			int fx = q.front() / n,fy = q.front() % n,fstep = step.front();
			q.pop();
			step.pop();
			for(int i = 0;i < 4;i++)
				if(fx + dx[i] >= 0 && fx + dx[i] < n && fy + dy[i] >= 0 && fy + dy[i] < n && map[(fx + dx[i]) * n + fy + dy[i]] == '.'){
					if(n * (fx + dx[i]) + fy + dy[i] == (n - 2) * (n + 1)){
						ans = fstep + 1;
						break;
					}
					map[n * (fx + dx[i]) + fy + dy[i]] = '#'; 
					q.push(n * (fx + dx[i]) + fy + dy[i]);
					step.push(fstep + 1);
				}			
		}
		printf((ans == -1)?"No solution!\n":"%d\n",ans);
	}
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

int pennies[101][101];
int total[101][101];
queue<Point> q;
int x_move[4] = {0,1,0,-1};
int y_move[4] = {1,0,-1,0};

int BFS(int sz, int step){
	int ans = 0;
	while(!q.empty()){
		Point cur = q.front();
		q.pop();
		if(ans < total[cur.x][cur.y])
			ans = total[cur.x][cur.y];
		for(int d=0; d<4; d++){
			for(int s=1; s<=step; s++){
				int mi = cur.x + x_move[d]*s;
				int mj = cur.y + y_move[d]*s;
				if((mi >= 0 && mi < sz) && (mj >= 0 && mj < sz) && pennies[mi][mj] > pennies[cur.x][cur.y]){
					if(total[mi][mj] < total[cur.x][cur.y] + pennies[mi][mj]){
						total[mi][mj] = total[cur.x][cur.y] + pennies[mi][mj];
						Point pos;
						pos.x = mi; pos.y = mj;
						q.push(pos);
						if(ans < total[mi][mj])
							ans = total[mi][mj];
					}
				}
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int T;
	int n, k;
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				total[i][j] = 0;
				cin >> pennies[i][j];
			}
		}
		total[0][0] = pennies[0][0];
		Point tmp;
		tmp.x = 0; tmp.y = 0;
		q.push(tmp);
		cout << BFS(n, k) << endl;
		if(T) cout << endl;
	}
	return 0;
}
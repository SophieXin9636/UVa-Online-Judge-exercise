#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX 100000

int node[102][102];

int main(){
	int n, r;
	int cnt = 1;
	int c1, c2, p;

	while(cin >> n >> r){
		if(n == 0 && r == 0) break;

		for(int i=0; i<102; i++){
			for(int j=0; j<102; j++){
				node[i][j] = 0;
			}
		}

		while(r--){	
			cin >> c1 >> c2;
			cin >> node[c1][c2];
			node[c2][c1] = node[c1][c2];
		}

		// Floyed-Warshall algo
		for(int k = 1; k<n+1; k++){
			for(int i=1; i<n+1; i++){
				for(int j=1; j<n+1; j++){
					//if(node[i][j] < node[i][k] && node[i][j] < node[k][j])
					//	node[i][j] = min(node[i][k], node[k][j]);
					node[i][j] = max(node[i][j], min(node[i][k], node[k][j]));
				}
			}
		}

		cin >> c1 >> c2 >> p;
		int ans = p / (node[c1][c2]-1);
		if(p % (node[c1][c2]-1) != 0) ans++;

		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", cnt++, ans);
	}

	return 0;
}
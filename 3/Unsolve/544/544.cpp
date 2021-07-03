#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int node[202][202];
std::map<string, int> m;

int main(){
	int n, r, p;
	int cnt = 1;
	string c1, c2;

	while(cin >> n >> r){
		if(n == 0 && r == 0) break;

		for(int i=0; i<202; i++){
			for(int j=0; j<202; j++){
				node[i][j] = 0;
			}
		}
		m.clear();
		int c = 0;
		while(r--){	
			cin >> c1 >> c2;
			if(m.find(c1) == m.end()) m[c1] = c++;
			if(m.find(c2) == m.end()) m[c2] = c++;
			cin >> node[m[c1]][m[c2]];
			node[m[c2]][m[c1]] = node[m[c1]][m[c2]];
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

		cin >> c1 >> c2;
		printf("Scenario #%d\n%d tons\n\n", cnt++, node[m[c1]][m[c2]]);
	}

	return 0;
}
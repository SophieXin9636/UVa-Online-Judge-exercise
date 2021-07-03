#include <iostream>
#define inf 9999
using namespace std;

int main(){
	int t, n, r, u, v, s, d;
	cin >> t;
	int e[101][101];

	for(int c=1; c<=t; c++){
		// initialization
		for(int i=0; i<101; i++)
			for(int j=0; j<101; j++){
				if(i == j) e[i][j] = 0;
				else e[i][j] = inf;
			}

		cin >> n >> r;
		for(int i=0; i<r; i++){
			cin >> u >> v;
			e[u][v] = e[v][u] = 1;
		}
		cin >> s >> d;

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(e[i][j] > e[i][k] + e[k][j])
						e[i][j] = e[i][k] + e[k][j];

		int maximum = 0;
		for(int k=0; k<n; k++)
			if(maximum < e[s][k] + e[k][d])
					maximum = e[s][k] + e[k][d];

		cout << "Case " << c <<": " << maximum << endl;
	}
	return 0;
}
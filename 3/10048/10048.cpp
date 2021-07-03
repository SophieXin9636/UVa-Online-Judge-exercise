#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX 10000

int noise[102][102];

int main(){
	int c, s, q;
	int cnt = 1;

	while(cin >> c >> s >> q){
		if(c == 0 && s == 0 && q == 0) break;
		if(cnt != 1) printf("\n");

		for(int i=0; i<102; i++){
			for(int j=0; j<102; j++){
				noise[i][j] = 0;
			}
		}

		for(int i=0; i<c+1; i++){
			for(int j=0; j<c+1; j++){
				noise[i][j] = MAX;
			}
		}

		while(s--){
			int c1, c2;
			cin >> c1 >> c2;
			cin >> noise[c1][c2];
			noise[c2][c1] = noise[c1][c2];
		}

		// Floyed-Warshall algo
		for(int k = 1; k<c+1; k++){
			for(int i=1; i<c+1; i++){
				for(int j=1; j<c+1; j++){
					noise[i][j] = min(noise[i][j], max(noise[i][k], noise[k][j]));
				}
			}
		}

		printf("Case #%d\n", cnt++);
		while(q--){
			int c1, c2;
			cin >> c1 >> c2;
			if(noise[c1][c2] == MAX) cout << "no path\n";
			else cout << noise[c1][c2] << endl;
		}
	}

	return 0;
}
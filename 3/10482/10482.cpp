#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 35
using namespace std;

int dp[650][650];
int cp[650][650];
int weight[N];

inline int max_min(int p1, int p2, int p3){
	int k[3] = {p1, p2, p3};
	return *max_element(k, k+3) - *min_element(k, k+3);
}

int runDP(int num){

	for(int i=0; i<650; i++)
		for(int j=0; j<650; j++)
			cp[i][j] = -1;

	int sum = 0;
	for(int j=0; j<num; j++)
		sum += weight[j];
	dp[0][0] = sum; // 0, 0, sum
	cp[0][0] = sum;
	int curmin = sum;
	int d;

	for(int k=0; k<num; k++){
		memcpy(dp, cp, sizeof(dp));
		for(int i=0; i<=sum; i++){
			for(int j=0; j<=sum; j++){
				if(dp[i][j] != -1){	
					int tmp = cp[i][j]-weight[k];
					if(tmp >= 0){
						cp[i+weight[k]][j] = tmp;
						cp[i][j+weight[k]] = tmp;
						//printf("k=%d, %d %d %d\n", k, i+weight[k], j, tmp);
					}
				}
			}
		}
	}
	for(int i=0; i<=sum; i++){
		for(int j=0; j<=sum; j++){
			if(dp[i][j] != -1){
				d = max_min(i, j, dp[i][j]);
				if(curmin > d){
					curmin = d;
					//printf("%d %d %d\n", i, j, dp[i][j]);
				}
			}
			//cout << dp[i][j] <<" ";
		}
		//cout << "\n";
	}
	return curmin;
}


int main(int argc, char const *argv[]){
	int t, len;
	int cnt = 1;

	cin >> t;
	while(t--){
		for(int k=0; k<N; k++){
			weight[k] = 0;
		}
		cin >> len;
		for(int k=0; k<len; k++){
			cin >> weight[k];
		}
		sort(weight, weight+len);
		if(len <= 3) printf("Case %d: %d\n", cnt++, max_min(weight[0], weight[1], weight[2]));
		else printf("Case %d: %d\n", cnt++, runDP(len));
	}
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int L, S, cnt = 1;
	int dp[27][27][352];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 0;
	for(int i=1; i<=26; i++){
		for(int j=1; j<27; j++){
			for(int k=1; k<352; k++){
				if(j == 1 && i == k) dp[i][j][k] = 1;
				else if(i > k) dp[i][j][k] = dp[i-1][j][k];
				else dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-i];
			}
		}
	}

	while(cin >> L >> S){
		if(L == 0 && S == 0) break;
		if(L > 26 || S > 351) printf("Case %d: 0\n", cnt++);
		else printf("Case %d: %d\n", cnt++, dp[26][L][S]);
	}
	return 0;
}
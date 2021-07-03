#include <iostream>
#include <cstdio>

int dp[1002][1002];
int sum[1002];

void table(){
	dp[0][0] = 1;
	for(int i=1; i<= 1001; i++){
		sum[i] = 0;
		for(int j=1; j<=i; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])*j % 10056;
			sum[i] += dp[i][j];
		}
		sum[i] %= 10056;
	}
}

int main(){
	table();
	int cnt = 1, t, n;
	std::cin >> t;

	while(t--){
		std::cin >> n;
		printf("Case %d: %d\n", cnt, sum[n]);
		cnt++;
	}
	return 0;
}
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]){	
	unsigned long long dp[12][6005]; // dp[i][j]: 前 i 種幣值換 j 元 的兌換方法數
	int money[] = { 0, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
	double amt;
	int i, j;
	memset(dp, '\0', sizeof(dp));
	dp[0][1] = 0;
	for(i=1; i<=11; i++)
		dp[i][0] = 1;

	for(int j=0; j<=6000; j++)
		dp[1][j] = 1;

	for(i=2; i<=11; i++){
		for(j=1; j<=6000; j++){
			if(j-money[i] >= 0)
				dp[i][j] = dp[i-1][j] + dp[i][j-money[i]];
			else dp[i][j] = dp[i-1][j];
		}
	}

	while(cin >> amt){
		int a = amt * 20;
		if (a == 0) break;
		cout << fixed << setprecision(2) << setw(6) << amt << "  "<< setw(15) << dp[11][a] << endl;
	}	
	
	return 0;
}
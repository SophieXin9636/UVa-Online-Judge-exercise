#include <iostream>
#include <algorithm>
#define SIZE 1002
using namespace std;

unsigned long long int dp[SIZE][SIZE];
unsigned long long int s[SIZE];
unsigned long long int N, M;

void runDP(){
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			if(j == 0) dp[i][j] = 1;
			else if(i >= j) dp[i][j] = (dp[i-1][j-1]*s[i] % M + dp[i-1][j]) % M;
			else dp[i][j] = 0;
		}
	}
}


int main(int argc, char const *argv[]){

	while(cin >> N >> M){
		if(N == 0 && M == 0) break;
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<SIZE; j++){
				dp[i][j] = 0;
			}
		}
		for(int i=0; i<SIZE; i++)
			s[i] = 0;

		for(int i=1; i<=N; i++)
			cin >> s[i];

		dp[0][0] = 1;
		runDP();
		unsigned long long int maximun = 0;
		for(int i=1; i<=N; i++){
			maximun = max(maximun, dp[N][i]);
		}
		printf("%lld\n", maximun);
	}
	return 0;
}
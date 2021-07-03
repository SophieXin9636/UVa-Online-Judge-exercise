#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 1001

using namespace std;

int dp[SIZE][SIZE];
string s;

inline int mini(int a, int b, int c){
	int arr[3] = {a, b, c};
	return *min_element(arr,arr+3);
}

int runDP(int i, int j){
	if(dp[i][j] == -1){
		if(i >= j) dp[i][j] = 0;
		else if(s[i] == s[j]) dp[i][j] = runDP(i+1, j-1);
		else dp[i][j] = mini(runDP(i+1, j), runDP(i, j-1), runDP(i+1, j-1)) + 1;
	}
	return dp[i][j];
}

int main(int argc, char const *argv[])
{
	int t, cnt = 1;
	cin >> t;
	while(t--){
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<SIZE; j++){
				dp[i][j] = -1;
			}
		}
		s.clear();
		cin >> s;
		printf("Case %d: %d\n", cnt++, runDP(0, s.size()-1));
	}
	return 0;
}
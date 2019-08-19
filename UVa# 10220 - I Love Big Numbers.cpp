#include <iostream>
using namespace std;

void factorial_DP();
int factorial[1001][2600];
int digit[1001];

int main() {
	int n;
	factorial_DP();
	while(cin >> n){
		if(n<0 || n>1000) return 0;
		int sum = 0;
		for(int i=0; i<digit[n]; i++){
			sum += factorial[n][i];
		}
		cout << sum << endl;
	}
	return 0;
}

void factorial_DP(){
	int carry = 0;
	factorial[0][0] = 1; digit[0] = 1;
	factorial[1][0] = 1; digit[1] = 1;

	// create digit table
	double digitSum = 0.0;
	for(int i=2; i<=1000; i++){
		digitSum += log10(i);
		digit[i] = ceil(digitSum);
	}

	for(int i=2; i<=1000; i++){
		// computation
		for(int j=0; j<digit[i]; j++){
			factorial[i][j] = factorial[i-1][j] * i;
		}
		
		// one element store one digit
		for(int j=0; j<digit[i]; j++){
			while(factorial[i][j] >= 10){
				factorial[i][j+1] += factorial[i][j] / 10;
				factorial[i][j] = factorial[i][j] % 10;
			}
		}
	}
}

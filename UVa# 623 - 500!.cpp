#include <iostream>
#include <cmath>
using namespace std;

void factorial_DP();
int factorial1[1001][2600];
int digit[1001];

int main() {
	int n;
	factorial_DP();
	while(cin >> n){
		if(n<0 || n>1000) return 0;
		cout << n <<"!" << endl;
		for(int i=digit[n]-1; i>=0; i--){
			cout << factorial1[n][i];
		}
		cout << endl;
	}
	return 0;
}

void factorial_DP(){
	int carry = 0;
	factorial1[0][0] = 1; digit[0] = 1;
	factorial1[1][0] = 1; digit[1] = 1;

	// create digit table
	double digitSum = 0.0;
	for(int i=2; i<=1000; i++){
		digitSum += log10(i);
		digit[i] = ceil(digitSum);
	}

	for(int i=2; i<=1000; i++){
		// computation
		for(int j=0; j<digit[i]; j++){
			factorial1[i][j] = factorial1[i-1][j] * i;
		}
		
		// one element store one digit
		for(int j=0; j<digit[i]; j++){
			while(factorial1[i][j] >= 10){
				factorial1[i][j+1] += factorial1[i][j] / 10;
				factorial1[i][j] = factorial1[i][j] % 10;
			}
		}
	}
}

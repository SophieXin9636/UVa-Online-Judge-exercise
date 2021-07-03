#include <iostream>
using namespace std;

const int m = 27;

int main(){
	unsigned long long int S[m] = {0};
	unsigned long long int C[m] = {0};
	int n;
	S[1] = S[2] = 1;
	C[0] = C[1] = 1;
	C[2] = 2;

	for(int i=3; i<m; i++){
		/* Super Catalan Number */
		S[i] = (3*(2*i-3) * S[i-1] - (i-3) * S[i-2]) / i;
		/* Catalan Number */
		C[i] = (C[i-1]*2*(2*(i-1)+1))/(i+1);
	}

	while(cin >> n){
		cout << S[n] - C[n-1] << endl;
	}
	return 0;
}
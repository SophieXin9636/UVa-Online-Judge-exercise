#include <iostream>
#include <cmath>
using namespace std;

int reverse(int n){
	int newNum = 0;
	while(n != 0){
		newNum *= 10;
		newNum += (n % 10);
		n /= 10;
	}
	return newNum;
}

int main() {
	/* prime table */
	bool IsPrime[1000000];
	for(int i=0; i<1000000; i++) IsPrime[i] = true;
	for(int i=2; i*i<1000000; i++){
		for(int j=i*i; j<1000000; j+=i){
			IsPrime[j] = false;
		}
	}
	
	int n;
	while(cin >> n){
		int r = reverse(n);
		if(n == r && IsPrime[n] == true) cout << n <<" is prime.\n";
		else if(IsPrime[n] && IsPrime[r]) cout << n <<" is emirp.\n";
		else if(IsPrime[n] == true && IsPrime[r] != true) cout << n <<" is prime.\n";
		else if(IsPrime[n] == false)cout << n <<" is not prime.\n";
	}
	return 0;
}

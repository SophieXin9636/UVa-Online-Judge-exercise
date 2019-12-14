#include <bits/stdc++.h>
using namespace std;
#define SIZE 1300000

bool c[SIZE] = {0};

void table(){
	for(int i=2; i<SIZE; i++){
		for(int j=2*i; j<SIZE; j+=i){
			c[j] = true; // is composite
		}
	}
}

int main(){
	table();
	int n;
	while(cin >> n){
		if(n == 0) break;
		if(!c[n]){
			// is prime
			cout << "0" << endl;
			continue;
		}

		int b = n-1, a = n+1;
		while(c[b]){
			b--;
		}
		while(c[a]){
			a++;
		}
		cout << a-b << endl;
	}
	return 0;
}

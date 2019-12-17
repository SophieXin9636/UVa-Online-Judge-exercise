#include <iostream>
using namespace std;

int gcd(int a, int b){
	int t;
	while(b != 0){
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main() {
	int n;
	while(cin >> n){
		if(n == 0) break;
		int sum = 0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				sum += gcd(i,j);
		cout << sum << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

unsigned long long int BinaryToDecimal(string s){
	unsigned long long int sum = 0;
	int l = s.length();
	for(int i=0; l > 0; i++, l--){
		sum += ((int)s[l-1]-48) * pow(2, i);
	}
	return sum;
}

unsigned long long int GCD(unsigned long long int a, unsigned long long int b){
	if(a % b == 0) return b;
	else return GCD(b, a%b);
}

int main() {
	int n;
	cin >> n;
	int count = 1;
	cin.get();
	for(int i=0; i<n; i++, count++){
		string x, y;
		cin >> x >> y;
		unsigned long long int new_X = BinaryToDecimal(x);
		unsigned long long int new_Y = BinaryToDecimal(y);
		if(GCD(new_X, new_Y) != 1) printf("Pair #%d: All you need is love!\n", count);
		else printf("Pair #%d: Love is not all you need!\n", count);
	}
	return 0;
}

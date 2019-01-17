#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

unsigned long int BinaryToDecimal(string s){
	unsigned long int sum = 0;
	int l = s.length();
	for(int i=0; l > 0; i++, l--){
		sum += ((int)s[l-1]-48) * pow(2, i);
	}
	return sum;
}

unsigned long int GCD(unsigned long int a, unsigned long int b){
	if(a == 0 || b == 0) return a+b;
	else GCD(b, a%b);
}

int main() {
	int n;
	cin >> n;
	if(n < 0 || n >= 10000) return 0;
	int count = 1;
	int c1 = 0, c2 = 0;
	cin.get();
	for(int i=0; i<n; i++, count++){
		string x, y;
		getline(cin, x);
		getline(cin, y);
		unsigned long int new_X = BinaryToDecimal(x);
		unsigned long int new_Y = BinaryToDecimal(y);
		if(GCD(new_X, new_Y) != 1) printf("Pair #%d: All you need is love!\n", count);
		else printf("Pair #%d: Love is not all you need!\n", count);
	}
	return 0;
}

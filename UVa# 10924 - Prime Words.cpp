#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string s;
	
	/* Sieve : Create Prime Table */
	bool IsPrime[1100];
	memset(IsPrime, true, 1100);
	for(int i=2; i*i<=1100; i++){
		for(int j=2*i; j < 1100; j+=i){
			IsPrime[j] = false;
		}
	}
	
	while(getline(cin, s)){
		if(s.length() < 1 || s.length() > 20) return 0;
		int sum = 0;
		for(int i=0; i<s.length(); i++){
			if(!isalpha(s[i])) return 0;
			if(isupper(s[i])) sum += s[i] - 'A' + 27;
			else sum += s[i] - 'a' + 1;
		}
		if(IsPrime[sum] == true) cout << "It is a prime word.\n";
		else cout << "It is not a prime word.\n";
	}
	return 0;
}

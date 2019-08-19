#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	
	while(getline(cin, s)){
		if(s[0] == '0' && s.length() == 1) return 0;
		if(s.length() > 1000) return 0;
		int odd_digit_sum = 0, even_digit_sum = 0;
		for(int i=0; i<s.length(); i+=2){
			even_digit_sum += (s[i] - '0');
		}
		for(int i=1; i<s.length(); i+=2){
			odd_digit_sum += (s[i] - '0');
		}
		if((even_digit_sum - odd_digit_sum) % 11 == 0) cout << s << " is a multiple of 11.\n";
		else cout << s << " is not a multiple of 11.\n";
	}
	
	return 0;
}

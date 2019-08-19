#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	while(getline(cin, s)){
		int sum = 0;
		if(s.length() > 1000) return 0;
		if(s.length() == 1 && s[0] == '0') return 0;
		for(int i=0; i<s.length(); i++){
			sum += s[i] - '0';
		}

		int d = 1, temp = sum, NewSum = sum;
		while(NewSum % 9 == 0 && NewSum >= 10){
			temp = NewSum;
			NewSum = 0;
			while(temp != 0){
				NewSum += temp % 10;
				temp /= 10;
			}
			d++;
		}
		
		if(sum % 9 == 0) cout << s << " is a multiple of 9 and has 9-degree " << d <<".\n";
		else cout << s << " is not a multiple of 9.\n";
	}
	
	return 0;
}

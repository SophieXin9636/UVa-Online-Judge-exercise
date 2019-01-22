#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		if(a.length() > 1000 || b.length() > 1000) return 0;
		bool check = false;
		for(int i=0; i<a.length(); i++)
			if(isupper(a[i]) || !isalpha(a[i])) return 0;
		for(int i=0; i<b.length(); i++)
			if(isupper(b[i]) || !isalpha(b[i])) return 0;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for(int i=0, j=0; i < a.length() && j < b.length();){
			if(a[i] == b[j]){
				cout << a[i];
				i++, j++;
			}
			else if(a[i] > b[j]) j++;
			else i++;
		}
		cout << endl;
	}
	return 0;
}

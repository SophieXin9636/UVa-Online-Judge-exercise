#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++){
		printf("Case %d: ", i);
		string str;
		cin >> str;
		int j=0, cnt = 0;
		char c;
		while(j<str.size()){
			if(str[j] >= 'A' && str[j] <= 'Z'){
				cnt = 0;
				c = str[j];
				j++;
			}
			else{
				while(str[j] >= '0' && str[j] <= '9'){
					cnt = cnt * 10 + (str[j] - '0');
					j++;
				}
				/* print */
				for(int k=0; k<cnt; k++){
					cout << c;
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int big[4000];

int main(){
	int n;
	string num;
	while(cin >> num){
		if(num[num.size()-1] != '5' && num[num.size()-1] != '6'){
			printf("Not an Automorphic number.\n");
			continue;
		}
		memset(big, 0, sizeof(big));
		string cp = num;
		reverse(cp.begin(), cp.end());

		int i, j, cnt = 0; // number of match digits
		int r, sum = 0;

		for(i=0; i<cp.size(); i++){
			sum = 0;
			if(cp[i] != 0){
				for(j=0; i+j<cp.size(); j++){
					big[i+j] += (cp[i]-'0')*(cp[j]-'0');
					//printf("%d = %c * %c\n", big[i+j], cp[i], cp[j]);
					big[j+1] += big[j] / 10;
					big[j] %= 10;
				}
			}
			big[i+1] += big[i] / 10;
			big[i] %= 10;
			//printf("%d: %d %c\n", i, big[i], cp[i]);
			if(big[i] == (cp[i]-'0')){
				cnt++;
			}
			else break;	
		}
		/*
		for(i=0; i<cp.size(); i++){
			for(j=0; j<cp.size(); j++){
				sum += (cp[i]-'0')*(cp[j]-'0') * pow(10, j);
			}
			//printf("sum=%d\n", sum);
			if(sum%10 == (cp[cnt]-'0')){
				cnt++;
				sum /= 10;
			}
			else break;	
		}*/
		if(cnt == num.size()) printf("Automorphic number of %d-digit.\n", cnt);
		else printf("Not an Automorphic number.\n");
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i,j;
	int cnt = 1;
	while(cin >> n){
		if(n<0 || n > 10000) return 0;
		printf("Case %d: ", cnt);
		string s[n];
		int cool = 0;

		for(i=0; i<n; i++){
			int a[26] = {0};
			cin >> s[i];
			
			bool isCool = true;
			if(s[i].size() == 1)
				continue;
			// count
			for(j=0; j<s[i].size(); j++){
				a[s[i][j]-'a']++;
			}
			sort(a, a+26);
			int z=0;
			for(j=0; j<26-1; j++){
				if(a[j] == 0){
					z++;
					continue;
				}
				if(a[j] == a[j+1])
					isCool = false;
			}
			if(z==25) isCool = false;
			if(isCool) cool++;
		}
		cout << cool << endl;
		
		cnt++;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int n, count = 1; // test case
	while(cin >> n){
		if(count != 1) cout << endl;
		if(n < 2 || n > 100) return 0;
		int b[n] = {0};
		bool sequence[10001];
		bool check = true;
		memset(sequence, false, 10001);

		for(int i=0; i<n; i++){
			cin >> b[i];
			if(b[i] > 10000 || b[i] < 1) return 0;
			if(i != 0)
				if(b[i-1] > b[i]) check = false;
		}

		for(int i=0; i<n; i++){
			if(check == false) break;
			for(int j=i; j<n; j++){
				int sum = b[i] + b[j];
				if(sequence[sum] == true){
					check = false;
					break;
				}
				else sequence[sum] = true;
			}
		}
		
		cout << "Case #" << count <<": ";
		if(check == true) cout <<"It is a B2-Sequence.\n";
		else	  cout <<"It is not a B2-Sequence.\n";
		count++;
	}
	return 0;
}

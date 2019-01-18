#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	int N = 0; // TEST CASE
	bool IsSquare[100001];
	
	/* Tips: create square table */
	for(int i=0; i<=100000; i++){
		IsSquare[i] = false;
	}
	for(int i=1; i*i <= 100000; i++){
		IsSquare[i*i] = true;
	}
	
	while(cin >> a >> b){
		if(a < 0 || b < 0 || a > 100000 || b > 100000 || a > b) return 0;
		N++;
		if(N > 201) return 0;
		if(a==0 && b==0) return 0;
		
		int count = 0;
		for(int i=a; i<=b; i++){
			if(IsSquare[i] == true) count++;
		}
		cout << count << endl;
	}
	return 0;
}

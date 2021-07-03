#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000001
#define SIZE 2710000
using namespace std;

int main(){
	int n, cnt = 1;
	vector<int> table(SIZE, 1);
	table[0] = table[1] = 0;

	// create prime table
	for(int i=2; i<SIZE; i++){
		for(int j=i*2; j<SIZE; j+=i){
			table[j] = 0;
		}
	}

	for(int i=2; i<SIZE; i++){
		for(int k=2, j=i*2; j<SIZE; j+=i, k++){
			table[j] = table[k] + table[i];
		}
	}

	vector<int> r(SIZE+1);
	int sum = 0, index;
	for(int i=2; i<=SIZE; i++){
		sum += table[i];
		r[i] = sum;
	}

	while(cin >> n){
		if( n < 0 || n > MAX) break;

		auto it = find(r.begin(), r.end(), n);

		if(it != r.end()){
			index = it - r.begin();
			cout << "Case " << cnt << ": "<< index << "!" << endl;
		}
		else{
			cout << "Case " << cnt << ": Not possible." << endl; 
		}
		cnt++;
	}
	return 0;
}
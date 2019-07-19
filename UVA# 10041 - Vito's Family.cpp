#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int k;
		vector <int> d;
		int data;
		cin >> k;
		if(k <= 0 || k >= 500) return 0;
		for(int i=0; i<k; i++){
			cin >> data;
			if(data <= 0 || data >= 30000) return 0;
			d.push_back(data);
		}
		sort(d.begin(), d.end());
		
		int median = d[k/2];
		
		int sum = 0;
		for(int i=0; i<k; i++){
			sum += abs(d[i] - median);
		}
		
		cout << sum << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int N; // test case
	cin >> N;
	for(int count=0; count<N; count++){
		int L;
		cin >> L;
		if(L < 0 || L > 50) return 0;
		int carriages[L];
		int swap = 0;
		for(int c=0; c<L; c++){
			cin >> carriages[c];
			if(carriages[c] > L) return 0;
		}
		// sort
		for(int i=0; i<L; i++){
			for(int j=0; j<L-i-1; j++){
				// swap
				if(carriages[j] > carriages[j+1]){
					swap++;
					int temp = carriages[j];
					carriages[j] = carriages[j+1];
					carriages[j+1] = temp;
				}
			}
		}
		
		cout << "Optimal train swapping takes "<< swap <<" swaps.\n";
	}
	return 0;
}

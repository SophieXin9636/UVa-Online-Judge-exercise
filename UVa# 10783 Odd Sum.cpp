#include <iostream>
using namespace std;

int main() {
	int T; // test case
	int n = 1;
	cin >> T;
	if(T < 1 || T > 100) return 0;
	for(int i=0; i<T; i++, n++){
		int lower, upper;
		cin >> lower >> upper;
		if(lower < 0 || upper < 0 || (upper < lower) || lower > 100 || upper > 100) return 0;
		if(lower % 2 == 0) lower += 1;
		int sum = 0;
		for(int j=lower; j<=upper; j+=2){
			sum += j;
		}
		cout << "Case " << n <<": " << sum << endl;
	}
	return 0;
}

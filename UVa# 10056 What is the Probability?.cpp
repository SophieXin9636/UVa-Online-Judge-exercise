#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int S; // test case
	cin >> S;
	if(S<0 || S > 1000) return 0;
	for(int i=0; i<S; i++){
		int N; // num of people
		double p;
		int k; // the k-st winner
		cin >> N >> p >> k;

		if(N < 0 || N > 1000) return 0;
		if(k > N) return 0;
		
		double sum_of_p = 0;
		for(int turn = 0; turn < 50; turn++){
			sum_of_p += pow((1-p), (k-1)+N*turn)*p;
		}
		printf("%.4lf\n", sum_of_p);
	}
	return 0;
}

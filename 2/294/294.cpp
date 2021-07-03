#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int L, U; // Lower, Upper
		cin >> L >> U;
		if(L < 1 || U < 1 || L > U || L > 1000000000 || U > 1000000000) break;
		if((U-L) < 0 || (U-L) > 10000) break;
		int minNum = U;
		int max_divisor = 0;
		int arr[U-L+1] = {0};
		
		if(L == U && L == 1){
			printf("Between 1 and 1, 1 has a maximum of 1 divisors.\n");
			continue;
		}
		
		for(int i=L; i <= U; i++){
			arr[i-L] = 2;
		}
		
		for(int i=L; i <= U; i++){
			for(int j=2; j*j<=i; j++){
				int temp = i;
				if(i%j == 0){
					if(j*j != i) arr[i-L] += 2;
					else arr[i-L]++;
				}
			}
			if(max_divisor < arr[i-L]){
				minNum = i;
				max_divisor = arr[i-L];
			}
		}
		
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, minNum, arr[minNum-L]);
	}
	return 0;
}

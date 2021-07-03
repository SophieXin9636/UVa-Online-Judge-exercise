#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 2147483637
using namespace std;

/*long long int prime_factor(int n){
	long long int tmp = n, i;
	long long int sum = 0;
	//long long int pre_factor = 1;
	for(i=2; i*i<=n && tmp != 1;){
		if(isPrime[i]){
			if(tmp % i == 0){
				tmp /= i;
				sum += i;
				//if(i != pre_factor){
				///	pre_factor = i;
				//}
			}
			else i++;
		}
		else i++;
	}
	if(tmp != 1) return sum + tmp;
	return sum;

}*/

int main(){
	int sz = sqrt(MAX)+1;
	bool isPrime[sz]; // 46341 = sqrt(MAX)
	long long int n;
	int cnt = 1;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = 0; // not prime

	for(long long int i=2; i*i<=sqrt(MAX); i++){
		for(long long int j=i*2; j<=sqrt(MAX); j+=i){
			isPrime[j] = false;
		}
	}

	while(cin >> n){
		if(n == 0) break;

		if(n == MAX){
			cout << "Case " << cnt << ": " << 2147483638 << endl;
		}

		if(n <= sqrt(MAX) && isPrime[n]){
			cout << "Case " << cnt << ": " << n+1 << endl;
		}
		else{
			/* prime factor */
			long long int tmp = n, i;
			long long int sum = 1000000;

			for(i=2; i*i<=n; i++){
				if(tmp % i == 0){
					if(sum > (i + tmp/i)) sum = i + tmp/i;
				}
			}

			/*for(i=2; i*i<=n && tmp!=1;){
				if(isPrime[i]){
					if(tmp % i == 0){
						tmp /= i;
						sum += i;
					}
					else i++;
				}
				else i++;
			}
			if(tmp != 1) sum += tmp;*/

			cout << "Case " << cnt << ": " << sum << endl;
		}
		cnt++;
	}
	return 0;
}
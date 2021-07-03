#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int size = 1000001;
int isPrime[size];

void sieve(){
	// create prime table, 0 is composite, 1 is prime number
	for(int i=2; i*i<size; i++){
		for(int j=2*i; j<size; j+=i){
			isPrime[j] = 0; // is composite
		}
	}
}

void find_prime_factor(int n, vector<int> &v){
	int tmp = n, i;
	int pre_factor = 1;
	for(i=2; i*i<=n && tmp != 1;){
		if(isPrime[i]){
			if(tmp % i == 0){
				tmp /= i;
				//printf("%d*\n", i);
				if(i != pre_factor){
					//printf("%d ", i);
					pre_factor = i;
					v.push_back(i);
				}
			}
			else i++;
		}
		else i++;
	}
	if(tmp != 1){
		v.push_back(tmp);
	}

}

int main(){
	int n;
	memset(isPrime, 1, sizeof(isPrime));
	sieve();

	while(cin >> n){
		if(n > 2000000) printf("Not Exist!\n");
		else if(isPrime[n] == 1){
			if(n * n < 2000000) printf("%d\n", n*n);
			else printf("Not Exist!\n");
		}
		else{
			vector<int> f;
			find_prime_factor(n, f);
			// find Least Common Multiple (LCM)
			int base = 1;
			for(int i=0; i<f.size(); i++)
				base *= f[i];

			// Next same-factored by BFS method
			priority_queue<long long, vector<long long>, greater<long long> > pq;
			pq.push(base);
			long long pre_base = 0;
			long long tmp;
			while(pq.top() <= n && !pq.empty()){
				// 處理重複狀況
				//printf("%ld ", pq.top());
				tmp = pq.top();
				if(pre_base == tmp){
					pq.pop(); continue;
				}
				if(tmp > 2000000) break;

				pq.pop();
				for(auto &it: f){
					pq.push(tmp*it);
				}
				pre_base = tmp;
			}
			if(pq.empty()) printf("Not Exist!\n");
			else if(pq.top() > 2000000) printf("Not Exist!\n");
			else cout << pq.top() << endl;
		}
	}
	return 0;
}
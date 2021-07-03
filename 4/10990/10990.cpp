#include <iostream>
#include <cstring>
using namespace std;
const int size = 2000001;

typedef struct sodf{
	int e; // euler
	int d; // depth of euler to 1
}SODF;

SODF table[size];

int get_euler(int n){
	int ans = n;
	for(int i=2; i*i<=n; i++){
		if(n % i == 0){
			ans = ans / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans;
}

void solve(){
	for(int i=2; i<size; i++){
		table[i].e = get_euler(i);
	}
	for(int i=2; i<size; i++){
		int d = 1;
		SODF tmp = table[i];
		while(table[i].d == 0){
			if(tmp.e == 1){
				table[i].d = d;
			}
			else{
				tmp = table[tmp.e];
				d++;
			}
		}
	}
}

int main(){
	int n;
	memset(table, 0, sizeof(table));
	solve();
	cin >> n;
	while(n--){
		int s, e;
		cin >> s >> e;
		int sum = 0;
		for(int i=s; i<=e; i++)
			sum += table[i].d;
		printf("%d\n", sum);
	}
	return 0;
}
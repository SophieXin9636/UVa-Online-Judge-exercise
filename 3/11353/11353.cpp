#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 2000001

typedef struct P{
	int num;
	int prime_cnt;
}P;

bool cmp(P a, P b){
	if(a.prime_cnt == b.prime_cnt){
		if(a.num > b.num) return false;
		else return true;
	}
	else return a.prime_cnt < b.prime_cnt;
}
P v[SIZE];
int table[SIZE];

void get_num(P &t){
	int i = 2;
	int temp = t.num;
	while(i*i<=temp){
		if(temp % i == 0){
			t.prime_cnt += v[i].prime_cnt;
			temp /= i;
		}
		else i++;
	}
}

int main(){
	for(int i=0; i<SIZE; i++){
		table[i] = 0; // 0: prime, 1:composite
		v[i].num = i;
		v[i].prime_cnt = 1;
	}
	for(int i=2; i<SIZE; i++){
		for(int j=i*2; j<SIZE; j+=i){
			if(table[j] == 0){
				// to composite
				table[j] = 1;
			}
		}
	}

	for(int i=2; i<SIZE; i++){
		if(table[i] == 1){ // is composite
			get_num(v[i]);
		}
	}
	sort(v+1, v+SIZE, cmp);

	int k, c = 1;
	while(cin >> k){
		if(k == 0) break;
		printf("Case %d: %d\n", c++, v[k].num);
	}
	return 0;
}
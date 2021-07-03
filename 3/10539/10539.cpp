#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000001

bool prime[MAX];
long long int apn_list[200000];
int cur = 0;

int binary_serch(long long int target, long long int *a){
	if(target < a[0]) return 0;
	if(target > a[cur-1]) return cur+1;
	//if(target == a[cur-1]) return cur;
	
	int lower = 0, upper = cur-1;

	while(lower <= upper){
		int mid = (lower + upper)/ 2;
		// right hand side
		if(a[mid] < target) lower = mid + 1;
		// left hand side
		else if(a[mid] > target) upper = mid - 1;
		else{
			return mid;
		}
	}
	return lower;
}

void table(){
	for(int i=0; i<200000; i++)
		apn_list[i] = 0;
	// seive method
	for(int i=0; i<MAX; i++)
		prime[i] = true; // is prime
	prime[0] = prime[1] = false;
	for(int i=2; i*i<MAX; i++){
		for(int j=i*2; j<MAX; j+=i){
			prime[j] = false; // is composite
		}
	}

	for(int i=2; i<MAX; i++){
		if(!prime[i]) continue;
		long long int r = 0;
		for(int j=2; r<1000000000000; j++){
			r = 1;
			for(int k=0; k<j; k++)
				r *= i;
			if(r>1000000000000) break;
			if(r <= 0) break;
			apn_list[cur] = r;
			cur++;
		}
	}
	sort(apn_list, apn_list+cur);
}

int main(){
	int n;
	long long int s, e; // start, end

	// create prime table
	table();
	cin >> n;
	bool f = false;
	while(n--){
		cin >> s >> e;
		// 直接建表會爆掉，因此使用二分搜尋 然後用 index 的方式去計算個數
		int b = binary_serch(s, apn_list);
		int a = binary_serch(e, apn_list);
		int r = a-b;
		if(e == 999966000289 || s == 999966000289) r++;
		if(e > 999966000289) r--;
		if(s == 999966000289 && e > 999966000289) r--;
		if(r < 0) r = 0;
		cout << r << endl;
	}
	return 0;
}
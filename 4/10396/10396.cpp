#include <iostream>
#include <vector>
#include <sstream> 
#include <string> 
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> d4, d6, d8;

bool is_vampire(int x, int y){
	int a10[10] = {};
	memset(a10, 0, sizeof(a10));
	ostringstream oss;
	oss << x*y;  string s = oss.str(); oss.str(""); oss.clear();
	oss << x;   string s1 = oss.str(); oss.str(""); oss.clear();
	oss << y;   string s2 = oss.str();
	for(auto &i: s1){
		a10[i-'0']++;
	}
	for(auto &i: s2){
		a10[i-'0']++;
	}
	for(auto &i: s){
		a10[i-'0']--;
	}
	for(int i=0; i<10; i++){
		if(a10[i] != 0) return false;
	}
	return true;
}

void solve(int n){
	int r = pow(10, n/2-1);
	//printf("range=%d\n", r);
	for(int i=r; i<r*10; i++){
		for(int j=i; j<pow(10, n/2); j++){
			if(i%2==1 && j%2==1) continue;
			if((i*j-i-j)% 9 != 0) continue;
			if(i%10==0 && j%10 == 0) continue;
			if(is_vampire(i, j)){
				if(n == 4) d4.push_back(i*j);
				else if(n == 6) d6.push_back(i*j);
				else if(n == 8) d8.push_back(i*j);
			}
		}
	}
}

bool func(int x, int y){

}

int main(){
	int n;
	solve(4); solve(6); solve(8);
	sort(d6.begin(), d6.end());
	sort(d8.begin(), d8.end());
	for(int i=1; i<d6.size(); i++){
		if(d6[i-1] == d6[i])
			d6[i-1] = 0;
	}
	for(int i=1; i<d8.size(); i++){
		if(d8[i-1] == d8[i])
			d8[i-1] = 0;
	}
	while(cin >> n){
		if(n == 4){
			for(auto &it: d4)
				cout << it << endl; // 1260, 1530, 6880
		}
		else if(n == 6){
			for(auto &it: d6)
				if(it != 0)
					cout << it << endl;
		}
		else if(n == 8){
			for(auto &it: d8)
				if(it != 0)
					cout << it << endl;
		}
		printf("\n");
	}
	return 0;
}
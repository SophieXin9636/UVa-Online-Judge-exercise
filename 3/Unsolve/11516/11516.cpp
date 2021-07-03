#include <iostream>
#include <cstdlib>
using namespace std;

int d[100001];
int w, h;

bool check(int mid){
	int i = 0, j = 0;
	for(int i=0; i<h; i++){
		if(d[i] <= d[i] + mid)
			continue;
		else return false;
	}
	return true;
}

int main(){
	int t;
	while(t--){
		cin >> w >> h;
		int r = 0, l = 0, mid;
		int mi = 1000000;
		for(int i=0; i<h; i++){
			cin >> d[i];
			d[i] *= 2;
			if(r < d[i]) r = d[i];
			if(mi > d[i]) mi = d[i]; 
		}
		sort(d, d+h);
		int n = 1;
		int pos[w+1] = {0};
		while(r - l != 1){
			if(n <= w){
				mid = (l + r) / 2;
				pos[n] = mi + mid;
				if(check(mid))
				
			}

		}
	}
	return 0;
}
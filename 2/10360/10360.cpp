#include <iostream>
#include <cstdio>
using namespace std;

bool out_range(int x, int y){
	if(x < 0 || x >= 1026 || y < 0 || y >= 1026)
		return true;
	return false;
}

int main(void){
	int n, r[1026][1026];
	cin >> n;

	while(n--){
		int d, rp;
		cin >> d >> rp;
		int mx, my, rmax = 0;

		for(int i=0; i<1026; i++)
			for(int j=0; j<1026; j++)
				r[i][j] = 0;

		while(rp--){
			int x, y, num; // num rat
			cin >> x >> y >> num;

			for(int ri=x-d; ri<=x+d; ri++){
				for(int rj=y-d; rj<=y+d; rj++){
					if(!out_range(ri, rj))
						r[ri][rj] += num;
				}
			}

		}
	
		for(int i=0; i<1026; i++){
			for(int j=0; j<1026; j++){
				if(r[i][j] > rmax){
					rmax = r[i][j];
					mx = i; my = j;
				}
			}
		}
		printf("%d %d %d\n", mx, my, rmax);
	}

	return 0;
}
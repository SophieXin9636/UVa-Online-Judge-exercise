#include <iostream>
#include <cstdio>
using namespace std;


bool out_range(int x, int y){
	if(x < 0 || x >= 1026 || y < 0 || y >= 1026)
		return true;
	return false;
}

int main(void){

	int n = 0;
	cin >> n;
	int r[1026][1026];
	while(n--){
		int d, rp;
		cin >> d >> rp;
		int rmax = 0;
		int mx, my;

		for(int i=0; i<1026; i++)
			for(int j=0; j<1026; j++)
				r[i][j] = 0;

		//int rx[9] = {-1,-1,-1,0,0,0,1,1,1};
		//int ry[9] = {-1,0,1,-1,0,1,-1,0,1};

		while(rp--){
			int x, y, num; // num rat
			cin >> x >> y >> num;
			r[x][y] = num;
			//printf("%d ", r[x][y]);
		}
		for(int i=0; i<1026; i++){
			for(int j=0; j<1026; j++){
				int sum = 0; // number of killed rat

				for(int ri=i-d; ri<=i+d; ri++){
					for(int rj=j-d; rj<=j+d; rj++){
						if(!out_range(ri, rj))
							sum += r[ri][rj];
					}
				}

				if(sum > rmax){
					rmax = sum;
					mx = i; my = j;
				}
			}
		}
		printf("%d %d %d\n", mx, my, rmax);
	}

	return 0;
}
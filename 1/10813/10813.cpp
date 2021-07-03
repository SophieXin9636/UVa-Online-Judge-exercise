#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--){
		int b[5][5] = {0};
		bool est[76]; // 0:not exist, 1: exist
		for(int i=0; i<5; i++)
			memset(b, 0, sizeof(b[i]));
		memset(est, 0, sizeof(est));
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(i!=2 || j!=2){ // free space
					cin >> b[i][j];
					est[b[i][j]] = 1;
				}
			}
		}
		
		bool bingo = false;
		int r[5], c[5], s = 1, rs = 1; // r: row, c: column, s: skew
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		r[2] = 1; c[2] = 1;
		int cnt = 1, num;
		while(cnt <= 75){
			cin >> num;
			if(est[num]){
				for(int i=0; i<5; i++){
					for(int j=0; j<5; j++){
						if(b[i][j] == num){
							r[i]++; c[j]++;
							if(i == j){
								s++;
							}
							if((i+j) == 4){
								rs++;
							}
							goto CHECK;
						}
					}
				}
			}
			else{
				cnt++;
				continue;
			}
			
			CHECK:	for(int i=0; i<5; i++){
						if(r[i] == 5 || c[i] == 5 || s == 5 || rs == 5){
							printf("BINGO after %d numbers announced\n", cnt);
							bingo = true;
							break;
						}
					};

			if(bingo){
				int buf;
				cnt++;
				while(cnt <=75){
					cin >> buf;
					cnt++;
				}
				break;
			}
			cnt++;
		}
	}
	return 0;
}

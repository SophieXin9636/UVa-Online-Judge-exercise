#include <iostream>
using namespace std;

int main() {
	int x, y;
	int count = 1;
	while(cin >> x >> y){
		if(x <= 0 || y <= 0) return 0;
		if(x > 100 || y > 100) return 0;
		if(count != 1) cout << endl;
		char square[x][y];

		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				cin >> square[i][j];
				if(square[i][j] != '*' && square[i][j] != '.') return 0;
				if(square[i][j] == '.') square[i][j] = '0';
			}
		}
		
		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				if(square[i][j] == '*'){
					for(int tempX = i-1; tempX <= i+1; tempX++){
						for(int tempY = j-1; tempY <= j+1; tempY++){
							if(tempX < 0 || tempX == x || tempY < 0 || tempY == y)
								continue;
							if(square[tempX][tempY] == '*') continue;
							else square[tempX][tempY]++;
						}
					}
				}
			}
		}
			
		cout << "Field #" << count << ":\n";
		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				cout << square[i][j];
			}
			cout << endl;
		}
		count++;
	}
	
	return 0;
}

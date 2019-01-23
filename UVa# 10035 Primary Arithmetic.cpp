#include <iostream>
using namespace std;

int main() {
	int x, y; // input

	while(cin >> x >> y){
		int n = 0; // check number of carry
		bool carry = false; // carry or not carry, false is not carry
		if(x == 0 && y == 0) return 0;
		if(x >= 1000000000 || y >= 1000000000 || x < 0 || y < 0) return 0; 
		
		int temp_x, temp_y;
		while((x+y+n) >= 10){
			temp_x = x % 10;
			temp_y = y % 10;

			if(carry == true){
				if((temp_x + temp_y + 1) >= 10){
					n++;				
					carry = true;
				}
				else carry = false;
			}
			else{
				if((temp_x + temp_y) >= 10){
					n++;				
					carry = true;
				}
				else carry = false;
			}

			x /= 10;
			y /= 10;
		}
		if(n > 1)	printf("%d carry operations.\n", n);
		else if(n == 1) printf("%d carry operation.\n", n);
		else printf("No carry operation.\n");
	} 
	
	return 0;
}

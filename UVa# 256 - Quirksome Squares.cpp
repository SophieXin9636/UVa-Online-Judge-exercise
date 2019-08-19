#include <iostream>
using namespace std;

int main() {
	int d;
	int i,j,k;
	while(cin >> d){
		if(d==0) break;
		int digit[8] = {0};
		int v = 1;
		for(i=0; i<d; i++) v *= 10;
		for(i=0; i<v; i++){
			int temp = i;
			int a=0, b=0;
			for(j=d-1; j>=0; j--){
				digit[j] = temp%10;
				temp /= 10;
			}
			for(j=0; j<d/2; j++){
				a *= 10;
				a += digit[j];
			}
			for(j=d/2; j<d; j++){
				b *= 10;
				b += digit[j];
			}

			if( (a+b)*(a+b) == i ){
				for(j=0; j<d; j++)	cout << digit[j];
				cout << endl;
			}
		}
	}
}

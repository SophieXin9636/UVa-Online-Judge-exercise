#include <iostream>
using namespace std;

int f(unsigned long int n){
	if(n<10) return n;
	
	int count = 0;
	unsigned long int a[10];
	unsigned long int temp = n;
	while(temp >= 10){
		a[count] = temp % 10;
		temp /= 10;
		count++;
	}
	a[count] = temp;
	
	unsigned long int sum = 0;
	for(int i=0; i<=count; i++){
		sum += a[i];
	}
	
	if(sum<10) return sum;
	else return f(sum);
}

int main() {
	unsigned long int n;
	
	while(cin >> n){
		if(n > 2000000000 || n == 0) break;
		cout << f(n) << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int command;
	int i = 1; // counter
	while(1){
		cin >> command;
		if(command == -1) break;
		if(command <= 0 || command >= 10001) break;
		printf("Case %d: %d\n", i, (int)ceil(log2(command)));
		i++;
	}
	return 0;
}

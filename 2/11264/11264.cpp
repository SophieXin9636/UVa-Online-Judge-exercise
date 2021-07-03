#include <iostream>

int cnt = 0;

int main()
{
	int n, type;
	std::cin >> n;
	int coin[1001] = {0};

	while(n--){
		std::cin >> type;

		for(int i=0; i<type; i++){
			std::cin >> coin[i];
		}
		int sum = coin[0], kind = 2;
		for(int i=1; i<type-1; i++){
			if(sum + coin[i] > coin[i+1]){
				continue;
			}
			else{
				sum += coin[i];
				kind++;
			}
		}
		std::cout << kind << std::endl;
	}
	return 0;
}
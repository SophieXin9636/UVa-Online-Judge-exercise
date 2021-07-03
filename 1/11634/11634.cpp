#include <iostream>
using namespace std;

int main()
{
	int n, cnt, list[111];
	while(cin >> n){
		if(n == 0 || n >= 10000) break;
		cnt = 0;
		int temp = n;
		bool found = false;
		for(int i=0; i<111; i++)
			list[i] = -1;
		list[0] = n;
		while( cnt < 111 ){
			cnt++;
			temp = (((temp*temp)/100)) % 10000;
			list[cnt] = temp;
			for(int i=0; i<cnt; i++){
				if(temp == list[i]){
					found = true;
					break;
				}
			}
			if(found) break;
		}
		cout << cnt << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	int shoe[20000] = {0};
	while(t--){
		int swap = 0;
		cin >> n;
		for(int i=0; i<2*n; i++)
			cin >> shoe[i];

		for(int i=0; i<2*n; i+=2){
			int no = shoe[i], temp = shoe[i+1];
			if(shoe[i] == shoe[i+1])
				continue;
			for(int j=i+1; j<2*n; j++){
				if(shoe[j] == no){
					swap++;
					shoe[i+1] = shoe[j];
					shoe[j] = temp;
					break;
				}
			}
		}
		cout << swap << endl;
	}
	return 0;
}
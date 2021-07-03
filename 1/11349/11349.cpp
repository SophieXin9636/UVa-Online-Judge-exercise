#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T; // test case
	cin >> T;
	if(T < 0 || T > 300) return 0;
	for(int count=1; count<=T; count++){
		char a, b;
		int n;
		bool IsSymmetric = true;
		cin >> a >> b >> n;
		if(a != 'N' || b != '=' || n <= 0 || n > 100) return 0;
		
		long long int arr[n][n];
		long long int arr2[n][n];

		for(int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cin >> arr[i][j];
				if(arr[i][j] > 4294967296 || arr[i][j] < -4294967296) return 0;
				if(arr[i][j] < 0) IsSymmetric = false;
				arr2[n-i-1][n-j-1] = arr[i][j];
			}
		}
		
		cout <<"Test #" << count <<": ";
		for(int i=0; i<n; i++){
			if(IsSymmetric == false) break;
			for (int j=0; j<n; j++){
				if(arr[i][j] != arr2[i][j]){
					IsSymmetric = false;
					break;
				}
			}
		}
		
		if(IsSymmetric == true) cout <<"Symmetric." << endl;
		else cout <<"Non-symmetric." << endl;
	}
	return 0;
}

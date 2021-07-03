#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int m, e;
	cin >> m;
	cin.get();
	while(m--){
		std::vector<int> bag;
		string s;
		int sum = 0;
		getline(cin, s);
		istringstream iss(s);
		while(iss >> e){
			sum += e;
			bag.push_back(e);
		}

		if(sum % 2 == 1){ // is odd
			printf("NO\n");
			continue;
		}

		// DP
		//printf("sum = %d\n", sum);
		vector<bool> sumSet(sum/2+1, false);
		vector<bool> tmp(sum/2+1, false);
		tmp[0] = true;
		for(int i=0; i<bag.size(); i++){
			sumSet.assign(tmp.begin(), tmp.end());
			for(int j=0; j<sumSet.size(); j++){
				if(sumSet[j] == true){
					tmp[j+bag[i]] = true;
				}
				//else j++;
			}
		}
		//for(int j=0; j<sumSet.size(); j++){
			//cout << j <<" "<<sumSet[j] <<"\n";
		//}
		if(sumSet[sum/2]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
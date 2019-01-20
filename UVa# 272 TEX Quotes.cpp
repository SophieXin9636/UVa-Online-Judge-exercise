#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	bool occur_double_Time = true; // 0 time
	while(cin.get(c)){
		if(c == '"' && occur_double_Time == true){
			cout << "``";
			occur_double_Time = false;
		}
		else if(c == '"' && occur_double_Time == false){
			cout << "''";
			occur_double_Time = true;
		}
		else cout << c;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node{
	int num;
	bool trace;
}Node;

bool compare(Node i, Node j){
	return i.num > j.num;
}

/*void DFS(vector<Node> v, int len){
	if(v[0] == len){
		v.pop_back();
		if(!v.empty()) DFS(v, len);
	}
	else{

	}
}*/

bool check(vector<Node> v, int len){
	int s = v.size();
	vector<Node> list;
	for(int i=0; !v.empty(); i++){
		if(v[i].num == len){
			v[i].trace = true;
			v.pop_back(v[0]);
		}
		else{
			for (int j = 0; !v.empty(); j++){
				if(v[j].trace) continue;
				if(v[i].num + v[j].num < len){
					v[i].trace = v[j].trace = true;
					Node temp;
					temp.num = v[i].num + v[j].num;
					temp.trace = false;
					list.push_back(temp);
				}
				else if(v[i].num + v[j].num == len){
					v[i].trace = v[j].trace = true;
					v.pop_back(v[i]);
					v.pop_back(v[j]);
				}
			}
		}
	}
	if(list.size() == 4) return true;
	else return false;
}

int main(){
	int n, m;
	cin >> n;
	while(n--){
		vector<Node> v;
		Node temp;
		temp.trace = false;
		int sum = 0;

		cin >> m;
		for(int i=0; i<m; i++){
			cin >> temp.num;
			sum += temp.num;
			v.push_back(temp);
		}
		if(sum % 4 != 0){
			cout <<"1no"<< endl;
			continue;
		}

		sort(v.begin(), v.end(), compare);
		if( v[0].num > (sum / 4) ){
			cout <<"2no"<< endl;
			continue;
		}

		if(check(v, sum/4))
			cout <<"yes"<< endl;
		else
			cout <<"3no"<< endl;
	}
	return 0;
}
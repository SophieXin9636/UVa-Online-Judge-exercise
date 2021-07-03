#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define NUM 256
int output_seq[NUM];

struct Node
{
	int no; // number
	bool exist;
	Node *left;
	Node *right;
	Node(int value):no(value),exist(0),left(0),right(0){}
};

void free_node(Node *root){
	if(root == NULL) return;
	free_node(root->left);
	free_node(root->right);
	free(root);
}

bool BFS(Node *root){
	if(root == NULL) return false;
	int n = 0; // number of nodes
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		if(temp->no == -1) return false; // not complete
		output_seq[n++] = temp->no;
		if(n >= NUM) return false; // not complete

		if(temp->left != 0) q.push(temp->left);
		if(temp->right != 0) q.push(temp->right);
	}
	return true;
}

int main(){
	string node_in;
	int i;
	Node *root = new Node(-1);
	bool repeat = false;
	while(cin >> node_in){

		// output result
		if(node_in == "()"){
			// output
			if(BFS(root) && !repeat){
				for(i=0; output_seq[i]!=0; i++){
					cout << output_seq[i];
					if(i < NUM && output_seq[i+1]!=0) cout <<" ";
				}
				cout << endl;
			}
			else cout <<"not complete\n";
			free_node(root);
			root = new Node(-1);
			memset(output_seq, 0, sizeof(int)*NUM);
			repeat = false;
			continue;
		}

		// Declare & initialize
		int num = 0;
		// input num
		for(i=1; node_in[i]!=','; i++){
			num = num*10 + node_in[i]-'0';
		}
		Node *nd = new Node(num);
		// root case
		if(node_in[i] == ',' && node_in[i+1] == ')'){
			root->no = num;
			continue;
		}
		// other case: input direction
		Node *cur = root;
		Node *p = 0;
		bool d = 0; // 0:left 1:right
		for(i=i+1; ; i++){
			if(node_in[i]==')') break;
			p = cur;

			if(node_in[i] == 'L'){
				d = 0;
				cur = cur->left;
			}
			else{
				d = 1;
				cur = cur->right;
			}
			if(cur == 0){
				Node *t = new Node(-1);
				if(d == 0) p->left = t;
				else p->right = t;
				cur = t;
			}

		}
		if(!cur->exist){
			cur->no = num;
			cur->exist = 1;
		}
		else repeat = 1;
	}
	return 0;
}
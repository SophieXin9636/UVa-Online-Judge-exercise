#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct Alphabet{
	int n;
	int ascii;
}Alpha;

template <class T>
void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	string s;
	int i=0;
	while(getline(cin, s)){
		if(i!=0) cout << endl;
		if(s.length() > 1000) return 0;
		int ASCII[129] = {0};
		sort(s.begin(), s.end());

		for(int i=0; i<s.length(); i++)	ASCII[s[i]]++;
		
		Alpha frequencies[129];
		// init
		for(int i=0; i<=128; i++){
			frequencies[i].n = ASCII[i];
			frequencies[i].ascii = i;
		}
		
		for(int i=32; i<=128; i++){
			for(int j=32; j<=128-1; j++){
				if(frequencies[j].n > frequencies[j+1].n){
					Swap<Alpha>(frequencies[j], frequencies[j+1]);
				}
			}
		}
		
		for(int i=32; i<=128; i++){
			for(int j=32; j<=128-1; j++){
				if(frequencies[j].n == frequencies[j+1].n){
					if(frequencies[j].ascii < frequencies[j+1].ascii)
						Swap<Alpha>(frequencies[j], frequencies[j+1]);
				}
			}
		}
		
		
		for(int i=32; i<=128; i++){
			if(frequencies[i].n != 0)
				cout << frequencies[i].ascii << " " << frequencies[i].n << endl;
		}
		i++;
	}
	return 0;
}

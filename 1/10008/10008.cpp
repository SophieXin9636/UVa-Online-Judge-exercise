#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

typedef struct TimeOfLetter{
	char letter;
	int num;
}Letter;

int main(){
	int n;
	char buf;
	cin >> n;
	buf = cin.get();
	if(buf == ' ') cin.get();
	int a[91] = {0};
	Letter b[91];
	
	/* init */
	for(int i=65; i<=91; i++){
		b[i].letter = i;
		b[i].num = 0;
	}

	for(int i=0; i<n; i++){
		string s;
		getline(cin, s);
		for(int j=0; s[j] != '\0'; j++){
			a[toupper(s[j])]++;
		}
	}
	
	for(int i=65; i<=90; i++){
		b[i].num = a[i];
	}

	/* sort */
	for(int i=65; i<90; i++){
		for(int j=65; j<90; j++){
			if(b[j].num < b[j+1].num){
				char c_temp = b[j].letter;
				b[j].letter = b[j+1].letter;
				b[j+1].letter = c_temp;
				
				int temp = b[j].num;
				b[j].num = b[j+1].num;
				b[j+1].num = temp;
			}
		}
	}
	
	for(int i=65; i<=90; i++){
		if(b[i].num != 0)
			printf("%c %d\n", b[i].letter, b[i].num);
	}
	return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[10][10];
int x_move[8] = {-2, -1,  1,  2, 2, 1, -1, -2};
int y_move[8] = {-1, -2, -2, -1, 1, 2,  2,  1};

bool DFS(int x1, int y1, int x2, int y2, int num){

}

int main()
{
	char c_x1, c_x2;
	int y1, y2;
	while(cin >> c_x1 >> y1 >> c_x2 >> y2){
		int x1 = c_x1 - 'a' + 1, x2 = c_x2 - 'a' + 1;
		if(c_x1 == c_x2 && y1 == y2){
			printf("To get from %c%d to %c%d takes 0 knight moves.\n", c_x1, y1, c_x2, y2);
			continue;
		}

		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++)
				a[i][j] = -1;


	}
	return 0;
}
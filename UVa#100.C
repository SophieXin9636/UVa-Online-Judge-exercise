#include <stdio.h>

int main(void) {
	int i, j;
	int high, low;
	int count;
	while(scanf("%d %d", &i, &j) != EOF){
		int max = 1;
		if(i < j){
			high = j;
			low = i;
		}
		else{
			high = i;
			low = j;
		}
		for(count = low; count <= high; count++){
			int n = count;
			int times = 1;
			while(n != 1){
				if(n % 2 == 0) n /= 2;
				else n = 3*n+1;
				times++;
			}
			if(times > max) max = times;
		}
		printf("%d %d %d\n", i, j, max);
	}
}

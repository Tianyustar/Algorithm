#include <stdio.h>

int flag[4];
char sets[4] ={'a','b','c','d'};
char res[4];
void find(int pos) {
	if (pos == 4)  {		
		for (int i=0;i<4;i++) {
			printf("%c ",res[i]);
		}
		printf("\n");
		return ;
		
	}
	for (int i=0; i<4 ;i++) {
			if (!flag[i]) {
				res[pos] = sets[i];
				flag[i] = 1;
				find(pos+1);
				flag[i] = 0;
			}
	}
}
int main() {
	find(0);
	return 0;
} 

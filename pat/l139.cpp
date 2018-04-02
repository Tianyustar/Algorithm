#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

char map[100][100];
int main() {
	
	//freopen("in.txt","r",stdin);
	int n;
	char str[10003]={0};
	scanf("%d",&n);
	getchar();
	gets(str);
	int len = strlen(str);
	int height = n;
	int width = (len-1)/n ;
	int count = 0;
	for (int j=width;j>=0;j--) {
		for (int i=0;i<n;i++){
			if (str[count]!=0){
				map[i][j] = str[count];
				count++;
			}else {
				map[i][j]=' ';
			}
		}
	}
	
	for(int i=0;i<n;i++) {
		for (int j=0;j<=width;j++) {
			putchar(map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

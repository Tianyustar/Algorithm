#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
void  adjust(int heap[], int n) {
	if (n == 0) {
		return ;
	}
	if (heap[(n-1)/2] >  heap[n]) {
		swap( heap[n], heap[(n-1)/2]);
		adjust(heap, (n-1)/2);		
	}
}
void jude(char* words, int *position) {
	
	int node1=0 , node2 = -10001;
	int flag = 0;
	if (strstr(words, "root") != NULL) {
		sscanf(words,"%d is the root",&node1);
		if (position[node1+10000] == 0) flag =1;
		
	} else if (strstr(words,"siblings") != NULL) {
		sscanf(words, "%d and %d are siblings",&node1,&node2);
		int p1 = position[node1+10000];
		int p2 = position[node2+10000];
		if ((p1-1)/2 == (p2-1)/2) flag = 1;
		
	} else if (strstr(words, "parent")!=NULL) {
		sscanf(words, "%d is the parent of %d",&node1, &node2);
		int p1 = position[node1+10000];
		int p2 = position[node2+10000];
		if ( (p2-1)/2 == p1) flag = 1;
		
	}else if (strstr(words,"child") !=  NULL) {
		sscanf(words, "%d is a child of %d",&node1,&node2);
		int p1 = position[node1+10000];
		int p2 = position[node2+10000];
		if ( (p1-1)/2 == p2) flag = 1;
	}
	if (flag)  puts("T");
	else puts("F");
	
}
int main() {
	
	int n,m;
	int heap[1000];
	int position[20005];
	scanf("%d%d",&n,&m);	
	for (int i=0;i<n;i++){
		scanf("%d",&heap[i]);
		adjust(heap,i);
	}
	for (int i=0;i<n;i++) {
		position[heap[i]+10000] = i;	
	}
	getchar();
	char word[1000];
	for (int i=0;i<m;i++){
		gets(word);
		jude(word,position);
	}
	return 0;
} 

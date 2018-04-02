#include <string>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	
//	freopen("in.txt","r",stdin);
	char name[12] ="";
	char name2[12]="";
	char name14[12]="";
	int len=0;
	while(strstr(name,".")==NULL) {
		scanf("%s",name);
		len++;
		if (len == 2)  strcpy(name2,name);
		if (len == 14 && strstr(name,".")==NULL)   {
			strcpy(name14,name);
		}
		
	}

	if (len < 3) {
		puts("Momo... No one is for you ...");
	}else if (len < 15) {
		printf("%s is the only one for you...",name2);
	}else {
		printf("%s and %s are inviting you to dinner...",name2,name14);
	}
	return 0;
} 

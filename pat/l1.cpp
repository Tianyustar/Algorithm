#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int book[1005];
int main() {

//	freopen("in.txt","r",stdin);
	int index, hh, mm;
	char tag;
	int n;
	double time=0;
	int count = 0;
	memset(book,-1,sizeof(book));
	scanf("%d",&n);
	while(n) {
		scanf("%d %c %d:%d", &index, &tag, &hh, &mm);
		if (index == 0) {
			printf("%d %.0f\n", count, count ? time/count : 0);
			memset(book, -1, sizeof(book));
			time = 0;
			count = 0;
			n--;
		} else {
			if (tag == 'S') {
				book[index] = hh*60 + mm;
			} else if (tag == 'E') {
				if (book[index] != -1) { // 有效的借阅记录
					count++;
					time += hh*60 + mm - book[index];
					book[index] = -1;
				}
			}
		}
	}
	return 0;
}

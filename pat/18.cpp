#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

typedef struct node {
	float c; // 系数
	int e; //指数
} ELEMENT;

vector<ELEMENT> N1,N2,Res;

vector<ELEMENT> div(vector<ELEMENT> num1,int n1, int n2) { // 返回结果的禅读 , 递归

	ELEMENT elem;
	vector<ELEMENT> result;
	result.clear();
	elem.e = num1[0].e - N2[0].e;
	elem.c = num1[0].c / N2[0].c;

	if (fabs(elem.c) >= 0.05)  Res.push_back(elem);  // shang
	int pos1=1,pos2=1;
	while(pos1 < n1 && pos2 < n2) {
		ELEMENT a;
		if (num1[pos1].e == (N2[pos2].e + elem.e)) {
			a.c = num1[pos1].c - (N2[pos2].c * elem.c);
			a.e = num1[pos1].e;
			result.push_back(a);
			pos1++;
			pos2++;
		} else if ( num1[pos1].e > (N2[pos2].e + elem.e)) {
			result.push_back(num1[pos1]);
			pos1++;
			
		} else if ( num1[pos1].e < (N2[pos2].e + elem.e) ) {
			a.c = 0-(N2[pos2].c *elem.c);
			a.e = N2[pos2].e + elem.e;
			result.push_back(a);
			pos2++;
		}
	}
	while (pos1 < n1) {
		result.push_back(num1[pos1++]);

	}
	while (pos2 < n2) {
		ELEMENT a;
		a.c = 0-(N2[pos2].c *elem.c);
		a.e = N2[pos2].e + elem.e;
		result.push_back(a);
		pos2++;

	}
	return result;
}
int main() {

//	freopen("in.txt","r",stdin);
	int n1,n2;
	scanf("%d",&n1);  // 被出数
	ELEMENT elem;
	for (int i=0; i<n1; i++) {
		scanf("%d%f",&elem.e,&elem.c);
		N1.push_back(elem);
	}
	scanf("%d",&n2);

	for (int i=0; i<n2; i++) {
		scanf("%d%f",&elem.e,&elem.c);
		N2.push_back(elem);
	}
	int i=0;
	while (N1.size()!=0 && N2.size()!=0 && N1[0].e >= N2[0].e) {
		N1 = div(N1,N1.size(),N2.size());  // 得到结果
//		for (int i=0; i<N1.size(); i++) {
//			printf("%d %.2f || ",N1[i].e, N1[i].c);
//		}

	}
	printf("%d",Res.size());
	if (Res.size() == 0) {
		printf(" 0 0.0");
	} 
	for (int i=0; i<Res.size(); i++) {
		printf(" %d %.1f",Res[i].e, Res[i].c);
	}
	printf("\n");
	int count  = 0;
	for (int i=0;i<N1.size();i++) {
		if (fabs(N1[i].c)>= 0.05) count++;
	}
	printf("%d",count);
	if (count > 0) {
		for (int i=0;i<N1.size();i++)
		if (fabs(N1[i].c) >= 0.05) 
		printf(" %d %.1f",N1[i].e , N1[i].c );
	} else 
	printf(" 0 0.0");
	return 0;
}

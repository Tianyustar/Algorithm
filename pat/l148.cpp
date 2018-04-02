#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

void read_num(int r, int c, int ma[100][100]) {
	for (int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>ma[i][j];
		}
	}
}


int main() {


	freopen("in.txt","r",stdin);
	int ra, ca, rb, cb;
	int maA[100][100];
	int maB[100][100];
	int res[100][100]= {0};
	cin >> ra >> ca;
	read_num(ra,ca,maA);
	cin >> rb >> cb;
	read_num(rb, cb, maB);
	if (ca != rb) {
		cout <<"Error: "<< ca << " != " << rb << endl;
	} else {
		for (int i=0; i<ra; i++) {
			for (int j=0; j<cb; j++) {
				for (int k=0; k<ca; k++) {
					res[i][j] += maA[i][k]*maB[k][j];
				}
			}
		}
		cout << ra << " " << cb << endl;
		for (int i=0; i<ra; i++) {
			for (int j=0; j<cb-1; j++) {
				cout<<res[i][j]<< " ";
			}
			cout<<res[i][cb-1]<< " ";
			cout<<endl;
		}
	}

	return 0;
}

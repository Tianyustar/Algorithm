#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	
	
	for (int i=2;i<10000;i++){
		int dist = i*127;
		if ((dist-1)%97==0 || (dist+1)%97==0) {
			cout<<i<<endl;
			cout<<(dist+1)/97<<endl;
			cout<<dist<<endl;
			break;
		}
		
	}
	return 0;
}

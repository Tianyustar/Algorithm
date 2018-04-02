#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std; 
int main() {
	
	int a, b, r;
	cin >> a;
	string c="";
	b=1;
	int count = 1;
	while(b < a ) {
		b=b*10+1;
		count++;	
	}
	
    c += '0' + b/a;
    r = b%a ;
    b = (b%a)*10 + 1;
	;
	while(r) {
		c += '0'+b/a;
		r = (b%a); 
		b = (b%a)*10 + 1;
		
		count++;
	}
	
	cout << c <<" "<<count << endl;

	return 0;
}

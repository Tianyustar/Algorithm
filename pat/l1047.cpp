#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std; 
int main() {
	
	int n;
	string name;
	int a, b;
	cin >> n;
	while(n--) {
		cin >> name >> a >>b;
		if (a < 15 || a > 20  || b < 50 || b > 70){
			cout << name <<endl;
		}
	}
	return 0;
}

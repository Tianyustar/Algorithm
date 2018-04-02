#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std; 
int main() {
	
	
	freopen("in.txt","r",stdin);
	int n;
	string str;
	map<string,string> Map;
	Map["ChuiZi"] = "Bu";
	Map["Bu"] ="JianDao";
	Map["JianDao"] = "ChuiZi" ;
	cin >> n;
	cin >> str;
	int count = 0;
	while(str.compare("End") ) {
		
		cout<<"----" <<str << endl;
		
		if (count!=n) {
			cout<<Map[str] <<endl;
			count++;
		
		}else {
			cout<<str<<endl;
				count=0;
		}
		cin>>str;
		
	}
	return 0;
} 

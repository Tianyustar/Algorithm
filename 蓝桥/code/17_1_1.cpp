#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	for (int year = 1800; year < 1900; year++) {
		for (int age = 40; age < 50; age++) {
			if (age*age == year+age){
				cout<< age <<endl;
				cout << year <<endl;
				cout<< age*age<<endl;
				return 0;
			}
		}
	}
	
	return 0;
 } 


#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std; 

int compare(const char* s1, const char* s2)
{
	if(s1==NULL && s2==NULL) return 0;
	if(s1==NULL) return -1;
	if(s2==NULL) return 1;
	
	if(*s1 == 0 && *s2== 0) return 0;
	if(*s1 == 0) return -1;
	if(*s2 == 0) return 1;
	
	if(*s1<*s2) return -1;
	if(*s1>*s2) return 1;
	
	int t = compare(s1+1,s2+1);
	if(t==0) return 0;
	
	return t > 0 ? 1+t:t-1; //Ìî¿ÕÎ»ÖÃ
}


int main()
{
	printf("%d\n", compare("abc","abk"));
	printf("%d\n", compare("abc","a"));
	printf("%d\n", compare("abcde","abcda"));
	return 0;
}

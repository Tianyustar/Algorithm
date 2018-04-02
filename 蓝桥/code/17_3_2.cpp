#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std; 
int flag['z'+1]={0};
long long value[20]={1,1,0};
void init() {
	for (int i=2;i<20;i++)
		{
			value[i] = value[i-1]*i;
		}
} 

int getCount(char letter) {
	
	int count = 0;
	
	for (int i='a';i<letter;i++) {
		if (flag[i]==0) count++;
	}
	flag[letter] = 1;
	return count;
}
int main()
{
	char str[1000]="bckfqlajhemgiodnp";
	init();
	long long result=0;
	int len = strlen(str);
	for (int i=0;i<len-1;i++) {
	//	putchar(str[i]);
		result += value[len-i-1]*getCount(str[i]);
	}
	cout << result << endl;
	return 0;
}

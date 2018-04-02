#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std; 
int main()
{
	char letter[27]={0};
	for (int i=0;i<17;i++)
		letter[i] = 'a'+i;
		puts(letter);
	long long  count = 0;
	while(strcmp(letter,"bckfqlajhemgiodnp")) {
		count++;
		if (!next_permutation(letter,letter+17)) break;
	//	puts(letter);
	}
	
	cout << count << endl;
	return 0;
 } 

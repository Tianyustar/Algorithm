#include <iostream>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    int num[4]={0,1,2,3};  
  // char num[4] ={'a','b','c','d'};
    do  
    {  
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<" "<<num[3]<<endl;  
    }while(next_permutation(num,num+4));  
    return 0;  
}  

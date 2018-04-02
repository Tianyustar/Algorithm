#include <iostream>  
#include <cstdio>  
#include <stack>  
using namespace std;  
const int MAX = 1e5;  
stack<int> stk;  
int bitree[MAX + 10];  
int N;  
inline int lowbit(int x)  
{  
    return x&(-x);  
}  
void add(int pos,int x)  
{  
    while(pos <= MAX)  
    {  
        bitree[pos] += x;  
        pos += lowbit(pos);  
    }  
}  
int sum(int pos)  
{  
    int res = 0;  
    while(pos > 0)  
    {  
        res += bitree[pos];  
        pos -= lowbit(pos);  
    }  
    return res;  
}  
bool check(int x,int size)  
{  
    if(N&2 == 0)  
        return sum(x) >= size/2;   
    else return sum(x) >= (size+1)/2;  
}  
int main()  
{  
    scanf("%d",&N);  
    char ops[20];  
    for(int i = 0;i < N;i++){  
        scanf("%s",ops);  
        if(ops[1] == 'o')  
        {  
            if(stk.empty())  
                puts("Invalid");  
            else{  
                int val = stk.top();stk.pop();  
                add(val,-1);  
                printf("%d\n",val);  
            }  
        }  
        else if(ops[1] == 'u')  
        {  
            int val;scanf("%d",&val);  
            stk.push(val);  
            add(val,1);  
        }  
        else  
        {  
            if(stk.empty()){puts("Invalid");continue;}  
              
            int l = 0,r = MAX;  
            while(l < r)  
            {  
                int m = (l+r)/2;  
                if(check(m,stk.size()))  
                    r = m;  
                else  
                    l = m+1;  
            }  
            printf("%d\n",l);  
        }  
    }  
    return 0;  
 }

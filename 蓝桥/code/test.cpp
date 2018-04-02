#include<cstdio>
#include<stack>
#include <iostream> 
#include<cstring>
using namespace std;
int main()
{
	char x[25];
	char c;
	int a,b,e;
	int i;
	int z=0;
	stack<char> s1,s2,d;
	stack<int> s; 
	gets(x);
	for(i=0;i<strlen(x);i++)
		d.push(x[i]);
	gets(x);
	for(i=0;i<strlen(x);i++)
		s1.push(x[i]);
	gets(x);
	for(i=0;i<strlen(x);i++)
		s2.push(x[i]);



	while(!s1.empty() || !s2.empty())
	{
		a=b=e=0;
		if(!s1.empty())
		{
			c=s1.top();
			s1.pop();
			a=c-'0';
		}
		printf("a:%d  ",a);
		if(!s2.empty())
		{
			c=s2.top();
			s2.pop();
			b=c-'0';
		}
		printf("b:%d  ",b);
		c=d.top();
		d.pop();
		e=c-'0';
		if(e==0)
			e=10;
		printf("e:%d    ",e);
		a=a+b+z;
		z=a/e;
		a=a%e;
		printf("z:%d  \n",z);
		s.push(a);
	}

	if(z)
		s.push(z);

	a=0;
	while(!s.empty())
	{
		a=a*10+s.top();
		s.pop();
	}

	printf("%d\n",a);
	return 0;
}


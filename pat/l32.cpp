//可以用树状数组解决问题，其中每当有元素入栈时 就把下表位置（树状）+1
// 那么sum（x）就变成了不超过x的元素的个数 

// question  和普通的记录然后算相比，速度快？  数组开的这么大，要维护的树状数组自然也就大，不会耗费开销吗？ 
//  速度应该时算sum（x） 即不超过x的元素的个数的速度 
//  如果用前缀法去计算和，那么效率也会很低，因为有元素更新

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack> 
#include <string.h>
#define MAX 10000

using namespace std;
int N;
int  bittree[MAX + 10];// 树状数组
 
inline int lowbit(int x) { // 使用内联，加快速度 
	return x&(-x); 
}

void add(int pos, int x){
	
	for (int i=pos;i<MAX;i += lowbit(i)) {
			bittree[i] += x;
	}
}

int sum(int pos) {
	
	int res = 0;
	for (int i=pos; i>0 ; i -= lowbit(i)) {
		res += bittree[i];
	//	printf(" i = %d\n",i);
	}
	return  res;
}

//bool check(int x , int size) {
//	if (N&2) return sum(x) >= (size+1)/2;
//	return sum(x) >= size/2;
//	
////	puts("have return ");
//}

bool check(int x,int size)  
{  
    if(N&2 == 0)  
        return sum(x) >= size/2;   
    else return sum(x) >= (size+1)/2;  
}  

int main() {
	
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	stack<int> num_stack;
	char command[10]={0};
	N = n;
	while(n--) {
		scanf("%s",command);
		if (strstr(command,"Pop")){
			if (num_stack.empty()) {
				puts("Invalid");
			}else {
				int value = num_stack.top();
				num_stack.pop();
				add(value,-1);// 下标位置减去1 
				printf("%d\n",value);
			}
		}else if (strstr(command,"Push")) {
			int value;
			scanf("%d",&value);
			num_stack.push(value);
			add(value,1); // 下标位置加上1  位数树状数组 
		} else {
			if (num_stack.empty())  {
				
				puts("Invalid");
				continue;
			}
			int l = 0, r = MAX;// MAX 实际上可以被减小开销，但是感觉得不偿失，没有必要
			
			while(l< r) {
			//	 puts("-------");
				int m = (l+r)/2 ; //  二分
			//	printf("size %d  \n", num_stack.size());
				if (check(m, num_stack.size())) {
					r = m;
				//	 puts("++++++++");
				} else {
				//	puts("++++++++++");
					l=m+1; 
				}
				  
				  
				 // puts("-------");
			}// 之所以不设置为找到之后就停止 是因为必须找到存在的那个值
			printf("%d\n",l); 
			
		} 
	}
	
	return 0;
}

// 线段树做法，其中sum的含义是不超过x的个数，每当pop一个元素，对用线段树下标-1  并更新
// 每当push一个元素 对应线段树 下标+1 并更新

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#define MAX 100005

using namespace std;

typedef struct node {
	int left;
	int right;
	int value;
} NODE;

NODE line_tree[4*MAX+10];

void push_up(int index) { //  更新
	line_tree[index].value = line_tree[index<<1].value + line_tree[index<<1|1].value;// 左移并且 +1
}

// 建树

void build(int left , int right ,int index) {

	line_tree[index].left = left;
	line_tree[index].right = right;
	if (left == right) return ;// 叶子节点  实际上应该是要相加，但是由于我们的线段树是一颗初始全为0的数 所以不需要加上叶子
	int mid = (left + right)  >> 1;
	build(left,mid,index<<1);//  左树
	build(mid+1,right,index<<1|1);// 右树
	// push_up(index);//  必须更新，但是由于初始为0 所以没有必要去更新
}

// 更新


//  感觉这个更新很奇怪。。。。认为有很多不需要的东西
//void update(int left, int right, int index, int pos, int value) // 更新  index 代表下标, pos为目标地址
//{
//	if (line_tree[index].left == line_tree[index].right && index == pos ) { // 只更新了一个节点？？？？？
//		line_tree[index].value += value;
//		return ;
//	}
//	int mid = (line_tree[index].left + line_tree[index].right) >> 1; //分
//	if  (mid >= pos) {
//		update(left, mid, index<<1, pos, value);// 如果mid >= pos  那么说明在左子树
//	} else {
//		update(mid+1, right, index<<1|1,pos, value) ; // 如果mind  <= pos 那么说明在右子树
//	}
//	line_tree[index].value += line_tree[index<<2].value + line_tree[index<<2|1].value;// 更新父节点
// }
//
// 更新
void Update(int index, int pos, int value) {

//	printf("index = %d pos = %d value  = %d\n ",index, pos, value);
//	printf("left = %d  right = %d  value = %d\n ",line_tree[index].left, line_tree[index].right, line_tree[index].value);
	if (line_tree[index].left == line_tree[index].right && line_tree[index].right == pos) {
		line_tree[index].value += value;
		return ; // 一定要记得return
	}
	//  如果pos <= 左子树 的right
	if (pos <= line_tree[index<<1].right)  {
		Update(index<<1,pos,value);
	} else {
		Update(index<<1|1,pos,value);// 去右子树
	}
	line_tree[index].value = line_tree[index<<1].value + line_tree[index<<1|1].value;

}

// 查询位置

int query(int index,int sum )  { // i 代表线段树的第i个节点， sum代表要查询的第k大的树

	//printf("index = %d sum =  %d\n",index, sum);
	//printf("index = %d left = %d right = %d value = %d\n",
	    //   index, line_tree[index].left, line_tree[index].right, line_tree[index].value);
	if (line_tree[index].left == line_tree[index].right) {

		return line_tree[index].left;
	}
	if (sum <= line_tree[index<<1].value) { // 如果小于等于左子树的值 ，那么在做子树 需要注意的是这里一定要加等于号
		return 	query(index<<1, sum);
	} else
		return  query(index<<1|1, sum-line_tree[index<<1].value); // 向右边查询 要减去左子树的值 
}
int main() {
	int n;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	stack<int> num_stack;
	char command[10]= {0};
	build(0,MAX,1); // 从1 到 MAX 建立树 ,1为起点
	while(n--) {
		scanf("%s",command);
		if (strstr(command,"Pop")) {
			if (num_stack.empty()) {
				puts("Invalid");
			} else {
				int value = num_stack.top();
				num_stack.pop();
				Update(1,value,-1);  // 从起点更新
				printf("%d\n",value);
			}
		} else if (strstr(command,"Push")) {
			int value;
			scanf("%d",&value);
			num_stack.push(value);
			Update(1,value,1) ;// 下标位置加上1  位数树状数组
		} else {
			if (num_stack.empty())  {
				puts("Invalid");
				continue;
			}
			int len = num_stack.size();
			//printf("len = %d \n",len);
			if (len%2) {
				//	puts("mod 1");
				printf("%d\n",query(1,(len+1)/2));
				//	printf("len +1 /2 = %d \n",(len+1)/2);
			} else {
				//	puts("mod 2");
				printf("%d\n",query(1,len/2));
			}


		}
	}
	return 0;
}

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef struct node{
	int addr;
	int value;
	int next;
}Node;
int main() {
	
	//freopen("in.txt","r",stdin);
	vector<Node> list,new_list;
	Node nodes_list[100000];
	Node node;
	int head,n;
	scanf("%d%d",&head,&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&node.addr,&node.value,&node.next);
		nodes_list[node.addr] = node;
	}
	int p = head;
	while(p!=-1){
		list.push_back(nodes_list[p]);
		p = nodes_list[p].next;
	}
	int front=0,tail = list.size()-1;
	while(front < tail){
		new_list.push_back(list[tail]);
		new_list.push_back(list[front]);
		front++;
		tail--;
	}
	if (front == tail)  new_list.push_back(list[front]);
	for (int i=0;i<new_list.size()-1;i++)
			printf("%05d %d %05d\n",new_list[i].addr,new_list[i].value,new_list[i+1].addr);
	printf("%05d %d -1\n",new_list[new_list.size()-1].addr,new_list[new_list.size()-1].value);
	
	return 0;
} 

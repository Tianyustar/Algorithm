#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;


int count = 0;
int flag[10]= {0};
vector<int> numbers;

bool isDiff(int num,int *flag) {
	char arr[12]= {0};
	sprintf(arr,"%d",num);

	bool tag = true;
	for (int i=0; i<strlen(arr); i++) {
		if (flag[arr[i]-'0'] )  tag = false;
		flag[arr[i]-'0']++;
	}
	return tag;
}

void reverse(int num, int *flag) {
	char arr[12]= {0};
	sprintf(arr,"%d",num);
	for (int i=0; i<strlen(arr); i++) {
		flag[arr[i]-'0']--;  //
	}
}

int countFlag(int *flag) {
	int count = 0;
	for (int i=0; i<10; i++) {
		if (flag[i]) count++;
	}
	return count;

}
// 记录一下 
int write[10]={0};
// 暴力递归 选或者不选
int find(int start,int index) {
	
	if (start >= numbers.size())  return 0;  // 查找到头 
	if (countFlag(flag)==10)  { // 递归成功 
		count++;
		cout<<"\n-------"<<endl;
		for (int i=0;i<index;i++) {
			cout<< write[i] <<"  ";
		}
		cout << "\n----------------"<<endl;
		return 1;
	}
	int value=0;
	if (isDiff(numbers[start],flag)) { // 符合条件,并且选择 
		  write[index] = numbers[start];
		  find(start+1,index+1);
	}
	//  回溯
	reverse(numbers[start], flag);//   不选择 
	find(start+1,index); 
	return 0; 
}
	int main() {


		// init
		int getNum[10]= {0};
		for (int i=0; i<=100000; i++) {
			memset(getNum,0,sizeof(getNum));
			if (isDiff(i*i,getNum))  {
			//	cout<< i*i <<endl;
				numbers.push_back(i*i);
			}
		}
		cout << numbers.size() << endl;
		find(0,0);
		cout << "\n*******" << endl;
		cout << count << endl;
		return 0;
	}

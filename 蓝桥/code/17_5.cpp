#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
// 似乎是有经度问题？ 
double left(double r, int money, int month) {
	
	double left_money = 1000000;// 剩余本金 
	for (int i=0;i<month;i++) {
			left_money = left_money*(r+1) - money;
	}
	return fabs(left_money);
}
int main() {
	
	double r;
	int money;
	int month;
	scanf("%lf%d",&r,&month);
	r =  r/(12*100);
	money = 1000000/month;
	int min_give = 100000000;
	double min_left  = 100000000;
	for (int give = money; give<=1000000;give++) {
			double money_left = left(r,give,month);
		//	cout << money_left << endl;
			if (money_left < min_left){
				min_give = give;
				min_left = money_left;
			}
	}
	cout<<min_give<<endl;
	cout << min_left<<endl;
	
	
	return 0;
} 

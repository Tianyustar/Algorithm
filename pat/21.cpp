#include <iostream>
#include<cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
typedef struct node{
	string name;
	int count;
	double aver;	
}Person;
bool cmp(Person per1, Person per2) {
	if (per1.count > per2.count) return true;
	if (per1.count == per2.count) {
			if (per1.aver < per2.aver)
					return true;
	}
	return false;
}
int main()
{
	
	//freopen("in.txt","r",stdin);
	int n,k,tag;
	vector<Person> person;
	cin>>n;
	for (int i=0;i<n;i++) {
		set<int> Set; 
		Person per;
		cin>>per.name;
		cin>>k;
		for (int i=0;i<k;i++) {
			cin>>tag;
			Set.insert(tag);
		}
		per.count = Set.size();
		per.aver = k*1.0/per.count;
		person.push_back(per);
	}
	sort(person.begin(), person.end(),cmp);
	int i;
	for (i=0;i<2&&i<person.size();i++) {
		cout<<person[i].name+" ";
	}
	for (i=i;i<2;i++) cout<<"- ";
	if (person.size() < 3) cout<<"-";
	else {
		cout<<person[2].name;
	}
	return 0;
}

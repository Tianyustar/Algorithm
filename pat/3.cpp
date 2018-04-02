#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int father[10000+1];
int p[10000+1];
set<int> s;
int n;
int find(int x){
    if(x!=father[x]) return father[x]=find(father[x]);
    return x;
}
int main(){
	
	freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=10000;i++)  father[i]=i;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int num,nm;
        cin>>nm;
        s.insert(nm);
        nm=find(nm);
        for(int j=1;j<m;j++){
             cin>>num;
             s.insert(num);
             father[find(num)]=nm;
        }
    }
    cout<<s.size();
    set<int> s2;
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        s2.insert(find(*it));
    }
    cout<<" "<<s2.size()<<endl;
    int l;
    cin>>l;
    for(int i=0;i<l;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"Y"<<endl;
        }
        else    cout<<"N"<<endl;
    }
    return 0;
}

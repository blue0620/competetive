#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdlib.h>
#include <set>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)


int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	REP(i,n){
		cin>>a[i];
	}
	vector<int>l(m);
	REP(i,m){
		cin>>l[i];
	}
	int ans[100001];
	set<int>num;
	int t=0;
	for(int i=n-1;i>=0;i--){
		if(num.find(a[i])==num.end()){
			num.insert(a[i]);
			t++;
		}
		ans[l[i]-1]=t;
	}
	REP(i,m){
		cout<<ans[l[i]-1]<<endl;
	}
	return 0;
}
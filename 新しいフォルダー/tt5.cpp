#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
	int n,d;
	cin>>n>>d;
	vector<int>a(n);
	REP(i,n){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int m;
	cin>>m;
	int ans=0;
	REP(i,m){
		if(i<n){
			ans+=a[i];
		}else{
			ans-=d;
		}
	}
	cout<<ans<<endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(long i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(long i = 0; i < (long)(n); ++i)

int main(){
	string sn;
	cin>>sn;
	long m;
	cin>>m;
	vector <string>ans;
	REP(i,m){
		long l,r;
		cin>>l>>r;
		string q=sn.substr(l-1,r-l+1);
		int c[3]={0};
		
		if(r-l<3){
			ans.push_back("YES");
		}else{
		FOR(j,0,r-l+1){
			if(q[j]=='x'){
				c[0]++;
			}else if(q[j]=='y'){
				c[1]++;
			}else{
				c[2]++;
			}
		}
		if(c[0]&&c[1]&&c[2]){
			if(max(c[0],max(c[1],c[2]))-min(c[0],min(c[0],c[1]))==0){
				ans.push_back("YES");
			}else if(max(c[0],max(c[1],c[2]))-min(c[0],min(c[0],c[1]))==1){
				ans.push_back("YES");
			}else{
				ans.push_back("NO");
			}
		}else{
			ans.push_back("NO");
		}
		}
		
	}
	REP(i,m){
		cout<<ans[i]<<endl;
	}
	return 0;
}
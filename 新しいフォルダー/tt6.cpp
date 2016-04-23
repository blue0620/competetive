#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <set>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)


int StringToInt(string str)
	{
  	stringstream ss;
	int number;
	ss<<str;
  	ss >> number;
  	return number;
}
int main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	FOR(i,0,n){
		string t;
		cin>>t;
		set<int>num;
		bool c=true;
		long tl=t.size();
		for(long j=0;j<tl;j++){
			num.insert(StringToInt(t.substr(j,1)));
		}
		int tt=0;
		set<int>::iterator it=num.begin();
		if(*it!=0) c=false;
		for(long j=0;j<tl;j++){
			if(*it==tt+1||*it==tt){
			}else{
				c=false;
				break;
			}
			tt=*it;
			it++;
		}
		
		if(c&&tt==k) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
//#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

#define MAX_N 30000
typedef __int64 LL;


int main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	int st[51];
	bool flag=false;
	REP(i,n){
		if(str[i]=='B'){
			flag=true;
			st[i]=1;
		}else{
			st[i]=0;
		}
	}
	if(!flag){
		cout<<0<<endl;return 0;
	}
	LL ans=0;
	while(true){
		int i=0;
		while(st[i]==0){
			if(i==n-1){
				cout<<ans<<endl;
				return 0;
			}
			i++;
		}
		st[i]=0;
		REP(j,i)st[j]=1;
		ans++;
	}
	return 0;
}
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
//typedef long long ll;
int a[100001];
int t[100001];
int ans[100000];
int main(){
	int n,k,w;
	cin>>n>>k>>w;
	string str;
	cin>>str;
	REP(i,n)a[i+1]=(str[i]=='1')?1:0;
	REP(i,w){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			if((j-l+1)%k==0&&a[j]==1){
			}else if((j-l+1)%k!=0&&a[j]==0){
			}else{
				//cout<<j<<endl;
				ans[i]++;
			}
		}
		
	}
	REP(i,w)cout<<ans[i]<<endl;
	
	return 0;
}

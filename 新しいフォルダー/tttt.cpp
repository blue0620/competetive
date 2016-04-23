#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

#define MAX_N 30000
//typedef __int64 LL;

int keta[1000001];
int ans[1000001];
int main(){
	int x,p;
	cin>>p>>x;
	
	if(p==1){
		if(x==1)cout<<"1"<<endl;
		else cout<<"Impossible"<<endl;
		return 0;
	}
	int p2=10*x-1;
	bool flag=false;
	for(int j=2;j<=9;j++){
		REP(k,p){
			if(k==0){
				keta[k]=j-1;
			}else if(k==p-1){
				keta[k]=10-j;
			}else{
				keta[k]=9;
			}
		}
		int i=0,kuri=0;
		while(i<p){
			if((keta[i]+kuri*10)/p2>0){
				kuri=(keta[i]+kuri*10)%p2;
				ans[i]=(int)(keta[i]+kuri*10)/p2;
				i++;
			}else{
				kuri=kuri*10+keta[i];
				ans[i]=0;
				i++;
			}
		}
		if(kuri==0)flag=true;
	}
	if(flag){
		REP(i,p)cout<<ans[i];
		cout<<endl;
		return 0;
	}
	
	cout<<"Impossible"<<endl;
    return 0;
}
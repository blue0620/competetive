#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
typedef __int64 ll;


ll c=0;
ll shori(ll w,ll m,ll k,ll p){
	int keta=(int)log10(m);
	while(w>0){
		ll temp=(keta+1)*k*p;
		if(w>=temp){
			w-=temp;
			c+=p;
			m+=p;
		}else if(w<1000){
			w-=(keta+1)*k;
            if(w<0)break;
            c++;
		}else{
			p/=10;
			shori(w,m,k,p);
		}
	}
	return 0;
}



int main(){
	ll w,m,k;
	cin>>w>>m>>k;
	while(w>0){
		int keta=(int)log10(m)+1;
		ll p=1;
		REP(i,keta)p*=10;
		ll temp=keta*k*(p-m);
		if(w>=temp){
			w-=temp;
			c+=(p-m);
			m=p;
		}else{
			p/=10;
			shori(w,m,k,p);
			break;
		}
	}
	cout<<c<<endl;
	return 0;
}
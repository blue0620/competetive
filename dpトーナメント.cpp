#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define CLR(a) memset((a), 0 ,sizeof(a))
double P[1030],tP[1030];
int r[1025];
int N;
double calc(int i,int j){
	return 1.0/(1+pow(10.0,(r[j]-r[i])/400.0));
}

void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	FOR(i,l,r+1)tP[i]=0.0;
	FOR(i,l,mid+1)FOR(j,mid+1,r+1){
		tP[i]+=P[i]*P[j]*calc(i,j);
		tP[j]+=P[i]*P[j]*calc(j,i);
	}
	FOR(i,l,r+1)P[i]=tP[i];
}
int main(){
	cin>>N;
	REP(i,1<<N){
		cin>>r[i];
		P[i]=1.0;
	}
	solve(0,(1<<N)-1);
	REP(i,1<<N)cout<<fixed<<setw(10)<<P[i]<<endl;
	return 0;
}
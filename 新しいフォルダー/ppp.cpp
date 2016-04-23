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
//typedef __int64 LL;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

#define MAX_N 1000000
#define MAX_LL 10000000000

typedef pair<int,int> P;//first‚ÍÅ’Z‹——£,second‚Í’¸“_”Ô†

int ab[1001][1001];
int cd[1001][1001];
int abm[1001],cdm[1001];



int main(){
	REP(i,1001)REP(j,1001)ab[i][j]=cd[i][j]=MAX_N;
	int n1,m1,n2,m2;
	cin>>n1>>m1;
	REP(i,m1){
		int a,b;
		scanf("%d%d",&a,&b);
		ab[a][b]=ab[b][a]=1;
	}
	
	cin>>n2>>m2;
	REP(i,m2){
		int c,d;
		scanf("%d%d",&c,&d);
		cd[c][d]=cd[d][c]=1;
	}
	
	REP(k,n1)REP(i,n1)REP(j,n1){
		if(i!=j)ab[i][j]=min(ab[i][j],ab[i][k]+ab[k][j]);
		//cout<<ab[1][3]<<endl;
	}
	
	REP(i,n1)REP(j,n1){
		if(i!=j){
			abm[i]=max(abm[i],ab[i][j]);
		}
	}
	
	REP(k,n2)REP(i,n2)REP(j,n2){
		if(i!=j)cd[i][j]=min(cd[i][j],cd[i][k]+cd[k][j]);
	}
	REP(i,n2)REP(j,n2){
		if(i!=j){
			cdm[i]=max(cdm[i],cd[i][j]);
		}
	}
	sort(abm,abm+n1);sort(cdm,cdm+n2);
	
	int abmin=abm[n1-1]/2+abm[n1-1]%2;
	int cdmin=cdm[n2-1]/2+cdm[n2-1]%2;
	abmin=max(abmin,abm[0]);
	cdmin=max(cdmin,cdm[0]);
	int ans1=max(abmin+cdmin+1,max(abm[n1-1],cdm[n2-1]));
	int ans2=abm[n1-1]+cdm[n2-1]+1;
	//cout<<abmin<<" "<<cdmin<<endl;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
/*
4 4
0 1
1 2
2 3
3 0
4 4
0 1
1 2
2 3
3 0
*/
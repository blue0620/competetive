#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(long i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define REP1(i,n) for(int i = 1; i <= (int)(n); i++)

int N[50001];
int A[50001];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int ans1=0,ans2=0;
	REP1(i,n){
		int tn;
		scanf("%d",&tn);
		if(tn){
			N[i]=1;ans1++;
		}
	}
	ans1=ans1*(ans1-1)/2;
	REP(i,m){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		if(N[t1]&&N[t2])A[t1]=A[t2]=1;
	}
	REP1(i,n)if(A[i])ans2++;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
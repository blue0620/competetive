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
int A[1001];
int B[1001][1001];
//int C[1001][1001];
int D[1001];
int sum[5];

int main(){
	int T;
	scanf("%d",&T);
	REP(k,T){
		int K,N,M;
		scanf("%d%d%d",&N,&M,&K);
		REP1(i,N)scanf("%d",&A[i]);
		REP1(i,N)REP1(j,M)scanf("%d",&B[i][j]);
		REP1(i,N)REP1(j,M){
			int c;
			scanf("%d",&c);
			D[i-1]=max(B[i][j]-B[i][A[i]]-c,D[i-1]);
		}
		sort(D,D+N,greater<int>());
		REP1(i,N)sum[k]+=B[i][A[i]];
		REP(i,K){
			//cout<<D[i]<<endl;
			if(i>=N||D[i]<=0)break;
			sum[k]+=D[i];
		}
	}
	
	REP(k,T)cout<<sum[k]<<endl;
	return 0;
}
/*
2
4 2 8
1 1 2 2
1 1
1 1
3 1
3 1
0 1
0 1
1 0
1 0
4 3 1
1 1 2 2
1 1 1
1 1 2
1 1 2
3 1 1
0 1 0
0 1 0
1 0 0
1 0 0
*/

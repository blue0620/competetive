#include<iostream>

#define MAX_N 20
#define INF 1000000
int n;
int d[MAX_N][MAX_N];

int dp[1<<MAX_N][MAX_N];
//既に訪れた頂点がS,現在位置がv
int rec(int S,int v){
	
	if(dp[S][v]>=0){
		return dp[S][v];
	}
	if(S==(1<<n)-1&&v==0){
		//すべての頂点を回って戻ってきた
		return dp[S][v]=0;
	}
	int res=INF;
	for(int u=0;u<n;u++){
		if(!(S>>u & 1)){
			res=min(res,rec(S|1<<u, u))+d[v][u]);
		}
	}
	return dp[S][v]=res;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<endl;
}



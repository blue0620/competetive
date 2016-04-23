#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stdio.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)
int mincost[MAX_V];//集合Xからの辺の最小コスト
bool used[MAX_V];//既に使われたかどうかのフラグ
int V;//頂点数


///////////////////////////これだと計算量O(|V|^2)
int prim(){
	REP(i,V){
		mincost[i]=INF;
		used[i]=false;
	}
	mincost[0]=0;
	int res=0;//辺の総コスト
	
	while(true){
		int v=-1;
		//Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
		REP(u,V){
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
		}
		if(v==-1)break;
		used[v]=true;//頂点vをXに追加
		res+=mincost[v];//辺のコストに加える
		REP(u,V)mincost[u]=min(mincost[u],mincost[v]+cost[v][u]);
		
	}
	return res;
}


/////////////////////////////priority_queue O(|E|log|V|) 
struct edge{int to,cost;};
typedef pair<int,int> P;//firstは最短距離,secondは頂点番号
int V;
vector<edge> G[MAX_V];
int mincost[MAX_V];

int primp(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(mincost,mincost+V,INF);
	mincost[0]=0;
	que.push(P(0,0));
	int res=0;
	while(!que.empty()){
		P p=que.top();que.pop();//仮の最短距離が短い順に取り出す
		int v=p.second;
		if(mincost[v]<p.first)continue;
		
		res+=mincost[v];
		REP(i,G[v].size()){
			edge e=G[v][i];
			if(mincost[e.to]>mincost[v]+e.cost){
				mincost[e.to]=mincost[v]+e.cost;
				que.push(P(mincost[e.to],e.to));//仮の最短距離と頂点の組を更新が行われる度に追加していく
			}
		}
	}
	return res;
}



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



//そのまんまダイクストラ(O(|V|^2))
//最短距離が確定した頂点とそれに隣接している頂点を更新する、確定頂点はもう使わないことで短縮
//負の辺がないことが前提、負の辺があるときはベルマンフォード法で解く

int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)
int d[MAX_V];//頂点sからの最短距離
bool used[MAX_V];//既に使われたかどうかのフラグ
int V;//頂点数

void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	d[s]=0;
	while(true){
		int v=-1;//まだ使われていない頂点のうち距離が最小のものを探す
		REP(u,V){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
		}
		if(v==-1) break;//まだ使われてない頂点が存在しないなら終了
		used[v]==true;
		REP(i,V){
			d[i]=min(d[i],d[v]+cost[v][i]);
			//頂点sから隣接頂点への距離と、頂点sから先ほど求めた距離最小頂点への距離と距離最小頂点から隣接頂点への距離の和のうち小さい方を新たな距離として更新する
		}
	}
	
}



//priority_queueを使った場合(O(|E|log|V|))
struct edge{int to,cost;};
typedef pair<int,int> P;//firstは最短距離,secondは頂点番号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();//仮の最短距離が短い順に取り出す
		int v=p.second;
		if(d[v]<p.first)continue;
		REP(i,G[v].size()){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));//仮の最短距離と頂点の組を更新が行われる度に追加していく
			}
		}
	}
}


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

int prev[MAX_V];//最短路の直前の頂点
int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)
int d[MAX_V];//頂点sからの最短距離
bool used[MAX_V];//既に使われたかどうかのフラグ
int V;//頂点数

//始点sから各頂点への最短距離を求める
void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	fill(prev,prev+V,-1);
	d[s]=0;
	while(true){
		int v=-1;
		REP(u,V){//vは仮の最短距離の頂点番号
			if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
		}
		if(v==-1)break;
		used[v]=true;
		REP(u,V){
			if(d[u]>d[v]+cost[v][u]){
				d[u]=d[v]+cost[v][u];
				prev[u]=v;//仮の頂点、つまり最短路の直前を保存
			}
		}
	}
}	
//頂点tへの最短路
vector<int> get_path(int t){
	vector<int>path;
	for(;t!=-1;t=prev[t])path.push_back(t);//tがsになるまでprev[t]を遡る
	reverse(path.begin(),path.end());
	return path;
}



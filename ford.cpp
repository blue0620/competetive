//単一始点最短路問題(ベルマンフォード法)
//グラフにsから到達可能な負のコストの閉路が存在しないならwhile内は|V|-1回しか回らない(同じ頂点を２回通らない)
//逆にV回以上回れば負のコストの閉路が存在する。これを全体から検出したいならd[i]=0と初期化してやる
//総コストはコストが負の閉路がないならO(|V|*|E|)
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

//頂点fromから頂点toへのコストcostの辺
struct edge{int from,to,cost;};

edge es[MAX_E];//辺

int d[MAX_V];//最短距離
int V,E;//Vは頂点数、Eは辺数

//s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s){
	REP(i,V) d[i]=INF;//距離を無限大として初期化
	d[s]=0;//sからsへの移動は距離０
	while(ture){
		bool update=false;
		REP(i,E){
			edge e=es[i];//辺を代入
			if(d[e.from]!=INF&&d[e.to]>d[e.from] +e.cost){
				//更新するかどうかを決める。一回目の更新は当然fromがs番目、toはINF、costは整数値(正負は不明)
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update) break;
	}
}

//trueなら負の閉路が存在する
bool find_negative_loop(){
	memset(d,0,sizeof(d));//0で初期化
	REP(i,V)REP(j,E){
		edge e=es[j];
		if(d[e.to]>d[e.from]+e.cost){
			d[e.to]=d[e.from]+e.cost;
			//V回目のループに入ったら閉路あり
			if(i==V-1)return true;
		}
	}
	return false;
}


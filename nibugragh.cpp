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


vector<int> G[MAX_V];
int V;
int color[MAX_V];//頂点iの色(-1,1)

//頂点を1と-1で塗る。もし連結であるかどうかを調べたいならdfsの呼び出し回数を数える。総呼び出し回数が1回なら連結
//木であるかどうかを調べるには？
//トポロジカル順序を調べるには？連結なグラフの中で現在の点の番号より大きな番号を持つ隣接点のうち最小のものに移動することを繰り返す？
//計算量はO(|V|+|E|)
bool dfs(int v,int c){
	color[v]=c;//頂点vをcで塗る
	REP(i,G[v]){
		//隣接している頂点がcで塗られていればfalse
		if(color[G[v][i]]==c) return false;
		//隣接している頂点がまだ塗られてないなら-cで塗ってfalse
		if(color[G[v][i]]==0 && !dfs(G[v][i],-c))return false;
	}
	//すべての頂点を塗れたらtrue
	return true;
}

void solve(){
	REP(i,V){
		if(color[i]==0){//まだ頂点が塗られていなければ塗る
			if(!dfs(i,1)){//隣接頂点と色が被ったら不適
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
}
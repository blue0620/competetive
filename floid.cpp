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

int d[MAX_V][MAX_V];//d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF,ただしd[i][i]=0とする)
int V;//頂点数

void warshall_floyd(){
	REP(k,V){
		REP(i,V){
			REP(j,V)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}

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

#define MAX_N 1000
int par[MAX_N];
int rnk[MAX_N];

void init(int n){
	REP(i,n){
		par[i]=i;
		rnk[i]=0;
	}
}

int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rnk[x]<rnk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}
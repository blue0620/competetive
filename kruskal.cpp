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

struct edge {int u,v,cost;};

bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}
edge es[MAX_E];
int V,E;

int kruskal(){
	sort(es,es+E,comp);//cost‚ª¬‚³‚¢‡‚Éƒ\[ƒg
	init_union_find(V);//Union-Find‚Ì‰Šú‰»
	int res=0;
	REP(i,E){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}

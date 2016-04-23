#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define SZ(a) int((a).size())
#define PB push_back
#define MP make_pair

#define MAX_N 100001
#define INF 100000

struct edge{int to,cost;};
typedef pair<int,int> P;//firstÇÕç≈íZãóó£,secondÇÕí∏ì_î‘çÜ

int par[MAX_N];
int Rank[MAX_N];
vector<edge> G[MAX_N];
int N;


void init(int n){
	REP(i,n){
		par[i]=i;
		Rank[i]=0;
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
	if(Rank[x]<Rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(Rank[x]==Rank[y]) Rank[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

struct Query {
  int u, v, w;
  Query(int u, int v) : u(u), v(v), w(-1) { }
};

void visit(int u,int w,vector<Query>&qs,vector<int>&color,vector<int>&ancestor){
	ancestor[find(u)]=u;
	REP(i,SZ(G[u])){
		edge e=G[u][i];
		if(e.to!=w){
			visit(e.to,u,qs,color,ancestor);
			unite(u,e.to);
			ancestor[find(u)]=u;
		}
	}
	color[u]=1;
	REP(i,SZ(qs)){
		Query q=qs[i];
		int w=(q.v==u?q.u:q.u==u?q.v:-1);
		if(w>=0&&color[w])q.w=ancestor[find(w)];
	}
}
void LCA(int r,vector<Query>&qs){
	init(N);
	vector<int> color(N), ancestor(N);
	visit(r,-1,qs,color,ancestor);
}
int main(){
	
	cin>>N;
	init(N);
	REP(i,N-1){
		int x,y;
		cin>>x>>y;
		x--;y--;
		edge e1,e2;
		e1.to=y;e1.cost=1;
		e2.to=x;e2.cost=1;
		G[x].PB(e1);
		G[y].PB(e2);
		unite(x,y);
	}
	int Q;
	cin>>Q;
	vector<int>res;
	vector<Query>qs;
	REP(i,Q){
		int a,b;
		cin>>a>>b;
		a--;b--;
		Query qq(a,b);
		qs.PB(qq);
	}
	LCA(r,qs);
	REP(i,Q){
		cout<<qs[i].w<<endl;
	}
	return 0;
}

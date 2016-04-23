#include <stdio.h> 
#include <stdlib.h>
#include <vector>
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
#include <fstream>
#include <utility>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()


int ans1,ans2;

typedef int Weight;
struct Edge {
  	int src, dst;
  	Weight weight;
  	Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef pair <int, int> PII;
typedef vector <Edge> Edges;
typedef vector <Edges> Graph;
typedef vector <Weight> Array;
typedef vector <Array> Matrix;
typedef pair <Weight, int> Result;


Result visit(int p, int v, const Graph &g) {
  Result r(0, v);
  for(int i=0;i<g[v].size();i++){
  	Edge e=g[v][i];
  	if (e.dst != p) {
    	Result t = visit(v, e.dst, g);
    	t.first += e.weight;
    	if (r.first < t.first) r = t;
  	}
  }
  return r;
}
Weight diameter(const Graph &g) {
  Result r = visit(-1, 0, g);
  Result t = visit(-1, r.second, g);
  ans1=r.second;
  ans2=t.second;
  return t.first; // (r.second, t.second) is farthest pair
}

int main(){
	int N;
	cin>>N;
	Graph G(N);
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(Edge(0,b,1));
		G[b].push_back(Edge(0,a,1));
	}
	diameter(G);
	cout<<ans1+1<<" "<<ans2+1<<endl;
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
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
#include <fstream>
#include <math.h>
#include "clx/sha1.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef boost::multiprecision::cpp_int bigint;

#define MAX_V 7000
#define INF 10000000000
struct edge{int to;long long cost;};
typedef pair<int,long long> P;//firstは最短距離,secondは頂点番号

int V;
vector<edge> G[MAX_V];
long long d[MAX_V];

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
long dp[82][82];
int main(){
	FILE *fp;
	fp = fopen("matrix.txt", "r" );
	
	char c[1000];
	int num[82][82];
	CLR(num);
	int x=1,y=1;
	int temp=0;
	REP(i,82)REP(j,82)num[i][j]=INF;
	while(fgets(c,1000,fp)!=NULL){
		REP(i,strlen(c)){
			if(c[i]=='\n'){
				num[y][x]=temp;
				x=1;y++;
				temp=0;
			}else if(c[i]==','){
				num[y][x]=temp;
				x++;
				temp=0;
			}else{
				temp*=10;
				temp+=(unsigned int)(c[i]-'0');
			}
		}
	}
	
	fclose(fp);
	V=6561;
	FOR(i,1,81)FOR(j,1,81){
		int pos=i*80+j;
		edge e1,e2,e3,e4;
		e1.to=(i+1)*80+j;//down
		e1.cost=num[i+1][j];
		e2.to=(i-1)*80+j;//up
		e2.cost=num[i-1][j];
		e3.to=i*80+(j+1);//right
		e3.cost=num[i][j+1];
		e4.to=i*80+(j-1);//left
		e4.cost=num[i][j-1];
		G[pos].PB(e1);
		G[pos].PB(e2);
		G[pos].PB(e3);
		G[pos].PB(e4);
	}
	
	dijkstra(81);
	cout<<d[80*80+80]+num[1][1]<<endl;
	return 0;
}



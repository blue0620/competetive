//include
//------------------------------------------
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
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
#define INF 10000000
#define MAX_V 101
struct edge{int to,cost;};
typedef pair<int,int> P;//firstは最短距離,secondは頂点番号

int V;
vector<edge> G[2][MAX_V];
int d[2][MAX_V];

void dijkstra(int s,int q){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d[q],d[q]+V,INF);
	d[q][s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();//仮の最短距離が短い順に取り出す
		int v=p.second;
		if(d[q][v]<p.first)continue;
		REP(i,G[q][v].size()){
			edge e=G[q][v][i];
			if(d[q][e.to]>d[q][v]+e.cost){
				d[q][e.to]=d[q][v]+e.cost;
				que.push(P(d[q][e.to],e.to));//仮の最短距離と頂点の組を更新が行われる度に追加していく
			}
		}
	}
}

int ar[2][14];
int cp[101][101],tp[101][101];

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		V=m;
		
		REP(i,2)REP(j,MAX_V)G[i][j].clear();
		REP(i,101)REP(j,101)cp[i][j]=INF,tp[i][j]=INF;
		REP(i,n){
			int at,bt,ct,tt;
			cin>>at>>bt>>ct>>tt;
			at--;bt--;
			if(at>bt)swap(at,bt);
			cp[at][bt]=min(cp[at][bt],ct);
			tp[at][bt]=min(tp[at][bt],tt);
		}
		REP(i,m)FOR(j,i+1,m){
			if(cp[i][j]!=INF){
				edge e;
				e.to=j;e.cost=cp[i][j];
				G[0][i].PB(e);
				e.to=i;
				G[0][j].PB(e);
				e.to=j;e.cost=tp[i][j];
				G[1][i].PB(e);
				e.to=i;
				G[1][j].PB(e);
			}
		}
		REP(i,m){
			dijkstra(i,0);
			dijkstra(i,1);
			REP(j,m){
				if(i!=j&&d[0][j]!=INF){
					cp[i][j]=d[0][j];
					tp[i][j]=d[1][j];
				}
			}
		}
		int k;
		cin>>k;
		REP(i,k){
			int p,q,r;
			cin>>p>>q>>r;
			p--;q--;
			if(r==0)cout<<cp[p][q]<<endl;
			else cout<<tp[p][q]<<endl;
		}
	}
	return 0;
}

/*
4
5+4*3+2/(1-1-1)=
(1+4)*(3+7)/5=
5+4-3=
(1+5)*(2+3)=
3
1+2*3/2=
1+2*(3-2)/(4+5)=
1*2+3/(2+5)=
*/
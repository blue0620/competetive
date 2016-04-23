//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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


///////////////////////ford-fulkerson O(F|E|)/////////////////////////////
#define MAX_V 1000
#define INF 1e9


struct edge{
	int to, cap, rev;
};//目的地,辺の容量,逆辺
vector <edge> G[MAX_V];//隣接リスト
bool used[MAX_V];//既に調べたか

//from->to方向へ向かう容量capの辺を張る。この時逆辺の容量は0
void add_edge(int from,int to,int cap){
	edge e={to, cap, SZ(G[to])};
	G[from].PB(e);
	edge e2={from, 0, SZ(G[from])-1};
	G[to].PB(e2);//逆辺は一つ前の行でpush_backした隣接リスト要素を指す
}

//増加パスをDFSで探す(現在地,目的地(不変),辺の流量)。流量は保存せず、辺の容量を変化させている
int dfs(int v,int t,int f){
	if(v==t)return f;//あるルートにおける最大流量
	used[v]=true;
	REP(i,SZ(G[v])){
		edge &e=G[v][i];//G[v][i]のポインタを参照
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				//下の操作の心は、それまでのフローを押し出す方向に新たなフローが生じることを表している
				e.cap-=d;//辺の容量を減算する
				G[e.to][e.rev].cap+=d;//逆辺の容量を加算する
				return d;
			}
		}
	}
	return 0;
}

//sからtへの最大流を求める
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		CLR(used);
		int f=dfs(s,t,INF);
		if(f==0)return flow;
		flow+=f;
	}
}

///////////////////////ford-fulkerson O(F|E|)/////////////////////////////



///////////////////////dinic O(|E||V|^2)/////////////////////////////
#define MAX_V 1000
#define INF 1e9
struct edge{
	int to, cap, rev;
};//目的地,辺の容量,逆辺
vector <edge> G[MAX_V];//隣接リスト
int level[MAX_V];//sからの距離
int iter[MAX_V];//どこまで調べたか


//from->to方向へ向かう容量capの辺を張る。この時逆辺の容量は0
void add_edge(int from,int to,int cap){
	edge e={to, cap, SZ(G[to])};
	G[from].PB(e);
	edge e2={from, 0, SZ(G[from])-1};
	G[to].PB(e2);//逆辺は一つ前の行でpush_backした隣接リスト要素を指す
}

//sからの最短距離を予めBFSで計算しておく
//距離が増加する向きの辺のみからなるグラフを作成する。(最短の増加パスの長さはフローを流すことで短くならない)
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		REP(i,SZ(G[v])){
			edge &e=G[v][i];
			if(e.cap>0&&level[v]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}


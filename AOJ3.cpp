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
#define MAX_V 100003
//priority_queueを使った場合(O(|E|log|V|))



struct edge{
	int to,cost;
	bool operator<( const edge& right ) const {
        return to == right.to ? cost < right.cost : to < right.to;
    }
	bool operator==( const edge& right ) const {
        return to == right.to;
    }
};

typedef pair<int,int> P;//firstは最短距離,secondは頂点番号

int V;
vector<edge> G[MAX_V];
long d[MAX_V];

void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();//仮の最短距離が短い順に取り出す
		long v=p.second;
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
vector<edge> Gctp[MAX_V];
int main(){
	LL N,Q;
	cin>>N>>Q;
	V=N;
	
	REP(i,N-1){
		int p,w;
		cin>>p>>w;
		p--;
		
		edge e;
		e.to=i+1;
		e.cost=w;
		G[p].PB(e);//親から子へp<i+1
		e.to=p;
		Gctp[i+1].PB(e);//子から親へ
	}
	vector<int>leaf;
	REP(i,N)if(G[i].empty()){//子ノード持たない
		leaf.PB(i);
	}else{
		SORT(G[i]);
	}
	
	vector<long>ans;
	REP(i,Q){
		int x;
		cin>>x;
		x--;
		edge e;
		e.to=x;e.cost=Gctp[x][0].cost;
		int prt=Gctp[x][0].to;
		vector<edge>::iterator itr=find(G[prt].begin(),G[prt].end(),e);
		if(itr!=G[prt].end()){
			G[prt].erase(itr);//親prt子xのルートが削除
			//e.cost=INF;
			//G[prt].insert(itr,e);
			//cout<<"!"<<endl;
		}
		dijkstra(0);
		long res=INF;
		REP(j,SZ(leaf)){
			//cout<<"!"<<leaf[j]<<endl;
			res=min(res,d[leaf[j]]);
		}
		if(res>=INF)ans.PB(-1);
		else ans.PB(res);
	}
	REP(i,SZ(ans))cout<<ans[i]<<endl;
	return 0;
}


//include
//------------------------------------------
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

//conversion
//------------------------------------------
inline long toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline long toLong(string s) {long v; istringstream sin(s);sin>>v;return v;}
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
//typedef boost::multiprecision::cpp_int bigint;
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
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-8;
const long INF = 1e12;


//priority_queueを使った場合(O(|E|log|V|))
struct edge{int to,cost;};
typedef PII P;//firstは最短距離,secondは頂点番号

#define MAX_V 1003
long V;
vector<edge> G[MAX_V];
long d[MAX_V];

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

int main(){
	ifstream ifs("rosalind_cte.txt");
	ofstream ofs("test.txt");
	int N;
	ifs>>N;
	REP(i,N){
		REP(j,1001)G[j].clear();
		int m;
		ifs>>V>>m;
		int res=0;
		PII pi;
		REP(j,m){
			int a,b,c;
			ifs>>a>>b>>c;
			a--;b--;
			if(j==0){
				pi=MP(a,b);
				res=c;
			}
			
			edge e;e.to=b;e.cost=c;
			G[a].PB(e);
		}
		dijkstra(pi.second);
		if(d[pi.first]!=INF)cout<<d[pi.first]+res<<" ";
		else cout<<-1<<" ";
	}
	cout<<endl;
	return 0;
}
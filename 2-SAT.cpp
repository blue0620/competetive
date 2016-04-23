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
const int INF = 1e5;

int V;
vector<int>G[2001],rG[2001];
vector<int>vs;
bool used[2001];
int cmp[2001];

void dfs(int v){
	used[v]=1;
	REP(i,SZ(G[v])){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.PB(v);
}

void rdfs(int v,int k){
	used[v]=1;
	cmp[v]=k;
	REP(i,SZ(rG[v])){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}

int main(){
	ifstream ifs("rosalind_2sat.txt");
	ofstream ofs("test3.txt");
	int T;ifs>>T;
	REP(tt,T){
		int N,M;
		ifs>>N>>M;
		V=2*N;
		CLR(G);CLR(rG);
		REP(i,M){
			int a,b;
			ifs>>a>>b;
			if(a>0)a--;
			else a=-a-1+N;
			if(b>0)b--;
			else b=-b-1+N;
			int nota=(a+N)%V;
			int notb=(b+N)%V;
			//(a || b)==(nota=>b)||(notb=>a)
			G[nota].PB(b);
			rG[b].PB(nota);//nota=>b
			
			G[notb].PB(a);//notb=>a
			rG[a].PB(notb);
		}
		CLR(used);
		vs.clear();
		REP(v,V)if(!used[v])dfs(v);
		CLR(used);
		int cnt=0;
		for(int i=SZ(vs)-1;i>=0;i--)if(!used[vs[i]])rdfs(vs[i],cnt++);
		bool flag=1;
		REP(i,N){
			if(cmp[i]==cmp[i+N]){
				flag=0;break;
			}
		}
		
		if(!flag)ofs<<0<<endl;
		else{
			ofs<<1<<" ";
			REP(i,N){
				if(cmp[i]>cmp[i+N]){
					ofs<<i+1<<" ";
				}else{
					ofs<<-(i+1)<<" ";
				}
			}
			ofs<<endl;
		}
		
	}
	ofs<<endl;
	return 0;
}
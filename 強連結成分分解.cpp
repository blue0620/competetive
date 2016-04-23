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
vector<int>G[1001],rG[1001];
vector<int>vs;
bool used[1001];
int cmp[1001];

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
	ifstream ifs("rosalind_scc.txt");
	ofstream ofs("test2.txt");
	int N,M;
	ifs>>N>>M;V=N;
	CLR(G);CLR(rG);
	REP(i,M){
		int a,b;
		ifs>>a>>b;a--;b--;
		G[a].PB(b);
		rG[b].PB(a);
	}
	
	CLR(used);
	vs.clear();
	
	REP(v,V)if(!used[v])dfs(v);
	CLR(used);
	int cnt=0;
	for(int i=SZ(vs)-1;i>=0;i--){
		if(!used[vs[i]])rdfs(vs[i],cnt++);
	}
	cout<<cnt<<endl;
	return 0;
}
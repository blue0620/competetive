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

#define MAX_V 1003
vector<int>G[MAX_V];
int color[MAX_V];
int V;

bool dfs(int v,int c){
	color[v]=c;
	REP(i,SZ(G[v])){
		//隣接した頂点がすでに同じ色だったらアウト
		if(color[G[v][i]]==c)return 0;
		//隣接頂点がまだ塗られてなければ-cで塗る.
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c))return 0;
	}
	return 1;
}

int main(){
	ifstream ifs("rosalind_bip.txt");
	ofstream ofs("test2.txt");
	int N;ifs>>N;
	REP(i,N){
		CLR(G);CLR(color);
		int m,aa,bb;
		ifs>>V>>m;
		REP(j,m){
			ifs>>aa>>bb;
			aa--;bb--;
			G[aa].PB(bb);
			G[bb].PB(aa);
		}
		bool flag=1;
		REP(j,V){
			if(!dfs(i,1)){
				flag=0;break;
			}
		}
		if(flag)cout<<1<<" ";
		else cout<<-1<<" ";
	}
	cout<<endl;
	return 0;
}
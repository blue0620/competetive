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

bool used[1001][1001];
int main(){
	ifstream ifs("rosalind_hdag.txt");
	ofstream ofs("test2.txt");
	int K;
	ifs>>K;
	REP(T,K){
		int N,M;
		ifs>>N>>M;
		CLR(used);
		vector<int>G[1001],E[1001];
		REP(i,M){
			int a,b;
			ifs>>a>>b;a--;b--;
			G[a].PB(b);
			E[b].PB(a);
			used[a][b]=1;
		}
		queue<int>S;
		REP(i,N)if(SZ(E[i])==0)S.push(i);//トポソーの始点
		vector<int>L;
		set<PII>era;
		while(!S.empty()){
			int n=S.front();S.pop();
			L.PB(n);
			REP(i,SZ(G[n])){
				int m=G[n][i];
				era.insert(MP(n,m));
				//cout<<"!"<<n<<" "<<m<<endl;
				bool f=1;
				REP(j,SZ(E[m])){
					if(era.find(MP(E[m][j],m))==era.end())f=0;
				}
				if(f)S.push(m);
			}
		}
		bool flag=1;
		REP(i,SZ(L))if(i!=SZ(L)-1&&used[L[i]][L[i+1]]==0)flag=0;
		if(!flag)ofs<<-1<<endl;
		else{
			ofs<<1<<" ";
			REP(i,SZ(L))ofs<<L[i]+1<<" ";
			ofs<<endl;
		}
	}
	return 0;
}
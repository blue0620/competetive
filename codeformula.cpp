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


#define INF 10000000000

long dp[100003];
long H[3002];

struct sche{
	long s;
	long f;
	long m;
	bool operator<( const sche& right ) const {
		return f == right.f ? s < right.s : f < right.f;
	}
};

int main(){
	
	int N;cin>>N;
	H[0]=0;
	REP(i,N){
		long h;
		cin>>h;
		H[i+1]=H[i]+h;
	}
	vector<sche> sch;
	REP(i,N){
		long A,B,C;
		cin>>A>>B>>C;
		sche sc;
		sc.m=A;
		sc.s=B;
		sc.f=C;
		sch.PB(sc);
	}
	SORT(sch);

	
	REP(i,N){
		dp[i]=max(dp[i],H[1]);
		REP(j,N)if(sch[i].s>=sch[j].f)dp[i]=max(dp[i],dp[j]+H[1]);
		int st=sch[i].s;
		int dst=sch[i].f;
		int cnt=1;
		FOR(j,i+1,N){
			if(sch[j].m!=sch[i].m)continue;
			if(dst<=sch[j].s){
				dst=sch[j].s;
				cnt++;
				dp[j]=max(dp[j],dp[i]-H[1]+H[cnt]);
			}
		}
	}
	cout<<*max_element(dp,dp+N)<<endl;
	return 0;
}
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
#include <complex>
#include <math.h>

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
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-12;
const int INF = 10000;


int mp[201][201],mp2[201][201];
int main(){
	LL N,M,Q;
	cin>>N>>M;
	CLR(mp);
	if(N>200||M>200)return 0;
	REP(i,M){
		LL a,b,c;
		cin>>a>>b>>c;
		REP(k,c)FOR(j,k,c)mp[a+j][b+k]=1;
	}
	cin>>Q;
	REP(i,Q){
		LL d,e,f;
		LL cnt=0;CLR(mp2);
		cin>>d>>e>>f;
		REP(k,f)FOR(j,k,f)mp2[d+j][e+k]=1;
		REP(j,N)REP(k,j+1)if(mp[j+1][k+1]==0&&mp2[j+1][k+1]==1)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
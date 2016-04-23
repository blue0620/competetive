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
const int INF = 10003;

int a[10001];
int dp[10001];

int main(){
	int n;
	cin>>n;
	REP(i,n)cin>>a[i];
	fill(dp,dp+n,INF);
	vector<int>rnk[10001];
	vector<int>res;
	int maxi=0;
	REP(i,n){
		int pos=lower_bound(dp,dp+n,a[i])-dp;
		rnk[pos].PB(a[i]);
		dp[pos]=a[i];
		maxi=max(maxi,pos);
		//for(int j=0;dp[j]!=INF;j++)cout<<dp[j]<<" ";
		//cout<<endl;
	}
	REP(i,maxi+1)SORT(rnk[i]);
	res.PB(rnk[maxi][0]);rnk[maxi].clear();
	for(int i=maxi-1;i>=0;i--){
		int tmp=lower_bound(ALL(rnk[i]),res.back())-rnk[i].begin();
		tmp--;rnk[i].clear();
		res.PB(rnk[i][tmp]);
	}
	reverse(ALL(res));
	REP(i,SZ(res))cout<<res[i]<<" ";
	cout<<endl;
	res.clear();
	maxi=0;
	fill(dp,dp+n,INF);reverse(a,a+n);
	REP(i,n){
		int pos=lower_bound(dp,dp+n,a[i])-dp;
		rnk[pos].PB(a[i]);
		dp[pos]=a[i];
		maxi=max(maxi,pos);
	}
	REP(i,maxi+1)SORT(rnk[i]);
	res.PB(rnk[maxi][0]);rnk[maxi].clear();
	for(int i=maxi-1;i>=0;i--){
		int tmp=lower_bound(ALL(rnk[i]),res.back())-rnk[i].begin();
		tmp--;rnk[i].clear();
		res.PB(rnk[i][tmp]);
	}
	REP(i,SZ(res))cout<<res[i]<<" ";
	cout<<endl;
	
	return 0;
}
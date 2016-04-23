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

LL dp[2][100003];
int main(){
	LL n,k;
	while(cin>>n>>k){
		if(n==0&&k==0)break;
		bool ck=false;
		vector<LL>ar;
		CLR(dp);
		REP(i,k){
			LL t;
			cin>>t;
			if(t==0)ck=true;
			else ar.PB(t);
		}
		SORT(ar);
		dp[0][0]=1;
		FOR(i,1,SZ(ar)){
			if(ar[i]-ar[i-1]==1){
				dp[0][i]=dp[0][i-1]+1;
				dp[1][i]=dp[1][i-1]+1;
			}else{
				dp[1][i]=dp[0][i-1]+1;
				if(i!=SZ(ar)-1&&ar[i+1]-ar[i]==1)dp[1][i]++;
				dp[0][i]=1;
			}
		}
		LL res=0;
		if(!ck)REP(i,SZ(ar))res=max(res,dp[0][i]);
		else REP(i,SZ(ar))res=max(res,max(dp[0][i],dp[1][i]));
		cout<<res<<endl;
	}
	return 0;
}

/*
7 5
6
2
4
7
1
7 5
6
3
0
4
7
0 0
*/
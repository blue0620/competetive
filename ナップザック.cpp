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
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-12;
const LL INF = 1e18;


long dp[1002];
long w[1001],v[1001];


int main(){
	int maxw,N;
	int cnt=1;
	while(cin>>maxw){
		if(maxw==0)break;
		cin>>N;
		CLR(dp);
		char c;
		REP(i,N)cin>>v[i]>>c>>w[i];
		
		REP(i,N){
			for(int j=maxw;j>=0;j--){
				if(j+w[i]<=maxw){
					dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
				}
			}
		}
		cout<<"Case "<<cnt<<":"<<endl;
		cout<<dp[maxw]<<endl;
		long res=0;
		REP(i,maxw+1){
			if(dp[i]==dp[maxw]){
				res=i;break;
			}
		}
		cout<<res<<endl;
		cnt++;
	}
	return 0;
}
/*

*/
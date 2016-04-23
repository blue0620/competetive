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

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const double EPS = 1e-12;
const double INF = 1e12;

int dp[4][101][101];//dp[上上:0 右右:1 上右:2 右上:3][交差点の座標]
int main(){
	int w,h;
	while(cin>>w>>h){
		if(w==0&&h==0)break;
		CLR(dp);
		dp[0][0][1]=dp[1][1][0]=1;
		
		FOR(i,1,w+1){//上j 右i
			FOR(j,1,h+1){
				dp[0][i][j]=(dp[0][i][j-1]+dp[3][i][j-1])%100000;
				dp[1][i][j]=(dp[1][i-1][j]+dp[2][i-1][j])%100000;
				dp[2][i][j]=dp[0][i-1][j]%100000;
				dp[3][i][j]=dp[1][i][j-1]%100000;
			}
		}
		long res=0;
		REP(i,4)res+=dp[i][w][h];
		cout<<res%100000<<endl;
	}
	return 0;
}
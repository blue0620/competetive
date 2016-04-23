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


LL dp[2][3][101];//dp[˜A‘±“ú”][Ží—Þ][“ú”]

int main(){
	int n,k;
	cin>>n>>k;
	CLR(dp);
	vector<int>check[101];
	REP(i,k){
		int a,b;
		cin>>a>>b;
		a--;b--;
		check[a].PB(b);
	}
	REP(i,3){
		if(!check[1].empty()&&!check[2].empty()&&check[1][0]==i&&check[2][0]==i){
			dp[0][i][0]=0;
		}else if(!check[0].empty()){
			dp[0][check[0][0]][0]=1;
		}else dp[0][i][0]=1;
	}
	FOR(i,1,n){
		if(!check[i].empty()){
			int t=check[i][0];
			REP(j,3)REP(k,2)if(t!=j){
				dp[0][t][i]+=dp[k][j][i-1];
				dp[0][t][i]%=10000;
			}
			dp[1][t][i]+=dp[0][t][i-1];
			dp[1][t][i]%=10000;
			continue;
		}
			
		REP(j,3)REP(j2,3){
			if(j!=j2)REP(k,2){
				dp[0][j][i]+=dp[k][j2][i-1];
				dp[0][j][i]%=10000;
			}else{
				dp[1][j][i]+=dp[0][j][i-1];
				dp[1][j][i]%=10000;
			}
		}
	}
	LL sum=0;
	REP(i,3)REP(j,2){
		sum+=dp[j][i][n-1];
		sum%=10000;
	}
	cout<<sum<<endl;
	return 0;
}
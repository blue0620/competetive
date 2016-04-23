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
#define INF 1000000000
#define MAX_N 100003
#define MAX_V 100003
#define MOD 1000000007
struct edge{int to,cost;};
typedef pair<int,int> P;//first�͍ŒZ����,second�͒��_�ԍ�

long bit[MAX_N],n;

LL sum(long i){
	LL s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;//i�̍Ō��1�̃r�b�g��i&-i�ŕ\����
	}
	return s;
}


int add(long i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
	return 0;
}



LL dp[MAX_N+1];
int main(){
	long N,R;
	dp[0]=1;
	for(LL i=1;i<=MAX_N;i++)dp[i]=dp[i-1]*i%MOD;
	while(cin>>N){
		if(N==0)break;
		cin>>R;
		n=N;
		long a[MAX_N];
		REP(i,N){
			a[i]=i+1;
			bit[i]=0;
		}
		bit[N]=0;
		REP(i,R){
			long s,t;
			cin>>s>>t;
			s--;t--;
			swap(a[s],a[t]);
		}
		LL res=0;
		for(long i=N-1,j=0;i>=0;i--,j++){
			res+=(sum(a[i])*dp[j]);
			add(a[i],1);
			res%=MOD;
			//cout<<kai<<" "<<sum(a[i])<<endl;
		}
		cout<<res<<endl;
	}
	return 0;
}

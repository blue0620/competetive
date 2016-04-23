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

int N,M;
int ar[11];
set<string>ch;

void re(string str,vector<bool>used,int cnt){
	if(cnt==0){
		ch.insert(str);
	}else{
		REP(i,SZ(used)){
			if(!used[i]){
				used[i]=true;
				re(str+toString(ar[i]),used,cnt-1);
				used[i]=false;
			}
		}
	}
}
int main(){
	
	while(cin>>N>>M){
		if(N==0&&M==0)break;
		ch.clear();
		REP(i,N)cin>>ar[i];
		vector<bool>used(N,false);
		re("",used,M);
		cout<<SZ(ch)<<endl;
	}
	return 0;
}
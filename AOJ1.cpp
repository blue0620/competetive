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
#define MAX_V 101


int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		map<string,int>mp;
		long item[101];
		CLR(item);
		REP(i,n){
			string str;long temp;
			cin>>str>>temp;
			mp[str]=i;
			item[i]=temp;
		}
		int m;
		cin>>m;
		vector<int>R[100];
		vector<PLL>pi;
		REP(i,m){
			string str;int num;
			cin>>str>>num;
			long sum=0;
			REP(j,num){
				string tt;
				cin>>tt;
				R[mp[str]].PB(mp[tt]);
				sum+=item[mp[tt]];
			}
			pi.PB(MP(sum,mp[str]));
		}//Œ»Ý‹àŠz‚ªˆê”Ô¬‚³‚¢‚à‚Ì‚©‚ç’€ŽŸˆ—‚µ‚½‚¢
		SORT(pi);
		REP(i,m){
			item[pi[i].second]=min(pi[i].first,item[pi[i].second]);
			pi.PB();
		}
		string res;
		cin>>res;
		cout<<item[mp[res]]<<endl;
	}
	return 0;
}

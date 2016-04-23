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

struct tester{
	int a,b,c,R;
	bool operator<( const tester& right ) const {
        return R == right.R ? a < right.a : R < right.R;
    }
};
int ac[301],wa[301];
int main(){
	int A,B,C,n;
	while(cin>>A>>B>>C){
		if(A==0&&B==0&&C==0)return 0;
		cin>>n;
		vector<tester>test;
		CLR(ac);CLR(wa);
		REP(i,n){
			int ta,tb,tc,tr;
			cin>>ta>>tb>>tc>>tr;
			tester t={ta,tb,tc,tr};
			test.PB(t);
		}
		SORT(test);
		int j;
		for(j=SZ(test)-1;j>=0,test[j].R==1;j--){
			ac[test[j].a]++;
			ac[test[j].b]++;
			ac[test[j].c]++;
		}
		for(j;j>=0;j--){
			if(ac[test[j].a]*ac[test[j].b]!=0){
				wa[test[j].c]++;
			}else if(ac[test[j].b]*ac[test[j].c]!=0){
				wa[test[j].a]++;
			}else if(ac[test[j].a]*ac[test[j].c]!=0){
				wa[test[j].b]++;
			}
		}
		FOR(i,1,A+B+C+1){
			if(ac[i]!=0)cout<<"1"<<endl;
			else if(wa[i]!=0)cout<<"0"<<endl;
			else cout<<"2"<<endl;
		}
	}
	return 0;
}


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
//typedef boost::multiprecision::cpp_int LL;
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
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-8;
const int INF = 1e5;
const LL MOD=1000000007;


vector<int> lcs(const vector<int>& a, const vector<int>& b) {
  const int n = a.size(), m = b.size();
  vector< vector<int> > X(n+1, vector<int>(m+1));
  vector< vector<int> > Y(n+1, vector<int>(m+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        X[i+1][j+1] = X[i][j] + 1;
        Y[i+1][j+1] = 0;
      } else if (X[i+1][j] < X[i][j+1]) {
        X[i+1][j+1] = X[i][j+1];
        Y[i+1][j+1] = +1;
      } else {
        X[i+1][j+1] = X[i+1][j];
        Y[i+1][j+1] = -1;
      }
    }
  }
  vector<int> c;
  for (int i = n, j = m; i > 0 && j > 0; ) {
    if      (Y[i][j] > 0) --i;
    else if (Y[i][j] < 0) --j;
    else { c.push_back(a[i-1]); --i; --j; }
  }
  reverse(c.begin(), c.end());
  return c;
}

vector<int> cntL(string str){
	string a=str;
	int n=a.size();
	vector<int> k1,k2;
	REP(i,n)k1.push_back(a[i]);
	REP(i,n)k2.push_back(a[n-i-1]);
	return lcs(k1,k2);
}


int main(){
	
	return 0;
}
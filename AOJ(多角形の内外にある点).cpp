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

typedef complex<double> P;
typedef vector< complex<double> >polygon;

namespace std {
  	bool operator < (const P& a, const P& b) {
    	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  	}
}

double cross(const P& a, const P& b) {
  	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}


int contains(const polygon& poly, const P & p) {
	bool in = false;
	for (int i = 0; i < SZ(poly); ++i) {
		P a = poly[i] - p, b = poly[(i+1)%SZ(poly)] - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
	  		if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
	}
	return in ? 2 : 0;
}


int main(){
	
	vector<string>res;
	polygon tri(3);
	P p;
	while(cin>>tri[0].real()>>tri[0].imag()>>tri[1].real()>>tri[1].imag()>>tri[2].real()>>tri[2].imag()>>p.real()>>p.imag()){
		if(contains(tri,p)==2)res.PB("YES");
		else res.PB("NO");
	}
	REP(i,SZ(res))cout<<res[i]<<endl;
	return 0;
}

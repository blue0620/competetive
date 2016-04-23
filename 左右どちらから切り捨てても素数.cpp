#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <math.h>
#include "clx/sha1.h"

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#include <boost/multiprecision/cpp_int.hpp>
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

typedef boost::multiprecision::cpp_int bigint;
bool is_prime(long t){
	if(t<=1)return 0;
	for(long i=2;i*i<=t;i++)if(t%i==0){
		return 0;
	}
	return 1;
}

int main(){
	long res=0;
	for(long i=9;i<1000000;i+=2){
		if(!is_prime(i))continue;
		long m=1;
		while(m*10<=i)m*=10;
		bool check=true;
		while(m>1){
			if(!is_prime(i%m)){
				check=false;
				break;
			}
			m/=10;
		}
		if(!check)continue;
		while(m<=i){
			if(!is_prime(i/m)){
				check=false;
				break;
			}
			m*=10;
		}
		if(check){
			cout<<i<<endl;
			res+=i;
		}
	}
	cout<<res<<endl;
	return 0;
}


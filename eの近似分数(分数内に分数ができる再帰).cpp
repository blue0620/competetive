#include <stdlib.h>
#include <stdio.h>
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
#include <boost/multiprecision/cpp_int.hpp>

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


#define M 99
int main(){
	VI e(M);
	int k=1;
	REP(i,M){
		if(i%3==1){
			e[i]=2*k;
			k++;
		}else e[i]=1;
	}
	reverse(ALL(e));
	bigint bunbo=e[0];
	bigint bunshi=1;
	REP(i,M-1){
		bigint t=bunbo;
		bunbo=e[i+1]*bunbo+bunshi;
		bunshi=t;
	}
	cout<<bunshi+bunbo*2<<" "<<bunbo<<endl;
	bigint tt=bunshi+bunbo*2;
	long sum=0;
	string str=tt.str();
	REP(i,SZ(str)){
		sum+=(unsigned int)(str[i]-'0');
	}
	cout<<sum<<endl;
	return 0;
}


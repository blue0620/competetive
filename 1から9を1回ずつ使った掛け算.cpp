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



int main(){
	int c[10];
	VI res;
	for(long i=1;i<=1000;i++)for(long j=i+1;;j++){
		CLR(c);
		long pro=i*j;
		long i2=i,j2=j,pro2=i*j;
		while(i2>0){
			c[i2%10]++;
			i2/=10;
		}
		while(j2>0){
			c[j2%10]++;
			j2/=10;
		}
		while(pro2>0){
			c[pro2%10]++;
			pro2/=10;
		}
		bool check=true;
		if(c[0]!=0)check=false;
		FOR(k,1,10)if(c[k]!=1)check=false;
		if(check){
			cout<<i<<" "<<j<<" "<<pro<<endl;
			res.PB(pro);
		}
		if(SZ(toString(i))+SZ(toString(j))+SZ(toString(pro))>=10)break;
	}
	SORT(res);
	long sum=res[0];
	FOR(i,1,SZ(res))if(res[i]!=res[i-1])sum+=res[i];
	cout<<sum<<endl;
	return 0;
}


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

#define MAX_I 50000000
bool is_prime(int t){
	if(t<=1)return false;
	for(int i=2;i*i<=t;i++)if(t%i==0)return false;
	return true;
}
int main(){
	vector<bigint> prime;
	set<bigint>biset;
	FOR(i,2,7080)if(is_prime(i))prime.PB((bigint)i);
	int sp=SZ(prime);
	long long cnt=0;
	REP(i,sp){
		bigint bi,bj,bk;
		bi=prime[i]*prime[i]*prime[i]*prime[i];
		if(bi>=MAX_I)break;
		REP(j,sp){
			bj=prime[j]*prime[j]*prime[j];
			if(bi+bj>=MAX_I)break;
			REP(k,sp){
				bk=prime[k]*prime[k];
				if(bi+bj+bk>=MAX_I)break;
				//if(bi+bj+bk<=50)cout<<bi+bj+bk<<endl;
				if(biset.find(bi+bj+bk)==biset.end()){
					cnt++;
					biset.insert(bi+bj+bk);
				}
			}
			
		}
		
	}
	cout<<cnt<<endl;
	return 0;
}


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

bool is_prime(long t){
	if(t<=1)return false;
	for(long i=2;i*i<=t;i++)if(t%i==0)return false;
	return true;
	
}

int main(){
	
	for(long i=111858;i<1000000;i++){
		if(!is_prime(i))continue;
		int c[10];
		unsigned int num[10];
		CLR(c);
		string str=toString(i);
		REP(j,SZ(str)){
			c[(unsigned int)(str[j]-'0')]++;
			num[j]=(unsigned int)(str[j]-'0');
		}
		bool check=false;
		int tt=0;
		REP(j,10)if(c[j]>=3){
			tt=j;
			check=true;
		}
		if(!check)continue;
		//cout<<i<<endl;
		int cnt=0;
		REP(j,10){
			int p=0;
			//cout<<tt<<" ";
			REP(k,SZ(str)){
				p*=10;
				if(num[k]==tt)p+=j;
				else p+=num[k];
			}
			//cout<<p<<endl;
			if(is_prime(p))cnt++;
			if(i==121313&&is_prime(p))cout<<cnt<<" "<<p<<endl;
		}
		if(cnt==8){
			cout<<i<<endl;
			//return 0;
		}
	}
	return 0;
}


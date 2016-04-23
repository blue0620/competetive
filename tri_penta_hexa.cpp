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

#define MAX_N 100000
long long tri[MAX_N],penta[MAX_N],hexa[MAX_N];
int main(){
	tri[0]=0;penta[0]=0;hexa[0]=0;
	tri[1]=1;penta[1]=1;hexa[1]=1;
	for(long i=1;i<MAX_N-1;i++){
		tri[i+1]=tri[i]+(i+1);
		penta[i+1]=penta[i]+(i*3+1);
		hexa[i+1]=hexa[i]+(i*4+1);
	}
	//cout<<tri[285]<<penta[165]<<hexa[143]<<endl;
	for(long i=1;i<MAX_N-1;i++){
		if(binary_search(penta,penta+MAX_N-1,tri[i])&&binary_search(hexa,hexa+MAX_N-1,tri[i])){
			cout<<tri[i]<<endl;
		}
	}
	//cout<<tri[5]<<" "<<penta[5]<<" "<<hexa[5]<<endl;
	return 0;
}


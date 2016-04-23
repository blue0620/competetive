#include <stdio.h> 
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

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int grass[101][101];
int hn[101],hm[101];
int main(){
	ifstream ifs( "B-small-practice.in" );
	ofstream ofs( "test.txt" );
	int T;
	ifs>>T;
	REP(i,T){
		int N,M;
		bool c=true;
		ifs>>N>>M;
		CLR(hn);CLR(hm);
		REP(j,N)REP(k,M){
			ifs>>grass[j][k];
			hn[j]=max(hn[j],grass[j][k]);
			hm[k]=max(hm[k],grass[j][k]);
		}
		REP(j,N)REP(k,M){
			if(grass[j][k]!=min(hn[j],hm[k]))c=false;
		}
		if(c)ofs<<"Case #"<<i+1<<": YES"<<endl;
		else ofs<<"Case #"<<i+1<<": NO"<<endl;
	}
	
	return 0;
}

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
#include <math.h>

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
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-12;
const double INF = 1e9;


typedef pair<int,int> PII;

char mp[4][102][102];
int ans[4][102][102];


int bfs(int sy,int sx){
	queue<PII>qu;
	qu.push(PII(sy,sx));ans[0][sy][sx]=1;
	while(!qu.empty()){
		
	}
}

int main(){
	ifstream ifs("test.txt");
	ofstream ofs("output.txt");
	char laser[]={'v','<','^','>','v','<','^','>'};
	REP(i,4)REP(j,102)REP(k,102)mp[i][j][k]='#';
	CLR(ans);
	
	int T;
	ifs>>T;
	REP(i,T){
		int m,n;
		ifs>>m>>n;
		REP(j,m)REP(k,n){
			char c;
			ifs>>c;
			if(c=='S')
			if(c=='S'||c=='G'||c=='.')REP(l,4)mp[l][j+1][k+1]=c;
			else{
				REP(l,4)if(c==laser[l]){
					REP(o,4)mp[o][j+1][k+1]=laser[l+o];
					break;
				}
			}
			
		}
		REP(i,4)REP(j,102)REP(k,102){
			int posj=j,posk=k;
			switch (mp[i][j][k]){
				case 'v':
				posj++;
				while(mp[i][posj][posk]=='.'){
					mp[i][posj][posk]='x';
					posj++;
				}
				break;
				
				case '<':
				posk--;
				while(mp[i][posj][posk]=='.'){
					mp[i][posj][posk]='x';
					posk--;
				}
				break;
				
				case '^':
				posj--;
				while(mp[i][posj][posk]=='.'){
					mp[i][posj][posk]='x';
					posj--;
				}
				break;
				
				case '>':
				posk++;
				while(mp[i][posj][posk]=='.'){
					mp[i][posj][posk]='x';
					posk++;
				}
				break;
			}
			mp[i][j][k]='#';
		}
		
		if(flag)ofs<<"Case #"<<i+1<<": yes"<<endl;
		else ofs<<"Case #"<<i+1<<": impossible"<<endl;
		//ofs<<"Case #"<<i+1<<": "<<mi<<" "<<ma<<endl;
	}
	return 0;
}
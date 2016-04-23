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
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
#define INF 10000000

int sq[102][102];//y,x
int w,h;
int sum;
int nx[][6]={
	{1,0,-1,-1,-1,0},
	{1,1,0,-1,0,1},//‰E—×‚©‚çŽžŒv‰ñ‚è
};
	
int ny[6]={0,1,1,0,-1,-1};

void dfs(int y,int x){
	sq[y][x]=-1;
	REP(i,6){
		int npx=x+nx[y%2][i];
		int npy=y+ny[i];
		if(npx>=0&&npx<=w+1&&npy>=0&&npy<=h+1){
			if(sq[npy][npx]==1)sum++;
			else if(sq[npy][npx]==0)dfs(npy,npx);
		}
	}
}

int main(){
	
	cin>>w>>h;
	REP(i,102)REP(j,102)sq[i][j]=0;
	
	
	REP(i,h)REP(j,w){
		cin>>sq[i+1][j+1];
	}
	sum=0;
	dfs(0,0);
	cout<<sum<<endl;
	return 0;
}

/*
8 4
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0

8 4
0 1 0 0 0 0 0 0
0 1 1 0 0 0 0 0
1 1 1 0 0 0 0 0
0 1 1 0 0 0 0 0

8 4
0 0 0 0 0 1 1 1
0 0 0 0 0 1 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 0 1 0

*/
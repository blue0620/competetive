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

const long double EPS = 1e-6;
const long INF = 1e10;

char mp[100][100];
int ans[100][100];
int dx[]={2,0,-2,0};
int dy[]={0,2,0,-2};
int main(){
	int w,h;
	while(cin>>w>>h){
		if(w==0&&h==0)break;
		REP(i,100){
			REP(j,100){
				mp[i][j]=(i%2==0||j%2==0)?'#':'o';
			}
		}
		int gx=w*2-1,gy=h*2-1;
		cin.ignore();
		//スタートは(1,1)
		REP(i,2*h-1){
			string str;
			getline(cin,str);
			REP(j,SZ(str)){
				if(str[j]=='0'){
					mp[i+1][j+1]='.';
					//cout<<"!"<<endl;
				}
			}
		}
		CLR(ans);
		queue<PII>qu;qu.push(MP(1,1));ans[1][1]=1;
		
		while(!qu.empty()){
			PII temp=qu.front();
			qu.pop();
			int y=temp.first;
			int x=temp.second;
			REP(i,4)if(mp[y+(dy[i]/2)][x+(dx[i]/2)]=='.'&&ans[y+dy[i]][x+dx[i]]==0){
				qu.push(MP(y+dy[i],x+dx[i]));
				ans[y+dy[i]][x+dx[i]]=ans[y][x]+1;
			}
		}
		cout<<ans[gy][gx]<<endl;
	}
	return 0;
}
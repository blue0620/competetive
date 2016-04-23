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
#define INF 1000000


int ar[2][14];

int ci(char c){
	return (unsigned int)(c-'0');
}

int kuri[130];
int main(){
	string str;
	while(cin>>str){
		string s1,s2,ans;
		bool pls=false,eq=false;
		
		REP(i,SZ(str)){
			if(str[i]=='+'){
				pls=true;
			}else if(str[i]='='){
				eq=true;
			}else if(!pls){
				s1+=str[i];
			}else if(!eq){
				s2=str[i];
			}else{
				ans+=str[i];
			}
		}
		reverse(ALL(s1));reverse(ALL(s2));reverse(ALL(ans));
		while(SZ(s1)<SZ(ans))s1+='0';
		while(SZ(s2)<SZ(ans))s2+='0';
		REP(i,130)kuri[i]=-1;
		REP(i,SZ(ans)){
			if(s1!='X'&&s2!='X'&&ans!='X'){
				if(ci(s1)+ci(s2)==ci(ans))kuri[i]=0;
				else if()
			}
		}
	}
	return 0;
}

/*
4
5+4*3+2/(1-1-1)=
(1+4)*(3+7)/5=
5+4-3=
(1+5)*(2+3)=
3
1+2*3/2=
1+2*(3-2)/(4+5)=
1*2+3/(2+5)=
*/
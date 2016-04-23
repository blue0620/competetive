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

int n,m;


void refl(int *array){
	int pa[]={0,n};
	int ch=0;
	int card[201];
	
	REP(i,2*n){
		card[i]=array[pa[i%2]++];
	}
	REP(i,201)array[i]=card[i];
	return;
}

void cutk(int *array,int k){
	int card[201];int cnt=0;
	REP(i,2*n){
		if(i<2*n-k){
			card[i]=array[i+k];
		}else{
			card[i]=array[cnt++];
		}
	}
	REP(i,201)array[i]=card[i];
	return;
}

int main(){
	int card[201];
	cin>>n>>m;
	REP(i,2*n)card[i]=i+1;
	REP(i,m){
		int k;
		cin>>k;
		if(k==0){
			refl(card);
		}else{
			cutk(card,k);
		}
	}
	REP(i,2*n)cout<<card[i]<<endl;
	return 0;
}


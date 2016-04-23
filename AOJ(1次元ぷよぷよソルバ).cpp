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

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const double EPS = 1e-12;
const double INF = 1e12;

int N;
int a[10003];
int pari(int pos){
	int l=pos-1,r=pos+1;
	int sum1=0,sum2=0,temp=1;
	int nowc=(a[l]!=0)?a[l]:a[r];
	
	while(1){
		if(a[l]!=nowc&&a[r]!=nowc||a[l]==0&&a[r]==0){
			if(temp>=4){
				sum1+=temp;
				temp=0;
				nowc=max(a[l],a[r]);
				if(nowc==0)break;
			}else{
				break;
			}
		}
		if(a[l]==nowc){
			temp++;
			l--;
		}
		if(a[r]==nowc){
			temp++;
			r++;
		}
	}
	temp=1;l=pos-1,r=pos+1;
	nowc=(a[r]!=0)?a[r]:a[l];
	while(1){
		//cout<<temp<<" "<<nowc<<endl;
		if(a[l]!=nowc&&a[r]!=nowc||a[l]==0&&a[r]==0){
			if(temp>=4){
				sum2+=temp;
				temp=0;
				nowc=max(a[l],a[r]);
				if(nowc==0)break;
			}else{
				break;
			}
		}
		if(a[l]==nowc){
			temp++;
			l--;
		}
		if(a[r]==nowc){
			temp++;
			r++;
		}
	}
	return max(sum1,sum2);
}

int main(){
	
	while(cin>>N){
		if(N==0)break;
		CLR(a);
		REP(i,N)cin>>a[i+1];
		int maxi=0;
		FOR(i,1,N+1){
			maxi=max(pari(i),maxi);
		}
		cout<<N-maxi<<endl;
	}
	return 0;
}

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
#define MAX_N 1000002

const int B=100000;
long A[MAX_N];
long N;
long I[MAX_N*2],J[MAX_N*2],K[MAX_N*2],ans[MAX_N*2];
long nums[MAX_N];
VI bucket[MAX_N/B];
void solve(){
	REP(i,N){
		bucket[i/B].PB(A[i]);
		nums[i]=A[i];
	}
	sort(nums,nums+N);
	REP(i,N/B)SORT(bucket[i]);
	REP(i,2*N){
		long l=I[i],r=J[i]+1,x=K[i];
		long lb=-1,ub=N-1;
		int tl=l,tr=r,c=0;
		while(tl<tr&&tl%B!=0)if(A[tl++]==x)c++;
		while(tl<tr&&tr%B!=0)if(A[--tr]==x)c++;
		while(tl<tr){
			int b=tl/B;
			c+=upper_bound(bucket[b].begin(), bucket[b].end(), x)-lower_bound(bucket[b].begin(), bucket[b].end(), x);
			tl+=B;
		}
		//cout<<c<<endl;
		ans[i]=c;
	}
}
int main(){
	cin>>N;
	REP(i,N)cin>>A[i];
	REP(i,N){
		I[i]=0;J[i]=i;K[i]=A[i];
		I[i+N]=i;J[i+N]=N-1;K[i+N]=A[i];
	}
	solve();
	long res=0;
	REP(i,N)FOR(j,i+1,N){
		//cout<<ans[i]<<endl;
		if(ans[i]>ans[N+j])res++;
	}
	cout<<res<<endl;
	return 0;
}

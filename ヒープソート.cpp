//include
//------------------------------------------
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
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
//typedef boost::multiprecision::cpp_int bigint;
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
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-8;
const long INF = 1e12;


long heap[100001],sz=0;

void push(int x){
	int i=sz++;
	while(i>0){
		int p=(i-1)/2;
		if(heap[p]<=x)break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i]=x;
}
long pop(){
	long ret=heap[0];//Å¬’l
	long x=heap[--sz];
	long i=0;
	while(i*2+1<sz){
		long a=i*2+1,b=i*2+2;
		if(b<sz&&heap[b]<heap[a])a=b;
		if(heap[a]>=x)break;
		heap[i]=heap[a];
		i=a;
	}
	heap[i]=x;
	return ret;
}

int main(){
	ifstream ifs("rosalind_ps.txt");
	ofstream ofs("test2.txt");
	long N,K;ifs>>N;
	REP(i,N){
		long A;
		ifs>>A;
		push(A);
	}
	ifs>>K;
	REP(i,K)ofs<<pop()<<" ";
	ofs<<endl;
	return 0;
}
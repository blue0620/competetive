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
const int INF = 1e5;

int a[401][401],b[401][401],c[401][401];
int mat[401][401];
void matrixmultiply(int N)
{
        int i,j,k;
        for(i=0;i<N;i++) {
                for(j=0;j<N;j++) {
                        for(k=0;k<N;k++) {
                                c[i][j]+=a[i][k]*b[k][j];
                        }
                }
        }
}

void beki(int N,int m){
	CLR(a);CLR(b);
	m--;
	REP(i,m){
		CLR(c);
		if(i==0){
			REP(j,N)REP(k,N){
				a[j][k]=mat[j][k];
				b[j][k]=mat[j][k];
			}
			matrixmultiply(N);
			REP(j,N)REP(k,N)a[j][k]=c[j][k];
		}else{
			matrixmultiply(N);
			REP(j,N)REP(k,N)a[j][k]=c[j][k];
		}
	}
}

int main(){
	ifstream ifs("rosalind_sq.txt");
	ofstream ofs("test2.txt");
	int N;ifs>>N;
	REP(i,N){
		CLR(mat);
		int n,m,aa,bb;
		ifs>>n>>m;
		REP(j,m){
			ifs>>aa>>bb;
			aa--;bb--;
			mat[aa][bb]=mat[bb][aa]=1;
		}
		
		long tr=0;
		beki(n,4);
		REP(j,n)tr+=a[j][j];
		beki(n,2);
		long aij=0;
		REP(j,n)FOR(k,j+1,n){
			aij+=a[j][k];
		}
		long res=(tr-2*m-4*aij)/8;
		cout<<res<<endl;
		
	}
	return 0;
}
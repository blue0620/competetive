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

int x[100003];

// 配列 x[ ] の left から right の要素のマージソートを行う
void MergeSort(int left, int right)
{
    int mid, i, j, k;
    if (left >= right)return;//配列の要素が1つのとき
                                    
    mid = (left + right) / 2;//ソートしたい範囲の中央
    MergeSort(left, mid);
    MergeSort(mid + 1, right);

    //sortしたい範囲についてキューで持つ
	queue<int>ql,qr;
    for (i = left; i <= mid; i++)ql.push(x[i]);
    for (i = mid + 1; i <= right; i++)qr.push(x[i]);
    for (k = left; k <= right; k++){
	    if(qr.empty()||(!ql.empty()&&ql.front()<qr.front())){
			x[k]=ql.front();ql.pop();
	    }else{
			x[k]=qr.front();qr.pop();
	    }
    }
}

int main(){
	ifstream ifs("rosalind_ms.txt");
	ofstream ofs("test2.txt");
	int N;ifs>>N;
	REP(i,N)ifs>>x[i];
	MergeSort(0,N-1);
	REP(i,N)ofs<<x[i]<<" ";
	ofs<<endl;
	return 0;
}
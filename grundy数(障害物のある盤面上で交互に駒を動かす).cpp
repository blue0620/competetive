//include
//------------------------------------------
#include <bits/stdc++.h>

using namespace std;

//conversion
//------------------------------------------
inline long long toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
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

const double EPS = 1e-12;
const double INF = 1e12;
const LL MOD=1000000007;


int dx[]={1,0,1},dy[]={0,1,1};
int H, W;
VS board;
 
int grundy( const int y, const int x )
{
	static VVI dp( H, VI( W, -1 ) );
 
	if ( dp[y][x] != -1 )
	{
		return dp[y][x];
	}
 
	set< int > s;
	REP( d, 3 )
	{
		const int ny = y + dy[d];
		const int nx = x + dx[d];
 
		if ( H <= ny || W <= nx || board[ ny ][ nx ] == '#' )
		{
			continue;
		}
		s.insert( grundy( ny, nx ) );
	}
 
	int res = 0;
	while ( EXIST( s, res ) )
	//grundy数(ある状態から1回の遷移で行ける状態のgrundy数の集合に含まれない最小の非負整数)
	{
		++res;
	}
	return dp[y][x] = res;
}
 
int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
 
	cin >> H >> W;
	board.resize( H );
	REP(i,H)cin >> board[i];
	
	cout << ( grundy( 0, 0 ) ? "First" : "Second" ) << endl;
	//grundy数が0でない状態からは必ずgrundy数が0の状態に遷移できる
	//grundy数が0の状態からgrundy数が0の状態へは遷移できない
	//つまり最初のゲームの状態のgrundy数が0ならば後手の勝ち
 
	return 0;
}
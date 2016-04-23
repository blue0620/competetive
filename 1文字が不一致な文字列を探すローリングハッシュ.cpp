/*
Watto, the owner of a spare parts store, has recently got an order for the mechanism that can process strings in a certain way. Initially the memory of the mechanism is filled with n strings. Then the mechanism should be able to process queries of the following type: "Given string s, determine if the memory of the mechanism contains string t that consists of the same number of characters as s and differs from s in exactly one position".

Watto has already compiled the mechanism, all that's left is to write a program for it and check it on the data consisting of n initial lines and m queries. He decided to entrust this job to you.
Input

The first line contains two non-negative numbers n and m (0???n???3・105, 0???m???3・105) ? the number of the initial strings and the number of queries, respectively.

Next follow n non-empty strings that are uploaded to the memory of the mechanism.

Next follow m non-empty strings that are the queries to the mechanism.

The total length of lines in the input doesn't exceed 6・105. Each line consists only of letters 'a', 'b', 'c'.
Output

For each query print on a single line "YES" (without the quotes), if the memory of the mechanism contains the required string, otherwise print "NO" (without the quotes).
*/


#include <bits/stdc++.h>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline int toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<long,long> PLL;
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
#define MAX_N 601000
const long double EPS = 1e-15;
const LL mod=1000000000000000003;
LL pw[MAX_N];

unordered_set<LL>ff;

int main(){
	int N,M;
	cin>>N>>M;
	pw[0]=1;
	FOR(i,1,MAX_N)pw[i]=pw[i-1]*3%mod;//3進数でi桁目の値を準備する(これに0~2をかければ良い)
	
	REP(i,N){
		string str;
		cin>>str;
		LL hs=0;
		REP(j,SZ(str))hs=(hs*3+(str[j]-'a'))%mod;//文字列全体のハッシュを作る
		ff.insert(hs);
	}
	REP(i,M){
		string str;
		cin>>str;
		LL hs=0;
		bool flag=0;
		REP(j,SZ(str))hs=(hs*3+(str[j]-'a'))%mod;//文字列全体のハッシュを作る
		REP(j,SZ(str)){
			LL nhs=(hs-(str[SZ(str)-1-j]-'a')*pw[j])%mod;//全体から1文字ずつ抜いた接頭辞のハッシュを作る
			if(nhs<0)nhs+=mod;
			REP(k,3)if(str[SZ(str)-1-j]-'a'!=k){
				if(ff.count((nhs+k*pw[j])%mod))flag=1;//抜いた部分に1文字ずつ入れてみてハッシュを作り, 照合する.
			}
			if(flag)break;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}
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

ofstream ofs("test.txt");
set<PII>st;
int cnt;
struct Trie {
  int value;
  Trie *next[0x100];
  Trie() { fill(next, next+0x100, (Trie*)0); }
};
Trie *fnd(const char *t, Trie *r) {
	//int num=1;
	r->value=1;
  for (int i = 0; t[i]; ++i) {
    char c = t[i];
    if (!r->next[c]){
		r->next[c] = new Trie;
		cnt++;
		r->next[c]->value=cnt;
    }
	if(st.find(MP(r->value,r->next[c]->value))==st.end()){
		st.insert(MP(r->value,r->next[c]->value));
		ofs<<r->value<<" "<<r->next[c]->value<<" "<<c<<endl;
	}
	//num=r->value+1;
    r = r->next[c];
  }
  return r;
}


int main(){
	ifstream ifs("rosalind_trie.txt");
	st.clear();
	string str;
	Trie r;cnt=1;
	while(ifs>>str){
		cout<<str<<endl;
		fnd(str.c_str(),&r);
		//cout<<r.value<<endl;
	}
	
	return 0;
}
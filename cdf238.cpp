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
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

char board[4][4];
int main(){
	ifstream ifs( "A-large-practice.in" );
	ofstream ofs( "test.txt" );
	int T;
	ifs>>T;
	REP(i,T){
		int c=0;
		REP(j,4)REP(k,4){
			ifs>>board[j][k];
			if(board[j][k]=='.')c++;
		}
		int x,o;
		int xwin=0,owin=0;
		REP(j,4){
			x=0;o=0;
			REP(k,4){
				if(board[j][k]=='X')x++;
				else if(board[j][k]=='O')o++;
				else if(board[j][k]=='T')x++,o++;
			}
			xwin=max(xwin,x);owin=max(owin,o);
		}
		REP(k,4){
			x=0;o=0;
			REP(j,4){
				if(board[j][k]=='X')x++;
				else if(board[j][k]=='O')o++;
				else if(board[j][k]=='T')x++,o++;
			}
			xwin=max(xwin,x);owin=max(owin,o);
		}
		x=0;o=0;
		REP(j,4){
			if(board[j][j]=='X')x++;
			else if(board[j][j]=='O')o++;
			else if(board[j][j]=='T')x++,o++;
			xwin=max(xwin,x);owin=max(owin,o);
		}
		x=0;o=0;
		REP(j,4){
			if(board[j][3-j]=='X')x++;
			else if(board[j][3-j]=='O')o++;
			else if(board[j][3-j]=='T')x++,o++;
			xwin=max(xwin,x);owin=max(owin,o);
		}
		string str;
		if(xwin!=4&&owin!=4&&c==0){
			str="Draw";
		}else if(xwin==4&&owin!=4){
			str="X won";
		}else if(xwin!=4&&owin==4){
			str="O won";
		}else{
			str="Game has not completed";
		}
		
		ofs<<"Case #"<<i+1<<": "<<str<<endl;
	}
	
	return 0;
}

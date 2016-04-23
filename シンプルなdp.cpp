#include <stdlib.h>
#include <stdio.h>
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
#include <math.h>
#include "clx/sha1.h"
#include <boost/multiprecision/cpp_int.hpp>

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
typedef boost::multiprecision::cpp_int bigint;

int dp[80][80];
int main(){
	FILE *fp;
	fp = fopen("matrix.txt", "r" );
	
	char c[1000];
	int num[80][80];
	CLR(num);
	int x=0,y=0;
	int temp=0;
	while(fgets(c,1000,fp)!=NULL){
		REP(i,strlen(c)){
			if(c[i]=='\n'){
				num[y][x]=temp;
				x=0;y++;
				temp=0;
			}else if(c[i]==','){
				num[y][x]=temp;
				x++;
				temp=0;
			}else{
				temp*=10;
				temp+=(unsigned int)(c[i]-'0');
			}
		}
	}
	fclose(fp);
	dp[0][0]=num[0][0];
	REP(i,79)dp[0][i+1]=dp[0][i]+num[0][i+1];
	REP(i,79)dp[i+1][0]=dp[i][0]+num[i+1][0];
	REP(i,79)REP(j,79){
		dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][j])+num[i+1][j+1];
	}
	cout<<dp[79][79]<<endl;
	return 0;
}



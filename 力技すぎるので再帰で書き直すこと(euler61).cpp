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

#define MAX_N 10000
int fig[9][MAX_N];
vector<PII>pi[6];
int main(){
	REP(i,9){
		fig[i][0]=0;
		fig[i][1]=1;
	}
	FOR(h,3,9)for(int i=1;i<MAX_N-1;i++){
		fig[h][i+1]=fig[h][i]+(i*(h-2)+1);
		if(fig[h][i+1]>=10000)break;
		if(fig[h][i+1]>=1000&&fig[h][i+1]%100>=10){
			pi[h-3].PB(MP(fig[h][i+1]/100,fig[h][i+1]%100));
		}
	}
	FOR(i1,1,6){
		REP(j1,SZ(pi[0]))REP(k1,SZ(pi[i1])){
			if(pi[i1][k1].first==pi[0][j1].second){
				FOR(i2,1,6)if(i2!=i1){
					REP(k2,SZ(pi[i2]))if(pi[i2][k2].first==pi[i1][k1].second){
						FOR(i3,1,6)if(i3!=i1&&i3!=i2){
							REP(k3,SZ(pi[i3]))if(pi[i3][k3].first==pi[i2][k2].second){
								FOR(i4,1,6)if(i4!=i1&&i4!=i2&&i4!=i3){
									REP(k4,SZ(pi[i4]))if(pi[i4][k4].first==pi[i3][k3].second){
										FOR(i5,1,6)if(i5!=i1&&i5!=i2&&i5!=i3&&i5!=i4){
											REP(k5,SZ(pi[i5]))if(pi[i5][k5].first==pi[i4][k4].second&&pi[i5][k5].second==pi[0][j1].first){
												cout<<pi[0][j1].first<<pi[0][j1].second<<" "<<pi[i1][k1].first<<pi[i1][k1].second<<" "<<pi[i2][k2].first<<pi[i2][k2].second;
												cout<<" "<<pi[i3][k3].first<<pi[i3][k3].second<<" "<<pi[i4][k4].first<<pi[i4][k4].second<<" "<<pi[i5][k5].first<<pi[i5][k5].second<<endl;
											}
										}
									}
								}
							}
						}
						
					}
				}
			}
		}
	}
	
	return 0;
}



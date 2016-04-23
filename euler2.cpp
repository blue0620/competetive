#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

#define INF 10000000

long dp[10001];
int main(){
	
	ifstream ifs("roman.txt");
	char romc[]={'M','D','C','L','X','V','I'};
	int romi[]={1000,500,100,50,10,5,1};
	//int value[]={1000,500,100,50,10,5,1,900,400,90,40,9,4};
	//int cost[]={1,1,1,1,1,1,1,2,2,2,2,2,2};
	long res=0;
	long mi=INF;
	int cnt=1,num=0;
	string c;
	while(getline(ifs,c)){
		long t1=SZ(c);
		long sum=0;
		int pos=-1;
		REP(i,7){
			FOR(j,pos+1,SZ(c))if(c[j]==romc[i]){
				sum+=romi[i];
				if(j-1>=0&&c[j-1]!=romc[i]){
					REP(k,7)if(c[j-1]==romc[k]&&k>i){
						sum-=romi[k];
					}
				}
				pos=j;
			}
		}
		long t2=0;
		while(sum>=1000){
			sum-=1000;
			t2++;
		}
		if(sum>=900){
			sum-=900;
			t2+=2;
		}
		if(sum>=500){
			sum-=500;
			t2++;
		}
		if(sum>=400){
			sum-=400;
			t2+=2;
		}
		while(sum>=100){
			sum-=100;
			t2++;
		}
		if(sum>=90){
			sum-=90;
			t2+=2;
		}
		if(sum>=50){
			sum-=50;
			t2++;
		}
		if(sum>=40){
			sum-=40;
			t2+=2;
		}
		while(sum>=10){
			sum-=10;
			t2++;
		}
		if(sum==9){
			sum-=9;
			t2+=2;
		}
		if(sum>=5){
			sum-=5;
			t2++;
		}
		if(sum==4){
			sum-=4;
			t2+=2;
		}
		while(sum!=0){
			t2++;
			sum--;
		}
		if(mi>t1){
			mi=t1;
			num=cnt;
		}
		res+=(t1-t2);
		cnt++;
	}
	cout<<mi<<" "<<num<<endl;
	cout<<res<<endl;
	return 0;
}



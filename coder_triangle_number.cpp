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
#include <math.h>
#include "clx/sha1.h"

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
#include <boost/multiprecision/cpp_int.hpp>
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


int main(){
	FILE *fp;
	fp = fopen("p042_words.txt","r");
	char c;
	string str="";
	int maxi=0;
	int tri[101];
	tri[0]=0;
	REP(i,100)tri[i+1]=tri[i]+(i+1);
	//cout<<tri[100]<<endl;
	int res=0;
	while(fscanf(fp,"%c",&c)!=EOF){
		if(c==','){
			str="";
		}else if(c=='"'&&SZ(str)!=0){
			//cout<<str<<endl;
			int sum=0;
			REP(i,SZ(str)){
				sum+=(unsigned int)(str[i]-'A')+1;
			}
			if(binary_search(tri,tri+100,sum)){
				cout<<str<<sum<<endl;
				res++;
			}
		}else if(c!='"'){
			str+=c;
		}
		
	}
	cout<<res<<endl;
	fclose(fp);
	return 0;
}


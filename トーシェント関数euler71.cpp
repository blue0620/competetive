//include
//------------------------------------------
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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
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
typedef boost::multiprecision::cpp_int bigint;
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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
typedef boost::multiprecision::cpp_int bigint;


long gcd(long a,long b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	long double mi=100.0;
	vector<long>prime;
	for(long i=2;SZ(prime)<2000;i++){
		bool c=true;
		for(long j=2;j*j<=i;j++)if(i%j==0)c=false;
		if(c)prime.PB(i);
	}
	cout<<prime[1999]<<endl;
	for(long i=0;i<SZ(prime);i++){
		for(long j=i;j<SZ(prime);j++){
			long sum=0;
			long temp=prime[i]*prime[j];
			
			if(temp>=10000000)break;
			/*for(long k=1;k<temp;k++){
				if(gcd(k,temp)==1)sum++;
			}*/
			sum=temp-(prime[i]+prime[j]-1);
			string str1=toString(temp);
			string str2=toString(sum);
			SORT(str1);
			SORT(str2);
			if(str1==str2){
				//cout<<prime[i]<<" "<<prime[j]<<endl;
				//cout<<(double)temp/sum<<endl;
				if(mi>(long double)temp/sum){
					mi=(long double)temp/sum;
					cout<<"!!"<<temp<<" "<<sum<<endl;
					cout<<"!!"<<mi<<endl;
				}
			}
		}
	}
	return 0;
}
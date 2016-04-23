#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
//#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

#define MAX_N 30000
typedef __int64 LL;


int main(){
	int a,b;
	cin>>a>>b;
	if(a>b){
		int n=0;
		while(log(b*b)>log((2*a-2*n-1)*(n+1)*(n+2)))n++;
		cout<<(LL)((a-n)*(a-n)-b*b/(n+1))<<endl;
		int rem=b%(n+1);
		int gap=(b-rem)/(n+1);
		REP(i,a-n)cout<<"o";
		int sum=0;
		int tt=0;
		cout<<n<<" "<<gap<<" "<<rem<<endl;
		while(sum<b){
			if(tt==gap+(rem>=0)&&n>0){
				cout<<"o";
				cout<<sum<<endl;
				n--;
				tt=0;
				rem--;
			}else{
				cout<<"x";
				tt++;
				sum++;
			}
		}
		cout<<sum<<endl;
		cout<<endl;
	}else if(a==b){
		cout<<0<<endl;
		REP(i,a)cout<<"o";
		REP(i,b)cout<<"x";
		cout<<endl;
	}else if(a<b){
		cout<<(LL)(-(b-a)*(b-a))<<endl;
		REP(i,b){
			cout<<"x";
			if(a>0)cout<<"o";
			a--;
		}
		cout<<endl;
	}
	return 0;
}
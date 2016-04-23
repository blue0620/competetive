#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define CLR(a) memset((a), 0 ,sizeof(a))

//[l,n]
int bit[MAX_N+1],n;

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;//iの最後の1のビットはi&-iで表せる
	}
	return s;
}


int add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
	return 0;
}


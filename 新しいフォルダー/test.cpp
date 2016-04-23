#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <sstream>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

double horner(double v,double x,int i){
	if(i>=0){
		i--;
		return horner(v*x+1.0,x,i);
	}else{
		return v;
	}
}

int main(){
	double x[6]={0.5,0.6,0.7,0.8,0.9,1.0};
	double xans[6][6]={{0}};
	double expans[6]={{0}};
	double logans[6]={0};
	
	REP(i,6)REP(j,6)xans[i][j]=horner(0.0,x[i],i+2);
	REP(i,6)REP(j,6){
		cout<<x[i]<<endl;
	}
	return 0;
}
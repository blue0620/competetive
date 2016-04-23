#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define X 0.75

double hpoly(double v,double x,int i){
	if(i>=0){
		i--;
		return hpoly(v*x+1.0,x,i);
	}else{
		return v;
	}
}
double ncount(double x0,double x1,double p0,double p1){
	return ((X-x0)*p1-(X-x1)*p0)/(x1-x0);
}

double nevi(double *x,double *p){
	double ne[6][6]={{0}};
	REP(i,6){
		ne[0][i]=p[i];
	}
	FOR(i,1,6){
		REP(j,6-i){
			ne[i][j]=ncount(x[j],x[j+i+1],ne[i-1][j],ne[i-1][j+1]);
		}
	}
	return ne[5][0];
}
int main(){
	double x[6]={0.5,0.6,0.7,0.8,0.9,1.0};
	double xans[6][6]={{0}};
	double expans[6]={{0}};
	double logans[6]={0};
	
	
	REP(i,6)REP(j,6)xans[i][j]=hpoly(0.0,x[j],i+2);
	
	REP(i,6){
		expans[i]=exp(x[i]);
		logans[i]=log(x[i]);
	}
	
	cout<<"polynomial f(0.75):"<<endl;
	REP(i,6){
		double t[6];
		REP(j,6)t[j]=xans[i][j];
		cout<<"    n="<<i+2<<": "<<nevi(x,t)<<" "<<"ƒ¢="<<hpoly(0.0,0.75,i+2)-nevi(x,t)<<endl;
		
	}
	cout<<"exp f(0.75): "<<nevi(x,expans)<<" "<<"ƒ¢="<<exp(X)-nevi(x,expans)<<endl;
	cout<<"log f(0.75): "<<nevi(x,logans)<<" "<<"ƒ¢="<<log(X)-nevi(x,logans)<<endl;
	
	
	return 0;
	
}
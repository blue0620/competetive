#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

int main(){
	ofstream ofs( "ld.dat" );
	ofstream plt( "plot.plt" );
	double p[17][201]={{0}};
	double x[201]={0};
	REP(i,201){
		p[0][i]=1;
		x[i]=p[1][i]=-1.0+(double)i/100;
	}
	FOR(n,1,16)REP(j,201)p[n+1][j]=((n*2+1)*x[j]*p[n][j]-n*p[n-1][j])/(n+1);
	REP(i,201){
		ofs<<x[i];
		REP(n,16){
			ofs<<" "<<p[n][i];
			if(i==0){
				if(n==0)plt<<"plot \"ld.dat\" using 1:"<<n+2<<" w l title \"P"<<n<<"\""<<endl;
				else plt<<"replot \"ld.dat\" using 1:"<<n+2<<" w l title \"P"<<n<<"\""<<endl;
			}
		}
		ofs<<endl;
	}
	return 0;
}
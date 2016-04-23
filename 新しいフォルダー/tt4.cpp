#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

int main(){
	double N,NX,NY,QX,QY;
	cin>>N>>NX>>NY>>QX>>QY;
	vector <double> wax(N);
	vector <double> way(N);
	vector <double> wbx(N);
	vector <double> wby(N);
	double A=(QY-NY)/(QX-NX);
	double B=NY-A*NX;
	FOR(i,0,N-1){
		cin>>wax[i]>>way[i]>>wbx[i]>>wby[i];
	}
	int count=1;
	FOR(i,0,N-1){
		double A2=(wby[i]-way[i])/(wbx[i]-wax[i]);
		double B2=way[i]-A2*wax[i];
		if(A!=A2){
		double x=(B2-B)/(A-A2);
		double y=x*A2+B2;
		if(x>=min(NX,QX)&&x<=max(NX,QX)&&y>=min(NY,QY)&&y<=max(NY,QY)){
			count++;
		}
		}
	}
	cout<<count<<endl;
	return 0;
}
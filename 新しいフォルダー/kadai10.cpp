#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <complex>
#include <time.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

typedef unsigned int uint;
typedef complex<double> Freq;

int polyprint(vector< complex<double> >& a)
{
	int asize=a.size();
	REP(i,asize) cout<<a[i]<<endl;
	return 0;
}

int fft(int k,vector< complex<double> >& a)
{
	int n=a.size();
	uint K=1;
	REP(i,k){
		K<<=1;
		int gap=K>>1;
		complex<double> w=exp(complex<double>(0.0,-2.0*M_PI/(double)K));
		complex<double> wnow(1.0,0.0);
		REP(j,gap){
			for(int l=0;l<n;l+=K){
				complex<double> temp=wnow*a[j+l+gap];
				int p1=j+l;
				int p2=j+l+gap;
				a[p2]=a[p1]-temp;
				a[p1]+=temp;
			}
			wnow*=w;
		}
	}
	polyprint(a);
	return 0;
}

int hpoly(vector< complex<double> >& t){
	int n=t.size();
	vector< complex<double> > ans(n);
	complex<double> w=exp(complex<double>(0.0,-2.0*M_PI/(double)n));
	complex<double> wnow(1.0,0.0);

	
	REP(j,n){
		ans[j]=t[n-1];
		for(int k=n-2;k>=0;k--){
			ans[j]=t[k]+ans[j]*wnow;
		}
		wnow*=w;
	}
	polyprint(ans);
	return 0;
}

int main(){
	uint k;
	cin>>k;
	uint K=1;
	REP(i,k)K<<=1;
	vector< complex<double> > t(K);
	REP(i,K)cin>>t[i];
	vector< complex<double> > a(K);
	clock_t t1, t2, t3;
	t1=clock();
	
	
	REP(i,K){//bit reverse
		uint n=i;
		uint r=0;
		for (int i = 0; i < k; i++, n>>=1){
        	r = r << 1 | n & 1;
		}
		a[i]=t[r];
	}
	
	cout<<"FFT:"<<endl;
	fft(k,a);
	t2=clock();
	cout<<t2-t1<<"ms"<<endl;
	
	cout<<"horner:"<<endl;
	hpoly(t);
	t3=clock();
	cout<<t3-t1<<"ms"<<endl;
	
	return 0;
}
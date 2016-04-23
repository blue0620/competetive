#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main(){
	int n,m,l;
	cin>>n>>m>>l;
	vector< vector<double> > array1(n, vector<double>(m));
	vector< vector<double> > array2(m, vector<double>(l));
	FOR(i,0,n){
		FOR(j,0,m){
			cin>>array1[i][j];
		}
	}
	FOR(i,0,m){
		FOR(j,0,l){
			cin>>array2[i][j];
		}
	}
	FOR(i,0,n){
		FOR(j,0,l){
			double t=0;
			FOR(k,0,m){
				t+=array1[i][k]*array2[k][j];
			}
			cout<<t<<" ";
		}
		cout<<endl;
	}
	return 0;
}
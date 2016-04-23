#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stdio.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)



int main(){
	int T;
	cin>>T;
	vector< vector<int> > A(T, vector<int>(4));
	vector <int> S(T);
	REP(i,T){
		REP(j,4)cin>>A[i][j];
		cin>>S[i];
	}
	REP(i,T){
		int sum[101]={0};
		sum[0]=0;
		REP(j,4)sum[1]+=A[j];
		int n=1;
		while(sum[n]<=S[i]){
			n++;
			int temp=((A[3]*n+A[2])*n+A[1])*n+A[0];
			if(temp==sum[1]){
				n=1;
				break;
			}
			sum[n]=temp;
		}
		
	}
	return 0;
	
}
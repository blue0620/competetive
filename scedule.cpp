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
#define MAX_N 10000
#define MAX_LOG_N 15

int N,M;
int s[MAX_N],t[MAX_N];
pair<int,int>ps[MAX_N*2];
int next[MAX_LOG_N][MAX_N];

long pcount(){
	long res=0;
	
	//区間の端点をソート
	REP(i,N){
		ps[i]=make_pair(t[i],i);
		ps[N+i]=make_pair(s[i],N+i);
	}
	sort(ps,ps+N*2);
	//next[0]の計算
	int last=-1;
	for(int i=N*2-1;i>=0;i--){
		int id=ps[i].second;
		if(id<N){
			//区間の末尾
			next[0][id]=last;
		}else{
			id-=N*2;
			if(last<0||t[last]>t[id]){
				last=id;
			}
		}
	}
	//nextの計算
	for(int k=0;k+1<MAX_LOG_N;k++){
		REP(i,N*2){
			if(next[k][i]<0)next[k+1][i]=-1;
			else next[k+1][i]=next[k][next[k][i]];
		}
	}
	REP(i,N){
		//二分探索
		int tmp=0;
		int j=i;
		for(int k=MAX_LOG_N-1;k>=0;k--){
			int j2=next[k][j];
			if(j2>=0&&t[j2]<=s[i]){
				j=j2;
				tmp |=1<<k;
			}
		}
		res=max(res,tmp+1);
	}
	return res;
}



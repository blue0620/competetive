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

int maze[501][501]={0};
int c[501][501]={0};
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	REP(i,n)REP(j,m){
		char ch;
		scanf(" %c",&ch);
		if(ch=='.')maze[i+1][j+1]=1;
	}
	FOR(i,1,n+1)FOR(j,1,m+1){
		if(maze[i][j]==1){
			c[i][j]=maze[i-1][j]+maze[i+1][j]+maze[i][j-1]+maze[i][j+1];
		}else{
			c[i][j]=-1;
		}
	}
	while(k>0){
		FOR(i,1,n+1){
		FOR(j,1,m+1){
			if(c[i][j]>=0&&c[i][j]==1){
				c[i][j]=-1;
				c[i-1][j]--;
				c[i+1][j]--;
				c[i][j-1]--;
				c[i][j+1]--;
				maze[i][j]=-1;
				k--;
				if(k==0)break;
			}
		}
		if(k==0)break;
		}
	}
	REP(i,n){
		REP(j,m){
			if(maze[i+1][j+1]==1){
				cout<<".";
			}else if(maze[i+1][j+1]==-1){
				cout<<"X";
			}else if(maze[i+1][j+1]==0){
				cout<<"#";
			}
		}
		cout<<endl;
	}
	return 0;

}
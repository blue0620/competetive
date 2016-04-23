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

int mrow[4]={0};
int mcol[4]={0};
int n,m;
stack <int>st;
int bring(int x,int y,int c){
	
	REP(i,4){
		int x2=x+mrow[i];
		int y2=y+mcol[i];
		if(!st.empty()){
			int i2=st.top();
			if(mrow[i]==-mrow[i2]&&mcol[i]==-mcol[i2]) continue;
		}
		if(x2<n&&x2>1&&y2<m&&y2>1){
			st.push(i);
			c++;
			cout<<c<<endl;
			return bring(x2,y2,c);
		}
	}
	if((x==1&&(y==1||y==m))||(x==n&&(y==1||y==m)))return c;
	if(!st.empty()){
		int i2=st.top();
		st.pop();
		c--;
		cout<<c<<endl;
		return bring(x-mrow[i2],y-mrow[i2],c);
	}else{
		return -1;
	}
	
}
int main(){
	int i, j, a, b;
	cin>>n>>m>>i>>j>>a>>b;
	mrow[0]=mrow[2]=-a;
	mrow[1]=mrow[3]=a;
	mcol[0]=mcol[1]=-b;
	mcol[2]=mcol[3]=b;
	
	int ans=bring(i,j,0);
	if(ans==-1){
		cout<<"Poor Inna and pony!"<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
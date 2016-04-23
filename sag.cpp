#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <numeric>
#include <stdio.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define N 101
int g[N][N];
int g2[N][N];
int adj[N][N];
int adj2[N][N];
int n,m,temp;
bool t=false;
void dfs(int a, vector<int>& route,bool c) {
  FOR(b,1,n+1){
  	//if(b==a)continue;
	//cout<<adj[a][b]<<endl;
    if(!c&&adj[a][b]>0){
      adj[a][b]--;
      adj[b][a]--;
	  c=true;
	  cout<<"1!"<<a<<" "<<b<<endl;
      dfs(b,route,c);
	  
    }else if(c){
		adj[a][b]--;
      	adj[b][a]--;
		c=false;
		cout<<"2!"<<a<<" "<<b<<endl;
		dfs(b,route,c);
    }
  }
  //cout<<"!!"<<c<<" "<<a<<endl;
  
  route.push_back(a);
  //c=(c==true)?false:true;
  //cout<<"!!"<<c<<endl;
  temp=a;
}
 
bool euler(int start) {
  int odd = 0;
  int nEdges = 0;
  FOR(i,1,n+1){
    int deg = accumulate(g[i], g[i] + n, 0);
    if(deg % 2 == 1)
      odd++;
    nEdges += deg;
  }
  nEdges /= 2;
 
  vector<int> route;
  int startdeg = accumulate(g[start], g[start] + n, 0);
  //if(odd == 0 || (odd == 2 && startdeg % 2 == 1)){
    memcpy(adj, g, sizeof(g));
	//memcpy(adj2, g2, sizeof(g2));
    dfs(start, route, false);
  //}
  cout<<"!"<<nEdges<<":"<<route.size()<<endl;
  if((int)route.size() != n+1)return false;// ”ñ˜AŒ‹‚¾‚Á‚½ê‡
  
  return true;
}

int main(){
	int T;
	cin>>T;
	vector<string>ans;
	REP(i,T){
		cin>>n>>m;
		bool c=true;
		if(n%2==1)c=false;
		CLR(adj);CLR(g);
		REP(j,m){
			int t1,t2;
			cin>>t1>>t2;
			//cout<<"!!"<<t1<<t2<<endl;
			g[t1][t2]++;
			g[t2][t1]++;
		}
		temp=-1;
		if(!c||!euler(1)){
			ans.push_back("NO");
		}else{
			ans.push_back("YES");
		}
	}
	REP(i,T)cout<<ans[i]<<endl;
	return 0;
}
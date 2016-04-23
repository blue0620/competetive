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

struct edge{int f,t;};
int n,m;
int par[1001];
int rank[1001];

bool comp(const edge& e1,const edge& e2){
	return e1.f<e2.f;
}

void init(int n){
	REP(i,n){
		par[i]=i;
		rank[i]=0;
	}
}

int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank[x]<rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

bool unizon(vector<edge>G){
	bool flag=false;
	//REP(i,G.size())cout<<"!!"<<G[i].f<<endl;
	REP(i,G.size()){
		if(G[i].f!=1)break;
		init(n);
		unite(1,G[i].t);
		int res=2;
		FOR(j,i+1,G.size()){
			if(!same(1,G[j].f)&&!same(1,G[j].t)){
				unite(1,G[j].f);unite(1,G[j].t);
				res+=2;
			}
			//cout<<"!"<<res<<endl;
		}
		if(res==n){
			flag=true;
			break;
		}
	}
	return flag;
}

int main(){
	int T;
	cin>>T;
	vector<string>ans;
	REP(i,T){
		cin>>n>>m;
		vector<edge> G(m);
		bool c=true;
		//cout<<"!"<<n<<" "<<m<<endl;
		if(n%2==1)c=false;
		REP(j,m){
			int t1,t2;
			cin>>t1>>t2;
			G[j].f=min(t1,t2);
			G[j].t=max(t1,t2);
		}
		sort(G.begin(),G.end(),comp);
		if(!c||!unizon(G)){
			ans.push_back("NO");
		}else{
			ans.push_back("YES");
		}
	}
	REP(i,T)cout<<ans[i]<<endl;
	return 0;
}


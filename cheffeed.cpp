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

typedef pair<long,long> P;//firstÇÕìûíÖ,secondÇÕèoî≠

struct edge{long s,f,p;};

bool comp(const edge& e1,const edge& e2){
	return e1.p<e2.p;
}
bool comp2(const long& l1,const long& l2){
	return l1<l2;
}
bool comp3(const P& p1,const P& p2){
	return p1<p2;
}

long pcount(vector<P>name){
	vector <long>dp(2*name.size());
	vector <long>x;
	dp[0]=0;
	REP(i,name.size()){
		x.push_back(name[i].first);
		x.push_back(name[i].second);
	}
	sort(x.begin(),x.end(),comp2);
	//sort(name.begin(),name.end(),comp3);
	REP(i,name.size()*2){
		
		REP(k,name.size()){
			if(name[k].second<=x[i]){
				REP(j,i){
					if(x[j]>=name[k].first){
						dp[i]=max(dp[j]+1,dp[i-1]);
						//cout<<"!"<<i<<":"<<x[i]<<":"<<dp[i]<<endl;
						break;
					}
				}
			}
		}
		
	}
	return dp[name.size()*2-1];
}

int main(){
	int T;
	cin>>T;
	vector<long>ans;
	REP(i,T){
		long res=0;
		long N,K;
		cin>>N>>K;
		vector <edge> G(N);
		REP(j,N)cin>>G[j].s>>G[j].f>>G[j].p;
		sort(G.begin(),G.end(),comp);
		long tp=G[0].p;
		vector<P>name;  
		REP(j,N){
			if(G[j].p==tp){
				name.push_back(P(G[j].s,G[j].f));
			}else{
				res+=pcount(name);
				name.clear();
				name.push_back(P(G[j].s,G[j].f));
				tp=G[j].p;
			}
		}
		res+=pcount(name);
		ans.push_back(res);
		
	}
	REP(i,T)cout<<ans[i]<<endl;
	return 0;
}
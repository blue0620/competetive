#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define SZ(a) int((a).size())

typedef pair<int, int> PII;



vector<PII>pi[1003];

int main(){
	int L,n,m;
	cin>>L>>n>>m;
	REP(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		pi[a].push_back(make_pair(b,c));
		pi[a+1].push_back(make_pair(c,-b));
	}
	FOR(i,1,n+1){
		sort(pi[i].begin(),pi[i].end());
	}
	
	if(SZ(pi[1])!=0)FOR(i,1,n+1){
		int value=0;
		int pos=i;
		while(1){
			int ub=SZ(pi[pos]);
			int lb=-1;
			while(ub-lb>1){
				int mb=(ub+lb)/2;
				if(pi[pos][mb].first>=value){
					ub=mb;
				}else{
					lb=mb;
				}
			}
			value=pi[pos][ub].second;
			if(value<0)pos--;
			else pos++;
			value=abs(value)+1;
			if(pi[pos][SZ(pi[pos])-1].first<value)break;
		}
		if(pos==1){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"1"<<endl;
	return 0;
}

/*
7 4 5
1 3 1
3 2 2
2 3 5
3 4 4
1 6 6
*/

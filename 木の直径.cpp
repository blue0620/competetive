#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <fstream>



using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------

/*
//���a�����߂�Ȍ��ȕ��@
typedef vector< vector<int> > Graph;
 
int getFar(const Graph& g, int start){
	const int INF = 1000000007;
	int n = g.size();
	vector<int> dist(n, INF);//�J�n�_����̋����An�̗v�f��INF�Ŗ��߂Ċm��
	dist[start] = 0;//�J�n�_�̋�����0
	queue<int> qu; qu.push(start);
	int res = start;//�ŉ��_
	while(!qu.empty()){
		int p = qu.front(); qu.pop();
		res = p;
		for(int i=0;i<g[p].size();i++){
			int next = g[p][i];//next��p�Ɨאڂ���_
			if(dist[next] < dist[p]+1) continue;//(�_next����J�n�_�̋���)<=(�_p����J�n�_�̋���)�Ȃ�ł��؂�
			dist[next] = dist[p]+1;
			qu.push(next);
		}
	}
	return res;
}
 
int main(){
	int N;
	while(cin >> N){
		Graph g(N);
		for(int i=0;i<N-1;i++){
			int a, b; cin >> a >> b;
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}
		int s = getFar(g, 0);//�؂̒��a�͔C�ӂ̓_����̍ŉ��_�ƁA���̍ŉ��_����̍ŉ��_��2�_�ł���
		int t = getFar(g, s);
		cout << s+1 << " " << t+1 << endl;
	}
}*/
////////

//////

int n;
int vcnt;
int v[100003];
vector<int> gnext[100003];
// distance, node number
pair<int,int> dfs(int nod, int depth) {
	pair<int,int> ret(depth, nod);
	v[nod] = vcnt;
	for(int i=0;i<SZ(gnext[nod]);i++){
		int next=gnext[nod][i];
		if (v[next] == vcnt) continue;
		pair<int,int> res = dfs(next, depth+1);
		ret = max(ret, res);
	}
	return ret;
}
 
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		gnext[a].push_back(b);
		gnext[b].push_back(a);
	}
	++vcnt;
	pair<int,int> r1 = dfs(0,0);
	++vcnt;
	pair<int,int> r2 = dfs(r1.second,0);
	printf("%d %d\n", r1.second + 1, r2.second + 1);
	return 0;
}

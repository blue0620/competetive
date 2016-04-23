//include
//------------------------------------------
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

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))


///////////////////////ford-fulkerson O(F|E|)/////////////////////////////
#define MAX_V 1000
#define INF 1e9


struct edge{
	int to, cap, rev;
};//�ړI�n,�ӂ̗e��,�t��
vector <edge> G[MAX_V];//�אڃ��X�g
bool used[MAX_V];//���ɒ��ׂ���

//from->to�����֌������e��cap�̕ӂ𒣂�B���̎��t�ӂ̗e�ʂ�0
void add_edge(int from,int to,int cap){
	edge e={to, cap, SZ(G[to])};
	G[from].PB(e);
	edge e2={from, 0, SZ(G[from])-1};
	G[to].PB(e2);//�t�ӂ͈�O�̍s��push_back�����אڃ��X�g�v�f���w��
}

//�����p�X��DFS�ŒT��(���ݒn,�ړI�n(�s��),�ӂ̗���)�B���ʂ͕ۑ������A�ӂ̗e�ʂ�ω������Ă���
int dfs(int v,int t,int f){
	if(v==t)return f;//���郋�[�g�ɂ�����ő嗬��
	used[v]=true;
	REP(i,SZ(G[v])){
		edge &e=G[v][i];//G[v][i]�̃|�C���^���Q��
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				//���̑���̐S�́A����܂ł̃t���[�������o�������ɐV���ȃt���[�������邱�Ƃ�\���Ă���
				e.cap-=d;//�ӂ̗e�ʂ����Z����
				G[e.to][e.rev].cap+=d;//�t�ӂ̗e�ʂ����Z����
				return d;
			}
		}
	}
	return 0;
}

//s����t�ւ̍ő嗬�����߂�
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		CLR(used);
		int f=dfs(s,t,INF);
		if(f==0)return flow;
		flow+=f;
	}
}

///////////////////////ford-fulkerson O(F|E|)/////////////////////////////



///////////////////////dinic O(|E||V|^2)/////////////////////////////
#define MAX_V 1000
#define INF 1e9
struct edge{
	int to, cap, rev;
};//�ړI�n,�ӂ̗e��,�t��
vector <edge> G[MAX_V];//�אڃ��X�g
int level[MAX_V];//s����̋���
int iter[MAX_V];//�ǂ��܂Œ��ׂ���


//from->to�����֌������e��cap�̕ӂ𒣂�B���̎��t�ӂ̗e�ʂ�0
void add_edge(int from,int to,int cap){
	edge e={to, cap, SZ(G[to])};
	G[from].PB(e);
	edge e2={from, 0, SZ(G[from])-1};
	G[to].PB(e2);//�t�ӂ͈�O�̍s��push_back�����אڃ��X�g�v�f���w��
}

//s����̍ŒZ������\��BFS�Ōv�Z���Ă���
//������������������̕ӂ݂̂���Ȃ�O���t���쐬����B(�ŒZ�̑����p�X�̒����̓t���[�𗬂����ƂŒZ���Ȃ�Ȃ�)
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		REP(i,SZ(G[v])){
			edge &e=G[v][i];
			if(e.cap>0&&level[v]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}


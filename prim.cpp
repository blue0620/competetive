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

int cost[MAX_V][MAX_V];//cost[u][v]�͕�e=(u,v)
int mincost[MAX_V];//�W��X����̕ӂ̍ŏ��R�X�g
bool used[MAX_V];//���Ɏg��ꂽ���ǂ����̃t���O
int V;//���_��


///////////////////////////���ꂾ�ƌv�Z��O(|V|^2)
int prim(){
	REP(i,V){
		mincost[i]=INF;
		used[i]=false;
	}
	mincost[0]=0;
	int res=0;//�ӂ̑��R�X�g
	
	while(true){
		int v=-1;
		//X�ɑ����Ȃ����_�̂���X����̕ӂ̃R�X�g���ŏ��ɂȂ钸�_��T��
		REP(u,V){
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
		}
		if(v==-1)break;
		used[v]=true;//���_v��X�ɒǉ�
		res+=mincost[v];//�ӂ̃R�X�g�ɉ�����
		REP(u,V)mincost[u]=min(mincost[u],mincost[v]+cost[v][u]);
		
	}
	return res;
}


/////////////////////////////priority_queue O(|E|log|V|) 
struct edge{int to,cost;};
typedef pair<int,int> P;//first�͍ŒZ����,second�͒��_�ԍ�
int V;
vector<edge> G[MAX_V];
int mincost[MAX_V];

int primp(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(mincost,mincost+V,INF);
	mincost[0]=0;
	que.push(P(0,0));
	int res=0;
	while(!que.empty()){
		P p=que.top();que.pop();//���̍ŒZ�������Z�����Ɏ��o��
		int v=p.second;
		if(mincost[v]<p.first)continue;
		
		res+=mincost[v];
		REP(i,G[v].size()){
			edge e=G[v][i];
			if(mincost[e.to]>mincost[v]+e.cost){
				mincost[e.to]=mincost[v]+e.cost;
				que.push(P(mincost[e.to],e.to));//���̍ŒZ�����ƒ��_�̑g���X�V���s����x�ɒǉ����Ă���
			}
		}
	}
	return res;
}



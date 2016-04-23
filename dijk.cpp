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



//���̂܂�܃_�C�N�X�g��(O(|V|^2))
//�ŒZ�������m�肵�����_�Ƃ���ɗאڂ��Ă��钸�_���X�V����A�m�蒸�_�͂����g��Ȃ����ƂŒZ�k
//���̕ӂ��Ȃ����Ƃ��O��A���̕ӂ�����Ƃ��̓x���}���t�H�[�h�@�ŉ���

int cost[MAX_V][MAX_V];//cost[u][v]�͕�e=(u,v)
int d[MAX_V];//���_s����̍ŒZ����
bool used[MAX_V];//���Ɏg��ꂽ���ǂ����̃t���O
int V;//���_��

void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	d[s]=0;
	while(true){
		int v=-1;//�܂��g���Ă��Ȃ����_�̂����������ŏ��̂��̂�T��
		REP(u,V){
			if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
		}
		if(v==-1) break;//�܂��g���ĂȂ����_�����݂��Ȃ��Ȃ�I��
		used[v]==true;
		REP(i,V){
			d[i]=min(d[i],d[v]+cost[v][i]);
			//���_s����אڒ��_�ւ̋����ƁA���_s�����قǋ��߂������ŏ����_�ւ̋����Ƌ����ŏ����_����אڒ��_�ւ̋����̘a�̂�������������V���ȋ����Ƃ��čX�V����
		}
	}
	
}



//priority_queue���g�����ꍇ(O(|E|log|V|))
struct edge{int to,cost;};
typedef pair<int,int> P;//first�͍ŒZ����,second�͒��_�ԍ�

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();//���̍ŒZ�������Z�����Ɏ��o��
		int v=p.second;
		if(d[v]<p.first)continue;
		REP(i,G[v].size()){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));//���̍ŒZ�����ƒ��_�̑g���X�V���s����x�ɒǉ����Ă���
			}
		}
	}
}


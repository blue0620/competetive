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

int prev[MAX_V];//�ŒZ�H�̒��O�̒��_
int cost[MAX_V][MAX_V];//cost[u][v]�͕�e=(u,v)
int d[MAX_V];//���_s����̍ŒZ����
bool used[MAX_V];//���Ɏg��ꂽ���ǂ����̃t���O
int V;//���_��

//�n�_s����e���_�ւ̍ŒZ���������߂�
void dijkstra(int s){
	fill(d,d+V,INF);
	fill(used,used+V,false);
	fill(prev,prev+V,-1);
	d[s]=0;
	while(true){
		int v=-1;
		REP(u,V){//v�͉��̍ŒZ�����̒��_�ԍ�
			if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
		}
		if(v==-1)break;
		used[v]=true;
		REP(u,V){
			if(d[u]>d[v]+cost[v][u]){
				d[u]=d[v]+cost[v][u];
				prev[u]=v;//���̒��_�A�܂�ŒZ�H�̒��O��ۑ�
			}
		}
	}
}	
//���_t�ւ̍ŒZ�H
vector<int> get_path(int t){
	vector<int>path;
	for(;t!=-1;t=prev[t])path.push_back(t);//t��s�ɂȂ�܂�prev[t]��k��
	reverse(path.begin(),path.end());
	return path;
}



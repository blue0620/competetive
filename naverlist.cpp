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


/////////ex1
vector<int> G[MAX_V];
/*�ӂɑ���������Ƃ�
struct edge{int to,int cost};
vector<edge> G[MAX_V];

*/
int main(){
	int V,E;
	scanf("%d %d",&V,&E);
	REP(i,E){
		int s,t;
		scanf("%d %d",&s,&t);
		G[s].push_back(t);//s����t�ւ̕�
		G[t].push_back(s);//t����s�ւ̕�(�����O���t)
	}
	return 0;
}
////////ex1


///////ex2

struct vectorx{
	vector<vectorx*> edge;
	/*
	���_�̑���
	*/
}

int main(){
	int V,E;
	scanf("%d %d",&V,&E);
	REP(i,E){
		int s,t;
		scanf("%d %d",&s,&t);
		G[s].edge.push_back(&G[t]);
		//G[t].edge.push_back(&G[s]);
	}
	/*
	�O���t�̑���
	*/
}



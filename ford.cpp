//�P��n�_�ŒZ�H���(�x���}���t�H�[�h�@)
//�O���t��s���瓞�B�\�ȕ��̃R�X�g�̕H�����݂��Ȃ��Ȃ�while����|V|-1�񂵂����Ȃ�(�������_���Q��ʂ�Ȃ�)
//�t��V��ȏ���Ε��̃R�X�g�̕H�����݂���B�����S�̂��猟�o�������Ȃ�d[i]=0�Ə��������Ă��
//���R�X�g�̓R�X�g�����̕H���Ȃ��Ȃ�O(|V|*|E|)
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

//���_from���璸�_to�ւ̃R�X�gcost�̕�
struct edge{int from,to,cost;};

edge es[MAX_E];//��

int d[MAX_V];//�ŒZ����
int V,E;//V�͒��_���AE�͕Ӑ�

//s�Ԗڂ̒��_����e���_�ւ̍ŒZ���������߂�
void shortest_path(int s){
	REP(i,V) d[i]=INF;//�����𖳌���Ƃ��ď�����
	d[s]=0;//s����s�ւ̈ړ��͋����O
	while(ture){
		bool update=false;
		REP(i,E){
			edge e=es[i];//�ӂ���
			if(d[e.from]!=INF&&d[e.to]>d[e.from] +e.cost){
				//�X�V���邩�ǂ��������߂�B���ڂ̍X�V�͓��Rfrom��s�ԖځAto��INF�Acost�͐����l(�����͕s��)
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update) break;
	}
}

//true�Ȃ畉�̕H�����݂���
bool find_negative_loop(){
	memset(d,0,sizeof(d));//0�ŏ�����
	REP(i,V)REP(j,E){
		edge e=es[j];
		if(d[e.to]>d[e.from]+e.cost){
			d[e.to]=d[e.from]+e.cost;
			//V��ڂ̃��[�v�ɓ�������H����
			if(i==V-1)return true;
		}
	}
	return false;
}


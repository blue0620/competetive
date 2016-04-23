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


vector<int> G[MAX_V];
int V;
int color[MAX_V];//���_i�̐F(-1,1)

//���_��1��-1�œh��B�����A���ł��邩�ǂ����𒲂ׂ����Ȃ�dfs�̌Ăяo���񐔂𐔂���B���Ăяo���񐔂�1��Ȃ�A��
//�؂ł��邩�ǂ����𒲂ׂ�ɂ́H
//�g�|���W�J�������𒲂ׂ�ɂ́H�A���ȃO���t�̒��Ō��݂̓_�̔ԍ����傫�Ȕԍ������אړ_�̂����ŏ��̂��̂Ɉړ����邱�Ƃ��J��Ԃ��H
//�v�Z�ʂ�O(|V|+|E|)
bool dfs(int v,int c){
	color[v]=c;//���_v��c�œh��
	REP(i,G[v]){
		//�אڂ��Ă��钸�_��c�œh���Ă����false
		if(color[G[v][i]]==c) return false;
		//�אڂ��Ă��钸�_���܂��h���ĂȂ��Ȃ�-c�œh����false
		if(color[G[v][i]]==0 && !dfs(G[v][i],-c))return false;
	}
	//���ׂĂ̒��_��h�ꂽ��true
	return true;
}

void solve(){
	REP(i,V){
		if(color[i]==0){//�܂����_���h���Ă��Ȃ���Γh��
			if(!dfs(i,1)){//�אڒ��_�ƐF���������s�K
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
}
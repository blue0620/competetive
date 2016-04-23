#include <iostream>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

//�~�j�}�b�N�X���ۂ��B���ʂ��^�[���ł͎������ő�ɂ�������Ƃ�B���߂��^�[���ł͑���(���ʂ�)���ŏ��ɂ���������B
//����ɂ�胁�����z�����ɂ��Ă����݂����őP����Ƃ邱�Ƃɖ������Ȃ�
int A,B;
int a[1001],b[1001];
int memo[1001][1001];
int solve(int x,int y){
	if(x==0&&y==0)return 0;
	if(memo[x][y]!=-1)return memo[x][y];
	
	int turn=(A+B-x-y)%2;
	int tmp;
	if(turn == 0){
		tmp=-1;
		if(x>0)tmp=max(tmp,solve(x-1,y)+a[A-x]);
		if(y>0)tmp=max(tmp,solve(x,y-1)+b[B-y]);
	}else{
		tmp=100000;
		if(x>0)tmp=min(tmp,solve(x-1,y));
		if(y>0)tmp=min(tmp,solve(x,y-1));
	}
	memo[x][y]=tmp;
	return tmp;
}

int main(){
	cin>>A>>B;
	REP(i,A)cin>>a[i];
	REP(i,B)cin>>b[i];
	memset(memo,-1,sizeof(memo));
	cout<<solve(A,B)<<endl;
	return 0;
}
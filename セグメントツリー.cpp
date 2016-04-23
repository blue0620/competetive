#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef int Weight;
//typedef
//------------------------------------------

const int MAX_N=1<<17;
//�Z�O�����g�؂����O���[�o���z��
int n,dat[2*MAX_N-1];

//������
void init(int n_){
	//�v�f����2�ׂ�
	n=1;
	while(n<n_)n*=2;
	REP(i,2*n-1)dat[i]=INT_MAX;
}

//k�Ԗڂ̒l��a�ɕύX
void update(int k,int a){
	k+=n-1;
	dat[k]=a;
	//�o��Ȃ���X�V
	while(k>0){
		k=(k-1)/2;
		dat[k]=min(dat[k*2+1],dat[k*2+2]);
	}
}
//[a,b)�̍ŏ��l�����߂�
//k���ߓ_�ԍ�,l,r�͂��̐ߓ_��[l,r)�ɑΉ��Â��Ă��邱�Ƃ�\���B
int query(int a,int b,int k,int l,int r){
	//[a,b)��[l,r)���������Ȃ����INT_MAX
	if(r<=a||b<=l)return INT_MAX;
	//[a,b)��[l,r)�����S�Ɋ܂�ł���΂��̐ߓ_�̒l
	if(a<=1&&r<=b)return dat[k];
	else{
		//�����łȂ����2�̎q�̍ŏ��l
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}

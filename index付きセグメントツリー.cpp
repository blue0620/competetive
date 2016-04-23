
#include <bits/stdc++.h>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline int toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<long,long> PLL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define PF push_front
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const int MAX_N=1<<17;

//�Z�O�����g�؂����O���[�o���z��
int n,dat[2*MAX_N-1];
int idx;
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
int find_index(int k){
	while(k<n-1){
		//cout<<k<<endl;
		k=(dat[k*2+1]>dat[k*2+2])?k*2+2:k*2+1;
	}
	k-=(n-1);
	return k;
}
//[a,b)�̍ŏ��l�����߂�
//k���ߓ_�ԍ�,l,r�͂��̐ߓ_��[l,r)�ɑΉ��Â��Ă��邱�Ƃ�\���B
int query(int a,int b,int k,int l,int r){
	//[a,b)��[l,r)���������Ȃ����INT_MAX
	if(r<=a||b<=l){
		idx=-1;
		return INT_MAX;
	}
	//[a,b)��[l,r)�����S�Ɋ܂�ł���΂��̐ߓ_�̒l
	if(a<=l&&r<=b){
		idx=k;
		return dat[k];
	}
	else{
		//�����łȂ����2�̎q�̍ŏ��l
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int lindex=idx;
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		int rindex=idx;
		if(vl>vr){
			idx=rindex;
			return vr;
		}else{
			idx=lindex;
			return vl;
		}
	}
}

int main(){
	int N,Q;
	cin>>N>>Q;
	init(N);
	REP(i,N){
		int a;
		cin>>a;
		update(i,a);
	}
	REP(i,Q){
		int b,c,d;
		cin>>b>>c>>d;
		if(b==2){
			update(c-1,d);
		}else{
			long val=query(c-1,d,0,0,n);
			int id=find_index(idx)+1;
			cout<<val<<" "<<id<<" "<<id<<endl;
		}
	}
	
	return 0;
}


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define CLR(a) memset((a), 0 ,sizeof(a))

int D;

typedef long long LL;
LL MOD = 1000000007;
LL dp[10010][110][2];

int modD(int x){
	return (x%D+D)%D;
}


int main(){
	int L;string num;
	cin>>D>>num;
	int N[10010];
	CLR(N);
	L=num.size();
	REP(i,L)N[i]=(unsigned int)(num[i]-'0');
	LL ans=0;
	CLR(dp);
	dp[L][0][0]=dp[L][0][1]=1;
	for(int i=L-1;i>=0;i--){
		for(int x=1;x<=9;x++){,,,,,,,,,,,,,,,,,...
			if(i==0&&x>N[i])continue;
			(ans+=dp[i+1][modD(x)][(i==0&&x==N[i])?1:0])%=MOD;
		}
		REP(d,D){
			for(int x=0;x<=9;x++){
				(dp[i][d][0]+=dp[i+1][modD(d+x)][0])%=MOD;
				if(x<=N[i])(dp[i][d][1]+=dp[i+1][modD(d+x)][x==N[i]?1:0])%=MOD;
				//xがNのi桁目の数未満の間、dp[i][d][1]をdp[i+1][modD(d+x)][0]で更新する
				//もしxがN[i]と等しければ、dp[i][d][1]をdp[i+1][modD(d+x)][1]で更新する
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
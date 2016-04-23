#include<iostream>

using namespace std;

typedef long long ll;

const ll maxn=110,mod=1000*1000*1000+7;

ll n,d,k,sum[maxn][2];

int main(){
	cin>>n>>k>>d;
	sum[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j>i)
				break;
			sum[i][0]+=sum[i-j][0];//
			sum[i][0]%=mod;
			if(j>=d)
				sum[i][1]+=sum[i-j][0];//
			else
				sum[i][1]+=sum[i-j][1];
			sum[i][1]%=mod;
		}	
	}
	cout<<sum[n][1]<<endl;
	return 0;
}
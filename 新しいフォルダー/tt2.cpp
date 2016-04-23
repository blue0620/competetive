#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

int burn(int a,int b,int n){
	n+=a;
	a=a/b;
	if(a==0)return n;
	return burn(a,b,n);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<burn(a,b,0)<<endl;
	return 0;
}

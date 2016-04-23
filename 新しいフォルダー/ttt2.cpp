#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(long i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)



int StringToInt(string str)
	{
  	stringstream ss;
	int number;
	ss<<str;
  	ss >> number;
  	return number;
}

int main(){
	int s[4000][4000]={{0}};
	long a;
	cin>>a;
	string str;
	cin>>str;
	long ans=0;
	long sl=str.size();
	vector<int> num(sl);
	FOR(i,0,sl){
		num[i]=StringToInt(str.substr(i,1));
	}
	FOR(i,0,sl){
		FOR(j,0,sl){
			//s[i][j]=(num[i]*num[j]<=a)?(num[i]*num[j]):-1;
			if(num[i]*num[j]==a)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
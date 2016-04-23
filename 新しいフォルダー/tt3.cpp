#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdio.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define NUM 0

int StringToInt(string str){
  	stringstream ss;
	int number;
	ss<<str;
  	ss >> number;
  	return number;
}
int main(){
	ifstream ifs("triangle.txt");
	vector <int> t,a1;
	FOR(i,1,101){
		string str;
		getline(ifs,str);
		//cout<<str<<endl;
		if(i==1){
			t.push_back(StringToInt(str.substr(0,2)));
			continue;
		}
		a1.clear();
		FOR(j,0,i){
			int tt=0;
			if(j==0||(j!=i-1&&t[j]>t[j-1])){
				tt=t[j];
			}else{
				tt=t[j-1];
			}
			a1.push_back(StringToInt(str.substr(j*3,2))+tt);
		}
		
		t=a1;
	}
	int ans=0;
	FOR(i,0,101){
		ans=max(ans,a1[i]);
	}
	cout<<ans<<endl;
	return 0;
}
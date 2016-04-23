//include
//------------------------------------------
#include<bits/stdc++.h>

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	std::cout<<2568*7765/gcd(2568,7765)<<std::endl;
	return 0;
}
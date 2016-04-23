#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
#define G 9.80665
#define REP(i,n) for(int i = 0; i < (int)(n); i++)

double func1(double x1,double x2,double r);
double func2(double x1,double x2,double r);
double rad(double x1,double x2,double y1,double y2);
double m1=10;
double m2=20;
double x1=5;
double x2=5;
double y1=10;
double y2=3;
int main(void){
	  double r;
	  double final_x, h;
	  double k1x1,k2x1,k1x2,k2x2,k1y1,k2y1,k1y2,k2y2;
	  final_x=10.0;
	  

	  
	  REP(i,1000){
	  	r=rad(x1,x2,y1,y2);
	  	k1x1=h*func1(x1,x2,r);
		k1x2=h*func2(x1,x2,r);
	  	k2x1=h*func1(x1+k1x1,x2+k1x2,r);
		k2x2=h*func2(x1+k1x1,x2+k1x2,r);
		x1=x1+1.0/2.0*(k1x1+k2x1);
		x2=x2+1.0/2.0*(k1x2+k2x2);
		k1y1=h*func1(y1,y2,r);
		k1y2=h*func2(y1,y2,r);
	  	k2y1=h*func1(y1+k1y1,x2+k1y2,r);
		k2y2=h*func2(y1+k1y1,x2+k1y2,r);
		y1=y1+1.0/2.0*(k1y1+k2y1);
		y2=y2+1.0/2.0*(k1y2+k2y2);
	  }
	  return 0;
}

double func1(double x1,double x2,double r){
	  double a;
	  a=-G*m2*(x1-x2)/pow(r,3);
	  return(a);
}
double func2(double x1,double x2,double r){
	  double a;
	  a=-G*m1*(x1-x2)/pow(r,3);
	  return(a);
}

double rad(double x1,double x2,double y1,double y2){
	double r=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	return (r);
}
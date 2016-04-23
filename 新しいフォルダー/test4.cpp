#include <iostream>
#include <string>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	double deg=112.5;
	double gap=225;
	int m2;
	if(m-deg>=0){
		m2=(m-deg)/gap;
	}else{
		m2=15;
	}
	string s;
	switch(m2){
		case 0:
		s="NNE";
		break;
		case 1:
		s="NE";
		break;
		case 2:
		s="ENE";
		break;
		case 3:
		s="E";
		break;
		case 4:
		s="ESE";
		break;
		case 5:
		s="SE";
		break;
		case 6:
		s="SSE";
		break;
		case 7:
		s="S";
		break;
		case 8:
		s="SSW";
		break;
		case 9:
		s="SW";
		break;
		case 10:
		s="WSW";
		break;
		case 11:
		s="W";
		break;
		case 12:
		s="WNW";
		break;
		case 13:
		s="NW";
		break;
		case 14:
		s="NNW";
		break;
		default:
		s="N";
		break;
	}
	
	double n2=(n*10+30)/60;
	n2=int(n2);
	n2/=10;
	int dv=0;
	if(n2<=0.2){
		s="C";
	}else if(n2<=1.5){
		dv=1;
	}else if(n2<=3.3){
		dv=2;
	}else if(n2<=5.4){
		dv=3;
	}else if(n2<=7.9){
		dv=4;
	}else if(n2<=10.7){
		dv=5;
	}else if(n2<=13.8){
		dv=6;
	}else if(n2<=17.1){
		dv=7;
	}else if(n2<=20.7){
		dv=8;
	}else if(n2<=24.4){
		dv=9;
	}else if(n2<=28.4){
		dv=10;
	}else if(n2<=32.6){
		dv=11;
	}else{
		dv=12;
	}
	cout << s << " " << dv << endl;
	return 0;
}
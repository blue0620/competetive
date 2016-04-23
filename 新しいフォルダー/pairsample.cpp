#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class BallsSeparating{
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue){
		int box=red.size();
		if(box<3) return -1;
		
		vector<pair<long, int> > r;
		vector<pair<long, int> > g;
		vector<pair<long, int> > b;
		for (int i = 0; i < box; i++) {
			r.push_back(pair<long, int>(red[i],i));
			g.push_back(pair<long, int>(green[i],i));
			b.push_back(pair<long, int>(blue[i],i));
		}
			r.push_back(pair<long, int>(0,box));
			g.push_back(pair<long, int>(0,box));
			b.push_back(pair<long, int>(0,box));
			
		sort(r.begin(), r.end(), greater<pair<long, int> >());
		sort(g.begin(), g.end(), greater<pair<long, int> >());
		sort(b.begin(), b.end(), greater<pair<long, int> >());
		vector<pair<long, int> >::iterator ri;
		vector<pair<long, int> >::iterator gi;
		vector<pair<long, int> >::iterator bi;
		ri=r.begin();
		gi=g.begin();
		bi=b.begin();
		long gap=0;
		
		long sum=0;
		for(int i=0;i<box;i++)sum+=(red[i]+green[i]+blue[i]);
	
	
		for(int i=0;i<box;){
			if((ri->first)>=(gi->first)&&(ri->first)>=(bi->first)){
				if(red[(ri->second)]!=0){
					i++;
					gap+=red[(ri->second)];
					red[(ri->second)]=green[(ri->second)]=blue[(ri->second)]=0;
				}
				if(ri!=r.end())ri++;
			}else if((gi->first)>=(ri->first)&&(gi->first)>=(bi->first)){
				if(green[(gi->second)]!=0){
					i++;
					gap+=green[(gi->second)];
					red[(gi->second)]=green[(gi->second)]=blue[(gi->second)]=0;
				}
				if(gi!=g.end())gi++;
			}else{
				if(blue[(bi->second)]!=0){
					i++;
					gap+=blue[(bi->second)];
					red[(bi->second)]=green[(bi->second)]=blue[(bi->second)]=0;
				}
				if(bi!=b.end()) bi++;
			}
		}
		
		
		return sum-gap;
	}
};

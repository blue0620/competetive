#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <complex>
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;//ç¿ïW(x,y)=(p.real,p.imag())
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

double cross(const P& a, const P& b) {
 	return imag(conj(a)*b);//ê≥Ç»ÇÁîΩéûåvâÒÇËÇÃâÒì],ïâÇ»ÇÁéûåvâÒÇË,0Ç»ÇÁìØàÍíºê¸
}
double dot(const P& a, const P& b) {
  	return real(conj(a)*b);//ïâÇ»ÇÁãtï˚å¸
}

struct L : public vector<P> {//íºê¸(2ì_ÇéwíË)
  	L(const P &a, const P &b) {
    	push_back(a); push_back(b);
  	}
};

typedef vector<P> G;//íPèÉëΩäpå`(îΩéûåvâÒÇËÇ…âÒÇÈ)

struct C {//â~C(íÜêS,íºåa)
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {//ì_ÇÃêiçsï˚å¸a->b->c
	b -= a; c -= a;
  	if (cross(b, c) > 0)   return +1;       // counter clockwise
  	if (cross(b, c) < 0)   return -1;       // clockwise
  	if (dot(b, c) < 0)     return +2;       // c--a--b on line(a->bÇ≈ãtÇå¸Ç¢ÇƒaÇí ÇËâzÇµÇƒb->c)
  	if (norm(b) < norm(c)) return -2;       // a--b--c on line
  	return 0;
}

bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
         abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
  	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
  	return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}



//include
//------------------------------------------
#include <bits/stdc++.h>

using namespace std;

//conversion
//------------------------------------------
inline long toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline long toLong(string s) {long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-8;
const long INF = 1e10;


struct PMA
{
        PMA* next[256];
        vector<int> matched;
        PMA(){memset(next, 0, sizeof(next));}
        ~PMA(){for(int i = 0; i < 256; i++) if(next[i]) delete next[i];}
};

vector<int> set_union(const vector<int> &a,const vector<int> &b)
{
        vector<int> res;
        set_union(ALL(a), ALL(b), back_inserter(res));
        return res;
}

PMA *buildPMA(vector<string> pattern)
{
        PMA *root = new PMA, *now;
        root->next[0] = root;
        for(int i = 0; i < pattern.size(); i++) {
                now = root;
                for(int j = 0; j < pattern[i].size(); j++) {
                        if(now->next[(int)pattern[i][j]] == 0)
                                now->next[(int)pattern[i][j]] = new PMA;
                        now = now->next[(int)pattern[i][j]];
                }
                now->matched.push_back(i);
        }

        queue<PMA*> que;
        for(int i = 1; i < 256; i++) {
                if(!root->next[i]) root->next[i] = root;
                else {
                        root->next[i]->next[0] = root;
                        que.push(root->next[i]);
                }
        }
        while(!que.empty()) {
                now = que.front(); que.pop();
                for(int i = 1; i < 256; i++) {
                        if(now->next[i]){
                                PMA *nxt = now->next[0];
                                while(!nxt->next[i]) nxt = nxt->next[0];
                                now->next[i]->next[0] = nxt->next[i];
                                now->next[i]->matched = set_union(now->next[i]->matched, nxt->next[i]->matched);
                                que.push(now->next[i]);
                        }
                }
        }
        return root;
}

void match(PMA* &pma, const string s, vector<int>&res)
{
        for(int i = 0; i < s.size(); i++){
                int c = s[i];
                while(!pma->next[c])
                        pma = pma->next[0];
                pma = pma->next[c];
                for(int j = 0; j < pma->matched.size(); j++)res.PB(i);
        }
}

int main(){
	ifstream ifs("rosalind_mprt.txt");
	ofstream ofs("t.txt");
	string str,oh,ami;
	
	vector<string>cdn;
	for(char st='S';st<='T';st++)for(char c1='A';c1<='Z';c1++)for(char c2='A';c2<='Z';c2++){
		if(c1=='P'||c2=='P')continue;
		string cd="";
		cd+='N';
		cd+=c1;
		cd+=st;
		cd+=c2;
		//cout<<cd<<endl;
		cdn.PB(cd);
	}
	PMA* pma=buildPMA(cdn);
	
	
	
	while(ifs>>str){
		vector<int>res;
		string url="http://www.uniprot.org/uniprot/";
		url+=str;
		url+=".fasta";
		FILE *f = popen(("curl -s -k -L \"" + url + "\"").c_str(), "r");
	    if (f == NULL) {
	        perror("error!");
	    }
	    char buf[2048];
		fgets(buf, 2048, f);
		string tg="";
	    while (!feof(f)) {
	        if (fgets(buf, 2048, f) == NULL) break;
	        string tmp=buf;if(tmp.back()=='\n')tmp.pop_back();
			tg+=tmp;
	    }
		cout<<str<<endl;
		cout<<tg<<endl;
		match(pma,tg,res);
	    pclose(f);
		if(SZ(res)!=0){
			ofs<<str<<endl;
			REP(i,SZ(res))ofs<<res[i]-2<<" ";
			ofs<<endl;
		}
	}
	
	
	return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int N = (int) 1e5, MODULO = (int) 1e9 + 7;
int n, m, weight[N], discover[N], low[N], used[N], ttime;
long long minCost, numWay;
vector<int> graph[N];
stack<int> st;

void dfs(int u) {
	discover[u] = low[u] = ttime++;
	st.push(u);
	for(int i = 0; i < (int) graph[u].size(); ++i) {
		int v = graph[u][i];
		if(used[v]) continue;
		if(discover[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], discover[v]);
		}
	}
	if(discover[u] == low[u]) {
		int v, best = (int) 2e9, cnt = 1;
		do {
			v = st.top(); st.pop();
			used[v] = true;
			if(weight[v] < best) best = weight[v], cnt = 0;
			if(weight[v] == best) ++cnt;
		} while(v != u);
		minCost += best;
		numWay = numWay * cnt % MODULO;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> weight[i];
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		graph[u].push_back(v);
	}
	memset(discover, -1, sizeof discover);
	minCost = 0;
	numWay = 1;
	for(int i = 0; i < n; ++i) if(discover[i] == -1) dfs(i);
	cout << minCost << ' ' << numWay;
	return 0;
}
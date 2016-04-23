    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    #include <stack>
    #include <queue>
    #include <set>
    #include <map>
    #include <algorithm>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <cctype>
    #include <cmath>
    #include <cassert>
    using namespace std;
     
    #define all(c) (c).begin(), (c).end()
    #define iter(c) __typeof((c).begin())
    #define cpresent(c, e) (find(all(c), (e)) != (c).end())
    #define rep(i, n) for (int i = 0; i < (int)(n); i++)
    #define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
    #define pb(e) push_back(e)
    #define mp(a, b) make_pair(a, b)
     
    typedef long long ll;
    const ll MOD = 1000000007;
     
    char N[10010];
    int D, L;
     
    inline int modD(int x) {
    return (x % D + D) % D;
    }
     
    ll dp[10010][110][2];
     
    int main() {
    while (2 == scanf("%d%s", &D, N)) {
    L = strlen(N);
    rep (i, L) N[i] -= '0';
     
    ll ans = 0;
     
    memset(dp, 0, sizeof(dp));
    dp[L][0][0] = dp[L][0][1] = 1;
    for (int i = L - 1; i >= 0; --i) {
    // Ends here
    for (int x = 1; x <= 9; ++x) {
    if (i == 0 && x > N[i]) continue;
    (ans += dp[i + 1][modD(x)][i == 0 && x == N[i] ? 1 : 0]) %= MOD;
    }
     
    // DP
    rep (d, D) {
    for (int x = 0; x <= 9; ++x) {
    (dp[i][d][0] += dp[i + 1][modD(d + x)][0]) %= MOD;
    (dp[i][d][1] += (x > N[i] ? 0 : dp[i + 1][modD(d + x)][x == N[i] ? 1 : 0])) %= MOD;
    }
    }
    }
     
    printf("%lld\n", ans);
    }
    return 0;
    }
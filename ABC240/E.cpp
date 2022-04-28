#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);

/*........................ let's try one more time ........................*/

vi g[N];
int cnt = 0;
vector<pii> res(N);

pii dfs(int u, int par = -1) {
  res[u] = {INF, 0};
  bool valid = 0;
  for (auto v : g[u]) {
    if (v == par) continue;
    valid = 1;
    pii temp = dfs(v, u);
    res[u].ff = min(res[u].ff, temp.ff);
    res[u].ss = max(res[u].ss, temp.ss);
  }
  if (!valid) {
    cnt++;
    res[u] = {cnt, cnt};
  }
  return res[u];
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) {
      cout << res[i].ff << " " << res[i].ss << nl;
    }
  }
  return 0;
}

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
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(nullptr);

/*........................ let's try one more time ........................*/

vi g[2005];
vector<bool> used(2005, 0);

void dfs(int u) {
  if (used[u]) return;
  used[u] = 1;
  for (auto v : g[u]) dfs(v);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) used[j] = 0;
      dfs(i);
      for (int j = 1; j <= n; ++j) res += used[j];
    }
    cout << res << nl;
  }
  return 0;
}

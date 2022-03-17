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
const ll INF      = (ll) 1e18 + 9;
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
    vector<vll> dist(n + 2, vll(m + 2, INF));
    vector<pair<int, pii>> edge;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      ll w;
      cin >> u >> v >> w;
      dist[u][v] = w;
      dist[v][u] = w;
      edge.pb({u, {v, w}});
    }
    // shortage path
    for (int k = 1; k <= n; ++k) {
      for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
          if (u == v) continue;
          dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
      }
    }

    int res = 0;
    for (auto x : edge) {
      int u = x.ff, v = x.ss.ff;
      ll w = x.ss.ss;
      int valid = 0;
      for (int k = 1; k <= n; ++k) {
        if (dist[u][v] >= (dist[u][k] + dist[k][v])) valid = 1;
      }
      res += valid;
    }
    cout << res<< nl;
  }
  return 0;
}

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

class Dsu {
  vector<int> par, rank;
  int root(int x) {
    return par[x] == x ? x : root(par[x]);
  }

public:
  Dsu(int n) {
    par.resize(n + 2, 0);
    rank.resize(n + 2, 0);
    for (int i = 0; i <= n; ++i) {
      par[i] = i;
    }
  }

  bool merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return 0;
    if (rank[x] <= rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    return 1;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vector<pair<int, pii>> edge;
    ll res = 0;
    while (m--) {
      int u, v, c; cin >> u >> v >> c;
      edge.push_back({c, {u, v}});
      if (c > 0) res += c;
    }
    sort(all(edge));
    Dsu ds(n);
    for (auto x : edge) {
      if (x.ff <= 0) ds.merge(x.ss.ff, x.ss.ss);
      else if (ds.merge(x.ss.ff, x.ss.ss)) res -= x.ff;
    }
    cout << res << nl;
  }
  return 0;
}

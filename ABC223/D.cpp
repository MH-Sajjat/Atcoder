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
    vi inDegree(n + 2, 0);
    vector<bool> condition(n + 2, 0);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      inDegree[v]++;
      condition[u] = condition[v] = 1;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> used(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
      if (inDegree[i] == 0) pq.push(i);
    }

    vi topo;

    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();
      if (used[u]) continue;
      used[u] = 1;
      topo.pb(u);
      for (auto v : g[u]) {
        inDegree[v]--;
        if (inDegree[v] == 0) pq.push(v);
      }
    }
    vi res;
    int pos = 1;
    for (auto x : topo) {
      while (condition[pos]) pos++;
      if (x < pos) res.pb(x);
      else {
        res.pb(pos);
        pos++;
      }
    }

    if (szof(res) == n) {
      for (auto x : res) cout << x << " ";
      cout << nl;
    } else {
      cout << -1 << nl;
    }
  }
  return 0;
}

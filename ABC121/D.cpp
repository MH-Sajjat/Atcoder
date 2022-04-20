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

vi g[N];
vi cnt(N, 0);
vi level(N, 0);
vector<bool> used(N, 0);

void bfs() {
  queue<int> q;
  q.push(1);
  level[1] = 1;
  cnt[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (level[v] == 0) {
        level[v] = level[u] + 1;
        cnt[v] += cnt[u];
        q.push(v);
      } else if (level[v] == (level[u] + 1)) {
        cnt[v] += cnt[u];
      }
      cnt[v] %= MOD;
    }
  }
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
      g[v].pb(u);
    }
    bfs();
    cout << cnt[n] << nl;
  }
  return 0;
}

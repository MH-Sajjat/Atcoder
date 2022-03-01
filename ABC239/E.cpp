#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

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
#define TN        typename
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

/*........................ let's try one more time ........................*/

vi g[N], val[N];
vector<bool> vis(N, 0);
int ar[N];

void merge(vi& v1, vi& v2) {
  int cnt = 20;
  vi v;
  int n = szof(v1), m = szof(v2);
  int i = 0, j = 0;
  while (i < n and j < m and cnt) {
    if (v1[i] > v2[j]) {
      v.pb(v1[i]);
      i++;
    } else {
      v.pb(v2[j]);
      j++;
    }
    cnt--;
  }
  while (i < n and cnt) {
    v.pb(v1[i]);
      i++;
      cnt--;
  }
  while (j < m and cnt) {
    v.pb(v2[j]);
      j++;
    cnt--;
  }
  v1.clear();
  for (auto x : v) {
    v1.pb(x);
  }
}

void dfs(int u) {
  val[u].pb(ar[u]);
  vis[u] = 1;
  for (auto v : g[u]) {
    if (vis[v]) continue;
    dfs(v);
    merge(val[u], val[v]);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  // Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> ar[i];
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1);
    while (q--) {
      int u, k;
      cin >> u >> k;
      cout << val[u][k - 1] << nl;
    }
  }
  return 0;
}

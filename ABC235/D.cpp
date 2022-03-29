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
const int mxN     = (int) 1e7 + 6;
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

ll changeNum(ll x) {
  ll d = x % 10;
  x /= 10;
  ll k = log10(x) + 1;
  ll ret = 1;
  for (int i = 1; i <= k; ++i) ret *= 10;
  ret *= d;
  ret += x;
  return ret;
}

ll countDigit(ll n) {
  return log10(n) + 1;
}

vll g[mxN];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    ll n, a;
    cin >> a >> n;
    queue<ll> q;
    q.push(1);
    map<ll, bool> used;
    used[1] = 1;
    ll limit = 10000000;
    while (!q.empty()) {
      ll x = q.front();
      q.pop();
      if (countDigit(x * a) <= countDigit(n) and !used[x * a]) {
        ll u = x, v = x * a;
        g[u].pb(v);
        g[v].pb(u);
        used[v] = 1;
        q.push(v);
      }
      if (x % 10 != 0) {
        ll xx = x;
        x = changeNum(x);
        if (countDigit(x) <= countDigit(n) and !used[x]) {
          ll u = xx, v = x;
          g[u].pb(v);
          g[v].pb(u);
          used[v] = 1;
          q.push(v);
        }
      }
    }
    vector<ll> dis(mxN, -1);
    vector<bool> vis(mxN, 0);
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
      ll u = q.front();
      q.pop();
      vis[u] = 1;
      for (auto v : g[u]) {
        if (!vis[v]) {
          q.push(v);
          dis[v] = dis[u] + 1;
        }
      }
    }
    cout << dis[n] << nl;
  }
  return 0;
}

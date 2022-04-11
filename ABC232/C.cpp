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

int n;
vector<vi> v;
vector<bool> used(20, 0);
vi track;

void permotation(int pos) {
  if (pos > n) {
    v.pb(track);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      used[i] = 1;
      track.pb(i);
      permotation(pos + 1);
      track.pop_back();
      used[i] = 0;
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
    int m;
    cin >> n >> m;
    permotation(1);
    vector<pii> edge;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      edge.pb({u, v});
    }
    map<pii, bool> MAP;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      MAP[{u, v}] = 1;
      MAP[{v, u}] = 1;
    }
    bool valid = 0;
    for (auto p : v) {
      bool ok = 1;
      for (auto x : edge) {
        if (!MAP[{p[x.ff - 1], p[x.ss - 1]}]) ok = 0;
      }
      valid |= ok;
      if (valid) break;
    }

    if (valid) cout << "Yes" << nl;
    else cout << "No" << nl;
  }
  return 0;
}

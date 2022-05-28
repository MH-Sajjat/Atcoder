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

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int l, q; cin >> l >> q;
    vector<int> v;
    v.pb(0);
    v.pb(l);
    vector<pii> query;
    for (int i = 1; i <= q; ++i) {
      int x, y; cin >> x >> y;
      query.pb({x, y});
      if (x == 1) v.pb(y);
    }
    sort(all(v));
    // for (auto x : v) debug(x)
    vi res;
    reverse(all(query));
    for (auto x : query) {
      // error(x.ff, x.ss);
      if (x.ff == 1) {
        auto it = lower_bound(all(v), x.ss);
        v.erase(it);
      } else {
        auto it1 = upper_bound(all(v), x.ss);
        auto it = it1;
        --it;
        // debug(*it1)
        res.pb(*it1 - *it);
      }
    }
    reverse(all(res));
    for (auto x : res) cout << x << nl;
  }
  return 0;
}

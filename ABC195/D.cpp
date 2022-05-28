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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m, q; cin >> n >> m >> q;
    vector<pii> bag(n, {0, 0});
    for (auto& x : bag) cin >> x.ff >> x.ss;
    sort(all(bag), [](pii a, pii b) -> bool {
      if (a.ss == b.ss) return (a.ff < b.ff);
      return (a.ss > b.ss);
    });
    vi box(m, 0);
    for (auto& x : box) cin >> x;
    while (q--) {
      int l, r; cin >> l >> r;
      l--;
      r--;
      vi ableBox;
      ll res = 0LL;
      for (int i = 0; i < m; ++i) {
        if ((i < l) or (i > r)) ableBox.pb(box[i]);
      }
      sort(all(ableBox));
      int s = szof(ableBox);
      vector<bool> used(s + 5, 0);
      for (auto x : bag) {
        for (int i = 0; i < s; ++i) {
          if (used[i]) continue;
          if (x.ff <= ableBox[i]) {
            res += x.ss;
            used[i] = 1;
            break;
          }
        }
      }
      cout << res << nl;
    }
  }
  return 0;
}

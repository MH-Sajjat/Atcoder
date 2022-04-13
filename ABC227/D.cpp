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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    ll n, k;
    cin >> n >> k;
    vll v(n, 0);
    for (ll& x : v) cin >> x;
    ll l = 0, r = 0;
    for (auto x : v) r += x;
    r /= k;
    ll res = 0;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      ll sum = 0;
      for (auto x : v) {
        sum += min(x, mid);
      }
      if (sum >= (k * mid)) {
        res = mid;
        l = mid + 1;
      } else r = mid - 1;
    }
    cout << res << nl;
  }
  return 0;
}

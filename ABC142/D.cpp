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
    ll a, b;
    cin >> a >> b;
    vll div1, div2;
    for (ll i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        div1.pb(i);
        while (a % i == 0) a /= i;
      }
    }
    if (a > 2) div1.pb(a);

    for (ll i = 2; i * i <= b; i++) {
      if (b % i == 0) {
        div2.pb(i);
        while (b % i == 0) b /= i;
      }
    }
    if (b > 2) div2.pb(b);
    map<ll, bool> m;
    for (auto x : div1) {
      m[x] = 1;
    }
    ll res = 1;
    for (auto x : div2) {
      if (m[x]) res++;
    }

    cout << res << nl;
  }
  return 0;
}

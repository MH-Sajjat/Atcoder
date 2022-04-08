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
    string s;
    cin >> s;
    int n = szof(s);
    s = '?' + s;
    vi sum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + s[i] - '0';
    }
    int carry = 0;
    string res = "";
    for (int i = n; i >= 1; --i) {
      carry += sum[i];
      res.pb(carry % 10 + '0');
      carry /= 10;
    }
    while (carry) {
      res.pb(carry % 10 + '0');
      carry /= 10;
    }
    while (res.back() == '0') res.pop_back();
    reverse(all(res));
    cout << res << nl;
  }
  return 0;
}

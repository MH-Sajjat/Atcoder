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
const int MOD     = (int) 998244353;
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
    int n;
    cin >> n;
    vi a(n + 2, 0), b(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<vi> dp(3005, vi(3005, 0));
    vi temp(3005, 1);

    for (int i = 1; i <= n; ++i) {
      for (int j = a[i]; j <= b[i]; ++j) {
        dp[i][j] = temp[j] % MOD;
      }
      temp.assign(3005, 0);
      for (int j = 0; j <= 3000; ++j) {
        temp[j] = dp[i][j] % MOD;
        if (j) {
          temp[j] += temp[j - 1];
          temp[j] %= MOD;
        }
      }
    }

    int res = 0;
    for (int i = a[n]; i <= b[n]; ++i) {
      res += dp[n][i];
      res %= MOD;
    }

    cout << res << nl;
  }
  return 0;
}

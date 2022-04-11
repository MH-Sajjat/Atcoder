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
    int n, m;
    cin >> n >> m;
    string grid[n + 2];
    for (int i = 1; i <= n; ++i) {
      cin >> grid[i];
      grid[i] = '?' + grid[i];
    }
    int res = 0;
    vector<vi> dp(n + 2, vi(m + 2, 0));
    if (grid[1][1] == '.') dp[1][1] = 1;
    
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (grid[i][j] == '.') {
          if (dp[i - 1][j] > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
          if (dp[i][j - 1] > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
        res = max(res, dp[i][j]);
      }
    }

    cout << res << nl;
  }
  return 0;
}

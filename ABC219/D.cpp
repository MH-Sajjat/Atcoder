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
    int n, X, Y; cin >> n >> X >> Y;
    vi a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    vector<vector<vi>> dp(350, vector<vi>(350, vi(350, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int x = 0; x <= X; x++) {
        for (int y = 0; y <= Y; ++y) {
          if (dp[i][x][y] < INF) {
            dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y]);
            dp[i + 1][min(x + a[i], X)][min(y + b[i], Y)] = 
              min(dp[i + 1][min(x + a[i], X)][min(y + b[i], Y)], dp[i][x][y] + 1);
          }
        }
      }
    }
    if (dp[n][X][Y] == INF) cout << -1 << nl;
    else cout << dp[n][X][Y] << nl;
  }
  return 0;
}

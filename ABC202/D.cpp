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

ll dp[35][35];

string find(int a, int b, ll k) {
  if (a == 0) {
    string temp(b, 'b');
    return temp;
  }
  if (b == 0) {
    string temp(a, 'a');
    return temp;
  }
  if (dp[a - 1][b] >= k) return (string) "a" + find(a - 1, b, k);
  else return (string) "b" + find(a, b - 1, k - dp[a - 1][b]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int a, b;
    ll k;
    cin >> a >> b >> k;
    dp[0][0] = 1;
    for (int i = 0; i <= a; ++i) {
      for (int j = 0; j <= b; ++j) {
        if (i > 0) dp[i][j] += dp[i - 1][j];
        if (j > 0) dp[i][j] += dp[i][j - 1];
      }
    }

    cout << find(a, b, k) << nl;
  }
  return 0;
}

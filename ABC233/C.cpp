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

vector<ll> balls[N];
map<pair<int, ll>, ll> dp;
map<pair<int, ll>, bool> used;

ll call(int n, ll x) {
  if (n == 0 and x == 1) return 1;
  if (x == 0) return 0;
  if (used[{n, x}]) return dp[{n, x}];

  ll ret = 0;
  for (auto p : balls[n]) {
    if (x % p == 0)
      ret += call(n - 1, x / p);
  } 

  used[{n, x}] = 1;
  return dp[{n, x}] = ret;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; ++j) {
        ll val;
        cin >> val;
        balls[i].pb(val);
      }
    }

    cout << call(n, x) << nl;
  }
  return 0;
}

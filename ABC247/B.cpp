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
    int n;
    cin >> n;
    vector<pair<string, string>> v(n);
    map<string, int> m;
    for (auto& x : v) {
      cin >> x.ff >> x.ss;
      m[x.ff]++;
      m[x.ss]++;
    }
    bool valid = 1;
    for (int i = 0; i < n; ++i) {
      bool ok1 = 1, ok2 = 1;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (v[i].ff == v[j].ff or v[i].ff == v[j].ss) ok1 = 0;
        if (v[i].ss == v[j].ff or v[i].ss == v[j].ss) ok2 = 0;
      }
      // debug(ok1)
      // debug(ok2)
      valid &= (ok1 or ok2);
    }
    if (valid) cout << "Yes" << nl;
    else cout << "No" << nl;
  }
  return 0;
}

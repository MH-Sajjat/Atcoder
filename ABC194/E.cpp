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
const int mxN     = (int) 2e6 + 6;
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

vector<int> cnt(mxN, 0);

int getMEX(int n) {
  while (cnt[n] > 0) n++;
  return n;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vi v(n, 0);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < m; ++i) cnt[v[i]]++;
    int p;
    int res = p = getMEX(0);
    // debug(res)
    for (int i = m; i < n; ++i) {
      cnt[v[i - m]]--;
      cnt[v[i]]++;
      if (cnt[v[i - m]] == 0 and v[i - m] < p) p = v[i - m];
      res = min(res, p);
    }
    cout << res << nl;
  }
  return 0;
}

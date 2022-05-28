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
    int n; cin >> n;
    vi v(n, 0);
    map<int, int> cnt;
    map<int, bool> used;
    for (auto& x : v) {
      cin >> x;
      cnt[x]++;
    }

    for (auto x : v) {
      if (used[x]) continue;
      if (cnt[x] > 1) used[x] = 1;
      for (int p = 2 * x; p <= mxN; p += x) used[p] = 1;
    }
    int res = 0;
    for (auto x : v) {
      if (used[x]) continue;
      res++;
    }
    cout << res << nl;
  }
  return 0;
}

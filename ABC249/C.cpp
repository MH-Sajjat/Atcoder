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
    int n, k;
    cin >> n >> k;
    string s[n];
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    vector<vi> cnt(n, vi(26, 0));
    for (int i = 0; i < n; ++i) {
      for (auto x : s[i]) {
        cnt[i][x - 'a']++;
      }
    }
    int res = 0;
    for (int i = 1; i < (1 << n); ++i) {
      int sub = 0;
      for (int j = 0; j < 26; ++j) {
        int coun = 0;
        for (int l = 0; l < n; ++l) {
          if (i & (1 << l)) coun += cnt[l][j];
        }
        if (coun == k) sub++;
      }
      res = max(res, sub);
    }

    cout << res << nl;
  }
  return 0;
}

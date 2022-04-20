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

vi notContain;
vi contain;

int isValid(int n) {
  vi v;
  while (n) {
    int d = n % 10;
    v.pb(d);
    n /= 10;
  }
  while (szof(v) < 4) v.pb(0);
  int valid = 1;
  for (auto x : v) {
    for (auto y : notContain) {
      if (x == y) valid = 0;
    }
  }
  for (auto x : contain) {
    int ok = 0;
    for (auto y : v) {
      if (x == y) ok = 1;
    }
    valid &= ok;
  }
  return valid;
}

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
    for (int i = 0; i < 10; ++i) {
      if (s[i] == 'x') notContain.pb(i);
      if (s[i] == 'o') contain.pb(i);
    }
    int res = 0;
    for (int i = 0; i <= 9999; ++i) {
      res += isValid(i);
    }

    cout << res << nl;
  }
  return 0;
}

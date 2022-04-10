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

vector<pii> segment;
vi v;
int X, Y;
ll res = 0;

void solve() {
  for (auto x : segment) {
    int L = x.ff, R = x.ss;
    map<int, int> m;
    int l = L, r = L;
    m[v[l]]++;
    while (l <= R) {
      while (r <= R and (m[X] < 1 or m[Y] < 1)) {
        ++r;
        m[v[r]]++;
      }
      if (r > R) break;
      res += (R - r + 1);
      m[v[l]]--;
      l++;
    }
  }
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
    cin >> n >> X >> Y;
    vi temp;
    temp.pb(-1);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      v.pb(x);
      if (x > X or x < Y) temp.pb(i);
    }
    temp.pb(n);
    for (int i = 1; i < szof(temp); ++i) {
      int l = temp[i - 1] + 1, r = temp[i] - 1;
      if (l <= r) segment.pb({l, r});
    }

    solve();
    cout << res << nl;
  }
  return 0;
}

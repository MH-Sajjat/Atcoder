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

vector<bool> used(20, 0);
int info[20][20];
vector<pii> pr;
int n;

int call() {
  if (szof(pr) == n) {
    int res = 0;
    for (auto x : pr) {
      res ^= info[x.ff][x.ss];
    }
    return res;
  }

  int l = -1;
  for (int i = 1; i <= 2 * n; ++i) {
    if (!used[i]) {
      used[i] = 1;
      l = i;
      break;
    }
  }
  int res = 0;
  for (int i = l + 1; i <= 2 * n; ++i) {
    if (!used[i]) {
      pr.push_back({l, i});
      used[i] = 1;
      res = max(res, call());
      used[i] = 0;
      pr.pop_back();
    }
  }
  used[l] = 0;
  return res;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
      for (int j = i + 1; j <= 2 * n; ++j) {
        cin >> info[i][j];
      }
    }

    cout << call() << nl;
  }
  return 0;
}

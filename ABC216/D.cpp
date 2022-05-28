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
    int n, m; cin >> n >> m;
    vector<stack<int>> st(m + 2, stack<int>());
    for (int i = 1; i <= m; ++i) {
      int k; cin >> k;
      vi temp(k, 0);
      for (auto& x : temp) cin >> x;
      for (int j = k - 1; j >= 0; --j) st[i].push(temp[j]);
    }

    stack<int> v;

    vector<pii> pos(n + 2, {0, 0});
    for (int i = 1; i <= m; ++i) {
      int tVal = st[i].top();
      if (pos[tVal].ff == 0) pos[tVal].ff = i;
      else {
        pos[tVal].ss = i;
        v.push(tVal);
      }
    }

    while (!v.empty()) {
      int val = v.top();
      v.pop();
      int posF = pos[val].ff;
      int posS = pos[val].ss;
      st[posF].pop();
      st[posS].pop();
      if (!st[posF].empty()) {
        int tVal = st[posF].top();
        if (pos[tVal].ff == 0) pos[tVal].ff = posF;
        else {
          pos[tVal].ss = posF;
          v.push(tVal);
        }
      }

      if (!st[posS].empty()) {
        int tVal = st[posS].top();
        if (pos[tVal].ff == 0) pos[tVal].ff = posS;
        else {
          pos[tVal].ss = posS;
          v.push(tVal);
        }
      }
    }
    bool valid = 1;
    for (int i = 1; i <= m; ++i) if (!st[i].empty()) valid = 0;
    if (valid) cout << "Yes" << nl;
    else cout << "No" << nl;
  }
  return 0;
}

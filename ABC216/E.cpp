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

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

int solve(ll low, ll high, ll k, ll x) {
  ll res = high + 1;
  ll l = low, r = high;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if ((high - mid + 1) * x <= k) {
      res = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  return res;
}

ll getSum(ll l, ll r) {
  return ((r * (r + 1)) - (l * (l - 1))) / 2LL;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n; cin >> n;
    ll k; cin >> k;
    vll v;
    priority_queue<ll> pq;
    pq.push(0LL);
    map<ll, ll> m;
    for (int i = 1; i <= n; ++i) {
      ll x; cin >> x;
      m[x]++;
      if (m[x] == 1) {
        pq.push(x);
      }
    }
    ll res = 0;
    while (szof(pq) > 1 and k > 0) {
      int tp = pq.top();
      pq.pop();
      ll x = m[tp];
      ll low = pq.top() + 1, high = tp;
      ll p = solve(low, high, k, x);
      if (p <= high) {
        res += getSum(p, high) * x;
        k -= (high - p + 1) * x;
        m[p - 1] += x;
        if (m[p - 1] == x) {
          pq.push(p - 1);
        }
      } else {
        res += high * k;
        k = 0;
      }
    }
    cout << res << nl;
  }
  return 0;
}

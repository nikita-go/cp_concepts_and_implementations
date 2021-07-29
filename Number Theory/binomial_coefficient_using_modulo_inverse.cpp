#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll factorial[1000001];

int power(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n%2) {
            n--;
            res = (res*a)%mod;
        }
        n /= 2;
        a = (a*a)%mod;
    }
    return res;
}

int coeff(ll n, ll k) {
    if (n<k) {
        return 0;
    }
    ll res = factorial[n]%MOD;
    res = (res*power(factorial[k], MOD-2, MOD))%MOD;
    res = (res*power(factorial[n-k], MOD-2, MOD))%MOD;
    return res;
}

int main() {
    factorial[0] = factorial[1] = 1;
    for (ll i = 2; i <= 1000000; i++) {
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << coeff(n, k) << "\n";
    }
}
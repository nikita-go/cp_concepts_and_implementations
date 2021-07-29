#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll multiply(ll a, ll b, ll c) {
    ll x = 0, y = a%c;
    while (b>0) {
        if (b%2==1) {
            x = (x+y)%c;
        }
        y = (y*2LL)%c;
        b /= 2;
    }
    return x%c;
}

ll binpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n%2==1) {
            n--;
            res = multiply(res, a, mod);
        }
        a = multiply(a, a, mod);
        n /= 2;
    }
    return res%mod;
}

bool check_composite(ll n, ll a, ll d, ll s) {
    ll x = binpow(a, d, n);
    if (x==1 || x==n-1) {
        return false;
    }
    for (ll r = 1; r < s; r++) {
        x = ((x%n)*(x%n))%n;
        if (x==n-1) {
            return false;
        }
    }
    return true;
}

bool isPrime(ll n) {
    if (n<2) {
        return false;
    }
    ll r = 0, d = n-1;
    while ((d&1)==0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n==a) {
            return true;
        }
        if (check_composite(n, a, d, r)) {
            return false;
        }
    }
    return true;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (isPrime(n)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
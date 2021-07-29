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

bool isPrime(ll n, ll iter=5) {
    if (n<4) {
        return n==2 || n==3;
    }
    for (int i = 1; i <= iter; i++) {
        ll a = 2+rand()%(n-3);
        ll res = binpow(a, n-1, n);
        if (res!=1) {
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
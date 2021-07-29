#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, ll> prime_factorization;
ll total = 0;

void factorize(ll n) {
    total = 1;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i==0) {
            int cnt = 0;
            while (n%i==0) {
                cnt++;
                n /= i;
            }
            prime_factorization[i] = cnt;
            total *= (cnt+1);
        }
    }
    if (n>1) {
        prime_factorization[n] = 1;
        total *= 2;
    }
}

int main() {
    ll n, q;
    cin >> n >> q;
    factorize(n);
    while (q--) {
        int k;
        cin >> k;
        ll res = 1;
        for (pair<ll, ll> p : prime_factorization) {
            ll cnt = 0;
            while (k%p.first==0) {
                cnt++;
                k /= p.first;
            }
            res *= min(cnt, p.second)+1;
        }
        cout << res << "\n";
    }
}
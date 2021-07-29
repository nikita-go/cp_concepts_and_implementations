#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> primes;
int prime[100001];

void sieve(int maxN) {
    vector<int> vec(maxN+1, 0);
    vec[1] = 1;
    for (int i = 2; i <= maxN; i++) {
        if (vec[i]==0) {
            for (int j = i*2; j <= maxN; j+=i) {
                vec[j] = 1;
            }
        }
    }
    for (int i = 1; i <= maxN; i++) {
        if (vec[i]==0) {
            primes.push_back(i);
        }
    }
}

void solve(int l, int r) {
    if (l==1) {
        l++;
    }
    int maxN = r-l+1;
    vector<int> vec(maxN, 0);
    for (ll p : primes) {
        if (p*p<=r) {
            int i = (l/p)*p;
            if (i<l) {
                i += p;
            }
            for (;i<=r;i+=p) {
                if (i!=p) {
                    vec[i-l] = 1;
                }
            }
        }
    }
    for (int i = 0; i < maxN; i++) {
        if (vec[i]==0) {
            cout << l+i << " ";
        }
    }
}

int main() {
    sieve(100000);
    int l, r;
    cin >> l >> r;
    solve(l, r);
}
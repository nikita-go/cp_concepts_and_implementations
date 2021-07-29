#include <bits/stdc++.h>
using namespace std;

int power(int a, int n, int mod) {
    int res = 1;
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

int main() {
    int a, mod;
    cin >> a >> mod;
    cout << power(a, mod-2, mod);
}
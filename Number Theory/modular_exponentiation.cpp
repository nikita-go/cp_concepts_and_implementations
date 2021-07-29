#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

int main() {
    int base, n, res = 1;
    cin >> base >> n;
    while (n!=0) {
        if (n%2==1) {
            res = (base*res)%MOD;
            n--;
        }
        base = (base*base)%MOD;
        n /= 2;
    }
    cout << res << "\n";
}
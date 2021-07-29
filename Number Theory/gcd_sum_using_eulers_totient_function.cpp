#include <bits/stdc++.h>
using namespace std;

int phi[1000001];

int main() {
    for (int i = 1; i <= 1000000; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= 1000000; i++) {
        if (phi[i]==i) {
            for (int j = i; j <= 1000000; j += i) {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    int n, res = 0;
    cin >> n;
    for (int i = 1; i*i <= n; i++) {
        if (n%i==0) {
            int d1 = i, d2 = n/i;
            res += d1*phi[n/d1];
            if (d1!=d2) {
                res += d2*phi[n/d2];
            }
        }
    }
    cout << res;
}
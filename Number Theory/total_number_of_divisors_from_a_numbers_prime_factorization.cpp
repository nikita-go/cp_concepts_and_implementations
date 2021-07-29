#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 2; i*i <= n; i++) {
        if (n%i==0) {
            int cnt = 0;
            while (n%i==0) {
                cnt++;
                n /= i;
            }
            ans = ((ans%MOD)*((cnt+1)%MOD))%MOD;
        }
    }
    if (n>1) {
        ans = ((ans%MOD)*((2)%MOD))%MOD;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int base, n, res = 1;
    cin >> base >> n;
    while (n!=0) {
        if (n%2==1) {
            res *= base;
            n--;
        }
        base *= base;
        n /= 2;
    }
    cout << res << "\n";
}
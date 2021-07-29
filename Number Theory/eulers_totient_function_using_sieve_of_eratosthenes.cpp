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
    int n;
    cin >> n;
    cout << phi[n];
}
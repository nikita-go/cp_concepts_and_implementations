#include <bits/stdc++.h>
using namespace std;

int isPrime[1000001];

int main() {
    int MAXN = 1000000;
    for (int i = 1; i <= MAXN; i++) {
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i; j*j <= MAXN; j += i) {
                isPrime[j] = {0};
            }
        }
    }
}
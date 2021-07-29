#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main() {
    int n, MAXN = 1000000;
    vector<int> factors;
    cin >> n;
    for (int i = 1; i <= MAXN; i++) {
        arr[i] = -1;
    }
    for (int i = 2; i <= MAXN; i++) {
        if (arr[i]==-1) {
            for (int j = i; j <= MAXN; j += i) {
                if (arr[j]==-1) {
                    arr[j] = i;
                }
            }
        }
    }
    while (n>1) {
        cout << arr[n] << " ";
        n /= arr[n];
    }
}
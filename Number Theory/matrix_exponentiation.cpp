#include <bits/stdc++.h>
using namespace std;

int arr[101][101], im[101][101];

void multiply(int a[][101], int b[][101], int size) {
    int res[size+1][size+1];
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            res[i][j] = 0;
            for (int k = 1; k <= size; k++) {
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for (int i = 0; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void power(int a[][101], int size, int n) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i==j) {
                im[i][j] = 1;
            }
        }
    }
    while (n) {
        if (n%2) {
            multiply(im, arr, size);
            n--;
        }
        multiply(arr, arr, size);
        n /= 2;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            arr[i][j] = im[i][j];
        }
    }
}

int main() {
    int size, n;
    cin >> size >> n;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cin >> arr[i][j];
        }
    }
    power(arr, size, n);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
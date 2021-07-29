#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}

bool solve(int a, int b, int c, int& x, int& y) {
    int x0, y0;
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c%g) {
        return false;
    }
    x = x0*c/g;
    y = y0*c/g;
    if (a<0) {
        x = -x;
    }
    if (b<0) {
        y = -y;
    }
    return true;
}

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c;
    if (solve(a, b, c, x, y)==false) {
        cout << "NO SOLUTION";
    }
    else {
        cout << x << " " << y;
    }
}
#include<iostream>
#include<cmath>
#define INF 1000000
using namespace std;

int remocon[10];

int check(int n) {
    if (n == 0) {
        if (remocon[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (remocon[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main() {
    int n,m, current = 100;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int j;
        cin >> j;
        remocon[j] = 1;
    }

    int result = abs(n-current);
    for (int i = 0; i <= INF; i++) {
        int c = i;
        int len = check(c);
        if (len > 0) {
            int press = abs(c - n);
            if (result > press + len)
                result = press + len;
        }
    }
    cout << result << '\n';
    return 0;
}
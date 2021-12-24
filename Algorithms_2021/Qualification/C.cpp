#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int sum = 0, sumn = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int nboxes = sum;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != 0)
            nboxes = min(nboxes, a[i] / b[i]);
        sumn += b[i];
    }
    int ans = 0;
    for (int i = 1; i * i <= sum && i <= nboxes; ++i) {
        if (sum % i == 0) {
            ans = i;
            if (sum / i <= nboxes) {
                ans = sum / i;
                break;
            }
        }
    }
    nboxes = ans;
    if (nboxes == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    cout << nboxes << " " << sum / nboxes << endl;
    int it = 0;
    a[0] -= b[0] * nboxes;
    for (int i = 0; i < nboxes; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < b[j]; ++k) {
                cout << j + 1 << " ";
            }
        }
        for (int j = sumn; j < sum / nboxes; ++j) {
            while (a[it] == 0) {
                ++it;
                a[it] -= b[it] * nboxes;
            }
            cout << it + 1 << " ";
            --a[it];
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

string charstostr(char c1, char c2, char c3, char c4) {
    vector<string> ans(4);
    ans[0].push_back(c1);
    ans[0].push_back(c2);
    ans[0].push_back(c4);
    ans[0].push_back(c3);

    ans[1].push_back(c2);
    ans[1].push_back(c4);
    ans[1].push_back(c3);
    ans[1].push_back(c1);

    ans[2].push_back(c4);
    ans[2].push_back(c3);
    ans[2].push_back(c1);
    ans[2].push_back(c2);

    ans[3].push_back(c3);
    ans[3].push_back(c1);
    ans[3].push_back(c2);
    ans[3].push_back(c4);

    sort(ans.begin(), ans.end());
    return ans[0];
}

int main() {
    map<string, int> a;
    int k;
    char c1, c2, c3, c4;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> c1 >> c2 >> c3 >> c4;
        string key = charstostr(c1, c2, c3, c4);
        if (a.find(key) != a.end())
            a[key] += 1;
        else
            a[key] = 1;
    }
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            c1 = s[2 * i][2 * j];
            c2 = s[2 * i][2 * j + 1];
            c4 = s[2 * i + 1][2 * j + 1];
            c3 = s[2 * i + 1][2 * j];
            string key = charstostr(c1, c2, c3, c4);
            if (a.find(key) != a.end() && a[key] > 0)
                a[key] -= 1;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
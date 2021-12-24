#include <bits/stdc++.h>

using namespace std;

bool check(string s, string t) {
    reverse(t.begin(), t.end());
    string curr = s + t;
    int length = 0;
    while (curr[s.size() + length] == curr[s.size() - 1 - length]) {
        ++length;
    }
    vector<int> pi(curr.size());
    pi[0] = 0;
	for (int i = 1; i < curr.size(); ++i) {
		int j = pi[i-1];
        while (j > 0 && curr[i] != curr[j])
            j = pi[j-1];
        if (curr[i] == curr[j])
            j++;
        pi[i] = j;
    }
	return curr.size() - pi[curr.size() - 1] <= s.size() + length; 
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    if (check(s, t)) {
        cout << "Yes" << '\n'; 
    } else {
        cout << "No" << '\n';
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int num, pos;
        char c;
        cin >> num >> pos >> c;
        if (num == 1) {
            s[pos - 1] = c;
        } else {
            t[pos - 1] = c;
        }
        if (check(s, t)) {
        cout << "Yes" << '\n'; 
        } else {
            cout << "No" << '\n';
        }
    }
}
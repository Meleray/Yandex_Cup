#include <bits/stdc++.h>
#include <numeric>

using namespace std;

vector<vector<int>> moves(50);
map<pair<string, int>, pair<int, int>> m;

void develop_strategy(string & a, int last) {
    if (m.find({a, last}) == m.end()) {
        m[{a, last}] = {0, 0};
        bool can_move = false;
        for (int i = 0; i < moves[last].size(); ++i) {
            int move = moves[last][i];
            if (a[move] != '0') {
                can_move = true;
                a[move] = '0';
                if (m.find({a, move}) == m.end()) {
                    develop_strategy(a, move);
                }
                pair<int, int> res = m[{a, move}];
                a[move] = '1';
                m[{a, last}].first += res.second;
                m[{a, last}].second += res.first;
            }
        }
        if (!can_move) {
            m[{a, last}].second = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < i; ++j) {
            if (std::gcd(i + 1, j + 1) == 1) {
                moves[i].push_back(j);
                moves[j].push_back(i);
            }
        }
    }
    string beg(50, '1');
    develop_strategy(beg, 1);
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            beg[j] = '1';
        }
        for (int j = n; j < 50; ++j) {
            beg[j] = '0';
        }
        if (m.find({beg, 1}) == m.end()) {
            develop_strategy(beg, 1);
        }
        int last = 1;
        pair<int, int> res = m[{beg, 1}];
        if (res.first > res.second) {
            cout << 1 << "\n";
            cout.flush();
            int move;
            double proba = 0;
            for (int j = 0; j < n; ++j) {
                beg[j] = '0';
                pair<int, int> out = m[{beg, i}];
                double cur_proba = (double)out.second / (out.first + out.second);
                if (cur_proba > proba) {
                    move = i;
                }
                beg[i] = '1';
            }
            cout << move + 1 << "\n";
            cout.flush();
        } else {
            cout << 2 << "\n";
            cout.flush();
        }
        cin >> last;
        --last;
        beg[last] = '0';
        res = m[{beg, last}];
        int move;
        double proba = 0;
        for (int i = 0; i < moves[last].size(); ++i) {
                beg[i] = '0';
                pair<int, int> out = m[{beg, i}];
                double cur_proba = (double)out.second / (out.first + out.second);
                if (cur_proba > proba) {
                    move = i;
                }
                beg[i] = '1';
            }
            cout << move + 1 << "\n";
            cout.flush();
    }
}
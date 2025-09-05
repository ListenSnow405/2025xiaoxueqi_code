#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string target = "fattyhappy";

void solve(const string &s) {
    int n = s.size();
    if (n < 10) {
        cout << -1 << endl;
        return;
    }
    vector<int> perfect_starts;
    for (int start = 0; start <= n - 10; start++) {
        vector<int> diff;
        for (int i = 0; i < 10; i++) {
            if (s[start + i] != target[i]) {
                diff.push_back(i);
            }
        }
        if (diff.size() == 0) {
            perfect_starts.push_back(start);
        } else if (diff.size() == 1) {
            int idx = diff[0];
            for (int j = 0; j < n; j++) {
                if (j < start || j >= start + 10) {
                    if (s[j] == target[idx]) {
                        cout << start + idx + 1 << " " << j + 1 << endl;
                        return;
                    }
                }
            }
        } else if (diff.size() == 2) {
            int i0 = diff[0], i1 = diff[1];
            if (s[start + i0] == target[i1] && s[start + i1] == target[i0]) {
                cout << start + i0 + 1 << " " << start + i1 + 1 << endl;
                return;
            }
        }
    }
    if (!perfect_starts.empty()) {
        int start = perfect_starts[0];
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (s[start + i] == s[start + j]) {
                    cout << start + i + 1 << " " << start + j + 1 << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
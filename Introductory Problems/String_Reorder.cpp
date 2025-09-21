#include <bits/stdc++.h>

using namespace std;

string solve(const string &s) {
    int n = s.size();
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'A']++;

    if (*max_element(cnt.begin(), cnt.end()) > (n + 1) / 2) return "-1";

    string res;
    char prev = '\0';

    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] > 0 && (prev != char('A' + j))) {
                cnt[j]--;
                if (*max_element(cnt.begin(), cnt.end()) <= (n - i - 1 + 1) / 2) {
                    res += char('A' + j);
                    prev = char('A' + j);
                    found = true;
                    break;
                }
                cnt[j]++;
            }
        }
        if (!found) return "-1";
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    cout << solve(s) << '\n';
    return 0;
}
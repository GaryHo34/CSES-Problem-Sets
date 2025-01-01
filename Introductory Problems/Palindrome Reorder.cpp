#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> a(26);
    for (auto ch : s)
    {
        a[ch - 'A']++;
    }

    char odd = 0;

    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!odd && a[i] % 2 == 1)
        {
            odd = 'A' + i;
        }
        else if (a[i] % 2 == 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        while (a[i] > 1)
        {
            s[j] = s[n - j - 1] = (i + 'A');
            a[i] -= 2;
            j++;
        }
    }
    if (odd)
        s[j] = odd;
    cout << s << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    cin >> n;

    vector<long long> arr;
    set<long long> s;
    long long ans = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
        ans = max(ans, (long long)j - i);
        s.erase(arr[i]);
    }
    cout << ans << endl;
    return 0;
}
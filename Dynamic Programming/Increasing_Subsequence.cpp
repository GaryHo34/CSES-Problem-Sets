#include <bits/stdc++.h>

using namespace std;

int LongestIncreaseSequence(vector<int> &vec)
{
    vector<int> lis;
    for (auto x : vec)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it != lis.end())
        {
            lis[it - lis.begin()] = x;
        }
        else
        {
            lis.push_back(x);
        }
    }
    return lis.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << LongestIncreaseSequence(vec) << endl;

    return 0;
}
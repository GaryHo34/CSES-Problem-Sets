#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies;
    for (int i=0; i<n; i++)
    {   
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }   
    sort(movies.begin(), movies.end());
    multiset<int> s;
    for (int i=0; i<k; i++) 
    {
        s.insert(0);
    }

    int ret = 0;
    for (auto [a, b]: movies)
    {
        if (a >= *s.begin())
        {
            s.erase(s.begin());
            s.insert(b);
            ret++;
        }
        else if (b < *s.rbegin())
        {
            s.erase(prev(s.end()));
            s.insert(b);
        }
    }
    cout << ret << endl;
    return 0;
}
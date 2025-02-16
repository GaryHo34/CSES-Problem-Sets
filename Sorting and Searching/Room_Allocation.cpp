#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<array<int,3>> arr;
    for (int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b, i});
    }
    vector<int> rets(n);
    sort(arr.begin(), arr.end());
    
    int mx = 0;
    queue<int> q;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // end, room;
    for (auto [start, end, idx]: arr)
    {   
        while (!pq.empty() && pq.top().first < start)
        {
            q.push(pq.top().second);
            pq.pop();
        }
        if (q.empty()) 
        {
            mx++;
            rets[idx] = mx;
            pq.push({end, mx});
        }
        else
        {
            rets[idx] = q.front();
            pq.push({end, q.front()});
            q.pop();
        }
    }

    cout << mx << endl;
    for (auto x: rets)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    vector<int> arr(n + 1);
    
    st.push(0);
    arr[0] = INT_MIN;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        cout << st.top() << (" \n")[i==n];
        st.push(i);
    }
    return 0;
}
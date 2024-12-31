#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    int n = input.size();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n && input[j] == input[j + 1])
        {
            j++;
        }
        ret = max(ret, j - i + 1);
        i = j;
    }
    cout << ret << endl;
    return 0;
}
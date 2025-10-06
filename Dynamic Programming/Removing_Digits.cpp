#include <bits/stdc++.h>

using namespace std;

int val[1000005];
int digit[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;

    for (int i = 0; i < x; i++)
        val[i] = INT_MAX / 2;

    for (int i = x; i > 0; i--)
    {
        int tmp = i;
        for (int j = 0; j < 10; j++)
            digit[j] = 0;
        while (tmp > 0)
        {
            digit[tmp % 10] = ((tmp % 10) > 0);
            tmp /= 10;
        }
        for (int j = 0; j < 10; j++)
            if (digit[j] > 0 && i - j >= 0)
                val[i-j] = min(val[i-j], val[i] + 1);
    }
    cout << val[0] << endl;
    return 0;
}
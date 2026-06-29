#include <bits/stdc++.h>

using namespace std;

using LL = long long;
LL MOD = 1e9 + 7;
class SegTreeNode
{
public:
    SegTreeNode *left = NULL;
    SegTreeNode *right = NULL;
    LL start, end;
    LL info; // the sum value over the range
    bool lazy_tag;
    LL lazy_val;

    SegTreeNode(LL a, LL b, LL val) // init for range [a,b] with val
    {
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a == b)
        {
            info = val;
            return;
        }
        LL mid = (a + b) / 2;
        if (left == NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid + 1, b, val);
            info = (left->info + right->info) % MOD; // check with your own logic
        }
    }

    SegTreeNode(LL a, LL b, vector<LL> &val) // init for range [a,b] with the same-size array val
    {
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a == b)
        {
            info = val[a];
            return;
        }
        LL mid = (a + b) / 2;
        if (left == NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid + 1, b, val);
            info = (left->info + right->info) % MOD; // check with your own logic
        }
    }

    void pushDown()
    {
        if (lazy_tag == 1 && left)
        {
            left->info = lazy_val * (left->end - left->start + 1);
            right->info = lazy_val * (right->end - right->start + 1);
            left->lazy_tag = 1;
            left->lazy_val = lazy_val;
            right->lazy_tag = 1;
            right->lazy_val = lazy_val;
            lazy_tag = 0;
            lazy_val = 0;
        }
    }

    void updateRange(LL a, LL b, LL val) // set range [a,b] with val
    {
        if (b < start || a > end) // not covered by [a,b] at all
            return;
        if (a <= start && end <= b) // completely covered within [a,b]
        {
            info = val * (end - start + 1);
            lazy_tag = 1;
            lazy_val = val;
            return;
        }

        if (left)
        {
            pushDown();
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = (left->info + right->info) % MOD; // write your own logic
        }
    }

    LL queryRange(LL a, LL b) // query the sum over range [a,b]
    {
        if (b < start || a > end)
        {
            return 0; // check with your own logic
        }
        if (a <= start && end <= b)
        {
            return info; // check with your own logic
        }

        if (left)
        {
            pushDown();
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);
            info = (left->info + right->info) % MOD; // check with your own logic
            return ret;
        }

        return info; // should not reach here
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n;
    cin >> n;

    vector<LL> vec(n);
    map<LL, LL> m;
    for (LL i = 0; i < n; i++)
    {
        cin >> vec[i];
        m[vec[i]]++;
    }
    int idx = 0;
    for (auto &p : m)
    {
        p.second = ++idx;
    }
    LL mn = LLONG_MAX;
    LL mx = LLONG_MIN;
    for (auto &x : vec)
    {
        x = m[x];
        mn = min(mn, x);
        mx = max(mx, x);
    }

    SegTreeNode root(mn, mx, 0);

    for (LL i = 0; i < n; i++)
    {
        LL ele = vec[i];
        LL org = root.queryRange(ele, ele);
        LL sum = (root.queryRange(mn, ele - 1) + 1 + org) % MOD;
        root.updateRange(ele, ele, sum);
    }

    cout << root.queryRange(mn, mx) << endl;

    return 0;
}
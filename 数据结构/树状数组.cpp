区间改单点查
若需要单点改区间查, 则只提供单点修改add(idx, w)
区间查询相当于查询其前缀和: query(r) - query(l - 1);
struct fenwick
{
    vector<ll> tree;
    int n;
    fenwick(int _n)
    {
        n = _n;
        tree.resize(n + 1);
    }
    void add(int idx, ll w)
    {
        for (int i = idx; i <= n; i += lowbit(i)) tree[i] += w;
    }
    void add(int l, int r, int w)
    {
        add(l, w);
        add(r + 1, -w);
    }
    ll query(int idx)
    {
        ll ret = 0;
        for (int i = idx; i; i -= lowbit(i)) ret += tree[i];
        return ret;
    }
};
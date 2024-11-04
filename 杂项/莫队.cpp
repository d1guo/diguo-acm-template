int nums[200001];
ll ans[200001];
struct node
{
    int l, r, id;
    bool operator < (const node& x) const
    {
        return nums[l] == nums[x.l] ? (nums[l] & 1 ? r < x.r : r > x.r): l < x.l;
    }
};
//转移，增加
void add(int idx)
{

}
//转移，减少
void del(int idx)
{

}
void solve()
{
    int n = read(), len = sqrt(n), q = read(), tot = 1, now = 0;
    rep(i, 1, n)
    {
        if (++now > len) now -= len, ++tot;
        nums[i] = tot;
    }
    rep(i, 1, n) a[i] = read();
    vector<node> qa(q + 1);
    rep(i, 1, q)
    {
        qa[i].l = read(), qa[i].r = read(), qa[i].id = i;
    }
    sort(qa.begin() + 1, qa.end());
    int l = 1, r = 0;
    rep(i, 1, q)
    {
        while (l < qa[i].l) del(l++);
        while (l > qa[i].l) add(--l);
        while (r < qa[i].r) add(++r);
        while (r > qa[i].r) del(r--);
        ans[qa[i].id] = cnt;
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}
struct node
{
    ll sum, mn;
    node(ll _sum, ll _mn): sum(_sum), mn(_mn){}
    node(): sum(0), mn(LNF){}
    node operator + (const node& x) const{
        return {sum + x.sum, min(mn, x.mn)};
    }
};
struct segtree
{
    int n;
    vector<node> tree;
    vector<long long> tag;
    void init(int _n)
    {
        n = _n;
        tree.resize(4 * n + 1);
        tag.resize(4 * n + 1);
        build(1, n, 1);
    }
    void build(int l, int r, int p)
    {
        if (l == r) return (void)(tree[p] = {a[l], a[l]});
        int mid = l + r >> 1;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }
    void push_down(int l, int r, int p)
    {
        if (l == r) return (void)(tag[p] = 0);
        tag[ls(p)] += tag[p], tag[rs(p)] += tag[p];
        int mid = l + r >> 1;
        tree[ls(p)].mn += tag[p], tree[rs(p)].mn += tag[p];
        tree[ls(p)].sum += (mid - l + 1) * tag[p], tree[rs(p)].sum += (r - mid) * tag[p];
        tag[p] = 0;
    }
    void update(int cl, int cr, int w, int l, int r, int p)
    {
        if (cl <= l && r <= cr)
            return (void)(tag[p] += w, tree[p].mn += w, tree[p].sum += (r - l + 1) * w);
        if (tag[p]) push_down(l, r, p);
        int mid = l + r >> 1;
        if (cl <= mid) update(cl, cr, w, l, mid, ls(p));
        if (mid + 1 <= cr) update(cl, cr, w, mid + 1, r, rs(p));
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }
    ll query(int cl, int cr, int l, int r, int p)
    {
        if (cl <= l && r <= cr) return tree[p].mn;
        if (tag[p]) push_down(l, r, p);
        int mid = l + r >> 1;
        ll ret = LNF;
        if (cl <= mid) ret = min(ret, query(cl, cr, l, mid, ls(p)));
        if (mid + 1 <= cr) ret = min(ret, query(cl, cr, mid + 1, r, rs(p)));
        return ret;
    }
}sgt;
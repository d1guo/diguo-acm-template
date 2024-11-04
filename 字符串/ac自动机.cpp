struct AC_automation
{
    static constexpr int ALPHABET = 26;
    static constexpr char BASE = 'a';
    int tot = 1;
    struct Node
    {
        int len, fail;
        array<int, ALPHABET> next;
        Node() : len{0}, fail{0}, next{} {}
    };
    vector<Node> tree;
    AC_automation()
    {
        re();
    }
    void re()
    {
        tree.assign(2, Node());
        tree[0].next.fill(1);
        tree[0].len = -1;
    }
    int newNode()
    {
        tree.emplace_back();
        return tree.size() - 1;
    }
    int insert(const string &a)
    {
        int p = 1;
        for (auto c: a) {
            int x = c - BASE;
            if (tree[p].next[x] == 0)
            {
                tree[p].next[x] = newNode();
                tree[tree[p].next[x]].len = tree[p].len + 1;
            }
            p = tree[p].next[x];
        }
        tot = max(tot, p);
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (tree[x].next[i] == 0)
                {
                    tree[x].next[i] = tree[tree[x].fail].next[i];
                }
                else
                {
                    tree[tree[x].next[i]].fail = tree[tree[x].fail].next[i];
                    q.push(tree[x].next[i]);
                }
            }
        }
    }
    int next(int p, int x)
    {
        return tree[p].next[x];
    }
    int fail(int p)
    {
        return tree[p].fail;
    }
    int len(int p)
    {
        return tree[p].len;
    }
    int size()
    {
        return tree.size();
    }
};
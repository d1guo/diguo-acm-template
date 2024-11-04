struct seq_automation
{
    static constexpr int ALPHABET = 26;
    static constexpr char BASE = 'a';
    int tot = 0;
    vector<vector<int> > seq;
    void work(const string &s)
    {
 
        tot = s.length() - 1;
        seq.resize(tot + 1);
        rep(i, 0, tot) seq[i].resize(ALPHABET);
        vector<int> nxt(ALPHABET, tot + 1);
        per(i, tot, 1)
        {
            nxt[s[i] - BASE] = i;
            rep(j, 0, ALPHABET - 1) seq[i - 1][j] = nxt[j];
        }
    }
    int next(int p, int x)
    {
        if (p >= tot) return tot + 1;
        return seq[p][x];
    }
};
const int PRIMEN = ;
bool isnp[PRIMEN + 1];
vector<int> primes; // 质数表
void init()
{
    for (int i = 2; i <= PRIMEN; ++i)
    {
        if (!isnp[i])
            primes.push_back(i);
        for (int p: primes)
        {
            if (p * i > PRIMEN)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}
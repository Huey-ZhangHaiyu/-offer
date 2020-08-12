//试除法判断质数
bool is_prime(int x)
{
    if (x < 2) return false;
    //只需要判断到根号x，因为一个i变大，那么另一个i一定变小，这个变小的i一定在前面判断过了
    for (int i = 2; i*i <= x; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

//分解质因数：本质上还是判断质数的同时去把质因子找出来
void divide(int x)
{
    for (int i = 2; i*i <= x; i ++ )//判断质数
        if (x % i == 0)//找到一个因子
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;//找到另一半
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;//别忘了自身和1
    cout << endl;
}

//朴素筛法找质因子：适用于已知范围内找质因子
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )//直接循环遍历
    {
        if (st[i]) continue;//被筛掉的直接跳过
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)//每次找到所有的倍数筛掉
            st[j] = true;
    }
}

//线性筛
//和上面的思路差不多
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;//不知道这句话能否去掉
        }
    }
}

//试除法求约数
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )//同样只算到根号x
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);//顺便把另一半拿进来
        }
    sort(res.begin(), res.end());
    return res;
}

//约数的个数和约数之和
//如果 N = p1^c1 * p2^c2 * ... *pk^ck
//约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
//约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)

//快速幂
//求 m^k mod p，时间复杂度 O(logk)。
//mod p是怕越界
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

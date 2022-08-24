constexpr int MOD = 1e9 + 7;

int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

int add(int a, int b) {
    return a + b < MOD ? a + b : a + b - MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int power(int a, long long p) {
    int ans = 1;
    for (; p > 0; p >>= 1, a = mul(a, a)) if (p & 1) ans = mul(ans, a);
    return ans;
}

int sub(int a, int b) {
    return a >= b ? a - b : a - b + MOD;
}

const int maxF = 4e5 + 5;

int fact[maxF], ifact[maxF], inum[maxF];

void initF() {
    int n = maxF - 1;
    fact[0] = inum[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[n] = power(fact[n], MOD - 2);
    inum[n] = mul(ifact[n], fact[n - 1]);
    for (int i = n - 1; i > 0; --i) {
        ifact[i] = mul(ifact[i + 1], i + 1);
        inum[i] = mul(ifact[i], fact[i - 1]);
    }
}

int inv(int a) {
    if (a < maxF) return inum[a];
    return power(a, MOD - 2);
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(ifact[n - k], ifact[k]));
}
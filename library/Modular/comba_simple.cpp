constexpr int MOD = 998244353;

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
    return a * (long long) b % MOD;
}

int sub(int a, int b) {
    return a >= b ? a - b : a - b + MOD;
}

int power(int a, long long p) {
    int ans = 1;
    for (; p > 0; p >>= 1, a = mul(a, a)) {
        if (p & 1) {
            ans = mul(ans, a);
        }
    }
    return ans;
}

int inv(int a) {
    return power(a, MOD - 2);
}